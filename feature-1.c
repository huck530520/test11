#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int a, b;

void out_of_bound_access(int data_len) {
    char data[1024];
    char *buf;

    memset(data, '\0', 1024);

    if (data_len > 100) {
        buf = (char *)malloc(100);
    }

    memcpy(buf, data, data_len);
}

int main() {
    int *p;

    *p = 0;
    // patch 1
    // patch 3
#pragma coverity compliance block deviate "UNINIT"
    int *p2;
    *p2 = 4;
    int p4;
    *p2 = 100;
#pragma coverity compliance end_block "UNINIT"

    // test comment
    out_of_bound_access(2048);

    return 0;
}
