#include <stdio.h>

int bf_match(const char txt[], const char pat[])
{
  int pt = 0;
  int pp = 0;

  while (txt[pt] != '\0' && pat[pp] != '\0'){
    if (txt[pt] == pat[pp]){
      pt++;
      pp++;
    }else{
      pt = pt - pp + 1;
      pp = 0;
    }
  }

  if (pat[pp] == '\0'){
    return (pt - pp);
  }

  return (-1);
}

int main(void)
{
  int idx;
  char s1[80];
  char s2[80];

  printf("テキスト：");
  scanf("%s", s1);

  printf("パターン：");
  scanf("%s", s2);

  idx = bf_match(s1, s2);

  if (idx = -1){
    puts("テキスト中にパターンは存在しません。");
  }else{
    printf("%d文字目に見つかりました。\n", idx + 1);
  }
  
  return (0);
}
