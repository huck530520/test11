#include <stdio.h>

int main()
{
  // robert: add a comment to test git/repo/gerrit
  int not_used; /* declared but not used variable. */
  int a;
  int b;

  a = 1;
  b = a + 2;
  a = b << 2;

  printf ("Hello Jenkins\n");
  printf("%d",a);

  printf ("Modified test.c\n");
  printf ("Modified test.c again\n");
  return 0;
}
