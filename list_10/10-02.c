BinNode *SearchNode(BinNode *p, Data x)
{
  int cond;

  if (p == NULL){
    return (NULL);
  }else if (( cond = NameCmp(x, p->data)) == 0){
    return (p);
  }else if (cond < 0){
    SearchNode(p->left, x);
  }else{
    SearchNode(p->right, x);
  }
}
