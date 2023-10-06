//
// Created by carrotgrx on 2023/10/6.
//

#ifndef SYSTEMTEACHER_VIEW_H
#define SYSTEMTEACHER_VIEW_H

#ifndef SCHOOL_SCREEN_H
#define SCHOOL_SCREEN_H

#include "lib.h"

// 视图
typedef struct SelectNode * Select;
typedef struct ViewNode *View;

struct SelectNode {
    int Index;
    char Title[20];
    void (*Function) (void);
    Select Previous;
    Select Next;
};

struct ViewNode {
    Select Head;
    Select Rear;
    Select Selected;
    int count;
    int first;
    View back;
};

extern PCOORD Window_Size;
extern int swch;

void color(short);
void gotoxy(int, int);

void initView(void);
void showTitle(void);
void setView(View);
void show(void);
void append(View , char[], void (*)(void));
View createView(void);

#endif //SYSTEMDEVICE_SCREEN_H


#endif //SYSTEMTEACHER_VIEW_H
