#include <stdio.h>

int maxof(const int a[], int n)
{
  int i ;
  int max = a[0];

  for(i = 1; i < n; i++){
    if(a[i] > max){
      max = a[i];
    }
  }
  return (max);
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

  printf("最大値は%dです。 \n", maxof(x, nx));

  return (0);
}
