#include "api.h"

int main() {
    initAPI();
    initView();
    importStu();
    setView(MAIN);
    show();
    while (1) {} //死循环保持程序运行
}
