#include <stdio.h>

int search(const int a[], int n, int key)
{
  int i;
  for(i = 0; i < n; i++){
    if(a[i] == key){
      return (i);
    }
  }
  return (-1);
}

int main(void)
{
  int i, ky, idx;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を入力してください。\n", nx);
  for(i = 0; i < nx; i++){
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }
  printf("探す値：");
  scanf("%d", &ky);

  idx = search(x, nx, ky);

  if(idx == -1){
    puts("探索に失敗しました。");
  }else{
    printf("%dは%d番目にあります。\n", ky, idx + 1);
  }

  return (0);
}
