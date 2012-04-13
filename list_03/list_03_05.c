#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
  if(*a < *b){
    return (-1);
  }else if(*a > *b){
    return (1);
  }else{
    return (0);
  }
}

int main(void)
{
  int i, ky, *p;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を昇順に入力してください。\n", nx);
  
  printf("x[0]:");
  scanf("%d", &x[0]);

  for(i = 1; i < nx; i++){
    do{
      printf("x[%d]:", i);
      scanf("%d", &x[i]);
    }while (x[i] < x[i - 1]);
  }

  printf("搜す値:");
  scanf("%d", &ky);

  p = bsearch(&ky, 
	      x, 
	      nx, 
	      sizeof(int), 
	      (int (*)(const void *, const void * ))int_cmp
	      );

  if(p == NULL){
    puts("探索に失敗しました。");
  }else{
    printf("%dは%d番目にあります。\n", ky, (int)(p - &x[0]) + 1);
  }

  return (0);
}
