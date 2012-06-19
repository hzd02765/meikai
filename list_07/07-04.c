#include <stdio.h>
#include "bsetlib.h"

int BsetMember(Bset s, int n)
{
  return (s & Bsetof(n));
}

void BsetInsert(Bset *s, int n)
{
  *s /= Bsetof(n);
}

void BsetDelete(Bset *s, int n)
{
  *s &= ~Bsetof(n);
}

int BsetMemNum(Bset s)
{
  int n = 0;

  for( ; s != BsetNull; n++){
    s &= s -1;
  }
  
  return (n);
}

Bset BsetDifference(Bset s1, Bset s2)
{
  return (s1 & ~s2);
}

void BsetPrint(Bset s)
{
  int i;
  
  printf("{ ");
  for (i = 0; i < BsetBIT; i++){
    if (BsetMember(s, i)){
      printf("%d", i);
    }
  }
  printf("}\n");
}

char *BsetStr(Bset s, char *buff)
{
  int i;
  char *save = buff;
  
  for (i = 0; i < BsetBIT; i++){
    *buff++ = ((s & BsetOne)  ? '0' + i % 10 : '-');
    s >>= 1;
  }
  *buff = '\0';
  return (save);
}

void Print(const char *msg, Bset x)
{
  char buffer[33];

  printf("%s%s\n", msg, BsetStr(x, buffer));
}

void PrintUID(Bset s1, Bset s2)
{
  Bset s3;

  printf("s1 = ");
  BsetPrint(s1);
  printf("s2 = ");
  BsetPrint(s2);

  printf("s1 | s2 = ");
  BsetPrint(s1 | s2);

  printf("s1 & s2 = ");
  BsetPrint(s1 & s2);

  s3 = BsetDifference(s1, s2);
  printf("s1 - s2 = ");
  BsetPrint(s3);
}

int main(void)
{
  int i;
  Bset s1 = BsetNull, s2;

  for (i = 1; i < 32; i += 4){
    BsetInsert(&s1, i);
  }
  s2 = s1;

  Print("s1 = ", s1);
  Print("s2 = ", s2);

  while (1){
    int m, x;

    PrintUID(s1, s2);
    printf("(1) s2に追加　(2) s2から削除　 (3) 終了：");
    scanf("%d", &m);

    if( m == 0){
      break;
    }

    switch (m){
    case 1:
      printf("データ：");
      scanf("%d", &x);
      BsetInsert(&s2, x);
      break;
    case 2:
      printf("データ：");
      scanf("%d", &x);
      BsetDelete(&s2, x);
      break;
    }
  }

  return (0);
}
