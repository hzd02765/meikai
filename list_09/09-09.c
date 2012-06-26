void PrintData(Data x)
{
  printf("番号:%d 氏名:%s\n", x.no, x.name);
}

void PrintCrntNode(List *list)
{
  if (list->crnt == NULL){
    puts("着目要素はありません。");
  }else{
    PrintData(list->crnt->data);
  }
}
