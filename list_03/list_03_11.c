#include <stdio.h>
#include <stdlib.h>

#define NO 1
#define NAME 2

typedef enum{
  Term, Insert, Delete, SrchNo, Dump
} Menu;

typedef struct{
  int no;
  char name[10];
} Data;

typedef struct __node{
  Data data;
  struct __node *next;
} Node;

typedef struct{
  int size;
  Node **table;
} Hash;

int hash(int key)
{
  return (key % 13);
}

void SetNode(Node *n, Data x, Node *next)
{
  n->data = x;
  n->next = next;
}

int InitHash(Hash *h, int size)
{
  int i;

  h->size = 0;
  if((h->table = calloc(size, sizeof(Node *))) == NULL)
    {
      return (0);
    }
  
  h->size = size;
  for(i = 0; i < size; i++){
    h->table[i] = NULL;
  }
}

void TermHash(Hash *h)
{
  int i;
  for(i = 0; i < h->size; i++){
    Node *p = h->table[i];
    while(p != NULL){
      Node *next = p->next;
      free(p);
      p = next;
    }
  }
  free(h->table);
}

Node *SearchNode(Hash *h, Data x)
{
  int key = hash(x.no);
  Node *p = h->table[key];

  while(p != NULL){
    if(p->data.no == x.no){
      return (p);
    }
    p = p->next;
  }
  return (NULL);
}

int InsertNode(Hash *h, Data x)
{
  int key = hash(x.no);
  Node *p = h->table[key];
  Node *temp;

  while(p != NULL){
    if(p->data.no == x.no){
      return (1);
    }
    p = p->next;
  }

  if((temp = (Node *)calloc(1, sizeof(Node))) == NULL){
    return (2);
  }

  SetNode(temp, x, h->table[key]);
  h->table[key] = temp;

  return (0);
}

int DeleteNode(Hash *h, Data x)
{
  int key = hash(x.no);
  Node *p = h->table[key];
  Node **pp = &h->table[key];

  while(p != NULL){
    if(p->data.no == x.no){
      *pp = p->next;
      free(p);
      return (0);
    }
    pp = &p->next;
    p = p->next;
  }

  return (1);
}

void DumpHash(Hash *h)
{
  int i;
  
  for(i = 0; i < h->size; i++){
    Node *p = h->table[i];
    printf("%02d ", i);
    while(p != NULL){
      printf("→ %d (%s)  ", p->data.no, p->data.name);
      p = p->next;
    }
    putchar('\n');
  }
}

void PrintData(Data x)
{
  printf("%d %s\n", x.no, x.name);
}

Data Read(char *message, int sw)
{
  Data temp;
  
  printf("%sするでーたを入力してください。\n", message);

  if(sw & NO){
    printf("番号：");
    scanf("%d", &temp.no);
  }

  if(sw & NAME){
    printf("名前：");
    scanf("%s", temp.name);
  }
  
  return (temp);
}

Menu SelectMenu(void)
{
  int i, ch;

  do{
    printf("（１）追加 （２）削除 （３）探索 （４）だんぷ （０）終了 ：");
    scanf("%d", &ch);
  } while(ch < Term || ch > Dump);

  return ((Menu)ch);
}

int main(void)
{
  Menu menu;
  Hash hash;

  InitHash(&hash, 13);

  do{
    int result;
    Data x;
    Node *temp;

    switch(menu = SelectMenu()){
    case Insert:
      x = Read("追加", NO | NAME);
      result = InsertNode(&hash, x);
      if(result){
	printf("追加に失敗しました", (result == 1) ? "登録済み" : "メモり不足");
      }
      break;
    case Delete:
      x = Read("削除", NO);
      result = DeleteNode(&hash, x);
      if(result == 1){
	printf("その番号のでーたは存在しませんん。\n");
      }
      break;
    case SrchNo:
      x = Read("探索", NO);
      temp = SearchNode(&hash, x);
      if(temp == NULL){
	printf("探索に失敗しました。\n");
      }else{
	printf("探索に成功しました。\n");
	PrintData(temp->data);
      }
      break;
    case Dump:
      DumpHash(&hash);

      break;
    }
  } while(menu != Term);

  TermHash(&hash);

  return (0);
}
