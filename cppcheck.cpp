#include <iostream>

int b;

int main() {
    std::cout << "Hello World!";
    int *p;
    *p = 6;

    char *ptr = malloc(10);
    std::cout << ptr[10];

    return 0;
}
