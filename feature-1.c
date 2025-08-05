void func() {
    int a;
    if (a > 0) {
        printf("test 1\n");
	return;
    }
    else {
	printf("test 2\n");
	return;
    }

    a = 999;
    return;
}

int main() {
    int *p;
    *p = 5;
    free(p);
    *p = 0;
    func();

    return 0;
}
