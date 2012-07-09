typedef struct {
  int no;
  char name[10];
} Data;

typedef struct __node {
  Data data;
  struct __node *prev;
  struct __node *next;
} Dnode;

typedef struct {
  Dnode *head;
  Dnode *crnt;
} Dlist;

Dnode *AllocDnode(void)
{
  return ((Dnode *)calloc(1, sizeof(Dnode)));
}

void InitDlist(Dlist *list)
{
  Dnode *dummyNode = AllocDnode();
  list->head = list->crnt = dummyNode;
  dummyNode->prev = dummyNode->next = dummyNode;
}

void SetDnode(Dnode *n, Data x, Dnode *prev, Dnode *next)
{
  n->data = x;
  n->prev = prev;
  n->next = next;
}

int isEmptylist(Dlist *list)
{
  return ((list->head)->next == list->head);
}
