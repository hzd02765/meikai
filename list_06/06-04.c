#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void selection(int a[], int n)
{
  int i, j;

  for(i = 0; i < n - 1; i++){
    int min = i;

    for(j = i + 1; j < n; j++){
      if(a[j] < a[min]){
	min = j;
      }
    }
    swap(int, a[i], a[min]);
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

  selection(x, nx);


  puts("昇順にソートしました。");
  for(i = 0; i < nx; i++){
    printf("x[%d] = %d\n", i , x[i]);
  }

  return (0);
}
