#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "typedef-1.h"

void out_of_bound_access(int data_len) {
    static uint8_t *buf = NULL;
    char data[1024];
    memset(data, '\0', 1024);

    if (data_len > 100) {
        if (buf != NULL) {
            free(buf);
            buf = NULL;
        }
        buf = malloc(data_len);
        if (buf == NULL) {
            return;
        }
    }

    if (buf != NULL) {
        memcpy(buf, data, data_len);
    }
}

int main() {
    int *p;
    p = malloc(sizeof(int));
    if (p != NULL) {
        *p = 0;
    }

    //p = malloc(sizeof(int));
    // patch 1
    // patch 3
#pragma coverity compliance block deviate "UNINIT"
    int *p2;
    p2 = malloc(sizeof(int));
    if (p2 != NULL) {
        *p2 = 4;
    }

    int p4;
    if (p2 != NULL) {
        *p2 = 100;
    }
#pragma coverity compliance end_block "UNINIT"

    // test comment
    out_of_bound_access(2048);

    return 0;
}