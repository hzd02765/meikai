void ClearList(List *list)
{
  while (list->head != NULL){
    RemoveFront(list);
  }
  list->crnt = NULL;
}
