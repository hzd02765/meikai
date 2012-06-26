void InsertFront(List *list, Data x)
{
  Node *ptr = list->head;
  list->head = list->crnt = AllocNode();
  SetNode(list->head, x, ptr);
}
