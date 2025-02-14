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
        }
        buf = malloc(100);
        if (buf == NULL) {
            // Handle memory allocation failure
            printf("Memory allocation failed\n");
            return;
        }
    }

    if (data_len > 100) {
        memcpy(buf, data, 100);
    } else {
        memcpy(buf, data, data_len);
    }
}

int main() {
    int *p;

    p = malloc(sizeof(int));
    if (p == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        return 1;
    }
    *p = 0;
    // patch 1
    // patch 3
#pragma coverity compliance block deviate "UNINIT"
    int *p2 = malloc(sizeof(int));
    if (p2 == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        free(p);
        return 1;
    }
    *p2 = 4;
    int p4;
    *p2 = 100;
#pragma coverity compliance end_block "UNINIT"

    // test comment
    out_of_bound_access(2048);

    free(p);
    free(p2);
    return 0;
}