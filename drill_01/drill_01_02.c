#include <stdio.h>

int max3(int a, int b, int c)
{
  int median = a;
  if (b >= a && b <= c) median = b;
  if (b <= a && b >= c) median = b;
  if (c >= a && c <= b) median = c;
  if (c <= a && c >= b) median = c;

  return (median);
}

int main(void)
{
  printf("max3(%d, %d, %d) = %d\n", 3, 2, 1, max3(3, 2, 1));
  printf("max3(%d, %d, %d) = %d\n", 3, 2, 2, max3(3, 2, 2));
  printf("max3(%d, %d, %d) = %d\n", 3, 1, 2, max3(3, 1, 2));
  printf("max3(%d, %d, %d) = %d\n", 3, 2, 3, max3(3, 2, 3));
  printf("max3(%d, %d, %d) = %d\n", 2, 1, 3, max3(2, 1, 3));
  printf("max3(%d, %d, %d) = %d\n", 3, 3, 1, max3(3, 3, 2));
  printf("max3(%d, %d, %d) = %d\n", 3, 3, 3, max3(3, 3, 3));
  printf("max3(%d, %d, %d) = %d\n", 2, 2, 3, max3(2, 2, 3));
  printf("max3(%d, %d, %d) = %d\n", 2, 3, 1, max3(2, 3, 1));
  printf("max3(%d, %d, %d) = %d\n", 2, 3, 2, max3(2, 3, 2));
  printf("max3(%d, %d, %d) = %d\n", 1, 3, 2, max3(1, 3, 2));
  printf("max3(%d, %d, %d) = %d\n", 2, 3, 3, max3(2, 3, 3));
  printf("max3(%d, %d, %d) = %d\n", 1, 2, 3, max3(1, 2, 3));

  return (0);
}
