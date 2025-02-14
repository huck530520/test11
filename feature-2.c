#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "typedef-1.h"

int main() {
  int *p = NULL;
  if (p != NULL) {
    free(p);
  }
  return 0;
}