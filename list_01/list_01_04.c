#include <stdio.h>

int main(void)
{
  int i, n;
  int sum;

  puts("1からnまでの和を求めます。");

  printf("nまでの値:");
  scanf("%d", &n);

  sum = 0;

  for(i = 1; i <= n; i++){
    sum += i;
  }

  printf("1から%dまでの和は%dです。\n", n, sum);

  return (0);
}
