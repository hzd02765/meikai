#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
  int i;
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

  srand(time(NULL));
  for(i = 0; i < nx; i++){
    x[i] = rand() % 100;
    printf("x[%d] = %d \n", i, x[i]);
  }

  printf("最大値は%dです。 \n", maxof(x, nx));

  return (0);
}
