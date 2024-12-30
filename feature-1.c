#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "typedef-1.h"

void out_of_bound_access(int data_len) {
    static uint8_t *buf = NULL;
    char data[1024];
    memset(data, '\0', 1024);

    if (data_len > 0 && data_len <= 100) {
        if (buf == NULL) {
            buf = malloc(data_len);
        } else if (data_len > 100) {
            free(buf);
            buf = malloc(100);
        }
    } else {
        printf("Invalid data length\n");
        return;
    }

    if (buf != NULL) {
        memcpy(buf, data, data_len);
    }
}

int main() {
    int *p = malloc(sizeof(int));
    if (p != NULL) {
        *p = 0;
    }

    int *p2 = malloc(sizeof(int));
    if (p2 != NULL) {
        *p2 = 4;
        *p2 = 100;
        free(p2);
    }

    if (p != NULL) {
        free(p);
    }

    out_of_bound_access(1024);

    return 0;
}