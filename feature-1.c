#include <stdlib.h>

#include <string.h>
#include <stdio.h>

int a, b;

void out_of_bound_access(int data_len) {
    char data[1024];
    char *buf;
    size_t len = (data_len > 1024) ? 1024 : data_len;
    memset(data, '\0', 1024);
    buf = malloc(len);
    if (buf != NULL) {
        memcpy(buf, data, len);
        free(buf); // Assuming buf is no longer needed after this
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
    out_of_bound_access(2048);

    return 0;
}
