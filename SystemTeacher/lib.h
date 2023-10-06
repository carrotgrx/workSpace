//
// Created by carrotgrx on 2023/10/6.
//

#ifndef SYSTEMTEACHER_LIB_H
#define SYSTEMTEACHER_LIB_H

//定义课程信息结构体类型
typedef struct course
{
    int course_id; //课程编号
    char course_name[20]; //课程名称
    int course_credit; //课程学分
    char course_teacher[20]; //课程教师
}course;

//定义作业信息结构体类型
typedef struct homework
{
    int homework_id; //作业编号
    char homework_title[50]; //作业标题
    char homework_content[200]; //作业内容
    char homework_deadline[20]; //作业截止时间
}homework;

//定义答疑/辅导信息结构体类型
typedef struct tutor
{
    int tutor_id; //答疑/辅导编号
    char tutor_topic[50]; //答疑/辅导主题
    char tutor_time[20]; //答疑/辅导时间
    char tutor_place[20]; //答疑/辅导地点
}tutor;

//定义学生考勤信息结构体类型
typedef struct attendance
{
    char student_name[20]; //学生姓名
    int student_id; //学生学号
    char attendance_date[20]; //考勤日期
    char attendance_status[10]; //考勤状态（出勤、缺勤、迟到、早退等）
}attendance;

//定义学生平时成绩信息结构体类型
typedef struct score
{
    char student_name[20]; //学生姓名
    int student_id; //学生学号
    int score; //平时成绩（0-100分）
}score;

//定义学生综合信息结构体类型
typedef struct student
{
    char student_name[20]; //学生姓名
    int student_id; //学生学号
    int course_score[10]; //各科成绩（0-100分）
    char bad_record[100]; //不良记录（如违纪、作弊等）
    char award_record[100]; //获奖情况（如优秀学生、三好学生等）
    char contest_record[100]; //竞赛情况（如数学竞赛、编程竞赛等）
    char exchange_record[100]; //学术交流情况（如参加论坛、发表论文等）
}student;

#endif //SYSTEMTEACHER_LIB_H
