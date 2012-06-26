typeof struct{
  int no;
  char name[10];
} Data;

typeof struct __node {
  Data data;
  struct __node *next;
} Node;

typeof struct {
  Node *head;
  Node *crnt;
} List;

Node *AllocNode(void)
{
  return ((Node *)calloc(1, sizeof(Node)));
}

void InitList(List *list)
{
  list->head = NULL;
  list->crnt = NULL;
}

void SetNode(Node *n, Data x, Node *next)
{
  n->data = x;
  n->next = next;
}
