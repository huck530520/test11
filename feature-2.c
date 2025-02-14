#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "typedef-1.h"

int main() {
  int *p = NULL; // Explicitly set to NULL for clarity
  if (p != NULL) { // Check before free to avoid unnecessary calls
    free(p);
  }
  return 0;
}