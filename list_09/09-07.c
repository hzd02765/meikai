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
