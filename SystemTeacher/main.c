#include "api.h"

int main() {
    importUser();
    initLogin();
    initView();
    view();
    TeaView();
    viewUser();
    viewCourse();
    viewCourse();
    viewTeacher();
    viewHomework();
    viewTutor();
    viewStudent();
    importCourse();
    importTeacher();
    importHomework();
    importTutor();
    importStudent();
    setView(LOGIN);
    show();
    while (1) {} //��ѭ�����ֳ�������
}
