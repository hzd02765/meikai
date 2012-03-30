#include <stdio.h>

int search(int a[], int n, int key)
{
  int i = 0;
  
  a[n] = key;

  while(1){
    if(a[i] == key){
      break;
    }
    i++;
  }

  return (i == n ? -1 : i);
}

int main(void)
{
  int i, ky, idx;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を入力してください。\n", nx - 1);
  for(i = 0; i < nx - 1; i++){
    printf("x[%d]:", i);
    scanf("%d", &x[i]);
  }
  printf("探す値：");
  scanf("%d", &ky);

  idx = search(x, nx - 1, ky);

  if(idx == -1){
    puts("探索に失敗しました。\n");
  }else{
    printf("%dは%d番目にあります。\n", ky, idx + 1);
  }

  return (0);
}
