int main() {
    int *p;
    *p = 5;
    free(p);
    *p = 0;
    return 0;
}
