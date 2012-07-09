void RemoveNode(Dlist *list, Dnode *p)
{
  (p->prev)->next = p->next;
  (p->next)->prev = p->prev;
  list->crnt = p->prev;
  free(p);
}

void RemoveFront(Dlist *list)
{
  if (!isEmptyDlist(list)){
    RemoveNode(list, (list->head)->next);
  }
}

void RemoveRear(Dlist *list)
{
  if (!isEmptyDlist(list)){
    RemoveNode(list, (list->head)->prev);
  }
}

void RemoveCrnt(Dlist *list)
{
  if (list->crnt != list->head){
    RemoveNode(list, list->crnt);
  }
}

void ClearDlist(Dlist *list)
{
  while (!isEmptyDlist(list)){
    RemoveFront(list);
  }
}
