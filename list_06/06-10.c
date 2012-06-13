#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

void quick(int a[], int left, int right)
{
  int ptr = 0;
  int lstack[100];
  int rstack[100];

  lstack[ptr] = left;
  rstack[ptr] = right;
  ptr++;

  while (ptr-- > 0){
    int pl = left = lstack[ptr];
    int pr = right = rstack[ptr];
    int x = a[(left + right) / 2];

    do{
      while (a[pl] < x) pl++;
      while (a[pr] > x) pr--;
      if(pl <= pr){
	swap(int, a[pl], a[pr]);
	pl++;
	pr--;
      }
    }while(pl <= pr);

    if(left < pr){
      lstack[ptr] = left;
      rstack[ptr] = pr;
      ptr++;
    }

    if(pl < right){
      lstack[ptr] = pl;
      rstack[ptr] = right;
      ptr++;
    }
  }
}

int main(void)
{
  int i;
  int x[9];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を入力せよ。\n", nx);
  for(i = 0; i < nx; i++){
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }

  quick(x, 0, nx - 1);
  
  puts("昇順にソートしました。");
  for(i = 0; i < nx; i++){
    printf("x[%d] = %d\n", i, x[i]);
  }

  return (0);
}
