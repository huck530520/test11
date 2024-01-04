int main() {
#ifndef __COVERITY__
    int *p;
    *p = 0;
    int *q;
    *q = 0;
#endif
    return 0;
}
