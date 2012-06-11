#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void bubble(int a[], int n)
{
  int k = 0;

  while(k < n - 1){
    int j;
    int last = n - 1;

    for(j = n - 1; j > k; j--){
      if(a[j - 1] > a [j]){
	swap(int, a[j - 1], a[j]);
	last = j;
      }
    }
    k = last;
  }
}


int main(void)
{
  int i;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を入力せよ。\n", nx);
  for(i = 0; i < nx; i++){
    printf("x[%d]:", i);
    scanf("%d", &x[i]);
  }

  bubble(x, nx);


  puts("昇順にソートしました。");
  for(i = 0; i < nx; i++){
    printf("x[%d] = %d\n", i , x[i]);
  }

  return (0);
}
