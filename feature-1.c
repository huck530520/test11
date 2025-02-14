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
            printf("Memory allocation failed\n");
            return;
        }
    }

    if (buf != NULL && data_len <= 100) {
        memcpy(buf, data, data_len);
    } else {
        printf("Invalid data length or buffer\n");
    }
}

int main() {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    *p = 0;

    int *p2 = malloc(sizeof(int));
    if (p2 == NULL) {
        printf("Memory allocation failed\n");
        free(p);
        return 1;
    }
    *p2 = 4;
    *p2 = 100;

    free(p);
    free(p2);

    out_of_bound_access(2048);

    return 0;
}