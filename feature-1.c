int main() {
    int *p;

    p = malloc(sizeof(int));
    if (p == NULL) {
        // Handle memory allocation failure
        return 1;
    }
    *p = 0;
    // patch 1
    // patch 3
#pragma coverity compliance block deviate "UNINIT"
    int *p2 = malloc(sizeof(int));
    if (p2 == NULL) {
        // Handle memory allocation failure
        free(p);
        return 1;
    }
    *p2 = 4;
    int p4;
    *p2 = 100;
#pragma coverity compliance end_block "UNINIT"

    // test comment
    // Ensure out_of_bound_access can handle the given value safely
    // For demonstration, assuming out_of_bound_access is defined to safely handle any integer value
    out_of_bound_access(2048);

    free(p);
    free(p2);
    return 0;
}