#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO 1
#define NAME 2

typedef enum {
  Term, Insert, Search, Print
} Menu;

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

BinNode *SearchNode(BinNode *p, Data x)
{
  int cond;

  if (p == NULL){
    return (NULL);
  }else if ((cond = NameCmp(x, p->data)) == 0){
    return (p);
  }else if (cond < 0){
    SearchNode(p->left, x);
  }else{
    SearchNode(p->right, x);
  }
}

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
  return (0);
}

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

void FreeTree(BinNode *p)
{
  if (p != NULL){
    FreeTree(p->left);
    FreeTree(p->right);
    free(p);
  }
}

Data Read(const char *message, int sw)
{
