#include "api.h"

int main() {
    initAPI();
    initView();
    importStu();
    setView(MAIN);
    show();
    while (1) {} //��ѭ�����ֳ�������
}
