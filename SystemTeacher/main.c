#include "api.h"

int main() {
    importUser();
    int flag = login();
    initView();
    setView(MAIN);
    show();
    importCourse();
    importTeacher();
    importHomework();
    importTutor();
    sortStuAverage();
    switch (flag) {
        case 0:
            view();
            initView();
            setView(MAIN);
            show();
            break;
        case 1:
            TeaView();
            initView();
            setView(MAIN);
            show();
            break;
    }
    while (1) {} //��ѭ�����ֳ�������
}
