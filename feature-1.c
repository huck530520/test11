#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(sizeof(int));
  if (p == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  *p = 0;
  free(p);

  int *p2 = malloc(sizeof(int));
  if (p2 == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  *p2 = 4;
  int p4;
  *p2 = 100;
  free(p2);

  // test comment
  // out_of_bound_access(2048); // This line may still cause issues depending on the implementation of out_of_bound_access

  return 0;
}