#include <stdio.h>

int main(void){
  int i, j, n;

  printf("何段の三角形ですか：");
  scanf("%d", &n);

  for(i = 0; i <= n; i++){
    for(j = 1; j <= i; j++){
      putchar('*');
    }
    putchar('\n');
  }

  return (0);
}
