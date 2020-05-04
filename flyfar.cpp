#include<iostream>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std;
#define MAPMAX 100
#define MAXSPEED 10000
long long int speed = 0;
long long int speed1 = 0;
long long int speed2 = 0;
int Map_High,Map_Width;
int Player_x,Player_y;
int Fly_x,Fly_y;

int Fly_x1,Fly_y1;
int Fly_x2,Fly_y2;

int Fly_x3,Fly_y3;
int Fly_x4,Fly_y4;
int Fly_x5,Fly_y5;
int Fly_x6,Fly_y6;

int Bullet_x,Bullet_y;
int Score;
int Seed = 1;
int Map[MAPMAX][MAPMAX];
void Good_Job()
{
  cout<<"you pass all the game"<<endl;
  cout<<"good bye"<<endl;
  exit(0);
}
void Time_Up()
{
  for(int i=10;i>=0;i--){
    printf("\r%d",i);
    Sleep(1000);
  }
  cout<<endl;
}
void Pass_Game2()
{
  cout<<endl;
  cout<<"you just have 10 second to face to the game three"<<endl;
  Time_Up();
  cout<<"Now game three is coming";
}

void Pass_Game1()
{
  cout<<"you just have 10 second to face to the game one"<<endl;
  Time_Up();
  cout<<"Now game one is coming";
}
void Pass_Game()
{
  cout<<"conguratulation! you pass the game one"<<endl;
  cout<<"you just have 10 second to face to the game two"<<endl;
  Time_Up();
  cout<<"Now game two is coming";
}
void Fly_Star2()
{
  Map_High = 40;
  Map_Width = 50;
  Player_x = Map_High-2;
  Player_y = Map_Width/2;
  Bullet_x = 0;
  Bullet_y = Player_y;
  Fly_x3 = 2;
  Fly_y3 = rand()%Map_Width+2;//Player_y - 1;
  Fly_x4 = 2;
  Fly_y4 = rand()%Map_Width+2;
  while(1){
    if(Fly_y4==Fly_y3||Fly_y4+1==Fly_y3||Fly_y4-1==Fly_y3){
      Fly_y4 = rand()%Map_Width+2;
      continue;
    }
    break;
  }
  Fly_x5 = 2;
  Fly_y5 = rand()%Map_Width+2;
  while(1){
    if(Fly_y5==Fly_y3||Fly_y5+1==Fly_y3||Fly_y5-1==Fly_y3||Fly_y5==Fly_y4||Fly_y5+1==Fly_y4||Fly_y5-1==Fly_y4){
      Fly_y5 = rand()%Map_Width+2;
      continue;
    }
    break;
  }
  Fly_x6 = 2;
  Fly_y6 = rand()%Map_Width+2;
  while(1){
    if(Fly_y6==Fly_y3||Fly_y6+1==Fly_y3||Fly_y6-1==Fly_y3||Fly_y6==Fly_y4||Fly_y6+1==Fly_y4||Fly_y6+1==Fly_y4||Fly_y6==Fly_y5||Fly_y6+1==Fly_y5||Fly_y6-1==Fly_y5){
      Fly_y6 = rand()%Map_Width+2;
      continue;
    }
    break;
  }
  Score = 0;
}
void Fly_Star1()
{
  Map_High = 40;
  Map_Width = 50;
  Player_x = Map_High-2;
  Player_y = Map_Width/2;
  Bullet_x = 0;
  Bullet_y = Player_y;
  Fly_x = 2;
  Fly_y = rand()%Map_Width+2;//Player_y - 1;
  Fly_x1 = 2;
  Fly_y1 = rand()%Map_Width+2;
  Fly_x2 = 2;
  Fly_y2 = rand()%Map_Width+2;
  Score = 0;
}
void Fly_Star()
{
  Map_High = 40;
  Map_Width = 50;
  Player_x = Map_High-2;
  Player_y = Map_Width/2;
  Bullet_x = 0;
  Bullet_y = Player_y;
  Fly_x = 2;
  Fly_y = rand()%Map_Width+2;//Player_y - 1;
  Fly_x1 = 2;
  Fly_y1 = rand()%Map_Width+2;
  Fly_x2 = 2;
  Fly_y2 = rand()%Map_Width+2;
  Score = 0;
}
int statr_all()
{
  srand((unsigned int)time(NULL));
  int choose = 0;
  make:
  for(int i =0;i<50;i++){
    cout<<"*";
  }
  cout<<endl;
  cout<<endl;
  cout<<"                   飞机大战                "<<endl;
  cout<<"                  1.开始游戏               "<<endl;
  cout<<"                  2.退出游戏               "<<endl;
  cout<<endl;
  for(int i =0;i<50;i++){
    cout<<"*";
  }
  cout<<endl;
  cout<<"请选择：";
  cin>>choose;
  if(choose==2){
    exit(0);
  }
  if(choose==1){
    return choose;
  }
  if(choose!=1&&choose!=2){
    cout<<"choose error,please choose again";
    goto make;
  }
}


void Map_Start2()
{
  int i,j;
  for(i = 1;i<=Map_High-1;i++){
    Map[i][1] = 4;
    for(j = 2;j<=Map_Width-1;j++)
      Map[i][j] = 0;
      Map[i][Map_Width] = 4;
  }
  i = Map_High;
  for(j = 1;j<=Map_Width;j++)
    Map[i][j] = 3;
  Map[Bullet_x][Bullet_y] = 5;
  Map[Player_x-1][Player_y] = 1;
  i = Player_x;
  for(j = Player_y - 2;j<=Player_y+2;j++)
    Map[i][j] = 1;
   Map[Player_x + 1][Player_y - 1] = 1;
   Map[Player_x + 1][Player_y + 1] = 1;
   Map[Player_x + 1][Player_y] = 1;
   Map[Fly_x3][Fly_y3] = 2;
   Map[Fly_x3 - 1][Fly_y3] = 2;
   Map[Fly_x3 - 1][Fly_y3 - 1] = 2;
   Map[Fly_x3 - 1][Fly_y3 + 1] = 2;

   Map[Fly_x4][Fly_y4] = 2;
   Map[Fly_x4 - 1][Fly_y4] = 2;
   Map[Fly_x4 - 1][Fly_y4 - 1] = 2;
   Map[Fly_x4 - 1][Fly_y5 + 1] = 2;

   Map[Fly_x5][Fly_y5] = 2;
   Map[Fly_x5 - 1][Fly_y5] = 2;
   Map[Fly_x5 - 1][Fly_y5 - 1] = 2;
   Map[Fly_x5 - 1][Fly_y5 + 1] = 2;

   Map[Fly_x6][Fly_y6] = 2;
   Map[Fly_x6 - 1][Fly_y6] = 2;
   Map[Fly_x6 - 1][Fly_y6 - 1] = 2;
   Map[Fly_x6 - 1][Fly_y6 + 1] = 2;


 }


void Map_Start1()
{
  int i,j;
  for(i = 1;i<=Map_High-1;i++){
    Map[i][1] = 4;
    for(j = 2;j<=Map_Width-1;j++)
      Map[i][j] = 0;
      Map[i][Map_Width] = 4;
  }
  i = Map_High;
  for(j = 1;j<=Map_Width;j++)
    Map[i][j] = 3;
  Map[Bullet_x][Bullet_y] = 5;
  Map[Player_x-1][Player_y] = 1;
  i = Player_x;
  for(j = Player_y - 2;j<=Player_y+2;j++)
    Map[i][j] = 1;
   Map[Player_x + 1][Player_y - 1] = 1;
   Map[Player_x + 1][Player_y + 1] = 1;
   Map[Player_x + 1][Player_y] = 1;
   Map[Fly_x2][Fly_y2] = 2;
   Map[Fly_x2 - 1][Fly_y2] = 2;
   Map[Fly_x2 - 1][Fly_y2 - 1] = 2;
   Map[Fly_x2 - 1][Fly_y2 + 1] = 2;
   /*Map[Fly_x1][Fly_y1] = 2;
   Map[Fly_x1 + 1][Fly_y1] = 2;
   Map[Fly_x1 - 1][Fly_y1] = 2;
   Map[Fly_x1 - 1][Fly_y1 - 1] = 2;
   Map[Fly_x1 - 1][Fly_y1 + 1] = 2;*/
 }
void Map_Start()
{
  int i,j;
  for(i = 1;i<=Map_High-1;i++){
    Map[i][1] = 4;
    for(j = 2;j<=Map_Width-1;j++)
      Map[i][j] = 0;
      Map[i][Map_Width] = 4;
  }
  i = Map_High;
  for(j = 1;j<=Map_Width;j++)
    Map[i][j] = 3;
  Map[Bullet_x][Bullet_y] = 5;
  Map[Player_x-1][Player_y] = 1;
  i = Player_x;
  for(j = Player_y - 2;j<=Player_y+2;j++)
    Map[i][j] = 1;
   Map[Player_x + 1][Player_y - 1] = 1;
   Map[Player_x + 1][Player_y + 1] = 1;
   Map[Player_x + 1][Player_y] = 1;
   Map[Fly_x][Fly_y] = 2;
   Map[Fly_x - 1][Fly_y] = 2;
   Map[Fly_x - 1][Fly_y - 1] = 2;
   Map[Fly_x - 1][Fly_y + 1] = 2;
   Map[Fly_x1][Fly_y1] = 2;
   Map[Fly_x1 + 1][Fly_y1] = 2;
   Map[Fly_x1 - 1][Fly_y1] = 2;
   Map[Fly_x1 - 1][Fly_y1 - 1] = 2;
   Map[Fly_x1 - 1][Fly_y1 + 1] = 2;
 }
 void Gmae_Over()
 {
   cout<<"GAME OVER"<<endl;
   cout<<"Your scoer is : "<<Score<<endl;
   cout<<endl;
   cout<<endl;
   exit(0);
 }
 void HideCursor()
 {
     CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
 }
 void gotoxy(int x, int y)
 {
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD pos;
     pos.X = x;
     pos.Y = y;
     SetConsoleCursorPosition(handle, pos);
 }



 void Get_Fly1_Far()
 {
   if(Bullet_x>0){
     Bullet_x--;
   }
   /*if((Bullet_x==Fly_x2)&&(Bullet_y==Fly_y2)||(Bullet_x==Fly_x2-1)&&(Bullet_y==Fly_y2-1)||(Bullet_x==Fly_x2-1)&&(Bullet_y==Fly_y2+1)){
     Score++;
     Fly_x2 = 0;
     Fly_y2 = rand()%Map_Width;
     Bullet_x = 0;
   }*/
   if((Bullet_x==Fly_x2)&&(Bullet_y==Fly_y2)||(Bullet_x==Fly_x2-1)&&(Bullet_y==Fly_y2-1)||(Bullet_x==Fly_x2-1)&&(Bullet_y==Fly_y2+1)){
     Score++;
     Fly_x2 = 0;
     Fly_y2 = rand()%Map_Width;
     Bullet_x = 0;
   }
   if(Fly_x2==Player_x&&Fly_y2==Player_y){
     Seed--;
     if(Seed == 0){
       Gmae_Over();
     }
   }
   if(Fly_x2>Map_High){
     Fly_x2 = 0;
     Fly_y2 = rand()%Map_Width;
   }
   if(speed == 1){
     for(int i = 1;i<=MAXSPEED/10;i++){
       for(int j = 1;j<=MAXSPEED/10;j++){
         speed = 1;
       }
     }
   }
   speed = 0;
   if(speed==0){
     Fly_x2++;
     speed=1;
   }
 }


 void Get_Fly2_Far()
 {
   if(Bullet_x>0){
     Bullet_x--;
   }
   if((Bullet_x==Fly_x3)&&(Bullet_y==Fly_y3)||(Bullet_x==Fly_x3-1)&&(Bullet_y==Fly_y3-1)||(Bullet_x==Fly_x3-1)&&(Bullet_y==Fly_y3+1)){
     Score++;
     Fly_x3 = 0;
     Fly_y3 = rand()%Map_Width+3;
     Bullet_x = 0;
   }
   if((Bullet_x==Fly_x4)&&(Bullet_y==Fly_y4)||(Bullet_x==Fly_x4-1)&&(Bullet_y==Fly_y4-1)||(Bullet_x==Fly_x4-1)&&(Bullet_y==Fly_y4+1)){
     Score++;
     Fly_x4 = 0;
     Fly_y4 = rand()%Map_Width+3;
     Bullet_x = 0;
   }
   if((Bullet_x==Fly_x5)&&(Bullet_y==Fly_y5)||(Bullet_x==Fly_x5-1)&&(Bullet_y==Fly_y5-1)||(Bullet_x==Fly_x5-1)&&(Bullet_y==Fly_y5+1)){
     Score++;
     Fly_x5 = 0;
     Fly_y5 = rand()%Map_Width+3;
     Bullet_x = 0;
   }
   if((Bullet_x==Fly_x6)&&(Bullet_y==Fly_y6)||(Bullet_x==Fly_x6-1)&&(Bullet_y==Fly_y6-1)||(Bullet_x==Fly_x6-1)&&(Bullet_y==Fly_y6+1)){
     Score++;
     Fly_x6 = 0;
     Fly_y6 = rand()%Map_Width+3;
     Bullet_x = 0;
   }
   if((Fly_x3==Player_x&&Fly_y3==Player_y)||(Fly_x4==Player_x&&Fly_y4==Player_y)||(Fly_x5==Player_x&&Fly_y5==Player_y)||(Fly_x6==Player_x&&Fly_y6==Player_y)){
     Seed--;
     if(Seed == 0){
       Gmae_Over();
     }
   }
   if(Fly_x3>Map_High||Fly_x5>Map_High||Fly_x4>Map_High||Fly_x6>Map_High){
     Fly_x3 = 0;
     Fly_y3 = rand()%Map_Width+2;
     Fly_x4 = 0;
     Fly_y4 = rand()%Map_Width+2;
     Fly_x5 = 0;
     Fly_y5 = rand()%Map_Width+2;
     Fly_x6 = 0;
     Fly_y6 = rand()%Map_Width+2;
   }
   if(speed == 1){
     for(int i = 1;i<=MAXSPEED/100;i++){
       for(int j = 1;j<=MAXSPEED/1000;j++){
         speed = 1;
       }
     }
   }
   speed = 0;
   if(speed==0){
     Fly_x3++;
     Fly_x4++;
     Fly_x5++;
     Fly_x6++;
     speed2=1;
   }
 }


 void Get_Fly_Far()
 {
   if(Bullet_x>0){
     Bullet_x--;
   }
   if((Bullet_x==Fly_x)&&(Bullet_y==Fly_y)||(Bullet_x==Fly_x-1)&&(Bullet_y==Fly_y-1)||(Bullet_x==Fly_x-1)&&(Bullet_y==Fly_y+1)){
     Score++;
     Fly_x = 0;
     Fly_y = rand()%Map_Width+3;
     Bullet_x = 0;
   }
   if((Bullet_x==Fly_x1)&&(Bullet_y==Fly_y1)||(Bullet_x==Fly_x1-1)&&(Bullet_y==Fly_y1-1)||(Bullet_x==Fly_x1-1)&&(Bullet_y==Fly_y1+1)){
     Score++;
     Fly_x1 = 0;
     Fly_y1 = rand()%Map_Width+3;
     Bullet_x = 0;
   }
   if((Fly_x==Player_x&&Fly_y==Player_y)||(Fly_x1==Player_x&&Fly_y1==Player_y)){
     Seed--;
     if(Seed == 0){
       Gmae_Over();
     }
   }
   if(Fly_x>Map_High||Fly_x1>Map_High){
     Fly_x = 0;
     Fly_y = rand()%Map_Width+2;
     Fly_x1 = 0;
     Fly_y1 = rand()%Map_Width+2;
     while(1){
       if(Fly_y==Fly_y1){
         Fly_y1 = rand()%Map_Width+2;
         continue;
       }
       break;
     }
   }
   if(speed == 1){
     for(int i = 1;i<=MAXSPEED/100;i++){
       for(int j = 1;j<=MAXSPEED/1000;j++){
         speed = 1;
       }
     }
   }
   speed = 0;
   if(speed==0){
     Fly_x++;
     Fly_x1++;
     speed=1;
   }
 }
 void Fly_Far_INPUT()
 {
   char input;
   if (kbhit())
   {
       input = getch();
       if (input == 'a'){
         if(Player_y<=4){
           ;
         }
         else{
           Player_y--;
         }
         //cout<<Player_y<<"***"<<endl;
       }
       if (input == 's'){
         if(Player_x>Map_High-3){
           ;
         }
         else{
           Player_x++;
         }
         //cout<<Player_x<<"----"<<endl;
       }
       if (input == 'd'){
         if(Player_y>Map_Width-3){
           ;
         }
         else{
           Player_y++;
         }
         //cout<<Player_y<<"*     *"<<endl;
       }
       if (input == 'w'){
         if(Player_x<3){
           ;
         }
         else{
           Player_x--;
         }
        // cout<<Player_x<<"++++++"<<endl;
       }
       if (input == ' ')
       {
           Bullet_x = Player_x - 1;
           Bullet_y = Player_y;
       }
   }
 }
 void Map_Show2()
 {
   gotoxy(0, 0);
   int i,j;
   for(i = 1;i<=Map_High;i++){
     for(j = 1;j<=Map_Width;j++){
       if (Map[i][j] == 0)
           cout<<" ";
       if (Map[i][j] == 1)
           cout<<"*";
       if (Map[i][j] == 2)
           cout<<"#";
       if (Map[i][j] == 3)
           cout<<"~";
       if (Map[i][j] == 4)
           cout<<"|";
       if (Map[i][j] == 5)
           cout<<"|";
   }
   cout<<endl;
   }
   cout<<"game three"<<"          "<<"Mission Score: 5 "<<endl;
   cout<<"your score : "<<Score<<"       "<<"your blood : "<<Seed<<endl;
   cout<<"W A S D 控制上 下 左 右"<<endl;
   cout<<"空格发射子弹"<<endl;
 }
 void Map_Show1()
 {
   gotoxy(0, 0);
   int i,j;
   for(i = 1;i<=Map_High;i++){
     for(j = 1;j<=Map_Width;j++){
       if (Map[i][j] == 0)
           cout<<" ";
       if (Map[i][j] == 1)
           cout<<"*";
       if (Map[i][j] == 2)
           cout<<"#";
       if (Map[i][j] == 3)
           cout<<"~";
       if (Map[i][j] == 4)
           cout<<"|";
       if (Map[i][j] == 5)
           cout<<"|";
   }
   cout<<endl;
   }
   cout<<"game two"<<"          "<<"Mission Score: 1 "<<endl;
   cout<<"your score : "<<Score<<"       "<<"your blood : "<<Seed<<endl;
   cout<<"W A S D 控制上 下 左 右"<<endl;
   cout<<"空格发射子弹"<<endl;
 }
void Map_Show()
{
  gotoxy(0, 0);
  int i,j;
  for(i = 1;i<=Map_High;i++){
    for(j = 1;j<=Map_Width;j++){
      if (Map[i][j] == 0)
          cout<<" ";
      if (Map[i][j] == 1)
          cout<<"*";
      if (Map[i][j] == 2)
          cout<<"#";
      if (Map[i][j] == 3)
          cout<<"~";
      if (Map[i][j] == 4)
          cout<<"|";
      if (Map[i][j] == 5)
          cout<<"|";
  }
  cout<<endl;
  }
  cout<<"game one"<<"          "<<"Mission Score: 2 "<<endl;
  cout<<"your score : "<<Score<<"       "<<"your blood : "<<Seed<<endl;
  cout<<"W A S D 控制上 下 左 右"<<endl;
  cout<<"空格发射子弹"<<endl;
}
void Game_Start3()
{
    Fly_Star2();
    while(1){
      HideCursor();
      Map_Start2();
      Map_Show2();
      Get_Fly2_Far();
      if(Score==3){
        Good_Job();
      }
    //  Get_Fly1_Far();
      Fly_Far_INPUT();
      //Time_Up();
  }
}
void Game_Start2()
{
    Fly_Star1();
    while(1){
      HideCursor();
      Map_Start();
      Map_Show1();
      Get_Fly_Far();
      if(Score==2){
        Pass_Game2();
        system("CLS");
        Game_Start3();
      }
    //  Get_Fly1_Far();
      Fly_Far_INPUT();
      //Time_Up();
  }
}
void Game_Start()
{
  int Pass = 0;
    Fly_Star1();
    while(1){
      HideCursor();
      Map_Start1();
      Map_Show();
      Get_Fly1_Far();
      if(Score==2){
        Pass_Game();
        system("CLS");
        Game_Start2();
      }
    //  Get_Fly1_Far();
      Fly_Far_INPUT();
      //Time_Up();
  }
}
int main()
{
  int Get = 0;
  Get=statr_all();
  if(Get==1)
  {
    Pass_Game1();
    Game_Start();
  }
  cout<<"8888888"<<endl;
  return 0;
}
