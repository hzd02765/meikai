int NoEqual(Data x, Data y)
{
  return (x.no == y.no);
}

int NameEqual(Data x, Data y)
{
  return (strcmp(x.name, y.name) == 0);
}

Dnode *SearchNode(Dlist *list, Data x, int equal(Data x, Data y))
{
  Dnode *ptr = (list->head)->next;

  while (ptr != list->head){
    if (equal(ptr->data, x)){
      list->crnt = ptr;
      return (ptr);
    }
    ptr = ptr->next;
  }
  return (NULL);
}
