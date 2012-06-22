#include <stdio.h>
#include <string.h>

int main(void)
{
  char s1[80], s2[80];
  char *p;

  printf("テキスト：");
  scanf("%s", s1);

  printf("パターン：");
  scanf("%s", s2);

  p = strstr(s1, s2);

  if (p == NULL){
    printf("テキスト中にパターンは存在しません。\n");
  }else{
    int ofs = p - s1;
    printf("\n%s\n", s1);
    printf("%*s|\n", ofs, "");
    printf("%*s%s\n", ofs, "", s2);
  }

  return (0);
}
