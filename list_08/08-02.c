#include <stdio.h>

int main(void)
{
  char st[10];

  st[0] = 'A';
  st[1] = 'B';
  st[2] = 'C';
  st[3] = 'D';
  st[4] = '\0';

  printf("文字列stには\"%s\"が格納されています。\n", st);

  return (0);
}
