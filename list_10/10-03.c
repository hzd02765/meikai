BinNode *InsertNode(BinNode *p, Data x)
{
  int cond;

  if (p == NULL){
    p = AllocNode();
    SetBinNode(p, x, NULL, NULL);
  } else if ((cond = NameCmp(x, p->data)) == 0){
    printf("【エラー】%sは既に登録されています。\n", x.name);
  } else if (cond < 0){
    p->left = InsertNode(p->left, x);
  } else {
    p->right = InsertNode(p->right, x);
  }
  return (p);
}
