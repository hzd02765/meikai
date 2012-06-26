void InsertRear(List *list, Data x)
{
  if (list->head == NULL){
    InsertFront (list, x);
  }else{
    node *ptr = list->head;
    while (ptr->next != NULL){
      ptr = ptr->next;
    }
    ptr->next = list->crnt = AllocNode();
    SetNode(ptr->next, x, NULL);
  }
}
