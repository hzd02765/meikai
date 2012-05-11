#include <stdio.h>

void move(int no, int x, int y)
{
  if(no > 1){
    move(no - 1, x, 6 - x - y);
  }

  printf("[%d]を%d軸から%d軸へ移動\n",  no, x, y);

  if(no > 1){
    move(no - 1, 6 - x - y, y);
  }
}

int main(void)
{
  int n;

  printf("円盤の枚数：");
  scanf("%d", &n);

  move(n, 1, 3);

  return (0);
}
