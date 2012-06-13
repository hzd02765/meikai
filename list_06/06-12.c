#include <stdio.h>

void merge(int a[], int na, int b[], int nb, int c[])
{
  int pa = 0;
  int pb = 0;
  int pc = 0;
  
  while(pa < na && pb < nb){
    c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
  }
  while(pa < na){
    c[pc++] = a[pa++];
  }
  while(pb < nb){
    c[pc++] = b[pb++];
  }
}

int main(void)
{
  int i;
  int a[6] = {1, 3, 5, 7, 9, 10};
  int b[7] = {0, 1, 2, 3, 8, 15, 19};
  int c[13];

  merge(a, 6, b, 7, c);

  puts("配列aとbをマージして配列cに格納しました。");
  for(i = 0; i < 13; i++){
    printf("c[%2d] = %2d\n", i, c[i]);
  }

  return (0);
}
