void InsertAfter(Dlist *list, Dnode *p, Data x)
{
  Dnode *ptr = AllocDnode();
  Dnode *nxt = p->next;

  p->next = (p->next)->prev = ptr;
  SetDnode(ptr, x, p, nxt);
  list->crnt = ptr;
}

void InsertFront(Dlist *list, Data x)
{
  InsertAfter(list, list->head, x);
}

void InsertRear(Dlist *list, Data x)
{
  InsertAfter(list, (list->head)->prev, x);
}
