//
// Created by carrotgrx on 2023/10/6.
//

#include <stdarg.h>
#include "lib.h"
#include "api.h"

Student Students;
User Users;
Course Courses;
Teacher Teachers;
Homework Homeworks;
Tutor Tutors;

View QUERY;
View MAIN;
View LOGIN;
int CountStu;
int CountUser;
int CountCourse;
int CountTeacher;
int CountHomework;
int CountTutor;

void back(void) { //�ص�������
    setView(QUERY->back);
    show();
}

void soutUser(int index, User user) { //��������û���Ϣ
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10s",
                user->username, user->type == 0 ? "����Ա" : "��ͨ�û�");
}

void soutCourse(int index, Course course) { //��������γ���Ϣ
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10d",
                course->name, course->credit);
}

void soutTeacher(int index, Teacher teacher) { //���������ʦ��Ϣ
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10s",
                teacher->name, teacher->emile);
}

void soutHomework(int index, Homework homework) { //���������ҵ��Ϣ
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10s%-10s",
                homework->deadline, homework->status == 0 ? "δ����" : "������");
}

void soutTutor(int index, Tutor tutor) { //�����������/������Ϣ
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s",
                tutor->time);
}

void soutStudent(int index, Student student) { //�������ѧ����Ϣ
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10d%-10d%-10s",
                student->name, student->class, student->average, student->bad == 0 ? "��" : "��");
}

void sortStuAverage(void) { //���ݼ����ɴ�С����
    int i, count = 0, num;
    Student p, q, t;
    p = Students;
    while(p->Next != NULL) {
        p = p->Next;
        count++;
    }
    for (i = 0; i < count - 1; ++i) {
        num = count - i - 1;
        q = Students->Next;
        p = q->Next;
        t = Students;
        while (num--) {
            if (q->average < p->average) {
                q->Next = p->Next;
                p->Next = q;
                t->Next = p;
            }
            t = t->Next;
            q = t->Next;
            p = q->Next;
        }
    }

}

void getStudent(int type, char text[30], int viewNum) { //��ȡѧ����Ϣ
    int value, i;
    char str[30];
    Student t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ��ѯ��%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    customPrint(5, Window_Size->X / 2 - 45, 13,
                "����        �꼶        ƽ���ɼ�    ������¼");
    for (i = 0, t = Students; t->Next != NULL; t = t->Next) {
        switch (type) {
            case 1:
                if (t->Next->id == value) {
                    soutStudent(i, t->Next);
                    ++i;
                }
                break;
            case 2:
                if (!strstr(t->Next->name, str)) {
                    soutStudent(i, t->Next);
                    ++i;
                }
                break;
            case 3:
                if (t->Next->class == value) {
                    soutStudent(i, t->Next);
                    ++i;
                }
                break;
            case 4:
                if (t->Next->average == value) {
                    soutStudent(i, t->Next);
                    ++i;
                }
                break;
            case 5:
                if (t->Next->bad == value) {
                    soutStudent(i, t->Next);
                    ++i;
                }
                break;
            default:
                break;
        }
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void getUser(int type, char text[30], int viewNum) { //��ȡ�û���Ϣ
    int value, i;
    char str[30];
    User t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ��ѯ��%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    customPrint(5, Window_Size->X / 2 - 45, 13, "�û���        �û�����");
    for (i = 0, t = Users; t->Next != NULL; t = t->Next) {
        switch (type) {
            case 1:
                if (t->Next->id == value) {
                    soutUser(i, t->Next);
                    ++i;
                }
                break;
            case 2:
                if (!strstr(t->Next->username, str)) {
                    soutUser(i, t->Next);
                    ++i;
                }
                break;
            case 3:
                if (t->Next->type == value) {
                    soutUser(i, t->Next);
                    ++i;
                }
                break;
            default:
                break;
        }
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void getCourse(int type, char text[30], int viewNum) { //��ȡ�γ���Ϣ
    int value, i;
    char str[30];
    Course t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ��ѯ��%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    customPrint(5, Window_Size->X / 2 - 45, 13, "�γ���        ѧ��");
    for (i = 0, t = Courses; t->Next != NULL; t = t->Next) {
        switch (type) {
            case 1:
                if (t->Next->id == value) {
                    soutCourse(i, t->Next);
                    ++i;
                }
                break;
            case 2:
                if (!strstr(t->Next->name, str)) {
                    soutCourse(i, t->Next);
                    ++i;
                }
                break;
            case 3:
                if (t->Next->credit == value) {
                    soutCourse(i, t->Next);
                    ++i;
                }
                break;
            default:
                break;
        }
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void getTeacher(int type, char text[30], int viewNum) { //��ȡ��ʦ��Ϣ
    int value, i;
    char str[30];
    Teacher t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ��ѯ��%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    customPrint(5, Window_Size->X / 2 - 45, 13, "��ʦ����        ��ʦ����");
    for (i = 0, t = Teachers; t->Next != NULL; t = t->Next) {
        switch (type) {
            case 1:
                if (t->Next->id == value) {
                    soutTeacher(i, t->Next);
                    ++i;
                }
                break;
            case 2:
                if (!strstr(t->Next->name, str)) {
                    soutTeacher(i, t->Next);
                    ++i;
                }
                break;
            case 3:
                if (!strstr(t->Next->emile, str)) {
                    soutTeacher(i, t->Next);
                    ++i;
                }
                break;
            default:
                break;
        }
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void getHomework(int type, char text[30], int viewNum) { //��ȡ��ҵ��Ϣ
    int value, i;
    char str[30];
    Homework t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ��ѯ��%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    customPrint(5, Window_Size->X / 2 - 45, 13, "��ֹʱ��        ����״̬");
    for (i = 0, t = Homeworks; t->Next != NULL; t = t->Next) {
        switch (type) {
            case 1:
                if (t->Next->id == value) {
                    soutHomework(i, t->Next);
                    ++i;
                }
                break;
            case 2:
                if (t->Next->course_id == value) {
                    soutHomework(i, t->Next);
                    ++i;
                }
                break;
            case 3:
                if (t->Next->teacher_id == value) {
                    soutHomework(i, t->Next);
                    ++i;
                }
                break;
            case 4:
                if (!strstr(t->Next->content, str)) {
                    soutHomework(i, t->Next);
                    ++i;
                }
                break;
            case 5:
                if (!strstr(t->Next->deadline, str)) {
                    soutHomework(i, t->Next);
                    ++i;
                }
                break;
            case 6:
                if (t->Next->status == value) {
                    soutHomework(i, t->Next);
                    ++i;
                }
                break;
            default:
                break;
        }
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void getTutor(int type, char text[30], int viewNum) { //��ȡ����/������Ϣ
    int value, i;
    char str[30];
    Tutor t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ��ѯ��%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    customPrint(5, Window_Size->X / 2 - 45, 13, "����/����ʱ��");
    for (i = 0, t = Tutors; t->Next != NULL; t = t->Next) {
        switch (type) {
            case 1:
                if (t->Next->id == value) {
                    soutTutor(i, t->Next);
                    ++i;
                }
                break;
            case 2:
                if (t->Next->course_id == value) {
                    soutTutor(i, t->Next);
                    ++i;
                }
                break;
            case 3:
                if (t->Next->teacher_id == value) {
                    soutTutor(i, t->Next);
                    ++i;
                }
                break;
            case 4:
                if (!strstr(t->Next->time, str)) {
                    soutTutor(i, t->Next);
                    ++i;
                }
                break;
            default:
                break;
        }
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryStu1(void) {
    getStudent(1, "ѧ�����", 1);
}

void queryStu2(void) {
    getStudent(2, "ѧ������", 0);
}

void queryStu3(void) {
    getStudent(3, "ѧ���꼶", 1);
}

void queryStu4(void) {
    getStudent(4, "ѧ��ƽ������", 1);
}

void queryStu5(void) {
    getStudent(5, "ѧ��������¼", 1);
}

void queryStu0(void) {
    int i;
    Student t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "����        �꼶        ƽ���ɼ�    ������¼");
    for (i = 0, t = Students; t->Next != NULL; t = t->Next) {
        soutStudent(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryUser1(void) {
    getUser(1, "�û����", 1);
}

void queryUser2(void) {
    getUser(2, "�û���", 0);
}

void queryUser3(void) {
    getUser(3, "�û�����", 1);
}

void queryUser0(void) {
    int i;
    User t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "�û���        �û�����");
    for (i = 0, t = Users; t->Next != NULL; t = t->Next) {
        soutUser(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryCourse1(void) {
    getCourse(1, "�γ̱��", 1);
}

void queryCourse2(void) {
    getCourse(2, "�γ���", 0);
}

void queryCourse3(void) {
    getCourse(3, "�γ�ѧ��", 1);
}

void queryCourse0(void) {
    int i;
    Course t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "�γ���        ѧ��");
    for (i = 0, t = Courses; t->Next != NULL; t = t->Next) {
        soutCourse(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryTeacher1(void) {
    getTeacher(1, "��ʦ���", 1);
}

void queryTeacher2(void) {
    getTeacher(2, "��ʦ����", 0);
}

void queryTeacher0(void) {
    int i;
    Teacher t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "��ʦ����        ��ʦ����");
    for (i = 0, t = Teachers; t->Next != NULL; t = t->Next) {
        soutTeacher(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryHomework1(void) {
    getHomework(1, "��ҵ���", 1);
}

void queryHomework2(void) {
    getHomework(2, "�γ̱��", 1);
}

void queryHomework3(void) {
    getHomework(3, "��ʦ���", 1);
}

void queryHomework0(void) {
    int i;
    Homework t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "��ֹʱ��        ����״̬");
    for (i = 0, t = Homeworks; t->Next != NULL; t = t->Next) {
        soutHomework(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryTutor1(void) {
    getTutor(1, "����/�������", 1);
}

void queryTutor2(void) {
    getTutor(2, "�γ̱��", 1);
}

void queryTutor3(void) {
    getTutor(3, "��ʦ���", 1);
}

void queryTutor0(void) {
    int i;
    Tutor t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "����/����ʱ��");
    for (i = 0, t = Tutors; t->Next != NULL; t = t->Next) {
        soutTutor(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}



void quit(void) { //�˳�
    exit(0);
}

int login() {
    LOGIN = createView();
    int i = 0;
    char username[20], password[20];
    User t;
    CLS();
//    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "�������û���: ");
    scanf("%s", username);
    customPrint(5, Window_Size->X / 2 - 25, 14, "����������: ");
    scanf("%s", password);
    for (t = Users; t->Next != NULL; t = t->Next) {
        if (!strcmp(t->Next->username, username) && !strcmp(t->Next->password, password)) {
            setView(MAIN);
            show();
            return t->Next->type;
        }
    }
    customPrint(4, Window_Size->X / 2 - 25, 15, "�û������������");
    gotoxy(0, Window_Size->Y);
}

void view(void) {
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "�û���Ϣ", &viewUser);
    append(MAIN, "ѧ����Ϣ", &viewStu);
    append(MAIN, "�γ���Ϣ", &viewCourse);
    append(MAIN, "��ʦ��Ϣ", &viewTeacher);
    append(MAIN, "��ҵ��Ϣ", &viewHomework);
    append(MAIN, "����/������Ϣ", &viewTutor);
    append(MAIN, "�˳�", &quit);
    QUERY->back = MAIN;
}

void TeaView(void) {
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "ѧ����Ϣ", &viewStu);
    append(MAIN, "�γ���Ϣ", &viewCourse);
    append(MAIN, "��ҵ��Ϣ", &viewHomework);
    append(MAIN, "����/������Ϣ", &viewTutor);
    append(MAIN, "�˳�", &quit);
    QUERY->back = MAIN;
}

void viewStu(void) { //��ʼ��ѧ��
    Students = (Student)malloc(sizeof(struct student));
    Students->Next = NULL;
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "����ѧ����Ϣ", &addStu);
    append(MAIN, "ɾ��ѧ����Ϣ", &delStu);
    append(MAIN, "�޸�ѧ����Ϣ", &modifyStu);
    append(MAIN, "��ѯѧ����Ϣ", &queryStu);
    append(MAIN, "�˳�", &quit);

    append(QUERY, "���ݱ�Ų�ѯ", &queryStu1);
    append(QUERY, "����������ѯ", &queryStu2);
    append(QUERY, "�����꼶��ѯ", &queryStu3);
    append(QUERY, "���ݼ����ѯ", &queryStu4);
    append(QUERY, "���ݼ�¼��ѯ", &queryStu5);
    append(QUERY, "�г�������Ϣ", &queryStu0);
    append(QUERY, "����", &back);
    QUERY->back = MAIN;
}

void viewUser(void) { //��ʼ���û�
    Users = (User)malloc(sizeof(struct user));
    Users->Next = NULL;
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "�����û���Ϣ", &addUser);
    append(MAIN, "ɾ���û���Ϣ", &delUser);
    append(MAIN, "�޸��û���Ϣ", &modifyUser);
    append(MAIN, "��ѯ�û���Ϣ", &queryUser);
    append(MAIN, "�˳�", &quit);

    append(QUERY, "���ݱ�Ų�ѯ", &queryUser1);
    append(QUERY, "����������ѯ", &queryUser2);
    append(QUERY, "�������Ͳ�ѯ", &queryUser3);
    append(QUERY, "�г�������Ϣ", &queryUser0);
    append(QUERY, "����", &back);
    QUERY->back = MAIN;

}

void viewCourse(void) { //��ʼ���γ�
    Courses = (Course)malloc(sizeof(struct course));
    Courses->Next = NULL;
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "�����γ���Ϣ", &addCourse);
    append(MAIN, "ɾ���γ���Ϣ", &delCourse);
    append(MAIN, "�޸Ŀγ���Ϣ", &modifyCourse);
    append(MAIN, "��ѯ�γ���Ϣ", &queryCourse);
    append(MAIN, "�˳�", &quit);

    append(QUERY, "���ݱ�Ų�ѯ", &queryCourse1);
    append(QUERY, "�������Ʋ�ѯ", &queryCourse2);
    append(QUERY, "����ѧ�ֲ�ѯ", &queryCourse3);
    append(QUERY, "�г�������Ϣ", &queryCourse0);
    append(QUERY, "����", &back);
    QUERY->back = MAIN;
}

void viewTeacher(void) { //��ʼ����ʦ
    Teachers = (Teacher)malloc(sizeof(struct teacher));
    Teachers->Next = NULL;
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "������ʦ��Ϣ", &addTeacher);
    append(MAIN, "ɾ����ʦ��Ϣ", &delTeacher);
    append(MAIN, "�޸Ľ�ʦ��Ϣ", &modifyTeacher);
    append(MAIN, "��ѯ��ʦ��Ϣ", &queryTeacher);
    append(MAIN, "�˳�", &quit);

    append(QUERY, "���ݱ�Ų�ѯ", &queryTeacher1);
    append(QUERY, "����������ѯ", &queryTeacher2);
    append(QUERY, "�г�������Ϣ", &queryTeacher0);
    append(QUERY, "����", &back);
    QUERY->back = MAIN;
}

void viewHomework(void) { //��ʼ����ҵ
    Homeworks = (Homework)malloc(sizeof(struct homework));
    Homeworks->Next = NULL;
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "������ҵ��Ϣ", &addHomework);
    append(MAIN, "ɾ����ҵ��Ϣ", &delHomework);
    append(MAIN, "�޸���ҵ��Ϣ", &modifyHomework);
    append(MAIN, "��ѯ��ҵ��Ϣ", &queryHomework);
    append(MAIN, "�˳�", &quit);

    append(QUERY, "���ݱ�Ų�ѯ", &queryHomework1);
    append(QUERY, "���ݿγ̲�ѯ", &queryHomework2);
    append(QUERY, "���ݽ�ʦ��ѯ", &queryHomework3);
    append(QUERY, "�г�������Ϣ", &queryHomework0);
    append(QUERY, "����", &back);
    QUERY->back = MAIN;
}

void viewTutor(void) { //��ʼ������/����
    Tutors = (Tutor)malloc(sizeof(struct tutor));
    Tutors->Next = NULL;
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "��������/������Ϣ", &addTutor);
    append(MAIN, "ɾ������/������Ϣ", &delTutor);
    append(MAIN, "�޸Ĵ���/������Ϣ", &modifyTutor);
    append(MAIN, "��ѯ����/������Ϣ", &queryTutor);
    append(MAIN, "�˳�", &quit);

    append(QUERY, "���ݱ�Ų�ѯ", &queryTutor1);
    append(QUERY, "���ݿγ̲�ѯ", &queryTutor2);
    append(QUERY, "���ݽ�ʦ��ѯ", &queryTutor3);
    append(QUERY, "�г�������Ϣ", &queryTutor0);
    append(QUERY, "����", &back);
    QUERY->back = MAIN;
}

void addStu(void) {//����
    Student t = (Student) malloc(sizeof(struct student));
    customPrint(5, Window_Size->X / 2 - 25, 13, "������ѧ�����: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "������ѧ������: ");
    scanf("%s", t->name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "������ѧ������: ");
    scanf("%s", t->emile);
    customPrint(5, Window_Size->X / 2 - 25, 16, "������ѧ���꼶: ");
    scanf("%d", &t->class);
    customPrint(5, Window_Size->X / 2 - 25, 17, "������ѧ��������¼: ");
    scanf("%d", &t->bad);
    for (int i = 0; i < 10; ++i) {
        t->course_id[i] = 0;
        t->grade[i] = 0;
        t->record[i] = 0;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            t->other[i][j] = 0;
        }
    }
    t->gpa = 0;
    t->average = 0;
    t->Next = Students->Next;
    Students->Next = t;
    CountStu++;  //������+1
    show();   //�ص�������
    saveStu();   //����
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "���ӳɹ�"); // ���½������ɫ���ӳɹ�
    gotoxy(0, Window_Size->Y);  //��������
}

void addUser(void) {//�����û�
    User t = (User) malloc(sizeof(struct user));
    customPrint(5, Window_Size->X / 2 - 25, 13, "�������û����: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "�������û���: ");
    scanf("%s", t->username);
    customPrint(5, Window_Size->X / 2 - 25, 15, "�������û�����: ");
    scanf("%s", t->password);
    customPrint(5, Window_Size->X / 2 - 25, 16, "�������û�����: ");
    scanf("%d", &t->type);
    t->Next = Users->Next;
    Users->Next = t;
    CountStu++;  //������+1
    show();   //�ص�������
    saveStu();   //����
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "���ӳɹ�"); // ���½������ɫ���ӳɹ�
    gotoxy(0, Window_Size->Y);  //��������
}

void addCourse(void) {//�����γ�
    Course t = (Course) malloc(sizeof(struct course));
    customPrint(5, Window_Size->X / 2 - 25, 13, "������γ̱��: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "������γ�����: ");
    scanf("%s", t->name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "������γ�ѧ��: ");
    scanf("%d", &t->credit);
    for (int i = 0; i < 10; ++i) {
        t->teacher_id[i] = 0;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 200; ++j) {
            t->student_id[i][j] = 0;
            t->grade[i][j] = 0;
            t->evaluation[i][j] = 0;
        }
    }
    t->Next = Courses->Next;
    Courses->Next = t;
    CountStu++;  //������+1
    show();   //�ص�������
    saveStu();   //����
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "���ӳɹ�"); // ���½������ɫ���ӳɹ�
    gotoxy(0, Window_Size->Y);  //��������
}

void addTeacher(void) {//������ʦ
    Teacher t = (Teacher) malloc(sizeof(struct teacher));
    customPrint(5, Window_Size->X / 2 - 25, 13, "�������ʦ���: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "�������ʦ����: ");
    scanf("%s", t->name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "�������ʦ����: ");
    scanf("%s", t->emile);
    t->Next = Teachers->Next;
    Teachers->Next = t;
    CountStu++;  //������+1
    show();   //�ص�������
    saveStu();   //����
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "���ӳɹ�"); // ���½������ɫ���ӳɹ�
    gotoxy(0, Window_Size->Y);  //��������
}

void addHomework(void) {//������ҵ
    Homework t = (Homework) malloc(sizeof(struct homework));
    customPrint(5, Window_Size->X / 2 - 25, 13, "��������ҵ���: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "������γ̱��: ");
    scanf("%d", &t->course_id);
    customPrint(5, Window_Size->X / 2 - 25, 15, "�������ʦ���: ");
    scanf("%d", &t->teacher_id);
    customPrint(5, Window_Size->X / 2 - 25, 16, "��������ҵ����: ");
    scanf("%s", t->content);
    customPrint(5, Window_Size->X / 2 - 25, 17, "�������ֹʱ��: ");
    scanf("%s", t->deadline);
    t->status = 0;
    t->Next = Homeworks->Next;
    Homeworks->Next = t;
    CountStu++;  //������+1
    show();   //�ص�������
    saveStu();   //����
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "���ӳɹ�"); // ���½������ɫ���ӳɹ�
    gotoxy(0, Window_Size->Y);  //��������
}

void addTutor(void) {//��������/����
    Tutor t = (Tutor) malloc(sizeof(struct tutor));
    customPrint(5, Window_Size->X / 2 - 25, 13, "���������/�������: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "������γ̱��: ");
    scanf("%d", &t->course_id);
    customPrint(5, Window_Size->X / 2 - 25, 15, "�������ʦ���: ");
    scanf("%d", &t->teacher_id);
    customPrint(5, Window_Size->X / 2 - 25, 16, "���������/����ʱ��: ");
    scanf("%s", t->time);
    t->Next = Tutors->Next;
    Tutors->Next = t;
    CountStu++;  //������+1
    show();   //�ص�������
    saveStu();   //����
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "���ӳɹ�"); // ���½������ɫ���ӳɹ�
    gotoxy(0, Window_Size->Y);  //��������
}

void modifyCourse(void) {//�޸Ŀγ�
    int id, comp = 0;
    Course t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ�޸Ŀγ̵ı��: ");
    scanf("%d", &id);
    for (t = Courses; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "������ĺ�ı��: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "������ĺ������: ");
            scanf("%s", t->Next->name);
            customPrint(5, Window_Size->X / 2 - 25, 17, "������ĺ��ѧ��: ");
            scanf("%d", &t->Next->credit);
            comp = 1;
            break;
        }
    }
    show();
    saveStu();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "�޸ĳɹ�");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "δ�ҵ�����Ϣ");
    gotoxy(0, Window_Size->Y);
}

void modifyTeacher(void) {//�޸Ľ�ʦ
    int id, comp = 0;
    Teacher t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ�޸Ľ�ʦ�ı��: ");
    scanf("%d", &id);
    for (t = Teachers; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "������ĺ�ı��: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "������ĺ������: ");
            scanf("%s", t->Next->name);
            customPrint(5, Window_Size->X / 2 - 25, 17, "������ĺ������: ");
            scanf("%s", t->Next->emile);
            comp = 1;
            break;
        }
    }
    show();
    saveStu();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "�޸ĳɹ�");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "δ�ҵ�����Ϣ");
    gotoxy(0, Window_Size->Y);
}

void modifyHomework(void) {
    int id, comp = 0;
    Homework t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ�޸���ҵ�ı��: ");
    scanf("%d", &id);
    for (t = Homeworks; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "������ĺ�ı��: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "������ĺ�Ŀγ̱��: ");
            scanf("%d", &t->Next->course_id);
            customPrint(5, Window_Size->X / 2 - 25, 17, "������ĺ�Ľ�ʦ���: ");
            scanf("%d", &t->Next->teacher_id);
            customPrint(5, Window_Size->X / 2 - 25, 18, "������ĺ����ҵ����: ");
            scanf("%s", t->Next->content);
            customPrint(5, Window_Size->X / 2 - 25, 19, "������ĺ�Ľ�ֹʱ��: ");
            scanf("%s", t->Next->deadline);
            comp = 1;
            break;
        }
    }
}

void modifyTutor(void) {
    int id, comp = 0;
    Tutor t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ�޸Ĵ���/�����ı��: ");
    scanf("%d", &id);
    for (t = Tutors; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "������ĺ�ı��: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "������ĺ�Ŀγ̱��: ");
            scanf("%d", &t->Next->course_id);
            customPrint(5, Window_Size->X / 2 - 25, 17, "������ĺ�Ľ�ʦ���: ");
            scanf("%d", &t->Next->teacher_id);
            customPrint(5, Window_Size->X / 2 - 25, 18, "������ĺ�Ĵ���/����ʱ��: ");
            scanf("%s", t->Next->time);
            comp = 1;
            break;
        }
    }
}

void modifyStu(void) {//�޸�
    int id, comp = 0;
    Student t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ�޸�ѧ���ı��: ");
    scanf("%d", &id);
    for (t = Students; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "������ĺ�ı��: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "������ĺ������: ");
            scanf("%s", t->Next->name);
            customPrint(5, Window_Size->X / 2 - 25, 17, "������ĺ������: ");
            scanf("%s", t->Next->emile);
            customPrint(5, Window_Size->X / 2 - 25, 18, "������ĺ���꼶: ");
            scanf("%d", &t->Next->class);
            comp = 1;
            break;
        }
    }
    show();
    saveStu();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "�޸ĳɹ�");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "δ�ҵ�����Ϣ");
    gotoxy(0, Window_Size->Y);
}

void modifyUser(void) {//�޸��û�
    int id, comp = 0;
    User t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫ�޸��û��ı��: ");
    scanf("%d", &id);
    for (t = Users; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "������ĺ�ı��: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "������ĺ���û���: ");
            scanf("%s", t->Next->username);
            customPrint(5, Window_Size->X / 2 - 25, 17, "������ĺ������: ");
            scanf("%s", t->Next->password);
            customPrint(5, Window_Size->X / 2 - 25, 18, "������ĺ������: ");
            scanf("%d", &t->Next->type);
            comp = 1;
            break;
        }
    }
    show();
    saveUser();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "�޸ĳɹ�");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "δ�ҵ�����Ϣ");
    gotoxy(0, Window_Size->Y);
}

void delStu(void) {//ɾ��
    int id, total = 0;
    Student p, t = Students;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫɾ���豸�ı��: ");
    scanf("%d", &id);
    while (t->Next != NULL) {
        if (t->Next->id == id) {
            p = t->Next;
            t->Next = p->Next;
            free(p);
            total++;
        } else t = t->Next;
    }
    CountStu -= total;
    show();
    saveStu();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "ɾ���� %d ����Ϣ", total);
    gotoxy(0, Window_Size->Y);
}

void delUser(void) {//ɾ���û�
    int id, total = 0;
    User p, t = Users;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫɾ���豸�ı��: ");
    scanf("%d", &id);
    while (t->Next != NULL) {
        if (t->Next->id == id) {
            p = t->Next;
            t->Next = p->Next;
            free(p);
            total++;
        } else t = t->Next;
    }
    CountStu -= total;
    show();
    saveStu();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "ɾ���� %d ����Ϣ", total);
    gotoxy(0, Window_Size->Y);
}

void delCourse(void) {//ɾ���γ�
    int id, total = 0;
    Course p, t = Courses;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫɾ���豸�ı��: ");
    scanf("%d", &id);
    while (t->Next != NULL) {
        if (t->Next->id == id) {
            p = t->Next;
            t->Next = p->Next;
            free(p);
            total++;
        } else t = t->Next;
    }
    CountStu -= total;
    show();
    saveStu();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "ɾ���� %d ����Ϣ", total);
    gotoxy(0, Window_Size->Y);
}

void delTeacher(void) {//ɾ����ʦ
    int id, total = 0;
    Teacher p, t = Teachers;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫɾ���豸�ı��: ");
    scanf("%d", &id);
    while (t->Next != NULL) {
        if (t->Next->id == id) {
            p = t->Next;
            t->Next = p->Next;
            free(p);
            total++;
        } else t = t->Next;
    }
    CountStu -= total;
    show();
    saveStu();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "ɾ���� %d ����Ϣ", total);
    gotoxy(0, Window_Size->Y);
}

void delHomework(void) {//ɾ����ҵ
    int id, total = 0;
    Homework p, t = Homeworks;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫɾ���豸�ı��: ");
    scanf("%d", &id);
    while (t->Next != NULL) {
        if (t->Next->id == id) {
            p = t->Next;
            t->Next = p->Next;
            free(p);
            total++;
        } else t = t->Next;
    }
    CountStu -= total;
    show();
    saveStu();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "ɾ���� %d ����Ϣ", total);
    gotoxy(0, Window_Size->Y);
}

void delTutor(void) {//ɾ������/����
    int id, total = 0;
    Tutor p, t = Tutors;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "������Ҫɾ���豸�ı��: ");
    scanf("%d", &id);
    while (t->Next != NULL) {
        if (t->Next->id == id) {
            p = t->Next;
            t->Next = p->Next;
            free(p);
            total++;
        } else t = t->Next;
    }
    CountStu -= total;
    show();
    saveStu();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "ɾ���� %d ����Ϣ", total);
    gotoxy(0, Window_Size->Y);
}



void queryStu(void) {//��ѯ
    setView(QUERY);
    show();
}

void queryUser(void) {//��ѯ�û�
    setView(QUERY);
    show();
}

void queryCourse(void) {//��ѯ�γ�
    setView(QUERY);
    show();
}

void queryTeacher(void) {//��ѯ��ʦ
    setView(QUERY);
    show();
}

void queryHomework(void) {//��ѯ��ҵ
    setView(QUERY);
    show();
}

void queryTutor(void) {//��ѯ����/����
    setView(QUERY);
    show();
}

void importStu(void) {//����
    int line, i;
    Student t;
    FILE *file = fopen("Stu.txt", "r");
    if (file == NULL) {
        file = fopen("Stu.txt", "w");
        fprintf(file, "0\n");
        fclose(file);
    } else {
        fscanf(file, "%d", &line);
        for (i = 0; i < line; ++i) {
            t = (Student) malloc(sizeof(struct student));
            fscanf(file, "%d", &t->id);
            fscanf(file, "%s", t->name);
            fscanf(file, "%s", t->emile);
            fscanf(file, "%d", &t->class);
            for (int j = 0; j < 10; ++j) {
                fscanf(file, "%d", &t->course_id[j]);
            }
            for (int j = 0; j < 10; ++j) {
                fscanf(file, "%d", &t->grade[j]);
            }
            fscanf(file, "%d", &t->average);
            fscanf(file, "%lf", &t->gpa);
            fscanf(file, "%d", &t->bad);
            for (int j = 0; j < 10; ++j) {
                fscanf(file, "%d", &t->record[j]);
            }
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 10; ++k) {
                    fscanf(file, "%d", &t->other[j][k]);
                }
            }
            t->Next = Students->Next;
            Students->Next = t;
        }
        fclose(file);
        CountStu += line;
    }
}

void importUser(void) {//�����û�
    int line, i;
    User t;
    FILE *file = fopen("User.txt", "r");
    if (file == NULL) {
        file = fopen("User.txt", "w");
        fprintf(file, "0\n");
        fclose(file);
    } else {
        fscanf(file, "%d", &line);
        for (i = 0; i < line; ++i) {
            t = (User) malloc(sizeof(struct user));
            fscanf(file, "%d", &t->id);
            fscanf(file, "%s", t->username);
            fscanf(file, "%s", t->password);
            fscanf(file, "%d", &t->type);
            t->Next = Users->Next;
            Users->Next = t;
        }
        fclose(file);
        CountUser += line;
    }
}

void importCourse(void) {//����γ�
    int line, i;
    Course t;
    FILE *file = fopen("Course.txt", "r");
    if (file == NULL) {
        file = fopen("Course.txt", "w");
        fprintf(file, "0\n");
        fclose(file);
    } else {
        fscanf(file, "%d", &line);
        for (i = 0; i < line; ++i) {
            t = (Course) malloc(sizeof(struct course));
            fscanf(file, "%d", &t->id);
            fscanf(file, "%s", t->name);
            fscanf(file, "%d", &t->credit);
            for (int j = 0; j < 10; ++j) {
                fscanf(file, "%d", &t->teacher_id[j]);
            }
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 200; ++k) {
                    fscanf(file, "%d", &t->student_id[j][k]);
                    fscanf(file, "%d", &t->grade[j][k]);
                    fscanf(file, "%d", &t->evaluation[j][k]);
                }
            }
            t->Next = Courses->Next;
            Courses->Next = t;
        }
        fclose(file);
        CountCourse += line;
    }
}

void importTeacher(void) {//�����ʦ
    int line, i;
    Teacher t;
    FILE *file = fopen("Teacher.txt", "r");
    if (file == NULL) {
        file = fopen("Teacher.txt", "w");
        fprintf(file, "0\n");
        fclose(file);
    } else {
        fscanf(file, "%d", &line);
        for (i = 0; i < line; ++i) {
            t = (Teacher) malloc(sizeof(struct teacher));
            fscanf(file, "%d", &t->id);
            fscanf(file, "%s", t->name);
            fscanf(file, "%s", t->emile);
            t->Next = Teachers->Next;
            Teachers->Next = t;
        }
        fclose(file);
        CountTeacher += line;
    }
}

void importHomework(void) {//������ҵ
    int line, i;
    Homework t;
    FILE *file = fopen("Homework.txt", "r");
    if (file == NULL) {
        file = fopen("Homework.txt", "w");
        fprintf(file, "0\n");
        fclose(file);
    } else {
        fscanf(file, "%d", &line);
        for (i = 0; i < line; ++i) {
            t = (Homework) malloc(sizeof(struct homework));
            fscanf(file, "%d", &t->id);
            fscanf(file, "%d", &t->course_id);
            fscanf(file, "%d", &t->teacher_id);
            fscanf(file, "%s", t->content);
            fscanf(file, "%s", t->deadline);
            fscanf(file, "%d", &t->status);
            t->Next = Homeworks->Next;
            Homeworks->Next = t;
        }
        fclose(file);
        CountHomework += line;
    }
}

void importTutor(void) {//�������/����
    int line, i;
    Tutor t;
    FILE *file = fopen("Tutor.txt", "r");
    if (file == NULL) {
        file = fopen("Tutor.txt", "w");
        fprintf(file, "0\n");
        fclose(file);
    } else {
        fscanf(file, "%d", &line);
        for (i = 0; i < line; ++i) {
            t = (Tutor) malloc(sizeof(struct tutor));
            fscanf(file, "%d", &t->id);
            fscanf(file, "%d", &t->course_id);
            fscanf(file, "%d", &t->teacher_id);
            fscanf(file, "%s", t->time);
            t->Next = Tutors->Next;
            Tutors->Next = t;
        }
        fclose(file);
        CountTutor += line;
    }
}



void saveStu(void) {//����
    Student t;
    int i = 0;
    FILE *file = fopen("Stu.txt", "w");

    fprintf(file, "%d\n", CountUser);
    for (t = Students; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %s %s %d ", t->Next->id, t->Next->name, t->Next->emile, t->Next->class);
        for (int j = 0; j < 10; ++j) {
            fprintf(file, "%d ", t->Next->course_id[j]);
        }
        for (int j = 0; j < 10; ++j) {
            fprintf(file, "%d ", t->Next->grade[j]);
        }
        fprintf(file, "%d %lf %d ", t->Next->average, t->Next->gpa, t->Next->bad);
        for (int j = 0; j < 10; ++j) {
            fprintf(file, "%d ", t->Next->record[j]);
        }
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 10; ++k) {
                fprintf(file, "%d ", t->Next->other[j][k]);
            }
        }
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "�ѱ���");
}

void saveUser(void) {//�����û�
    User t;
    int i = 0;
    FILE *file = fopen("User.txt", "w");

    fprintf(file, "%d\n", CountUser);
    for (t = Users; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %s %s %d ", t->Next->id, t->Next->username, t->Next->password, t->Next->type);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "�ѱ���");
}

void saveCourse(void) {//����γ�
    Course t;
    int i = 0;
    FILE *file = fopen("Course.txt", "w");

    fprintf(file, "%d\n", CountCourse);
    for (t = Courses; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %s %d ", t->Next->id, t->Next->name, t->Next->credit);
        for (int j = 0; j < 10; ++j) {
            fprintf(file, "%d ", t->Next->teacher_id[j]);
        }
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 200; ++k) {
                fprintf(file, "%d ", t->Next->student_id[j][k]);
                fprintf(file, "%d ", t->Next->grade[j][k]);
                fprintf(file, "%d ", t->Next->evaluation[j][k]);
            }
        }
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "�ѱ���");
}

void saveTeacher(void) {//�����ʦ
    Teacher t;
    int i = 0;
    FILE *file = fopen("Teacher.txt", "w");

    fprintf(file, "%d\n", CountTeacher);
    for (t = Teachers; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %s %s ", t->Next->id, t->Next->name, t->Next->emile);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "�ѱ���");
}

void saveHomework(void) {//������ҵ
    Homework t;
    int i = 0;
    FILE *file = fopen("Homework.txt", "w");

    fprintf(file, "%d\n", CountHomework);
    for (t = Homeworks; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %d %d %s %s %d ", t->Next->id, t->Next->course_id, t->Next->teacher_id, t->Next->content,
                t->Next->deadline, t->Next->status);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "�ѱ���");
}

void saveTutor(void) {//�������/����
    Tutor t;
    int i = 0;
    FILE *file = fopen("Tutor.txt", "w");

    fprintf(file, "%d\n", CountTutor);
    for (t = Tutors; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %d %d %s ", t->Next->id, t->Next->course_id, t->Next->teacher_id, t->Next->time);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "�ѱ���");
}

int customPrint(short c, int x, int y, const char *__restrict__ _Format, ...) {//�Զ������
    va_list vl;
    va_start(vl, _Format);
    gotoxy(x, y);
    color(c);
    vprintf(_Format, vl);
    color(7);
    va_end(vl);
}
