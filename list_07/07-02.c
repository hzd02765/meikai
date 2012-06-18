#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int max;
  int num;
  int *set;
} Set;

int SetAlloc(Set *s, int max)
{
  s->max = s->num = 0;
  if ((s->set = (int * )calloc(max, sizeof(int))) == NULL){
    s->max = 0;
    return (-1);
  }
  s->max = max;
  return (0);
}

void SetFree(Set *s)
{
  if(s->set != NULL){
    free(s->set);
    s->max = s->num = 0;
  }
}

int SetMember(const Set *s, int n)
{
  int i;

  for(i = 0; i < s->num; i++){
    if (s->set[i] == n){
      return (i);
    }
  }
  return (-1);
}

void SetInsert(Set *s, int n)
{
  if (s->num < s->max && SetMember(s, n) == -1){
    s->set[s->num++] = n;
  }
}

void SetDelete(Set *s, int n)
{
  int idx;
  
  if (s->num > 0 && (idx = SetMember(s, n)) != -1){
    int i;

    --s->num;
    for(i = idx; i < s->num; i++){
      s->set[i] = s->set[i + 1];
    }
  }
}

int SetMemMax(const Set *s)
{
  return (s->max);
}

int SetMemNum(const Set *s)
{
  return (s->num);
}

void SetAssign(Set *s1, const Set *s2)
{
  int i;

  for (i = 0; i < s2->num; i++){
    s1->set[i] = s2->set[i];
  }
  s1->num = s2->num;
}

void SetUnion(Set *s1, const Set *s2, const Set *s3)
{
  int i;

  SetAssign(s1, s2);
  for (i  = 0; i < s3->num; i++){
    SetInsert(s1, s3->set[i]);
  }
}

void SetIntersection(Set *s1, const Set *s2, const Set *s3)
{
  int i, j;

  s1->num = 0;
  for (i = 0; i < s2->num; i++){
    for (j = 0; j < s3->num; j++){
      if (s2->set[i] == s3->set[j]){
	s1->set[s1->num++] = s2->set[i];
      }
    }
  }
}

void SetDifference(Set *s1, const Set *s2, const Set *s3)
{
  int i, j;

  s1->num = 0;
  for (i = 0; i < s2->num; i++){
    for (j = 0; j < s3->num; j++){
      if (s2->set[i] == s3->set[j]){
	break;
      }
    }
    if (j == s3->num){
      s1->set[s1->num++] = s2->set[i];
    }
  }
}

void SetPrint(const Set *s)
{
  int i;

  printf("{ ");
  for (i = 0; i < s->num; i++){
    printf("%d ", s->set[i]);
  }
  printf("}\n");
}

void PrintUID(const Set *s1, const Set *s2)
{
  Set s3;

  if (SetAlloc(&s3, 10) == -1){
    puts("集合の確保に失敗しました。");
    return;
  }

  printf("s1 = ");
  SetPrint(s1);
  printf("s2 = ");
  SetPrint(s2);

  SetUnion(&s3, s1, s2);
  printf("s1 | s2 = ");
  SetPrint(&s3);

  SetIntersection(&s3, s1, s2);
  printf("s1 & s2 = ");
  SetPrint(&s3);

  SetDifference(&s3, s1, s2);
  printf("s1 - s2 = ");
  SetPrint(&s3);
}

int main(void)
{
  Set s1, s2, s3;

  if (SetAlloc(&s1, 10) == -1 || SetAlloc(&s2, 10) == -1){
    puts("集合の確保に失敗しました。");
    return (1);
  }

  SetInsert(&s1, 10);
  SetInsert(&s1, 15);
  SetInsert(&s1, 20);
  SetInsert(&s1, 25);

  SetAssign(&s2, &s1);

  while (1){
    int m, x;

    PrintUID(&s1, &s2);
    printf("(1) s2に追加　(2) s2から削除　(0)終了：");
    scanf("%d", &m);
    
    if (m == 0){
      break;
    }

    switch (m){
    case 1:
      printf("データ：");
      scanf("%d", &x);
      SetInsert(&s2, x);
      break;
    case 2:
      printf("データ：");
      scanf("%d", &x);
      SetDelete(&s2, x);
      break;
    }
  }

  SetFree(&s1);
  SetFree(&s2);

  return (0);
}
