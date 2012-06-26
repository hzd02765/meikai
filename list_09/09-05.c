void RemoveFront (List *list)
{
  if (list->head != NULL){
    Node *ptr = (list->head)->next;
    free(list->head);
    list->head = list->crnt = ptr;
  }
}
