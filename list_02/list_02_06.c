#include <stdio.h>

void ary_reverse(int a[], int n)
{
  int i;

  for(i = 0; i < n/2; i++){
    int t = a[i];

    a[i] = a[n - i - 1];
    a[n - i - 1] = t;
  }  
}

int main(void)
{
  int i;
  int a[5] = {1, 2, 3, 4, 5};
  int n = sizeof(a) / sizeof(a[0]);

  for(i = 0; i < n; i++){
    printf("%d \n", a[i]);
  }
  printf("\n");

  ary_reverse(a, n);

  for(i = 0; i < n; i++){
    printf("%d \n", a[i]);
  }

  return (0);
}
