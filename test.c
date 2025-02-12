#include <stdio.h>

int main()
{
  // robert: add a comment to test git/repo/gerrit
  int not_used; /* declared but not used variable. */
  int a;
  int b, c, d;

  a = 1;
  b = a + 2;
  a = b << 2;

  printf ("Hello Jenkins\n");
  printf ("Hello Jenkins\n");
  printf("%d",a);

  printf ("Test https\n");
  printf ("Modified test.c\n");
  printf ("Modified test.c again\n");
  printf ("Modified test.c again and again\n");
  printf ("Modified test.c again and again and again\n");
  return 0;
}
