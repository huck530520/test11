#include <iostream>

int main() {
    std::cout << "Hello World!";
    //int *p;
    //*p = 5;

    char *ptr = malloc(10);
    std::cout << ptr[10];

    return 0;
}
