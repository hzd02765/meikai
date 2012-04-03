#include <stdio.h>

int bin_search(const int a[], int n, int key)
{
  int pl = 0;
  int pr = n - 1;
  int pc;

  do{
    pc = (pl + pr) / 2;
    if(a[pc] == key){
      return (pc);
    }else if(a[pc] < key){
      pl = pc + 1;
    }else{
      pr = pc - 1;
    }
  } while(pl <= pr);

  return (-1);
}

int main(void)
{
  int i, ky, idx;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を昇順に入力してください。\n", nx);

  printf("x[0]:");
  scanf("%d", &x[0]);

  for(i = 1; i < nx; i++){
    do{
      printf("x[%d]:", i);
      scanf("%d", &x[i]);
    } while(x[i] < x[i - 1]);
  }
  printf("探す値:");
  scanf("%d", &ky);

  idx = bin_search(x, nx, ky);

  if(idx == -1){
    puts("探索に失敗しました。");
  }else{
    printf("%dは%d番目にあります。\n", ky, idx + 1);
  }

  return (0);
}
