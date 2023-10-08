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
    User left;
    User right;
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
    Course left;
    Course right;
};

//��ʦ��Ϣ
typedef struct teacher {
    int id;                 //��ʦ���
    char name[20];          //��ʦ����
    char emile[20];         //��ʦ����
    Teacher left;
    Teacher right;
};

//��ҵ��Ϣ
typedef struct homework {
    int id;                 //��ҵ���
    int course_id;          //��ҵ�����γ�
    int teacher_id;         //��ҵ���ý�ʦ
    char content[200];      //��ҵ����
    char deadline[20];      //��ҵ��ֹʱ��  xxxx-xx-xx xx:xx:xx
    int status;             //��ҵ����״̬ 0-δ��� 1-�����
    Homework left;
    Homework right;
};

//����/������Ϣ
typedef struct tutor {
    int id;                 //����/�������
    int course_id;          //����/�����γ�
    int teacher_id;         //����/������ʦ
    char time[20];          //����/����ʱ�� xxxx-xx-xx xx:xx:xx
    Tutor left;
    Tutor right;
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
    Student left;
    Student right;
};

User createUser(void);
Course createCourse(void);
Teacher createTeacher(void);
Homework createHomework(void);
Tutor createTutor(void);
Student createStudent(void);


#endif //SYSTEMTEACHER_API_H
