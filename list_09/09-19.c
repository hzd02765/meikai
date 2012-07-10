#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO 1
#define NAME 2

typedef enum {
  Term, InsFront, InsRear, RmvFront, RmvRear, PrintCrnt, RmvCrnt, SrchNo, SrchName, PrintAll, Clear
} Menu;

typedef struct {
  int no;
  char name[10];
} Data;

typedef struct __node {
  Data data;
  struct __node *prev;
  struct __node *next;
} Dnode;

typedef struct {
  Dnode *head;
  Dnode *crnt;
} Dlist;

Dnode *AllocDnode(void)
{
  return ((Dnode *)calloc(1, sizeof(Dnode)));
}

void InitDlist(Dlist *list)
{
  Dnode *dummyNode = AllocDnode();
  list->head = list->crnt = dummyNode;
  dummyNode->prev = dummyNode->next = dummyNode;
}

void SetDnode(Dnode *n, Data x, Dnode *prev, Dnode *next)
{
  n->data = x;
  n->prev = prev;
  n->next = next;
}

int isEmptyDlist(Dlist *list)
{
  return ((list->head)->next == list->head);
}

int NoEqual(Data x, Data y)
{
  return (x.no == y.no);
}

int NameEqual(Data x, Data y)
{
  return (strcmp(x.name, y.name) == 0);
}

Dnode *SearchNode(Dlist *list, Data x, int equal(Data x, Data y))
{
  Dnode *ptr = (list->head)->next;

  while (ptr != list->head){
    if (equal(ptr->data, x)){
      list->crnt = ptr;
      return (ptr);
    }
    ptr = ptr->next;
  }
  return (NULL);
}

void PrintData(Data x)
{
  printf("番号：%d 氏名：%s\n", x.no, x.name);
}

void PrintCrntDnode(Dlist *list)
{
  if (isEmptyDlist(list)){
    puts("着目要素はありません。");
  }else{
    PrintData(list->crnt->data);
  }
}

void PrintDlist(Dlist *list)
{
  if (isEmptyDlist (list)){
    puts("ノードがありません。");
  }else{
    Dnode *ptr = (list->head)->next;

    puts("【一覧表】");
    while (ptr != list->head){
      PrintData(ptr->data);
      ptr = ptr->next;
    }
  }
}

void InsertAfter(Dlist *list, Dnode *p, Data x)
{
  Dnode *ptr = AllocDnode();
  Dnode *nxt = p->next;

  p->next = (p->next)->prev = ptr;
  SetDnode(ptr, x, p, nxt);
  list->crnt = ptr;
}

void InsertFront(Dlist *list, Data x)
{
  InsertAfter(list, list->head, x);
}

void InsertRear(Dlist *list, Data x)
{
  InsertAfter(list, (list->head)->prev, x);
}

void RemoveNode(Dlist *list, Dnode *p)
{
  (p->prev)->next = p->next;
  (p->next)->prev = p->prev;
  list->crnt = p->prev;
  free(p);
}

void RemoveFront(Dlist *list)
{
  if (!isEmptyDlist(list)){
    RemoveNode(list, (list->head)->next);
  }
}

void RemoveRear(Dlist *list)
{
  if (!isEmptyDlist(list)){
    RemoveNode(list, (list->head)->prev);
  }
}

void RemoveCrnt(Dlist *list)
{
  if (list->crnt != list->head){
    RemoveNode(list, list->crnt);
  }
}

void ClearDlist(Dlist *list)
{
  while (!isEmptyDlist(list)){
    RemoveFront(list);
  }
}

void TermDlist(Dlist *list)
{
  ClearDlist(list);
  free(list->head);
  list->head = list->crnt = NULL;
}

Data Read(const char *message, int sw)
{
  Data temp;

  printf("%sするデータを入力してください。\n", message);

  if (sw & NO){
    printf("番号：");
    scanf("%d", &temp.no);
  }
  if (sw & NAME){
    printf("名前：");
    scanf("%s", temp.name);
  }

  return (temp);
}

Menu SelectMenu(void)
{
  int i, ch;
  char *mstring[] = {
    "先頭にノードを挿入", "末尾にノードを挿入", "先頭のノードを削除",
    "末尾のノードを削除", "着目ノードを表示", "着目ノードを削除",
    "番号を検索", "氏名で検索", "全ノードを表示",
    "全ノードを削除",
  };

  do {
    for (i = Term; i < Clear; i++){
      printf("(%2d) %-18.18s  ", i + 1, mstring[i]);
      if((i % 3) == 2){
	putchar('\n');
      }
      printf("(0)終了：");
      scanf("%d", &ch);
    }
  } while (ch < Term || ch > Clear);

  return ((Menu)ch);
}

int main(void)
{
  Menu menu;
  Dlist list;
  
  InitDlist(&list);

  do {
    Data x;

    switch (menu = SelectMenu()){
    case InsFront:
      x = Read("先頭に挿入", NO | NAME);
      InsertFront(&list, x);
      break;
    case InsRear:
      x = Read("末尾に挿入", NO | NAME);
      InsertRear(&list, x);
      break;
    case RmvFront:
      RemoveFront(&list);
      break;
    case RmvRear:
      RemoveRear(&list);
      break;
    case PrintCrnt:
      PrintCrntDnode(&list);
      break;
    case RmvCrnt:
      RemoveCrnt(&list);
      break;
    case SrchNo:
      x = Read("探索", NO);
      if (SearchNode(&list, x, NoEqual) != NULL){
	PrintCrntDnode(&list);
      }
      break;
    case SrchName:
      x = Read("探索", NAME);
      if (SearchNode(&list, x, NameEqual) != NULL){
	PrintCrntDnode(&list);
      }
      break;
    case PrintAll:
      PrintDlist(&list);
      break;
    case Clear:
      ClearDlist(&list);
      break;
    }
  } while (menu != Term);

  TermDlist(&list);

  return (0);
}
