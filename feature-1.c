int main() {
    int *p;
    p = malloc(sizeof(int));
    if (p == NULL) {
        return 1;
    }
    *p = 0;
    free(p);

    int *p2 = malloc(sizeof(int));
    if (p2 == NULL) {
        return 1;
    }
    *p2 = 4;
    *p2 = 100;
    free(p2);

    // test comment
    // out_of_bound_access(2048); // This function call is potentially problematic without knowing its definition

    return 0;
}