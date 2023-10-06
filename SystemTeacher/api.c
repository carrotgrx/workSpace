//
// Created by carrotgrx on 2023/10/6.
//

#include <stdarg.h>
#include "lib.h"
#include "api.h"

Course Courses;
Homework Homeworks;
Tutor Tutors;
Student Students;
View QUERY;
View MAIN;
int Count;

void back(void) { //回到主界面
    setView(QUERY->back);
    show();
}

void soutCourse(int index, Course course) { //输出单个课程信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-12d%-12s",
                course->name, course->credit);
}

void soutTeacher(int index, Teacher teacher) { //输出教师信息
    for (int i = 0; i < 10; ++i) {
        customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-12s",
                    teacher->name);
    }
}

void soutHomework(int index, Homework homework, char course[]) { //输出作业信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-12s%-12s",
                course, homework->deadline);
}

void get(int type, char text[10], int viewNum) { //获取设备信息
    int value, i;
    char str[30];
    Device t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要查询的%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    customPrint(5, Window_Size->X / 2 - 45, 13,
                "编号        名称        价格        供应商      购买日期      购买部门      设备健康情况");
    for (i = 0, t = Devices; t->Next != NULL; t = t->Next) {
        switch (type) {
            case 1:
                if (t->Next->ID == value) {
                    sout(i, t->Next);
                    ++i;
                }
                break;
            case 2:
                if (!strcmp(t->Next->Name, str)) {
                    sout(i, t->Next);
                    ++i;
                }
                break;
            case 3:
                if (t->Next->Price == value) {
                    sout(i, t->Next);
                    ++i;
                }
                break;
            case 4:
                if (!strcmp(t->Next->Supplier, str)) {
                    sout(i, t->Next);
                    ++i;
                }
                break;
            case 5:
                if (!strcmp(t->Next->Date, str)) {
                    sout(i, t->Next);
                    ++i;
                }
                break;
            case 6:
                if (t->Next->Flag == value) {
                    sout(i, t->Next);
                    ++i;
                }
                break;
            case 7:
                if (!strcmp(t->Next->Department, str)) {
                    sout(i, t->Next);
                    ++i;
                }
                break;
        }
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void query1(void) {
    get(1, "设备编号", 1);
}
void query2(void) {
    get(2, "设备名称", 0);
}
void query3(void) {
    get(3, "价格", 1);
}
void query4(void) {
    get(4, "供应商", 0);
}
void query5(void) {
    get(5, "设备健康情况", 1);
}
void query6(void) {
    get(6, "购买部门", 0);
}
void query7(void) {
    get(7, "购买日期", 0);
}
void query0(void) {
    int i;
    Device t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "编号        名称        价格        供应商      购买日期      购买部门      设备健康情况");
    for (i = 0, t = Devices; t->Next != NULL; t = t->Next) {
        sout(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void quit(void) { //退出
    exit(0);
}

void initAPI(void) { //初始化
    Devices = (Device)malloc(sizeof(struct DeviceNode));
    Devices->Next = NULL;
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "新增设备信息", &add);
    append(MAIN, "删除设备信息", &del);
    append(MAIN, "修改设备信息", &modify);
    append(MAIN, "查询设备信息", &query);
    append(MAIN, "退出", &quit);

    append(QUERY, "根据编号查询", &query1);
    append(QUERY, "根据名称查询查询", &query2);
    append(QUERY, "根据供应商查询", &query3);
    append(QUERY, "根据购买日期查询", &query4);
    append(QUERY, "根据价格查询", &query5);
    append(QUERY, "根据报废情况查询", &query6);
    append(QUERY, "根据购买部门查询", &query7);
    append(QUERY, "列出所有信息", &query0);
    append(QUERY, "返回", &back);
    QUERY->back = MAIN;
}

void add(void) {//新增
    CLS();
    showTitle();
    Device t = (Device) malloc(sizeof(struct DeviceNode));
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入设备编号: ");
    scanf("%d", &t->ID);
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入设备名称: ");
    scanf("%s", t->Name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "请输入价格: ");
    scanf("%d", &t->Price);
    customPrint(5, Window_Size->X / 2 - 25, 16, "请输入供应商: ");
    scanf("%s", t->Supplier);
    customPrint(5, Window_Size->X / 2 - 25, 17, "请输入健康情况: ");
    scanf("%d", &t->Flag);
    customPrint(5, Window_Size->X / 2 - 25, 18, "请输入购买日期: ");
    scanf("%s", t->Date);
    customPrint(5, Window_Size->X / 2 - 25, 19, "请输入购买部门: ");
    scanf("%s", t->Department);
    t->Next = Devices->Next;
    Devices->Next = t;
    Count++;  //总数量+1
    show();   //回到主界面
    save();   //保存
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "增加成功"); // 右下角输出绿色增加成功
    gotoxy(0, Window_Size->Y);  //重置坐标
}

void modify(void) {//修改
    int id, comp = 0;
    Device t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要修改设备的编号: ");
    scanf("%d", &id);
    for (t = Devices; t->Next != NULL; t = t->Next) {
        if (t->Next->ID == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "请输入改后的编号: ");
            scanf("%d", &t->Next->ID);
            customPrint(5, Window_Size->X / 2 - 25, 16, "请输入改后的名称: ");
            scanf("%s", t->Next->Name);
            customPrint(5, Window_Size->X / 2 - 25, 17, "请输入改后的价格: ");
            scanf("%d", &t->Next->Price);
            customPrint(5, Window_Size->X / 2 - 25, 18, "请输入改后的供应商: ");
            scanf("%s", t->Next->Supplier);
            customPrint(5, Window_Size->X / 2 - 25, 19, "请输入改后的健康状况: ");
            scanf("%d", &t->Next->Flag);
            customPrint(5, Window_Size->X / 2 - 25, 20, "请输入改后的购买日期: ");
            scanf("%s", t->Next->Date);
            customPrint(5, Window_Size->X / 2 - 25, 21, "请输入改后的购买部门: ");
            scanf("%s", t->Next->Department);
            comp = 1;
            break;
        }
    }
    show();
    save();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "修改成功");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "未找到此信息");
    gotoxy(0, Window_Size->Y);
}

void del(void) {//删除
    int id, total = 0;
    Device p, t = Devices;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要删除设备的编号: ");
    scanf("%d", &id);
    while (t->Next != NULL) {
        if (t->Next->ID == id) {
            p = t->Next;
            t->Next = p->Next;
            free(p);
            total++;
        } else t = t->Next;
    }
    Count -= total;
    show();
    save();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "删除了 %d 条信息", total);
    gotoxy(0, Window_Size->Y);
}

void query(void) {//查询
    setView(QUERY);
    show();
}

void import(void) {//导入
    int line, i;
    Device t;
    FILE *file = fopen("config.txt", "r");
    if (file == NULL) {
        file = fopen("config.txt", "w");
        fprintf(file, "0\n");
        fclose(file);
    } else {
        fscanf(file, "%d", &line);
        for (i = 0; i < line; ++i) {
            t = (Device) malloc(sizeof(struct DeviceNode));
            fscanf(file, "%d", &t->ID);
            fscanf(file, "%s", t->Name);
            fscanf(file, "%d", &t->Price);
            fscanf(file, "%s", t->Supplier);
            fscanf(file, "%d", &t->Flag);
            fscanf(file, "%s", t->Date);
            fscanf(file, "%s", t->Department);
            t->Next = Devices->Next;
            Devices->Next = t;
        }
        fclose(file);
        Count += line;
    }
}

void save(void) {//保存
    Device t;
    int i = 0;
    FILE *file = fopen("config.txt", "w");
    for (t = Devices; t->Next != NULL; t = t->Next)
        if (t->Next->Flag == 0) i++;

    fprintf(file, "%d\n", Count - i);
    for (t = Devices; t->Next != NULL; t = t->Next) {
        if (t->Next->Flag == 0) continue;
        fprintf(file, "%d %s %d %s %s %s %d\n",
                t->Next->ID, t->Next->Name, t->Next->Price, t->Next->Supplier, t->Next->Date, t->Next->Department,
                t->Next->Flag);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "已保存");
}

int customPrint(short c, int x, int y, const char *__restrict__ _Format, ...) {//自定义输出
    va_list vl;
    va_start(vl, _Format);
    gotoxy(x, y);
    color(c);
    vprintf(_Format, vl);
    color(7);
    va_end(vl);
}
