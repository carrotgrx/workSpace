#include "api.h"

int main() {
    int flag = login();

    switch (flag) {
        case 0:

    }

    viewStu();
    initView();
    importStu();
    setView(MAIN);
    show();
    while (1) {} //死循环保持程序运行
}
