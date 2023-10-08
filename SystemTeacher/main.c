#include "api.h"

int main() {
    const char* haystack = "Hello, World!";
    const char* needle = "World";

    // 在haystack中查找needle
    char* result = strstr(haystack, needle);

    if (result != NULL) {
        printf("找到了关键字：%s\n", result);
    } else {
        printf("未找到关键字\n");
    }

    return 0;
}
