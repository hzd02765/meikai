int NoEqual(Data x, Data y)
{
  return (x.no == y.no);
}

int NameEqual(Data x, Data y)
{
  return (strcmp(x.name, y.name) == 0);
}

Node *SearchNode(List *list, Data x, int equal(Data x, Data y))
{
  Node *ptr = list->head;

  while (ptr != NULL){
    if (equal(ptr->data, x)){
      list->crnt = ptr;
      return (ptr);
    }
    ptr = ptr->next;
  }
  return (NULL);
}
