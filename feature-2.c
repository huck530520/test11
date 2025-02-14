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
        // Don't forget to free the allocated memory
        // free(buf);
    }

    // Check for null pointer before memcpy
    if (buf != NULL) {
        memcpy(buf, data, data_len);
    }
}
*/

int main() {
    int *p = NULL; // Initialize pointer to null
    // Only free the pointer if it's not null
    if (p != NULL) {
        free(p);
    }
    return 0;
}