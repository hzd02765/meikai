#include <stdio.h>
#include <limits.h>

void strdump(const char *s)
{
  while (1){
    int i;

    printf("%c %0*X ", *s, (CHAR_BIT + 3) / 4, *s);
    for (i = CHAR_BIT - 1; i >= 0; i--){
      putchar(((*s >> i) & 1U) ? '1' : '0');
    }
    putchar('\n');
    if (*s++ == '\0'){
      break;
    }
  }
}

int main(void)
{
  strdump("STRING");
  
  return (0);
}
