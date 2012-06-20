#include <stdio.h>
#include <string.h>

int main(void)
{
  char st[100];

  puts("\"STRING\"の先頭3文字と比較します。");
  puts("\"XXXX\"で終了します。");

  while (1){
    printf("文字列st:");
    scanf("%s", st);

    if (strcmp("XXXX", st) == 0){
      break;
    }
    printf("strncp(\"STRING\", st, 3) = %d\n", strncmp("STRING", st, 3));
  }

  return (0);
}
