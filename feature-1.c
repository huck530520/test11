#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char   uint8_t;

void out_of_bound_access(int data_len) {
    static uint8_t *buf = NULL;
    char data[1024];
    memset(data, '\0', 1024);

    if (data_len > 100) {
        buf = malloc(100);
    }

    memcpy(buf, data, data_len);
}

int main() {
    //int *p2;
    //*p2 = 4;
    int *p2 = malloc(sizeof(int));
    *p2 = 4;

    //add patch
    //add patch 2
    //add patch 3

    out_of_bound_access(2048);
    printf("trigger by comment added on gerrit-dup-4\n");

    return 0;
}
