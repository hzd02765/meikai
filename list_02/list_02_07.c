#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y, y = t;} while (0)

void ary_reverse(int a[], int n)
{
  int i;

  for (i = 0; i < n / 2; i++){
    swap(int, a[i], a[n - i - 1]);
  }
}

int main(void)
{
  int i;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を入力してください。\n", nx);
  for(i = 0; i < nx; i++){
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  ary_reverse(x, nx);

  printf("配列の要素の並びを逆転しました。\n");
  for(i = 0; i < nx; i++){
    printf("x[%d] : %d\n", i, x[i]);
  }

  return (0);
}
