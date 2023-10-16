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

//�û���Ϣ
typedef struct user {
    int id;                 //�û����
    char username[20];      //�û���
    char password[20];      //����
    int type;               //�û����� 0-����Ա 1-��ʦ 2-ѧ��
    User Next;
};

//�γ���Ϣ
typedef struct course {
    int id;                     //�γ̱��
    char name[20];              //�γ�����
    int credit;                 //�γ�ѧ��
    int teacher_id[10];         //�ڿν�ʦ���
    int student_id[10][200];    //ѡ��ѧ�����
    int grade[10][200];         //ѡ��ѧ��ƽʱ�ɼ�
    int evaluation[10][200];    //ѡ��ѧ������
    Course Next;
};

//��ʦ��Ϣ
typedef struct teacher {
    int id;                 //��ʦ���
    char name[20];          //��ʦ����
    char emile[20];         //��ʦ����
    Teacher Next;
};

//��ҵ��Ϣ
typedef struct homework {
    int id;                 //��ҵ���
    int course_id;          //��ҵ�����γ�
    int teacher_id;         //��ҵ���ý�ʦ
    char content[200];      //��ҵ����
    char deadline[20];      //��ҵ��ֹʱ��  xxxx-xx-xx xx:xx:xx
    int status;             //��ҵ����״̬ 0-δ��� 1-�����
    Homework Next;
};

//����/������Ϣ
typedef struct tutor {
    int id;                 //����/�������
    int course_id;          //����/�����γ�
    int teacher_id;         //����/������ʦ
    char time[20];          //����/����ʱ�� xxxx-xx-xx xx:xx:xx
    Tutor Next;
};

//ѧ����Ϣ
typedef struct student {
    int id;                 //ѧ�����
    char name[20];          //ѧ������
    char emile[20];         //ѧ������
    int class;              //ѧ���꼶
    int course_id[10];      //ѧ����ѡ�γ�
    int grade[10];          //ѧ����ѡ�γ̳ɼ�
    int average;            //ѧ��ƽ���ɼ�
    double gpa;             //ѧ��ƽ������
    int bad;                //ѧ��������¼���
    int record[10];         //������¼
    int other[3][10];       // 0-�������� 1-ѧ���÷� 2-�����÷�
    Student Next;
};

extern View LOGIN;
extern View MENU_USER;
extern View MENU_TEACHER;

extern View MAIN_USER;
extern View MAIN_COURSE;
extern View MAIN_TEACHER;
extern View MAIN_HOMEWORK;
extern View MAIN_TUTOR;
extern View MAIN_STUDENT;

extern View QUERY_USER;
extern View QUERY_COURSE;
extern View QUERY_TEACHER;
extern View QUERY_HOMEWORK;
extern View QUERY_TUTOR;
extern View QUERY_STUDENT;

extern User Users;
extern Course Courses;
extern Teacher Teachers;
extern Homework Homeworks;
extern Tutor Tutors;
extern Student Students;

extern int CountStu;
extern int CountUser;
extern int CountCourse;
extern int CountTeacher;
extern int CountHomework;
extern int CountTutor;

extern int flag;

void backUser(void);
void backCourse(void);
void backTeacher(void);
void backHomework(void);
void backTutor(void);
void backStudent(void);

void quit(void);

void soutUser(int index, User user);
void soutCourse(int index, Course course);
void soutTeacher(int index, Teacher teacher);
void soutHomework(int index, Homework homework);
void soutTutor(int index, Tutor tutor);
void soutStudent(int index, Student student);

void sortStuGpa(void);
void sortStuBad(void);

void getUser(int type, char text[30], int viewNum);
void getCourse(int type, char text[30], int viewNum);
void getTeacher(int type, char text[30], int viewNum);
void getHomework(int type, char text[30], int viewNum);
void getTutor(int type, char text[30], int viewNum);
void getStudent(int type, char text[30], int viewNum);

void queryUser1(void);
void queryUser2(void);
void queryUser3(void);
void queryUser0(void);

void queryCourse1(void);
void queryCourse2(void);
void queryCourse3(void);
void queryCourse0(void);

void queryTeacher1(void);
void queryTeacher2(void);
void queryTeacher0(void);

void queryHomework1(void);
void queryHomework2(void);
void queryHomework3(void);
void queryHomework0(void);

void queryTutor1(void);
void queryTutor2(void);
void queryTutor3(void);
void queryTutor0(void);

void queryStu1(void);
void queryStu2(void);
void queryStu3(void);
void queryStu4(void);
void queryStu5(void);
void queryStu0(void);

void showUser(void);
void showCourse(void);
void showTeacher(void);
void showHomework(void);
void showTutor(void);
void showStudent(void);

void login(void);
void initLogin(void);
void view(void);
void TeaView(void);

void viewUser(void);
void viewCourse(void);
void viewTeacher(void);
void viewHomework(void);
void viewTutor(void);
void viewStudent(void);

void addUser(void);
void addCourse(void);
void addTeacher(void);
void addHomework(void);
void addTutor(void);
void addStudent(void);

void modifyUser(void);
void modifyCourse(void);
void modifyTeacher(void);
void modifyHomework(void);
void modifyTutor(void);
void modifyStudent(void);

void delUser(void);
void delCourse(void);
void delTeacher(void);
void delHomework(void);
void delTutor(void);
void delStudent(void);

void queryUser(void);
void queryCourse(void);
void queryTeacher(void);
void queryHomework(void);
void queryTutor(void);
void queryStudent(void);

void importUser(void);
void importCourse(void);
void importTeacher(void);
void importHomework(void);
void importTutor(void);
void importStudent(void);

void saveUser(void);
void saveCourse(void);
void saveTeacher(void);
void saveHomework(void);
void saveTutor(void);
void saveStudent(void);

int customPrint(short c, int x, int y, const char * __restrict__ _Format, ...);


#endif //SYSTEMTEACHER_API_H
