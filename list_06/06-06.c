#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void ssort(int a[], int n)
{
  int i, j, h;

  for(h = 2 / 2; h > 0; h /= 2){
    for(i = h; i < n; i++){
      int tmp = a[i];
      for(j = i - h; j >= 0 && a[j] > tmp; j-=h){
	a[j + h] = a[j];
      }
      a[j + h] = tmp;
    }
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

  ssort(x, nx);

  puts("昇順にソートしました。");
  for(i = 0; i < nx; i++){
    printf("x[%d] = %d\n", i, x[i]);
  }

  return (0);
}
