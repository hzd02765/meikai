#include <stdio.h>

int str_len(const char *s)
{
  int len = 0;

  while (s[len]){
    len++;
  }
  
  return (len);
}

int main(void)
{
  char str[100];

  printf("文字列: ");
  scanf("%s", str);

  printf("その文字列は%d文字です。\n", str_len(str));

  return (0);
}
