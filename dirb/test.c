int main() {
    char *src = malloc(1024); // Initialize src with allocated memory
    if (src == NULL) {
        return 1; // Handle allocation failure
    }
    int *p = malloc(100);
    if (p == NULL) {
        free(src); // Clean up src if p allocation fails
        return 1;
    }
    memcpy(p, src, 1024);
    int *q = p; // Fix type mismatch by assigning a valid pointer
    free(src); // Clean up allocated memory
    free(p);
    return 0;
}
