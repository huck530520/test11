int main() {
    int *p;

    *p = 5;
    *p = 6;
    *p = 999;

    free(p);

    int *q = malloc(sizeof(int));
    memset(q, 0, sizeof(*q));

    return 0;
}
