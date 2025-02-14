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
            // Handle memory allocation error
            printf("Memory allocation error\n");
            return;
        }
    }

    if (data_len > 100) {
        data_len = 100;
    }
    memcpy(buf, data, data_len);
}

int main() {
    int *p;

    p = malloc(sizeof(int));
    if (p == NULL) {
        // Handle memory allocation error
        printf("Memory allocation error\n");
        return 1;
    }
    *p = 0;
    free(p);

    int *p2 = malloc(sizeof(int));
    if (p2 == NULL) {
        // Handle memory allocation error
        printf("Memory allocation error\n");
        return 1;
    }
    *p2 = 4;
    int p4;
    *p2 = 100;
    free(p2);

    out_of_bound_access(2048);

    return 0;
}