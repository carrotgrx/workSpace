//
// Created by carrotgrx on 2023/10/6.
//

#include <stdarg.h>
#include "lib.h"
#include "api.h"

User Users;
Course Courses;
Teacher Teachers;
Homework Homeworks;
Tutor Tutors;
Student Students;

View LOGIN;
View MENU_USER;
View MENU_TEACHER;

View MAIN_USER;
View MAIN_COURSE;
View MAIN_TEACHER;
View MAIN_HOMEWORK;
View MAIN_TUTOR;
View MAIN_STUDENT;

View QUERY_USER;
View QUERY_COURSE;
View QUERY_TEACHER;
View QUERY_HOMEWORK;
View QUERY_TUTOR;
View QUERY_STUDENT;

int CountUser;
int CountCourse;
int CountTeacher;
int CountHomework;
int CountTutor;
int CountStu;



void backUser(void) { //回到上层界面
    setView(QUERY_USER->back);
    show();
}

void backCourse(void) {
    setView(QUERY_COURSE->back);
    show();
}

void backTeacher(void) {
    setView(QUERY_TEACHER->back);
    show();
}

void backHomework(void) {
    setView(QUERY_HOMEWORK->back);
    show();
}

void backTutor(void) {
    setView(QUERY_TUTOR->back);
    show();
}

void backStudent(void) {
    setView(QUERY_STUDENT->back);
    show();
}

void quit(void) { //退出
    exit(0);
}

void soutUser(int index, User user) { //输出单个用户信息
    customPrint(5, Window_Size->X / 2 - 45, 14 + index, "%-14s%-10s",
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

void sortStuGpa(void) {
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
            if (q->gpa < p->gpa) {
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

void sortStuBad(void) {
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
            if (q->bad < p->bad) {
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

void getUser(int type, char text[30], int viewNum) { //获取用户信息
    int value, i;
    char str[30];
    User t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要查询的%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "用户名        用户类型");
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

void getCourse(int type, char text[30], int viewNum) { //获取课程信息
    int value, i;
    char str[30];
    Course t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要查询的%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "课程名        学分");
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

void getTeacher(int type, char text[30], int viewNum) { //获取教师信息
    int value, i;
    char str[30];
    Teacher t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要查询的%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "教师姓名        教师邮箱");
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

void getHomework(int type, char text[30], int viewNum) { //获取作业信息
    int value, i;
    char str[30];
    Homework t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要查询的%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "截止时间        批改状态");
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

void getTutor(int type, char text[30], int viewNum) { //获取答疑/辅导信息
    int value, i;
    char str[30];
    Tutor t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 10, 13, "请输入要查询的%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 30, 13, "答疑/辅导时间");
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

void getStudent(int type, char text[30], int viewNum) { //获取学生信息
    int value, i;
    char str[30];
    Student t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要查询的%s: ", text);
    if (viewNum) scanf("%d", &value);
    else { scanf("%s", str); }
    if (type == 4) sortStuGpa();
    if (type == 5) sortStuBad();
    CLS();
    showTitle();
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
                if (t->Next != NULL) {
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

void queryUser1(void) {
    getUser(1, "用户编号", 1);
}

void queryUser2(void) {
    getUser(2, "用户名", 0);
}

void queryUser3(void) {
    getUser(3, "用户类型", 1);
}

void queryUser0(void) {
    int i;
    User t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "用户名        用户类型");
    for (i = 0, t = Users; t->Next != NULL; t = t->Next) {
        soutUser(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryCourse1(void) {
    getCourse(1, "课程编号", 1);
}

void queryCourse2(void) {
    getCourse(2, "课程名", 0);
}

void queryCourse3(void) {
    getCourse(3, "课程学分", 1);
}

void queryCourse0(void) {
    int i;
    Course t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "课程名        学分");
    for (i = 0, t = Courses; t->Next != NULL; t = t->Next) {
        soutCourse(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryTeacher1(void) {
    getTeacher(1, "教师编号", 1);
}

void queryTeacher2(void) {
    getTeacher(2, "教师姓名", 0);
}

void queryTeacher0(void) {
    int i;
    Teacher t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "教师姓名        教师邮箱");
    for (i = 0, t = Teachers; t->Next != NULL; t = t->Next) {
        soutTeacher(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryHomework1(void) {
    getHomework(1, "作业编号", 1);
}

void queryHomework2(void) {
    getHomework(2, "课程编号", 1);
}

void queryHomework3(void) {
    getHomework(3, "教师编号", 1);
}

void queryHomework0(void) {
    int i;
    Homework t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "截止时间        批改状态");
    for (i = 0, t = Homeworks; t->Next != NULL; t = t->Next) {
        soutHomework(i, t->Next);
        ++i;
    }
    gotoxy(0, Window_Size->Y);
    swch = 2;
}

void queryTutor1(void) {
    getTutor(1, "答疑/辅导编号", 1);
}

void queryTutor2(void) {
    getTutor(2, "课程编号", 1);
}

void queryTutor3(void) {
    getTutor(3, "教师编号", 1);
}

void queryTutor0(void) {
    int i;
    Tutor t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 45, 13, "答疑/辅导时间");
    for (i = 0, t = Tutors; t->Next != NULL; t = t->Next) {
        soutTutor(i, t->Next);
        ++i;
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
    getStudent(4, "学生绩点", 1);
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

void login(void) {
    int i = 0;
    char username[20], password[20];
    User t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入用户名: ");
    scanf("%s", username);
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入密码: ");
    scanf("%s", password);
    for (t = Users; t->Next != NULL; t = t->Next) {
        if (!strcmp(t->Next->username, username) && !strcmp(t->Next->password, password)) {
            if (t->Next->type == 0) {
                setView(MENU_USER);
                show();
                return;
            } else {
                setView(MENU_TEACHER);
                show();
                return;
            }
        }
    }
    customPrint(4, Window_Size->X / 2 - 25, 15, "用户名或密码错误");
    gotoxy(0, Window_Size->Y);
    exit(0);
}

void initLogin(void) {
    LOGIN = createView();
    append(LOGIN, "登录", &login);
    append(LOGIN, "退出", &quit);
}

void showUser(void) {
    setView(MAIN_USER);
    show();
}

void showCourse(void) {
    setView(MAIN_COURSE);
    show();
}

void showTeacher(void) {
    setView(MAIN_TEACHER);
    show();
}

void showHomework(void) {
    setView(MAIN_HOMEWORK);
    show();
}

void showTutor(void) {
    setView(MAIN_TUTOR);
    show();
}

void showStudent(void) {
    setView(MAIN_STUDENT);
    show();
}

void view(void) {
    MENU_USER = createView();
    append(MENU_USER, "用户信息", &showUser);
    append(MENU_USER, "学生信息", &showStudent);
    append(MENU_USER, "课程信息", &showCourse);
    append(MENU_USER, "教师信息", &showTeacher);
    append(MENU_USER, "作业信息", &showHomework);
    append(MENU_USER, "答疑/辅导信息", &showTutor);
    append(MENU_USER, "退出", &quit);
}

void TeaView(void) {
    MENU_TEACHER = createView();
    append(MENU_TEACHER, "学生信息", &showStudent);
    append(MENU_TEACHER, "课程信息", &showCourse);
    append(MENU_TEACHER, "作业信息", &showHomework);
    append(MENU_TEACHER, "答疑/辅导信息", &showTutor);
    append(MENU_TEACHER, "退出", &quit);
}

void viewUser(void) { //初始化用户
    MAIN_USER = createView();
    QUERY_USER = createView();
    append(MAIN_USER, "新增用户信息", &addUser);
    append(MAIN_USER, "删除用户信息", &delUser);
    append(MAIN_USER, "修改用户信息", &modifyUser);
    append(MAIN_USER, "查询用户信息", &queryUser);
    append(MAIN_USER, "发送邮件", &quit);
    append(MAIN_USER, "退出", &quit);

    append(QUERY_USER, "根据编号查询", &queryUser1);
    append(QUERY_USER, "根据姓名查询", &queryUser2);
    append(QUERY_USER, "根据类型查询", &queryUser3);
    append(QUERY_USER, "列出所有信息", &queryUser0);
    append(QUERY_USER, "返回", &backUser);
    QUERY_USER->back = MAIN_USER;

}

void viewCourse(void) { //初始化课程
    Courses = (Course)malloc(sizeof(struct course));
    Courses->Next = NULL;
    MAIN_COURSE = createView();
    QUERY_COURSE = createView();
    append(MAIN_COURSE, "新增课程信息", &addCourse);
    append(MAIN_COURSE, "删除课程信息", &delCourse);
    append(MAIN_COURSE, "修改课程信息", &modifyCourse);
    append(MAIN_COURSE, "查询课程信息", &queryCourse);
    append(MAIN_COURSE, "退出", &quit);

    append(QUERY_COURSE, "根据编号查询", &queryCourse1);
    append(QUERY_COURSE, "根据名称查询", &queryCourse2);
    append(QUERY_COURSE, "根据学分查询", &queryCourse3);
    append(QUERY_COURSE, "列出所有信息", &queryCourse0);
    append(QUERY_COURSE, "返回", &backCourse);
    QUERY_COURSE->back = MAIN_COURSE;
}

void viewTeacher(void) { //初始化教师
    Teachers = (Teacher)malloc(sizeof(struct teacher));
    Teachers->Next = NULL;
    MAIN_TEACHER = createView();
    QUERY_TEACHER = createView();
    append(MAIN_TEACHER, "新增教师信息", &addTeacher);
    append(MAIN_TEACHER, "删除教师信息", &delTeacher);
    append(MAIN_TEACHER, "修改教师信息", &modifyTeacher);
    append(MAIN_TEACHER, "查询教师信息", &queryTeacher);
    append(MAIN_TEACHER, "退出", &quit);

    append(QUERY_TEACHER, "根据编号查询", &queryTeacher1);
    append(QUERY_TEACHER, "根据姓名查询", &queryTeacher2);
    append(QUERY_TEACHER, "列出所有信息", &queryTeacher0);
    append(QUERY_TEACHER, "返回", &backTeacher);
    QUERY_TEACHER->back = MAIN_TEACHER;
}

void viewHomework(void) { //初始化作业
    Homeworks = (Homework)malloc(sizeof(struct homework));
    Homeworks->Next = NULL;
    MAIN_HOMEWORK = createView();
    QUERY_HOMEWORK = createView();
    append(MAIN_HOMEWORK, "新增作业信息", &addHomework);
    append(MAIN_HOMEWORK, "删除作业信息", &delHomework);
    append(MAIN_HOMEWORK, "修改作业信息", &modifyHomework);
    append(MAIN_HOMEWORK, "查询作业信息", &queryHomework);
    append(MAIN_HOMEWORK, "退出", &quit);

    append(QUERY_HOMEWORK, "根据编号查询", &queryHomework1);
    append(QUERY_HOMEWORK, "根据课程查询", &queryHomework2);
    append(QUERY_HOMEWORK, "根据教师查询", &queryHomework3);
    append(QUERY_HOMEWORK, "列出所有信息", &queryHomework0);
    append(QUERY_HOMEWORK, "返回", &backHomework);
    QUERY_HOMEWORK->back = MAIN_HOMEWORK;
}

void viewTutor(void) { //初始化答疑/辅导
    Tutors = (Tutor)malloc(sizeof(struct tutor));
    Tutors->Next = NULL;
    MAIN_TUTOR = createView();
    QUERY_TUTOR = createView();
    append(MAIN_TUTOR, "新增答疑/辅导信息", &addTutor);
    append(MAIN_TUTOR, "删除答疑/辅导信息", &delTutor);
    append(MAIN_TUTOR, "修改答疑/辅导信息", &modifyTutor);
    append(MAIN_TUTOR, "查询答疑/辅导信息", &queryTutor);
    append(MAIN_TUTOR, "退出", &quit);

    append(QUERY_TUTOR, "根据编号查询", &queryTutor1);
    append(QUERY_TUTOR, "根据课程查询", &queryTutor2);
    append(QUERY_TUTOR, "根据教师查询", &queryTutor3);
    append(QUERY_TUTOR, "列出所有信息", &queryTutor0);
    append(QUERY_TUTOR, "返回", &backTutor);
    QUERY_TUTOR->back = MAIN_TUTOR;
}

void viewStudent(void) {
    Students = (Student)malloc(sizeof(struct student));
    Students->Next = NULL;
    MAIN_STUDENT = createView();
    QUERY_STUDENT = createView();
    append(MAIN_STUDENT, "新增学生信息", &addStudent);
    append(MAIN_STUDENT, "删除学生信息", &delStudent);
    append(MAIN_STUDENT, "修改学生信息", &modifyStudent);
    append(MAIN_STUDENT, "查询学生信息", &queryStudent);
    append(MAIN_STUDENT, "退出", &quit);

    append(QUERY_STUDENT, "根据编号查询", &queryStu1);
    append(QUERY_STUDENT, "根据姓名查询", &queryStu2);
    append(QUERY_STUDENT, "根据年级查询", &queryStu3);
    append(QUERY_STUDENT, "根据绩点查询", &queryStu4);
    append(QUERY_STUDENT, "根据记录查询", &queryStu5);
    append(QUERY_STUDENT, "列出所有信息", &queryStu0);
    append(QUERY_STUDENT, "返回", &backStudent);
    QUERY_STUDENT->back = MAIN_STUDENT;
}

void addUser(void) {//新增用户
    CLS();
    showTitle();
    User t = (User) malloc(sizeof(struct user));
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入用户编号: ");
    scanf("%d", &t->id);
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入用户名: ");
    scanf("%s", t->username);
    customPrint(5, Window_Size->X / 2 - 25, 15, "请输入用户密码: ");
    scanf("%s", t->password);
    customPrint(5, Window_Size->X / 2 - 25, 16, "请输入用户类型: ");
    scanf("%d", &t->type);
    t->Next = Users->Next;
    Users->Next = t;
    CountUser++;  //总数量+1
    show();   //回到主界面
    saveUser();   //保存
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "增加成功"); // 右下角输出绿色增加成功
    gotoxy(0, Window_Size->Y);  //重置坐标
}

void addCourse(void) {//新增课程
    Course t = (Course) malloc(sizeof(struct course));
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入课程编号: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入课程名称: ");
    scanf("%s", t->name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "请输入课程学分: ");
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
    CountCourse++;  //总数量+1
    show();   //回到主界面
    saveCourse();   //保存
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "增加成功"); // 右下角输出绿色增加成功
    gotoxy(0, Window_Size->Y);  //重置坐标
}

void addTeacher(void) {//新增教师
    Teacher t = (Teacher) malloc(sizeof(struct teacher));
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入教师编号: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入教师姓名: ");
    scanf("%s", t->name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "请输入教师邮箱: ");
    scanf("%s", t->emile);
    t->Next = Teachers->Next;
    Teachers->Next = t;
    CountTeacher++;  //总数量+1
    show();   //回到主界面
    saveTeacher();   //保存
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "增加成功"); // 右下角输出绿色增加成功
    gotoxy(0, Window_Size->Y);  //重置坐标
}

void addHomework(void) {//新增作业
    Homework t = (Homework) malloc(sizeof(struct homework));
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入作业编号: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入课程编号: ");
    scanf("%d", &t->course_id);
    customPrint(5, Window_Size->X / 2 - 25, 15, "请输入教师编号: ");
    scanf("%d", &t->teacher_id);
    customPrint(5, Window_Size->X / 2 - 25, 16, "请输入作业内容: ");
    scanf("%s", t->content);
    customPrint(5, Window_Size->X / 2 - 25, 17, "请输入截止时间: ");
    scanf("%s", t->deadline);
    t->status = 0;
    t->Next = Homeworks->Next;
    Homeworks->Next = t;
    CountHomework++;  //总数量+1
    show();   //回到主界面
    saveHomework();   //保存
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "增加成功"); // 右下角输出绿色增加成功
    gotoxy(0, Window_Size->Y);  //重置坐标
}

void addTutor(void) {//新增答疑/辅导
    Tutor t = (Tutor) malloc(sizeof(struct tutor));
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入答疑/辅导编号: ");
    scanf("%d", &t->id);
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入课程编号: ");
    scanf("%d", &t->course_id);
    customPrint(5, Window_Size->X / 2 - 25, 15, "请输入教师编号: ");
    scanf("%d", &t->teacher_id);
    customPrint(5, Window_Size->X / 2 - 25, 16, "请输入答疑/辅导时间: ");
    scanf("%s", t->time);
    t->Next = Tutors->Next;
    Tutors->Next = t;
    CountTutor++;  //总数量+1
    show();   //回到主界面
    saveTutor();   //保存
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "增加成功"); // 右下角输出绿色增加成功
    gotoxy(0, Window_Size->Y);  //重置坐标
}

void addStudent(void) {//新增
    Student t = (Student) malloc(sizeof(struct student));
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入学生编号: ");
    scanf("%d", &t->id);
    customPrint(5, Window_Size->X / 2 - 25, 14, "请输入学生姓名: ");
    scanf("%s", t->name);
    customPrint(5, Window_Size->X / 2 - 25, 15, "请输入学生邮箱: ");
    scanf("%s", t->emile);
    customPrint(5, Window_Size->X / 2 - 25, 16, "请输入学生年级: ");
    scanf("%d", &t->class);
    customPrint(5, Window_Size->X / 2 - 25, 17, "请输入学生不良记录: ");
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
    CountStu++;  //总数量+1
    show();   //回到主界面
    saveStudent();   //保存
    customPrint(2, Window_Size->X - 7, Window_Size->Y, "增加成功"); // 右下角输出绿色增加成功
    gotoxy(0, Window_Size->Y);  //重置坐标
}

void modifyUser(void) {//修改用户
    int id, comp = 0;
    User t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要修改用户的编号: ");
    scanf("%d", &id);
    for (t = Users; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "请输入改后的编号: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "请输入改后的用户名: ");
            scanf("%s", t->Next->username);
            customPrint(5, Window_Size->X / 2 - 25, 17, "请输入改后的密码: ");
            scanf("%s", t->Next->password);
            customPrint(5, Window_Size->X / 2 - 25, 18, "请输入改后的类型: ");
            scanf("%d", &t->Next->type);
            comp = 1;
            break;
        }
    }
    show();
    saveUser();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "修改成功");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "未找到此信息");
    gotoxy(0, Window_Size->Y);
}

void modifyCourse(void) {//修改课程
    int id, comp = 0;
    Course t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要修改课程的编号: ");
    scanf("%d", &id);
    for (t = Courses; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "请输入改后的编号: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "请输入改后的名称: ");
            scanf("%s", t->Next->name);
            customPrint(5, Window_Size->X / 2 - 25, 17, "请输入改后的学分: ");
            scanf("%d", &t->Next->credit);
            comp = 1;
            break;
        }
    }
    show();
    saveCourse();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "修改成功");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "未找到此信息");
    gotoxy(0, Window_Size->Y);
}

void modifyTeacher(void) {//修改教师
    int id, comp = 0;
    Teacher t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要修改教师的编号: ");
    scanf("%d", &id);
    for (t = Teachers; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "请输入改后的编号: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "请输入改后的姓名: ");
            scanf("%s", t->Next->name);
            customPrint(5, Window_Size->X / 2 - 25, 17, "请输入改后的邮箱: ");
            scanf("%s", t->Next->emile);
            comp = 1;
            break;
        }
    }
    show();
    saveTeacher();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "修改成功");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "未找到此信息");
    gotoxy(0, Window_Size->Y);
}

void modifyHomework(void) {//修改作业
    int id, comp = 0;
    Homework t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要修改作业的编号: ");
    scanf("%d", &id);
    for (t = Homeworks; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "请输入改后的编号: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "请输入改后的课程编号: ");
            scanf("%d", &t->Next->course_id);
            customPrint(5, Window_Size->X / 2 - 25, 17, "请输入改后的教师编号: ");
            scanf("%d", &t->Next->teacher_id);
            customPrint(5, Window_Size->X / 2 - 25, 18, "请输入改后的作业内容: ");
            scanf("%s", t->Next->content);
            customPrint(5, Window_Size->X / 2 - 25, 19, "请输入改后的截止时间: ");
            scanf("%s", t->Next->deadline);
            comp = 1;
            break;
        }
    }
    show();
    saveHomework();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "修改成功");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "未找到此信息");
    gotoxy(0, Window_Size->Y);
}

void modifyTutor(void) {//修改答疑/辅导
    int id, comp = 0;
    Tutor t;
    CLS();
    showTitle();
    customPrint(5, Window_Size->X / 2 - 25, 13, "请输入要修改答疑/辅导的编号: ");
    scanf("%d", &id);
    for (t = Tutors; t->Next != NULL; t = t->Next) {
        if (t->Next->id == id) {
            customPrint(5, Window_Size->X / 2 - 25, 15, "请输入改后的编号: ");
            scanf("%d", &t->Next->id);
            customPrint(5, Window_Size->X / 2 - 25, 16, "请输入改后的课程编号: ");
            scanf("%d", &t->Next->course_id);
            customPrint(5, Window_Size->X / 2 - 25, 17, "请输入改后的教师编号: ");
            scanf("%d", &t->Next->teacher_id);
            customPrint(5, Window_Size->X / 2 - 25, 18, "请输入改后的答疑/辅导时间: ");
            scanf("%s", t->Next->time);
            comp = 1;
            break;
        }
    }
    show();
    saveTutor();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "修改成功");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "未找到此信息");
    gotoxy(0, Window_Size->Y);
}

void modifyStudent(void) {//修改
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
    saveStudent();
    if (comp) customPrint(2, Window_Size->X - 7, Window_Size->Y, "修改成功");
    else customPrint(4, Window_Size->X - 11, Window_Size->Y, "未找到此信息");
    gotoxy(0, Window_Size->Y);
}

void delUser(void) {//删除用户
    int id, total = 0;
    User p, t = Users;
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
    CountUser -= total;
    show();
    saveUser();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "删除了 %d 条信息", total);
    gotoxy(0, Window_Size->Y);
}

void delCourse(void) {//删除课程
    int id, total = 0;
    Course p, t = Courses;
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
    CountCourse -= total;
    show();
    saveCourse();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "删除了 %d 条信息", total);
    gotoxy(0, Window_Size->Y);
}

void delTeacher(void) {//删除教师
    int id, total = 0;
    Teacher p, t = Teachers;
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
    CountTeacher -= total;
    show();
    saveTeacher();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "删除了 %d 条信息", total);
    gotoxy(0, Window_Size->Y);
}

void delHomework(void) {//删除作业
    int id, total = 0;
    Homework p, t = Homeworks;
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
    CountHomework -= total;
    show();
    saveHomework();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "删除了 %d 条信息", total);
    gotoxy(0, Window_Size->Y);
}

void delTutor(void) {//删除答疑/辅导
    int id, total = 0;
    Tutor p, t = Tutors;
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
    CountTutor -= total;
    show();
    saveTutor();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "删除了 %d 条信息", total);
    gotoxy(0, Window_Size->Y);
}

void delStudent(void) {//删除
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
    CountStu -= total;
    show();
    saveStudent();
    customPrint(2, Window_Size->X - 15, Window_Size->Y, "删除了 %d 条信息", total);
    gotoxy(0, Window_Size->Y);
}

void queryUser(void) {//查询用户
    setView(QUERY_USER);
    show();
}

void queryCourse(void) {//查询课程
    setView(QUERY_COURSE);
    show();
}

void queryTeacher(void) {//查询教师
    setView(QUERY_TEACHER);
    show();
}

void queryHomework(void) {//查询作业
    setView(QUERY_HOMEWORK);
    show();
}

void queryTutor(void) {//查询答疑/辅导
    setView(QUERY_TUTOR);
    show();
}

void queryStudent(void) {//查询
    setView(QUERY_STUDENT);
    show();
}

void importUser(void) {//导入用户
    Users = (User)malloc(sizeof(struct user));
    Users->Next = NULL;
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

void importCourse(void) {//导入课程
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

void importTeacher(void) {//导入教师
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

void importHomework(void) {//导入作业
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

void importTutor(void) {//导入答疑/辅导
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

void importStudent(void) {//导入
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

void saveUser(void) {//保存用户
    User t;
    int i = 0;
    FILE *file = fopen("User.txt", "w");

    fprintf(file, "%d\n", CountUser);
    for (t = Users; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %s %s %d\n", t->Next->id, t->Next->username, t->Next->password, t->Next->type);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "已保存");
}

void saveCourse(void) {//保存课程
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
        fprintf(file, "\n");
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "已保存");
}

void saveTeacher(void) {//保存教师
    Teacher t;
    int i = 0;
    FILE *file = fopen("Teacher.txt", "w");

    fprintf(file, "%d\n", CountTeacher);
    for (t = Teachers; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %s %s\n", t->Next->id, t->Next->name, t->Next->emile);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "已保存");
}

void saveHomework(void) {//保存作业
    Homework t;
    int i = 0;
    FILE *file = fopen("Homework.txt", "w");

    fprintf(file, "%d\n", CountHomework);
    for (t = Homeworks; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %d %d %s %s %d\n", t->Next->id, t->Next->course_id, t->Next->teacher_id, t->Next->content,
                t->Next->deadline, t->Next->status);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "已保存");
}

void saveTutor(void) {//保存答疑/辅导
    Tutor t;
    int i = 0;
    FILE *file = fopen("Tutor.txt", "w");

    fprintf(file, "%d\n", CountTutor);
    for (t = Tutors; t->Next != NULL; t = t->Next) {
        fprintf(file, "%d %d %d %s\n", t->Next->id, t->Next->course_id, t->Next->teacher_id, t->Next->time);
    }
    fclose(file);
    customPrint(2, Window_Size->X - 5, Window_Size->Y - 1, "已保存");
}

void saveStudent(void) {//保存
    Student t;
    int i = 0;
    FILE *file = fopen("Stu.txt", "w");

    fprintf(file, "%d\n", CountStu);
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
        fprintf(file, "\n");
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
