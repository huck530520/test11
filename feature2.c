int main() {
    int *p;
    *p = 5;
    free(p);

    int *q = malloc(sizeof(int));
    memset(q, 0, sizeof(*q));

    int *r;
    *r = 1001;

    int *s;
    *s = 999;
    *s = 1000;

    int *t;
    *t = 0;

    return 0;
}
