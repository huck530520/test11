int main() {
  int *p;

  p = malloc(sizeof(int));
  if (p == NULL) {
    // Handle memory allocation failure
    return 1;
  }
  *p = 0;
  // patch 1
  // patch 3
  int *p2 = malloc(sizeof(int));
  if (p2 == NULL) {
    // Handle memory allocation failure
    free(p);
    return 1;
  }
  *p2 = 4;
  int p4;
  *p2 = 100;
  free(p);
  free(p2);

  // test comment
  // out_of_bound_access(2048); // Commented out to prevent out-of-bounds access

  return 0;
}