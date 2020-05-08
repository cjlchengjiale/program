#include<cstdlib>
#include<iostream>
#include<windows.h>
#include<cstdio>
#include<time.h>
#include<conio.h>
using namespace std;
#define MAPH 25
#define MAPW 60
#define SNAKESIZE 50
#define EASYSPEED 300
#define COMMONSPEED 100
#define HELLSPEED 50
struct{
  int x;
  int y;
}snakefood;
struct{
  int x[SNAKESIZE];
  int y[SNAKESIZE];
  int len;
  int speed;
}snake;
int key = 'a';
int flag = 0;
int score = 0;
int sul = 1;
int menu()
{
  cd:
  cout<<"     snake     "<<endl;
  cout<<"***************"<<endl;
  cout<<"****1.play*****"<<endl;
  cout<<"****2.exit*****"<<endl;
  cout<<"***************"<<endl;
  int choice = 0;
  cin>>choice;
  if(choice==2){
    exit(0);
  }
  else if(choice==1){
    cc:
    system("CLS");
    cout<<"***************"<<endl;
    cout<<"****1.easy*****"<<endl;
    cout<<"****2.common***"<<endl;
    cout<<"****3.hell*****"<<endl;
    cout<<"****4.back up**"<<endl;
    cout<<"***************"<<endl;
    int ch;
    cin>>ch;
    if(ch==1){
        snake.speed = EASYSPEED;
        sul = 1;
        return 1;
    }
    else if(ch==2){
        snake.speed = COMMONSPEED;
        sul = 3;
        return 1;
    }
    else if(ch==3){
        snake.speed = HELLSPEED;
        sul = 5;
        return 1;
    }
    else if(ch==4){
      system("CLS");
      goto cd;
    }
    else{
      cout<<"error please choice again"<<endl;
      goto cc;
    }
  }
  else{
    cout<<"error please choice again"<<endl;
    goto cd;
  }
}
void gotoxy(int x,int y)
{
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(handle,coord);
}
void mapcreat()
{
  srand((unsigned int)time(NULL));
  for(int i = 0;i<=MAPH;i++){
    gotoxy(0,i);
    cout<<"¡ö";
    gotoxy(MAPW,i);
    cout<<"¡ö";
  }
  for(int i = 0;i<=MAPW;i+=2){
    gotoxy(i,0);
    cout<<"¡ö";
    gotoxy(i,MAPH);
    cout<<"¡ö";
  }
  snake.len = 3;
  snake.x[0] = MAPW/2;
  snake.y[0] = MAPH/2;
  gotoxy(snake.x[0],snake.y[0]);
  cout<<"¡ö";
  for(int k = 1;k<snake.len;k++){
    snake.x[k] = snake.x[k-1] + 2;
    snake.y[k] = snake.y[k-1];
    cout<<"¡ö";
  }
  while(1){
    snakefood.x = rand() % (MAPW-4) + 2;
    snakefood.y = rand() % (MAPH-2) + 1;
    if(snakefood.x%2!=0){
      continue;
    }
    gotoxy(snakefood.x,snakefood.y);
    printf("¡õ");
    break;
  }
}
void foodcreat()
{
  if(snake.x[0] == snakefood.x&&snake.y[0] == snakefood.y){
    score++;
    srand((unsigned int)time(NULL));
    while(1){
      int tmp = 1;
      snakefood.x = rand()%(MAPW - 4) + 2;
      snakefood.y = rand()%(MAPH - 2) + 1;
      for(int k =0;k<snake.len;k++){
        if(snake.x[k] == snakefood.x&&snake.y[0] == snakefood.y){
          tmp = 0;
          break;
        }
      }
      if(tmp&&snakefood.x%2 == 0){
        gotoxy(snakefood.x,snakefood.y);
        cout<<"¡õ";
        snake.len++;
        flag = 1;
        break;
      }
    }
  }
}
void snakemove()
{
  if(_kbhit()){
    fflush(stdin);
    key = getch();
  }
  if(!flag){
    gotoxy(snake.x[snake.len - 1],snake.y[snake.len-1]);
    cout<<"  ";
  }
  for(int i =snake.len-1;i>0;i--){
    snake.x[i] = snake.x[i - 1];
    snake.y[i] = snake.y[i - 1];
  }
  switch(key){
    case 'w':
    case 'W':{
      // if(snake.y[1]=='¡ö'){
      //   break;
      // }
      snake.y[0]--;
      break;
    }
    case 's':
    case 'S':{
      // if(snake.y[1]=='¡ö'){
      //   break;
      // }
      snake.y[0]++;
      break;
    }
    case 'A':
    case 'a':{
      // if(snake.x[2]=='¡ö'){
      //   break;
      // }
      snake.x[0]-=2;
      break;
    }
    case 'D':
    case 'd':{
      // if(snake.x[2]=='¡ö'){
      //   break;
      // }
      snake.x[0]+=2;
      break;
    }
  }
  gotoxy(snake.x[0],snake.y[0]);
  cout<<"¡ö";
  flag = 0;
  gotoxy(MAPW+1,0);
}
int snakestatus()
{
  if(snake.x[0]==0||snake.x[0]==MAPW||snake.y[0]==0||snake.y[0]==MAPH){
    //gotoxy(snake.y[0],MAPW-4);
    //cout<<"¡ö";
    return 0;
  }
  for(int i = 1;i<snake.len;i++){
    if(snake.x[0] == snake.x[i]&&snake.y[0]==snake.y[i]){
      return 0;
    }
  }
  return 1;
}
void game()
{
  system("CLS");
  mapcreat();
  while(1){
    foodcreat();
    Sleep(snake.speed);
    snakemove();
    if(snakestatus()==0){
      break;
    }
  }
  system("CLS");
  //gotoxy(MAPW+1,0);
  printf("game over score:%d\n",score*sul);
  score = 0;
  system("pause");
  system("CLS");
}
int main()
{
  while(1){
    int k = menu();
    if(k==1){
      game();
    }
  }
  return 0;
}
