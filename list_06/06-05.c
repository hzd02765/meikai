#include <stdio.h>

#define swap(type, x, y) do{type t; t = x; x = y; y = t;}while(0)

void insertion(int a[], int n)
{
  int i, j;

  for(i = 1; i < n; i++){
    int tmp = a[i];

    for(j = i; j > 0 && a[j - 1] > tmp; j--){
      a[j] = a[j - 1];
    }
    a[j] = tmp;
  }
}

int main(void)
{
  int i;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を入力せよ。\n", nx);
  for(i = 0; i < nx; i++){
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  insertion(x, nx);

  puts("昇順にソートしました。");
  for(i = 0; i < nx; i++){
    printf("x[%d] = %d\n", i, x[i]);
  }

  return (0);
}
