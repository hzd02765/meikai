#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm_match(const char txt[], const char pat[])
{
  int pt;
  int pp;
  int txt_len = strlen(txt);
  int pat_len = strlen(pat);
  int skip[UCHAR_MAX + 1];

  for (pt = 0; pt <= UCHAR_MAX; pt++){
    skip[pt] = pat_len;
  }
  for (pt = 0; pt < pat_len - 1; pt++){
    skip[pat[pt]] = pat_len - pt - 1;
  }

  while (pt < txt_len){
    pp = pat_len - 1;

    while (txt[pt] == pat[pp]){
      if (pp == 0){
	return (pt);
      }
      pp--;
      pt--;
    }
    pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
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

  printf("パターン");
  scanf("%s", s2);

  idx = bm_match(s1, s2);

  if (idx == -1){
    puts("テキスト中にパターンは存在しません。");
  }else{
    printf("%d文字目に見つかりました。\n", idx + 1);
  }

  return (0);
}
