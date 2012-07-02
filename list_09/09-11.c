#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO 1
#define NAME 2

typedef enum{
  Term, InsFront, InsRear, RmvFront, RmvRear, PrintCrnt, RmvCrnt, SrchNo, SrchName, PrintAll, Clear
} Menu;

typedef struct{
  int no;
  char name[10];
} Data;

typedef struct __node{ 
  Data data;
  struct __node *next;
}Node;

typedef struct {
  Node *head;
  Node *crnt;
} List;

Node *AllocNode(void)
{
  return ((Node *)calloc(1, sizeof(Node)));
}

void InitList(List *list)
{
  list->head = NULL;
  list->crnt = NULL;
}

void SetNode(Node *n, Data x, Node *next)
{
  n->data = x;
  n->next = next;
}

int NoEqual(Data x, Data y)
{
  return (x.no == y.no);
}

int NameEqual(Data x, Data y)
{
  return (strcmp(x.name, y.name) == 0);
}

Node *SearchNode(List *list, Data x, int equal(Data x, Data y))
{
  Node *ptr = list->head;

  while (ptr != NULL){
    if (equal(ptr->data, x)){
	list->crnt = ptr;
	return (ptr);
    }
    ptr = ptr->next;
  }
  return (NULL);
}

void InsertFront(List *list, Data x)
{
  Node *ptr = list->head;
  list->head = list->crnt = AllocNode();
  SetNode(list->head, x, ptr);
}

void InsertRear(List *list, Data x)
{
  if (list->head == NULL){
    InsertFront(list, x);
  }else{
    Node *ptr = list->head;
    while (ptr->next != NULL){
      ptr = ptr->next;
    }
    ptr->next = list->crnt = AllocNode();
    SetNode(ptr->next, x, NULL);
  }
}

void RemoveFront(List *list)
{
  if (list->head != NULL){
    Node *ptr = (list->head)->next;
    free(list->head);
    list->head = list->crnt = ptr;
  }
}

void RemoveRear(List *list)
{
  if (list->head != NULL){
    if((list->head)->next == NULL){
      RemoveFront(list);
    }else{
      Node *ptr = list->head;
      Node *pre;

      while (ptr->next != NULL){
	pre = ptr;
	ptr = ptr->next;
      }
      pre->next = NULL;
      free(ptr);
      list->crnt = pre;
    }
  }
}

void RemoveCrnt(List *list)
{
  if (list->head != NULL){
    if (list->crnt == list->head){
      RemoveFront(list);
    }else{
      Node *ptr = list->head;

      while (ptr->next != list->crnt){
	ptr = ptr->next;
      }
      ptr->next = list->crnt->next;
      free(list->crnt);
      list->crnt = ptr;
    }
  }
}

void ClearList(List *list)
{
  while (list->head != NULL){
    RemoveFront(list);
  }
  list->crnt = NULL;
}

void PrintData(Data x){
  printf("番号：%d 氏名：%s\n", x.no, x.name);
}
void PrintCrntNode(List *list)
{
  if (list->crnt == NULL){
    puts("着目要素はありません。");
  }else{
    PrintData(list->crnt->data);
  }
}

void PrintList(List *list)
{
  if (list->head == NULL){
    puts("ノードがありません。");
  }else{
    Node *ptr = list->head;

    puts("【一覧表】");
    while (ptr != NULL){
      PrintData(ptr->data);
      ptr = ptr->next;
    }
  }
}

void TermList(List *list)
{
  ClearList(list);
}

Data Read(const char *message, int sw)
{
  Data temp;
  printf("%sするデータを入力してください。\n", message);

  if (sw && NO) {
    printf("番号:");
    scanf("%d", &temp.no);
  }

  if (sw && NAME) {
    printf("名前:");
    scanf("%s", temp.name);
  }
}

Menu SelectMenu(void)
{
  int i, ch;
  char *mstring[] = {
    "先頭にノードを挿入", "末尾にノードを挿入", "先頭のノードを削除",
    "末尾のノードを削除", "着目ノードを表示", "着目ノードを削除"
    "番号で検索", "氏名で検索", "全ノードを表示",
    "全ノードを削除",
  };

  do{
    for (i = Term; i < Clear; i++){
      printf("(%2d) %-18.18s  ", i + 1, mstring[i]);
      if ((i % 3) == 2){
	putchar('\n');
      }
    }
    printf("( 0)終了 :");
    scanf("%d", &ch);
  } while (ch < Term || ch > Clear);

  return ((Menu)ch);
}

int main(void)
{
  Menu menu;
  List list;

  InitList(&list);

  do {
    Data x;

    switch (menu = SelectMenu()) {
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
      PrintCrntNode(&list);
      break;
    case RmvCrnt:
      RemoveCrnt(&list);
      break;
    case SrchNo:
      x = Read("探索", NO);
      if (SearchNode(&list, x, NoEqual) != NULL){
	PrintCrntNode(&list);
      }
      break;
    case SrchName:
      x = Read("探索", NAME);
      if(SearchNode(&list, x, NameEqual) != NULL){
	PrintCrntNode(&list);
      }
      break;
    case PrintAll:
      PrintList(&list);
      break;
    case Clear:
      ClearList(&list);
      break;
    }
  } while (menu != Term);

  TermList(&list);

  return (0);
}
