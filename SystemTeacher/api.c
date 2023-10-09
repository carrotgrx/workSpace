//
// Created by carrotgrx on 2023/10/6.
//

#include <stdarg.h>
#include "lib.h"
#include "api.h"

Student Students;

View QUERY;
View MAIN;
int Count;

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

void getStudent(int type, char text[10], int viewNum) { //��ȡѧ����Ϣ
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

void quit(void) { //�˳�
    exit(0);
}

void initAPI(void) { //��ʼ��
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

void addStu(void) {//����
    CLS();
    showTitle();
    Student t = (Student) malloc(sizeof(struct student));
    customPrint(5, Window_Size->X / 2 - 25, 13, "������ѧ�����: ");
    scanf("%d", &t->id);
    customPrint(5, Window_Size->X / 2 - 25, 14, "������ѧ������: ");
    scanf("%s", t->name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "������ѧ���꼶: ");
    scanf("%d", &t->class);
    customPrint(5, Window_Size->X / 2 - 25, 16, "������ѧ��ƽ������: ");
    scanf("%d", &t->average);
    customPrint(5, Window_Size->X / 2 - 25, 17, "������ѧ��������¼: ");
    scanf("%d", &t->bad);
    t->Next = Students->Next;
    Students->Next = t;
    Count++;  //������+1
    show();   //�ص�������
    saveStu();   //����
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "���ӳɹ�"); // ���½������ɫ���ӳɹ�
    gotoxy(0, Window_Size->Y);  //��������
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
    Count -= total;
    show();
    saveStu();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "ɾ���� %d ����Ϣ", total);
    gotoxy(0, Window_Size->Y);
}

void queryStu(void) {//��ѯ
    setView(QUERY);
    show();
}

void importStu(void) {//����
    int line, i;
    Student t;
    FILE *file = fopen("config.txt", "r");
    if (file == NULL) {
        file = fopen("config.txt", "w");
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
        Count += line;
    }
}

void saveStu(void) {//����
    Student t;
    int i = 0;
    FILE *file = fopen("config.txt", "w");

    fprintf(file, "%d\n", Count);
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

int customPrint(short c, int x, int y, const char *__restrict__ _Format, ...) {//�Զ������
    va_list vl;
    va_start(vl, _Format);
    gotoxy(x, y);
    color(c);
    vprintf(_Format, vl);
    color(7);
    va_end(vl);
}
