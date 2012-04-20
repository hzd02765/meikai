#include <stdio.h>

int gcd(int x, int y)
{
  if(y == 0){
    return (x);
  }else{
    return (gcd(y, x % y));
  }
}

int main(void)
{
  int x, y;

  printf("整数を入力せよ：");
  scanf("%d", &x);

  printf("整数を入力せよ：");
  scanf("%d", &y);

  printf("最大公約数は%dです。\n", gcd(x, y));

  return (0);
}
