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
