#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void partition(int a[], int n)
{
  int i;
  int pl = 0;
  int pr = n - 1;
  int x = a[n / 2];

  do{
    while (a[pl] < x) pl++;
    while (a[pr] > x) pr--;
    if(pl <= pr){
      swap(int, a[pl], a[pr]);
      pl++;
      pr--;
    }
  }while (pl <= pr);

  printf("枢軸の値は%dです。\n", x);

  printf("枢軸以下のグループ\n");
  for(i = 0; i <= pl - 1; i++){
    printf("%d ", a[i]);
  }
  putchar('\n');

  if(pl > pr + 1){
    printf("枢軸と等しい並び\n");
    for(i = pr + 1; i <= pl - 1; i++){
      printf("%d ", a[i]);
    }
    putchar('\n');
  }

  printf("枢軸以上のグループ\n");
  for(i = pr + 1; i < n; i++){
    printf("%d ", a[i]);
  }
  putchar('\n');
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
  
  partition(x, nx);

  return (0);
}
