#include <stdio.h>

int main(void)
{
  int a, b, c;
  int max;

  printf("整数aの値："); scanf("%d", &a);
  printf("整数bの値："); scanf("%d", &b);
  printf("整数cの値："); scanf("%d", &c);

  max = a;
  if(b > max) max = b;
  if(c > max) max = c;

  printf("最大値は%dです。\n", max);

  return(0);
}
