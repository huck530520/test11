int main() {
    int *p;

    p = malloc(sizeof(int));
    if (p == NULL) {
        // handle memory allocation error
        return 1;
    }
    *p = 0;
    // patch 1
    // patch 3
#pragma coverity compliance block deviate "UNINIT"
    int *p2 = malloc(sizeof(int));
    if (p2 == NULL) {
        // handle memory allocation error
        return 1;
    }
    *p2 = 4;
    int p4;
    *p2 = 100;
#pragma coverity compliance end_block "UNINIT"

    // test comment
    // out_of_bound_access(2048); // commented out to prevent out-of-bounds access
    free(p);
    free(p2);
    return 0;
}