typedef struct {
  int no;
  char name[10];
} Data;

typedef struct __bnode {
  Data data;
  struct __bnode *left;
  struct __bnode *right;
} BinNode;

int NameCmp(Data x, Data y)
{
  return (strcmp(x.name, y.name));
}

BinNode *AllocNode(void)
{
  return ((BinNode *)calloc(1, sizeof(BinNode)));
}

void SetBinNode(BinNode *n, Data x, BinNode *left, BinNode *right)
{
  n->data = x;
  n->left = left;
  n->right = right;
}
