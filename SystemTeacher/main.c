#include "api.h"

int main() {
    const char* haystack = "Hello, World!";
    const char* needle = "123";

    // ��haystack�в���needle
    char* result = strstr(haystack, needle);

    if (result != NULL) {
        printf("�ҵ��˹ؼ��֣�%s\n", result);
    } else {
        printf("δ�ҵ��ؼ���\n");
    }
    return 0;
}
