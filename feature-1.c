#include <stdlib.h>

#include <string.h>
#include <stdio.h>

int a, b;

void out_of_bound_access(int data_len) {
    char data[1024];
    char *buf;
    memset(data, '\0', 1024);
    buf = data; // Initialize buf to stack buffer
    if (data_len > 100) {
        buf = malloc(data_len); // Allocate correct size for larger data_len
        if (buf == NULL) {
            return; // Handle allocation failure
        }
    }
    memcpy(buf, data, data_len);
    if (data_len > 100) {
        free(buf); // Free heap-allocated buffer
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
	int *p2 = malloc(sizeof(int));
	*p2 = 4;
	int p4;
	*p2 = 100;
	// test comment
	out_of_bound_access(1023);
	return 0;
}
