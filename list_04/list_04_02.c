#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int max;
  int num;
  int front;
  int rear;
  int *que;
} Queue;

int QueueAlloc(Queue *q, int max)
{
  q->num = q->front = q->rear = 0;
  if((q->que = calloc(max, sizeof(int))) == NULL ){
    q->max = 0;
    return (-1);
  }
  q->max = max;

  return (0);
}


void QueueFree(Queue *q)
{
  if(q->que != NULL){
    free(q->que);
    q->max = q->num = q->front = q->rear = 0;
  }
}

int QueueEnque(Queue *q, int x)
{
  if(q->num >= q->max){
    return (-1);
  }else{
    q->num++;
    q->que[q->rear++] = x;
    if(q->rear == q->max){
      q->rear = 0;
    }
    return (0);
  }
}

int QueueDeque(Queue *q, int *x)
{
  if(q->num <= 0){
    return (-1);
  }else{
    q->num--;
    *x = q->que[q->front++];
    if(q->front == q->max){
      q->front = 0;
    }
    return (0);
  }
}

int QueueSize(const Queue *q)
{
  return (q->max);
}

int QueueNo(const Queue *q)
{
  return (q->num);
}

int QueueIsEmpty(const Queue *q)
{
  return (q->num <= 0);
}

int QueueIsFull(const Queue *q)
{
  return (q->num >= q->max);
}

int main(void)
{
  Queue que;
  
  if(QueueAlloc(&que, 100) == -1){
    puts("キューの確保に失敗しました。");
    return (1);
  }
  
  while(1){
    int m, x;

    printf("現在のデータ数：%d/%d\n", QueueNo(&que), QueueSize(&que));
    printf("（１）エンキュー （２）デキュー （０）終了：");
    scanf("%d", &m);

    if(m == 0){
      break;
    }

    switch (m){
    case 1:
      printf("データ：");
      scanf("%d", &x);
      if(QueueEnque(&que, x) == -1){
	puts("データのエンキューに失敗しました。");
      }
      break;
    case 2:
      if(QueueDeque(&que, &x) == -1){
	puts("デキュー出来ませんん。");
      }else{
	printf("デキューしたデータは%dです。\n", x);
      }
      break;
    }
  }

  QueueFree(&que);

  return (0);
}
