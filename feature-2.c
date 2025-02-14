#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "typedef-1.h"
/*
void out_of_bound_access(int data_len) {
    static uint8_t *buf = NULL;
    char data[1024];
    memset(data, '\0', 1024);

    if (data_len > 100) {
        buf = malloc(100);
        if (buf == NULL) {
            // Handle memory allocation failure
            return;
        }
    }

    if (buf != NULL) {
        memcpy(buf, data, (data_len < 100) ? data_len : 100);
        free(buf);
        buf = NULL;
    }
}
*/

int main() {
    int *p = NULL;
    if (p != NULL) {
        free(p);
    }
    return 0;
}