#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO 1
#define NAME 2

typedef enum{
  Term, Insert, Delete, SrchNo, Dump
} Menu;

typedef enum{
  Occupied, Empty, Deleted
} Status;

typedef struct{
  int no;
  char name[10];
} Data;

typedef struct{
  Data data;
  Status stat;
} Bucket;

typedef struct{
  int size;
  Bucket *table;
} Hash;

int hash(int key)
{
  return (key % 13);
}

int rehash(int key)
{
  return ((key + 1) % 13);
}

void SetBucked(Bucket *n, Data x, Status stat)
{
  n->data = x;
  n->stat = stat;
}

int InitHash(Hash *h, int size)
{
  int i;
  h->size = 0;
  if((h->table = calloc(size, sizeof(Bucket))) == NULL){
    return (0);
  }
  h->size = size;
  for(i = 0; i < size; i++){
    h->table[i].stat = Empty;
  }
  return (1);
}

void TermHash(Hash *h)
{
  free(h->table);
}

Bucket *SearchBucket(Hash *h, Data x)
{
  int i;
  int key = hash(x.no);
  Bucket *P = &h->table[key];

  for(i = 0; p->stat != Empty && i < h->size; i++){
    if(p->stat == Occupied && p->data.no == x.no){
      return (p);
    }
    key = rehash(key);
    p = &h->table[key];
  }
  return (NULL);
}

int InsertBucket(Hash *h, Data x)
{
  int i;
  int key = hash(x.no);
  Bucket *p = &h->table[key];

  if(SearchBucket(h, x)){
    return (1);
  }

  for(i = 0; i < h->size; i++){
    if(p->stat == Empty || p->stat == Deleted){
      SetBucket(p, x, Occupied);
      return (0);
    }
    key = rehash(key);
    p = &h->table[key];
  }
}

int DeleteBucket(Hash *h, Data x)
{
  Bucket *p = SearchBucket(h, x);
  if(p == NULL){
    return (1);
  }
  p->stat = Deleted;
  return (0);
}

void DumpHash(Hash *h)
{
  int i;
  
  for(i = 0; i < h->size; i++){
    printf("%02d ：", i);
    switch(h->table[i].stat){
    case Occupied:
      printf("%d (%s) \n", h->table[i].data.no, h->table[i].data.name);
      break;
    case Empty:
      printf("ーー 未登録 ーー\n");
      break;
    case Deleted:
      printf("ーー 削除済 ーー\n");
      break;
    }
  }
}

void PrintData(Data x)
{
  printf("%d %s\n", x.no, x.name);
}

Data Read(char *message, int sw)
{
  Data temp;

  printf("%sするでーたを入力してください。\n", message);
  if(sw & NO){
    printf("番号：");
    scanf("%d", &temp.no);
  }
  if(sw & NAME){
    printf("名前：");
    scanf("%s", temp.name);
  }
  return (temp);
}

Menu SelectMenu(void)
{
  int i, ch;
  do{
    printf("（１）追加 （２）削除 （３）探索 （４）だんぷ （０）終了");
    scanf("%d", &ch);
  } while(ch < Term || ch > Dump);
  return ((Menu)ch);
}

int main(void)
{
  Menu menu;
  Hash hash;
  
  InitHash(&hash, 13);

  do{
    int result;
    Data x;
    Bucket *temp;

    switch(menu = SelectMenu()){
    case Insert:
      x = Read("追加", NO | NAME);
      result = InsertBucket(&hash, x);
      if(result){
	printf("追加に失敗しました(%s)。\n", (result == 1) ? "登録済み" : "表は満杯");
      }
      break;
    case Delete:
      x = Read("削除", NO);
      result = DeleteBucket(&hash, x);
      if(result == 1){
	printf("その番号のでーたは存在しません。\n");
      }
      break;
    case SrchNo:
      x = Read("探索", NO);
      temp = SearchBucket(&hash, x);
      if(temp == NULL){
	printf("探索に失敗しました。\n");
      }else{
	printf("探索に成功しました。\n");
	PrintData(temp->data);
      }
      break;
    case Dump:
      DumpHash(&hash);
      break;
    }
  } while (menu != Term);

  TermHash(&hash);

  return (0);
}
