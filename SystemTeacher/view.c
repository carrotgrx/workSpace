//
// Created by carrotgrx on 2023/10/6.
//
#include <pthread.h>
#include <conio.h>
#include "view.h"

HANDLE hOut;
PCOORD Window_Size;
pthread_t thread;
View showing;
int swch;

void gotoxy(int x, int y) {//定位坐标
    COORD pos = {x, y};
    SetConsoleCursorPosition(hOut, pos);
}

void color(short value) {//输出颜色
    SetConsoleTextAttribute(hOut, value);
}

void next(void) {//下一个选项
    if (showing->Selected->Next == NULL) {
        showing->Selected = showing->Head;
        showing->first = 0;
    } else {
        showing->Selected = showing->Selected->Next;
        if (showing->Selected->Next && showing->Selected->Index == (Window_Size->Y - 15) / 2 + showing->first - 1)
            showing->first++;
    }
    show();
}

void previous(void) {//上一个选项
    if (showing->Selected->Previous == NULL) {
        showing->Selected = showing->Rear;
        if ((Window_Size->Y - 15) / 2 >= showing->count) showing->first = 0;
        else showing->first = showing->count - (Window_Size->Y - 15) / 2;
    } else {
        showing->Selected = showing->Selected->Previous;
        if (showing->Selected->Previous && showing->Selected->Index == showing->first)
            showing->first--;
    }
    show();
}

void run(void) {//执行
    if (showing->Selected->Function) {
        swch = 0;
        showing->Selected->Function();
    } else {
        gotoxy(Window_Size->X - 25, Window_Size->Y);
        color(4);
        printf("ERROR: 此选项没有执行内容!");
        color(7);
    }
}

int freshSize(void) {//刷新界面大小
    int x, y;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hOut, &info);
    x = info.srWindow.Right - info.srWindow.Left;
    y = info.srWindow.Bottom - info.srWindow.Top;
    if (x != Window_Size->X || y != Window_Size->Y) {
        Window_Size->X = x;
        Window_Size->Y = y;
        return 1;
    } else return 0;
}

void *getSwitch(void *args) {//多线程读取按键
    while (1) {
        if (swch == 1) {
            if (freshSize()) show();
            if (_kbhit()) {
                int ch;
                ch = _getch();
                switch (ch) {
                    case 13:  //回车
                        run();
                        break;
                    case 27:  //ESC
                        setView(showing->back);
                        show();
                        break;
                    case 0xE0: //方向键组要读取两次, 第一次是224
                        ch = _getch();
                        switch (ch) {
                            case 72:
                                previous();
                                break;//上
                            case 80:
                                next();
                                break;//下
                        }
                        break;
                }
            }
        } else if (swch == 2 && _kbhit()) { //按任意键继续, 因为不想显示那几个字所以不使用pause
            _getch();
            swch = 0;
            show();
        }
    }
}

void initView(void) {//初始化ui界面
    Window_Size = (PCOORD) malloc(sizeof(COORD));
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pthread_create(&thread, NULL, &getSwitch, NULL);
}

void setView(View view) {//设置显示的ui界面
    showing = view;
}

void showTitle(void) {//显示标题
    /*
     *   _____ __  __  _____
     *  / ____|  \/  |/ ____|          _
     * | (___ | \  / | (___  _   _ ___| |_ ___ _ __ ___
     *  \___ \| |\/| |\___ \| | | / __| __/ _ \ '_ ` _ \
     *  ____) | |  | |____) | |_| \__ \ ||  __/ | | | | |
     * |_____/|_|  |_|_____/ \__, |___/\__\___|_| |_| |_|
     *                        __/ |
     *                       |___/
     */
    color(2);
    gotoxy(Window_Size->X / 2 - 25, 2);
    printf("  _____ __  __  _____");
    gotoxy(Window_Size->X / 2 - 25, 3);
    printf(" / ____|  \\/  |/ ____|          _");
    gotoxy(Window_Size->X / 2 - 25, 4);
    printf("| (___ | \\  / | (___  _   _ ___| |_ ___ _ __ ___");
    gotoxy(Window_Size->X / 2 - 25, 5);
    printf(" \\___ \\| |\\/| |\\___ \\| | | / __| __/ _ \\ '_ ` _ \\");
    gotoxy(Window_Size->X / 2 - 25, 6);
    printf(" ____) | |  | |____) | |_| \\__ \\ \\|  __/ | | | | |");
    gotoxy(Window_Size->X / 2 - 25, 7);
    printf("|_____/|_|  |_|_____/ \\__, |___/\\__\\___|_| |_| |_|");
    gotoxy(Window_Size->X / 2 - 25, 8);
    printf("                       __/ |");
    gotoxy(Window_Size->X / 2 - 25, 9);
    printf("                      |___/");
    color(7);
}

void show() {//显示选项
    Select t;
    CLS();
    showTitle();
    if (showing == NULL) {
        gotoxy(Window_Size->X / 2 - 4, Window_Size->Y - 5);
        exit(0);
    }
    for (t = showing->Head; t != NULL; t = t->Next) {
        if (t->Index >= showing->first && t->Index <= (Window_Size->Y - 15) / 2 + showing->first - 1) {
            gotoxy(Window_Size->X / 2 - strlen(t->Title) / 2 - 1, (t->Index - showing->first) * 2 + 13);
            if (!strcmp(showing->Selected->Title, t->Title)) color(134);
            else { color(6); }
            printf(" %s ", t->Title);
        }
    }
    color(7);
    gotoxy(0, Window_Size->Y);
    swch = 1;
}

void append(View view, char title[20], void (*function)(void)) {//添加选项
    Select t = (Select) malloc(sizeof(struct SelectNode));
    t->Index = (view->count)++;
    strcpy(t->Title, title);
    t->Function = function;
    t->Next = NULL;
    t->Previous = view->Rear;
    if (view->Head == NULL) view->Head = view->Selected = view->Rear = t;
    else {
        view->Rear->Next = t;
        view->Rear = t;
    }
}

View createView(void) {//创建ui
    View s = (View) malloc(sizeof(struct ViewNode));
    s->Head = s->Rear = s->Selected = NULL;
    s->count = s->first = 0;
    s->back = NULL;
    return s;
}
