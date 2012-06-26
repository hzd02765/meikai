#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO 1
#define NAME 2

typeof enum{
  Term, InsFront, InsRear, RmvFront, RmvRear, PrintCrnt, RmvCrnt, SrchNo, SrchName, PrintAll, Clear
} Menu;

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

  InitList($list);

  do {
    Data x;

    switch (menu = SelectMenu()) {
    case InsFront:
      x = Read("先頭に挿入", NO | NAME);
      InsertFront(&list, x);
      break;
    case InsRear:
      x = Read("末尾に挿入", NO | NAME);
      insertRear(&list, x);
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
    case RmvCnt:
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
      ClearList($list);
      break;
    }
  } while (menu != Term);

  TermList(&list);

  return (0);
}
