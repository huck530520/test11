int main() {
#ifndef __COVERITY__
    int *p;
    *p = 0;
#endif
    int *q;
    *q = 0;
    return 0;
}
