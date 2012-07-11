void FreeTree(BinNode *p)
{
  if (p != NULL){
    FreeTree(p->left);
    FreeTree(p->right);
    free(p);
  }
}
