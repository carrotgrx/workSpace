//
// Created by carrotgrx on 2023/10/6.
//

#ifndef SYSTEMTEACHER_API_H
#define SYSTEMTEACHER_API_H

#include "view.h"

typedef struct user *User;
typedef struct course *Course;
typedef struct teacher *Teacher;
typedef struct homework *Homework;
typedef struct tutor *Tutor;
typedef struct student *Student;

//用户信息
typedef struct user {
    int id;                 //用户编号
    char username[20];      //用户名
    char password[20];      //密码
    int type;               //用户类型 0-管理员 1-教师 2-学生
    User Next;
};

//课程信息
typedef struct course {
    int id;                     //课程编号
    char name[20];              //课程名称
    int credit;                 //课程学分
    int teacher_id[10];         //授课教师编号
    int student_id[10][200];    //选课学生编号
    int grade[10][200];         //选课学生平时成绩
    int evaluation[10][200];    //选课学生评价
    Course Next;
};

//教师信息
typedef struct teacher {
    int id;                 //教师编号
    char name[20];          //教师姓名
    char emile[20];         //教师邮箱
    Teacher Next;
};

//作业信息
typedef struct homework {
    int id;                 //作业编号
    int course_id;          //作业所属课程
    int teacher_id;         //作业布置教师
    char content[200];      //作业内容
    char deadline[20];      //作业截止时间  xxxx-xx-xx xx:xx:xx
    int status;             //作业批改状态 0-未完成 1-已完成
    Homework Next;
};

//答疑/辅导信息
typedef struct tutor {
    int id;                 //答疑/辅导编号
    int course_id;          //答疑/辅导课程
    int teacher_id;         //答疑/辅导教师
    char time[20];          //答疑/辅导时间 xxxx-xx-xx xx:xx:xx
    Tutor Next;
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
    Student Next;
};

extern User Users;
extern Course Courses;
extern Teacher Teachers;
extern Homework Homeworks;
extern Tutor Tutors;
extern Student Students;
extern View QUERY;
extern View MAIN;
extern int Count;

void back(void);
void soutUser(int index, User user);
void soutCourse(int index, Course course);
void soutTeacher(int index, Teacher teacher);
void soutHomework(int index, Homework homework);
void soutTutor(int index, Tutor tutor);
void soutStudent(int index, Student student);
void getStudent(int type, char text[10], int viewNum);
void getCourse(int type, char text[10], int viewNum);
void getTeacher(int type, char text[10], int viewNum);
void getHomework(int type, char text[10], int viewNum);
void getTutor(int type, char text[10], int viewNum);
void getUser(int type, char text[10], int viewNum);

void queryStu1(void);
void queryStu2(void);
void queryStu3(void);
void queryStu4(void);
void queryStu5(void);
void queryStu0(void);

void quit(void);
void initAPI(void);
void addStu(void);
void modifyStu(void);
void delStu(void);
void queryStu(void);
void importStu(void);
void saveStu(void);

int customPrint(short c, int x, int y, const char * __restrict__ _Format, ...);


#endif //SYSTEMTEACHER_API_H
