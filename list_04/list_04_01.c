#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int max;
  int ptr;
  int *stk;
} Stack;

int StackAlloc(Stack *s, int max)
{
  s->ptr = 0;
  if((s->stk = calloc(max, sizeof(int))) == NULL){
    s->max = 0;
    return (-1);
  }
  s->max = max;
  return (0);
}

void StackFree(Stack *s)
{
  if(s->stk != NULL){
    free(s->stk);
    s->max = s->ptr = 0;
  }
}

int StackPush(Stack *s, int x)
{
  if(s->ptr >= s->max){
    return (-1);
  }
  s->stk[s->ptr++] = x;
  return (0);
}

int StackPop(Stack *s, int *x)
{
  if(s->ptr <= 0){
    return (-1);
  }
  *x = s->stk[--s->ptr];
  return (0);
}

int StackPeek(const Stack *s, int *x)
{
  if(s->ptr <= 0){
    return (-1);
  }
  *x = s->stk[s->ptr - 1];
  return (0);
}

int StackSize(const Stack *s)
{
  return (s->max);
}

int StackNo(const Stack *s)
{
  return (s->ptr);
}

int StackIsEmpty(const Stack *s)
{
  return (s->ptr <= 0);
}

int StackIsFull(const Stack *s)
{
  return (s->ptr >= s->max);
}

void StackClear(Stack *s)
{
  s->ptr = 0;
}

int main(void)
{
  Stack s;
  
  if(StackAlloc(&s, 100) == -1){
    puts("すたっくの確保に失敗しました。");
    return (1);
  }
  
  while(1){
    int m, x;
    
    printf("現在のでーた数：%d/%d\n", StackNo(&s), StackSize(&s));
    printf("（１）ぷっしゅ （２）ぽっぷ （０）終了 ：");
    scanf("%d", &m);

    if(m == 0){
      break;
    }

    switch (m){
    case 1:
      printf("でーた：");
      scanf("%d", &x);
      if(StackPush(&s, x) == -1){
	puts("すたっくへのぷっしゅに失敗しました。");
      }
      break;
    case 2:
      if(StackPop(&s, &x) == -1){
	puts("ぽっぷできません。");
      }else{
	printf("ぽっぷしたでーたは%dです。\n", x);
      }
      break;
    }
  }

  StackFree(&s);

  return (0);
}
