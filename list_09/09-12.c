#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO 1
#define NAME 2
#define Null -1

typedef enum{
  Term, InsFront, InsRear, RmvFront, RmvRear, PrintCrnt, RmvCrnt, SrchNo, SrchName, PrintAll, Clear
} Menu;

typedef struct{
  int no;
  char name[10];
} Data;

typedef int index;

typedef struct{
  Data data;
  Index next;
  Index Dnext;
} Node;

typedef struct{
  Node *n;
  Index head;
  Index max;
  Index deleted;
  Index crnt;
} List;

int NoEqual(Data x, Data y)
{
  return (x.no == y.no);
}

int NameEqual(Data x, Data y)
{
  return (strcmp(x.name, y.name) == 0);
}

void SetNode(Node *n, Data x, Index next){
  n->data = x;
  n->next = next;
}

void InitList(List *list, int size)
{
  list->n = (Node *)calloc(size, sizeof(Node));
  list->head = Null;
  list->crnt = Null;
  list->max = Null;
  list->deleted = Null;
}

Index GetIndex(List *list)
{
  if (list->deleted == Null){
    return (++(list->max));
  }else{
    Index rec = list->deleted;
    list->deleted = list->n[rec].Dnext;
    return (rec);
  }
}

void DeleteIndex(List *list, Index idx)
{
  if (list->deleted == Null){
    list->deleted = idx;
    list->n[idx].Dnext = Null;
  }else{
    Index ptr = list->deleted;
    list->deleted = idx;
    list->n[idx].Dnext = ptr;
  }
}


void InsertFront(List *list, Data x)
{
  Index ptr = list->head;
  list->head = list->crnt = GetIndex(list);
  SetNode(&list->n[list->head], x, ptr);
}

void InsertRear(List *list, Data x)
{
  if (list->head == Null){
    InsertFront(list, x);
  }else{
    Index ptr = list->head;
    while (list->n[ptr].next != Null){
      ptr = list->n[ptr].next;
    }
    list->n[ptr].next = list->crnt = GetIndex(list);
    SetNode(&list->n[list->n[ptr].next], x, Null);
  }
}

void RemoveFront(List *list)
{
  if (list->head != Null){
    Index ptr = list->n[list->head].next;
    DeleteIndex(list, list->head);
    list->head = list->crnt = ptr;
  }
}

void RemoveRear(List *list)
{
  if (list->head != Null){
    if (list->n[list->head].next == Null){
      RemoveFront(list);
    }else{
      Index ptr = list->head;
      Index pre;

      while (list->n[ptr].next != Null){
	pre = ptr;
	ptr = list->n[ptr].next;
      }
      list->n[pre].next = Null;
      DeleteIndex(list, ptr);
      list->crnt = pre;
    }
  }
}

void RemoveCrnt(List *list)
{
  if (list->head != Null){
    if (list->crnt == list->head){
      RemoveFront(list);
    }else{
      Index ptr = list->head;

      while (list->n[ptr].next != list->crnt){
	ptr = list->n[ptr].next;
      }
      list->n[ptr].next = list->n[list->crnt].next;
      DeleteIndex(list, list->crnt);
      list->crnt = ptr;
    }
  }
}

void ClearList(List *list)
{
  while (list->head != Null){
    RemoveFront(list);
  }
  list->crnt = Null;
}

Index SearchNode(List *list, Data x, int equal(Data x, Data y))
{
  Index ptr = list->head;
  while (ptr != Null){
    if (equal(list->n[ptr].data, x)){
      list->crnt = ptr;
      return (ptr);
    }
    ptr = list->n[ptr].next;
  }
  return (Null);
}

void TermList(List *list)
{
  ClearList(list);
  free(list->n);
}

void PrintData(Data x)
{
  printf("番号：%s 氏名：%x\n", x.no, x.name);
}

void PrintCrntNode(const List *list)
{
  if (list->crnt = Null){
    puts("着目要素はありません。");
  }else{
    PrintData(list->n[list->crnt].data);
  }
}

void PrintList(const List *list)
{
  if (list->head == Null){
    puts("ノードがありません。");
  }else{
    Index ptr = list->head;

    puts("【一覧表】");
    while (ptr != Null){
      PrintData(list->n[ptr].data);
      ptr = list->n[ptr].next;
    }
  }
}

Data Read(const char *message, int sw)
{
  Data temp;
  
  printf("%sするデータを入力してください。\n", message);
  if (sw & NO){
    printf("番号:");
    scanf("%d", &temp.no);
  }
  if (sw & NAME){
    printf("名前:");
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
    "番号で探索", "氏名で探索", "全ノードを表示",
    "",
  };

  do {
    for (i = Term; i < Clear; i++){
      printf("(%2d) %-18.18s ", i + 1, mstring[i]);
      if ((i % 3) == 2){
	putchar('\n');
      }
    }
    printf("(0)終了：");
    scanf("%d", &ch);
  } while (ch < Term || ch > Clear);

  return ((Menu)ch);
}
