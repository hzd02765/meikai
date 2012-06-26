void RemoveRear(List *list)
{
  if (list->head != NULL){
    if ((list->head)->next == NULL){
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
