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
