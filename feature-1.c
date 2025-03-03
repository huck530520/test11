int main() {
    int *p;

    p = malloc(sizeof(int));
    *p = 0;
    // patch 1
    // patch 3
#pragma coverity compliance block deviate "UNINIT"
    int *p2 = malloc(sizeof(int)); // Initialize p2
    *p2 = 4;
    int p4;
    *p2 = 100;
#pragma coverity compliance end_block "UNINIT"

    // test comment
    // out_of_bound_access(2048); // Commented out to avoid out-of-bounds access
    return 0; // Added return statement
}