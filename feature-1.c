#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char   uint8_t;

void out_of_bound_access(int data_len) {
    static uint8_t *buf = NULL;
    char data[1024];
    memset(data, '\0', 1024);

    if (data_len > 100) {
        buf = malloc(100);
    }

    memcpy(buf, data, data_len);
}

int main() {
#pragma coverity compliance block deviate "UNINIT"
    int *p2;
    *p2 = 4;
    int p4;
    *p2 = 100;
#pragma coverity compliance end_block "UNINIT"

    // test comment
    out_of_bound_access(2048);
    add something
    printf("trigger by comment added on gerrit-dup-4\n");

    return 0;
}
