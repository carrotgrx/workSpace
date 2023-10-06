//
// Created by carrotgrx on 2023/10/6.
//

#ifndef SYSTEMTEACHER_API_H
#define SYSTEMTEACHER_API_H

#include "view.h"

typedef struct course *Course;
typedef struct teacher *Teacher;
typedef struct homework *Homework;
typedef struct tutor *Tutor;
typedef struct student *Student;

//课程信息
typedef struct course {
    int id;                     //课程编号
    char name[20];              //课程名称
    int credit;                 //课程学分
    int teacher_id[10];         //授课教师编号
    int student_id[10][200];    //选课学生编号
    int grade[10][200];         //选课学生平时成绩
    int evaluation[10][200];    //选课学生评价
    Course next;
};

//教师信息
typedef struct teacher {
    int id;                 //教师编号
    char name[20];          //教师姓名
    char emile[20];         //教师邮箱
    Teacher next;
};

//作业信息
typedef struct homework {
    int id;                 //作业编号
    int course_id;          //作业所属课程
    int teacher_id;         //作业布置教师
    char content[200];      //作业内容
    char deadline[20];      //作业截止时间  xxxx-xx-xx xx:xx:xx
    int status;             //作业批改状态 0-未完成 1-已完成
    Homework next;
};

//答疑/辅导信息
typedef struct tutor {
    int id;                 //答疑/辅导编号
    int course_id;          //答疑/辅导课程
    int teacher_id;         //答疑/辅导教师
    char time[20];          //答疑/辅导时间
    Tutor next;
};

//学生信息
typedef struct student {
    int id;                 //学生编号
    char name[20];          //学生姓名
    char emile[20];         //学生邮箱
    int class;              //学生年级
    int course_id[10];      //学生所选课程
    int grade[10];          //学生所选课程成绩
    int average;            //学生平均成绩
    double gpa;             //学生平均绩点
    int bad;                //学生不良记录情况
    int record[10];         //不良记录
    int other[3][10];       // 0-竞赛奖项 1-学术得分 2-其他得分
    Student next;
};

extern View QUERY;
extern View MAIN;
extern int Count;

void initAPI(void);
void add(void);
void modify(void);
void del(void);
void query(void);
void import(void);
void save(void);

int customPrint(short c, int x, int y, const char * __restrict__ _Format, ...);


#endif //SYSTEMTEACHER_API_H
