#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void quick(int a[], int left, int right)
{
  int pl = left;
  int pr = right;
  int x = a[(pl + pr) / 2];

  do{
    while (a[pl] < x) pl++;
    while (a[pr] > x) pr--;
    if(pl <= pr){
      swap(int, a[pl], a[pr]);
      pl++;
      pr--;
    }
  } while (pl <= pr);

  if (left < pr) quick(a, left, pr);
  if (pl < right) quick(a, pl, right);
}

int main(void)
{
  int i;
  int x[9];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を入力せよ。\n", nx);
  for(i = 0; i < nx; i++){
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  quick(x, 0, nx - 1);
  
  puts("昇順にソートしました。");
  for(i = 0; i < nx; i++){
    printf("x[%d] = %d\n", i, x[i]);
  }

  return (0);
}
