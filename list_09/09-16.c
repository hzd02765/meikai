void PrintDlist(Dlist *list)
{
  if (isEmptyDlist(list)){
    puts("ソートがありません。");
  }else{
    Dnode *ptr = (list->head)->next;

    puts("【一覧表】");
    while (ptr != list->head){
      PrintData(ptr->data);
      ptr = ptr->next;
    }
  }
}
