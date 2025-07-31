int main() {
    char *src = malloc(1024);
    int *p = malloc(100);
    memcpy(p, src, 1024);
    int *q = 4;
}
