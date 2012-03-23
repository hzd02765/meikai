#include <stdio.h>

int card_convr(unsigned x, int n, char d[])
{
  char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int digits = 0;

  if(x == 0){
    d[digits++] = dchar[0];
  }else{
    while(x){
      d[digits++] = dchar[x % n];
      x /= n;
    }
  }
  return (digits);
}

int main(void)
{
  int i;
  unsigned no;
  int cd;
  int dno;
  char cno[100];
  int retry;

  do{
    printf("正の整数値を入力してください。：");
    scanf("%u", &no);

    do{
      printf("何進数に変換しますか(2-36):");
      scanf("%d", &cd);
    }while(cd < 2 || cd > 36);

    dno = card_convr(no, cd, cno);

    printf("%d進数では", cd);
    for(i = dno - 1; i >= 0; i--){
      printf("%c", cno[i]);
    }
    printf("です。\n");

    printf("もう一度しますか(１・・・はい / ２・・・いいえ) :");
    scanf("%d", &retry);
  }while (retry == 1);
  
  return (0);
}
