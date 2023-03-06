int main() {
    int *p;
    *p = 5;
    free(p);

    int *q = malloc(sizeof(int));
    memset(q, 0, sizeof(*q));

    return 0;
}
