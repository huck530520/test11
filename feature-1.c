#include <stdlib.h>

#include <string.h>
#include <stdio.h>

int a, b;

void out_of_bound_access(int data_len) {
    char data[1024];
    char *buf;
    if (data_len > 100) {
        buf = malloc(data_len); // Allocate sufficient size for all cases
        if (buf == NULL) {
            return; // Handle allocation failure
        }
    } else {
        buf = data; // Use stack buffer when data_len is <= 100
    }
    memcpy(buf, data, data_len);
    if (data_len > 100) {
        free(buf); // Free heap-allocated memory
    }
}

int main() {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        return -1;
    }
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
    out_of_bound_access(1023);  // Changed from 2048 to 1023 to avoid buffer overrun

    return 0;
}
