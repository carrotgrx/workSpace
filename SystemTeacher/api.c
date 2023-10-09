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

void back(void) { //回到主界面
    setView(QUERY->back);
    show();
}

void soutUser(int index, User user) { //输出单个用户信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10s",
                user->username, user->type == 0 ? "管理员" : "普通用户");
}

void soutCourse(int index, Course course) { //输出单个课程信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10d",
                course->name, course->credit);
}

void soutTeacher(int index, Teacher teacher) { //输出单个教师信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10s",
                teacher->name, teacher->emile);
}

void soutHomework(int index, Homework homework) { //输出单个作业信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10s%-10s",
                homework->deadline, homework->status == 0 ? "未批改" : "已批改");
}

void soutTutor(int index, Tutor tutor) { //输出单个答疑/辅导信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s",
                tutor->time);
}

void soutStudent(int index, Student student) { //输出单个学生信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-10s%-10d%-10d%-10s",
                student->name, student->class, student->average, student->bad == 0 ? "无" : "有");
}

void getStudent(int type, char text[10], int viewNum) { //获取学生信息
    int value, i;
    char str[30];
    Student t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要查询的%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    customPrint(5, Window_Size->X / 2 - 45, 13,
                "姓名        年级        平均成绩    不良记录");
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
    getStudent(1, "学生编号", 1);
}

void queryStu2(void) {
    getStudent(2, "学生姓名", 0);
}

void queryStu3(void) {
    getStudent(3, "学生年级", 1);
}

void queryStu4(void) {
    getStudent(4, "学生平均绩点", 1);
}

void queryStu5(void) {
    getStudent(5, "学生不良记录", 1);
}

void queryStu0(void) {
    int i;
    Student t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "姓名        年级        平均成绩    不良记录");
    for (i = 0, t = Students; t->Next != NULL; t = t->Next) {
        soutStudent(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void quit(void) { //退出
    exit(0);
}

void initAPI(void) { //初始化
    Students = (Student)malloc(sizeof(struct student));
    Students->Next = NULL;
    MAIN = createView();
    QUERY = createView();
    append(MAIN, "新增学生信息", &addStu);
    append(MAIN, "删除学生信息", &delStu);
    append(MAIN, "修改学生信息", &modifyStu);
    append(MAIN, "查询学生信息", &queryStu);
    append(MAIN, "退出", &quit);

    append(QUERY, "根据编号查询", &queryStu1);
    append(QUERY, "根据姓名查询", &queryStu2);
    append(QUERY, "根据年级查询", &queryStu3);
    append(QUERY, "根据绩点查询", &queryStu4);
    append(QUERY, "根据记录查询", &queryStu5);
    append(QUERY, "列出所有信息", &queryStu0);
    append(QUERY, "返回", &back);
    QUERY->back = MAIN;
}

void addStu(void) {//新增
    CLS();
    showTitle();
    Student t = (Student) malloc(sizeof(struct student));
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入学生编号: ");
    scanf("%d", &t->id);
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入学生姓名: ");
    scanf("%s", t->name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "请输入学生年级: ");
    scanf("%d", &t->class);
    customPrint(5, Window_Size->X / 2 - 25, 16, "请输入学生平均绩点: ");
    scanf("%d", &t->average);
    customPrint(5, Window_Size->X / 2 - 25, 17, "请输入学生不良记录: ");
    scanf("%d", &t->bad);
    t->Next = Students->Next;
    Students->Next = t;
    Count++;  //总数量+1
    show();   //回到主界面
    saveStu();   //保存
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "增加成功"); // 右下角输出绿色增加成功
    gotoxy(0, Window_Size->Y);  //重置坐标
}

void modifyStu(void) {//修改
    int id, comp = 0;
    Student t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要修改学生的编号: ");
    scanf("%d", &id);
    for (t = Students; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "请输入改后的编号: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "请输入改后的姓名: ");
            scanf("%s", t->Next->name);
            customPrint(5, Window_Size->X / 2 - 25, 17, "请输入改后的邮箱: ");
            scanf("%s", t->Next->emile);
            customPrint(5, Window_Size->X / 2 - 25, 18, "请输入改后的年级: ");
            scanf("%d", &t->Next->class);
            comp = 1;
            break;
        }
    }
    show();
    saveStu();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "修改成功");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "未找到此信息");
    gotoxy(0, Window_Size->Y);
}

void delStu(void) {//删除
    int id, total = 0;
    Student p, t = Students;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要删除设备的编号: ");
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
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "删除了 %d 条信息", total);
    gotoxy(0, Window_Size->Y);
}

void queryStu(void) {//查询
    setView(QUERY);
    show();
}

void importStu(void) {//导入
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

void saveStu(void) {//保存
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
