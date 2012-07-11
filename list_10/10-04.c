void PrintData(Data x)
{
  printf("番号：%d 氏名：%s\n", x.no, x.name);
}

void PrintTree(BinNode *p)
{
  if (p != NULL){
    PrintTree(p->left);
    PrintData(p->data);
    PrintTree(p->right);
  }
}
