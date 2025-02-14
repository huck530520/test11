#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "typedef-1.h"


void out_of_bound_access(int data_len) {
    static uint8_t *buf = NULL;
    char data[1024];
    memset(data, '\0', 1024);

    if (data_len > 100) {
        buf = malloc(data_len); // allocate sufficient memory
    } else {
        buf = malloc(100);
    }

    if (buf != NULL) { // check for allocation failure
        memcpy(buf, data, data_len);
        free(buf); // free allocated memory to prevent memory leak
        buf = NULL;
    }
}

int main() {
    int *p;

    p = malloc(sizeof(int));
    if (p != NULL) { // check for allocation failure
        *p = 0;
        free(p); // free allocated memory to prevent memory leak
    }

    int *p2 = malloc(sizeof(int)); // initialize p2 with allocated memory
    if (p2 != NULL) { // check for allocation failure
        *p2 = 4;
        *p2 = 100;
        free(p2); // free allocated memory to prevent memory leak
    }

    out_of_bound_access(2048);

    return 0;
}