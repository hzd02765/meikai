#include <stdio.h>

#define VMAX 21

typedef struct{
  char name[20];
  int height;
  double vision;
}PhysCheck;

double ave_height(const PhysCheck dat[], int n)
{
  int i;
  double sum = 0;

  for(i = 0; i < n; i++){
    sum += dat[i].height;
  }

  return (sum / n);
}

void dist_vision(const PhysCheck dat[], int n, int dist[])
{
  int i;

  for(i = 0; i < VMAX; i++){
    dist[i] = 0;
  }

  for(i = 0; i < n; i++){
    if(dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0){
      dist[(int)(dat[i].vision * 10)]++;
    }
  }
}

int main(void)
{
  int i;
  PhysCheck x[] = {
    {"AKANE Kouichi", 170, 2.0},
    {"TOKUTOMI Shyuji", 173, 1.5},
    {"NISHIDA Taro", 170, 0.5},
    {"TSUJINO Jiro", 175, 0.4},
    {"MATSUO Keiji", 167, 0.6},
    {"OHYAMA Kazuhiro", 168, 0.2},
    {"KITAYAMA Takuya", 179, 0.6},
    {"TANAKA Rina", 158, 0.9},
  };
  int nx = sizeof(x) / sizeof(x[0]);
  int vdist[VMAX];
  
  puts("------身体調査一覧----------");
  puts("氏名            　身長　視力");
  puts("----------------------------");
  for(i = 0; i < nx; i++){
    printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
  }

  printf("\n平均身長：%5.1fcm\n", ave_height(x, nx));

  dist_vision(x, nx, vdist);

  printf("\n視力の分布\n");
  for(i = 0; i < VMAX; i++){
    printf("%3.1f～：%2d人\n", i / 10.0, vdist[i]);
  }

  return (0);
}
