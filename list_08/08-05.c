#include <stdio.h>

void swap_ptr(char **x, char **y)
{
  char *tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(void)
{
  char *s1 = "ABCD";
  char *s2 = "EFGH";

  printf("文字列s1は\"%s\"です。\n", s1);
  printf("文字列s2は\"%s\"です。\n", s2);

  swap_ptr(&s1, &s2);

  puts("ポインタs1とs2を交換しました。");

  printf("文字列s1は\"%s\"です。\n", s1);
  printf("文字列s2は\"%s\"です。\n", s2);
}
