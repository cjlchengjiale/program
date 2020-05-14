#include<iostream>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std;
#define MAPMAX 10
#define MAP_PASS 12
int People_x,People_y;
int Box_x,Box_y;
int Box_x1,Box_y1;
int Seat_x,Seat_y;
int Seat_x1,Seat_y1;
int Map[MAPMAX][MAPMAX+3] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,2,1,1,1,1,1,1,1,2,2,2,0},
  {0,2,2,2,1,1,1,1,1,2,2,2,0},
  {0,2,1,2,1,1,1,2,2,2,2,2,0},
  {0,2,2,2,2,2,2,2,2,2,2,2,0},
  {0,2,1,2,2,1,1,1,1,1,2,2,0},
  {0,2,1,2,2,2,2,2,2,2,2,2,0},
  {0,2,1,1,1,2,2,1,1,1,1,1,0},
  {0,2,2,2,2,2,2,1,2,2,2,2,2},
  {0,0,0,0,0,0,0,0,2,2,2,2,2},
};

void Map_Start()
{
      Map[People_x][People_y]=4;
      Map[Box_x][Box_y]=3;
      Map[Box_x1][Box_y1]=6;
}
void Creat_Seat()
{
  People_x=1;
  People_y=1;
  Box_x=3;
  Box_y=8;
  Box_x1=4;
  Box_y1=8;
  Seat_x=7;
  Seat_y=1;
  Seat_x1=6;
  Seat_y1=4;
  Map[Seat_x][Seat_y]=5;
  Map[Seat_x1][Seat_y1]=7;
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
int Search_Box()
{
  if(Box_x==Seat_x&&Box_y==Seat_y&&Box_x1==Seat_x1&&Box_y1==Seat_y1){
    return 1;
  }
  if(Box_x==Seat_x1&&Box_y==Seat_y1&&Box_x1==Seat_x&&Box_y1==Seat_y){
    return 1;
  }
}
void Creat_Map()
{
  gotoxy(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map[i][j]==0){
        cout<<"■";
      }
      if(Map[i][j]==1){
        cout<<"■";
      }
      if(Map[i][j]==2){
        cout<<"  ";
      }
      if(Map[i][j]==3){
        cout<<"□";
      }
      if(Map[i][j]==4){
        cout<<"♀";
      }
      if(Map[i][j]==5){
        cout<<"●";
      }
      if(Map[i][j]==7){
        cout<<"●";
      }
      if(Map[i][j]==6){
        cout<<"□";
      }
      if(Map[i][j]==8){
        cout<<"□";
      }
    }
    cout<<endl;
  }
  cout<<"Game one"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map[People_x-1][People_y]==1){
         ;
       }
       else if((Map[People_x-1][People_y]==Map[Box_x][Box_y]&&Map[Box_x-1][Box_y]==0)||(Map[People_x-1][People_y]==Map[Box_x1][Box_y1]&&Map[Box_x1-1][Box_y1]==0)){
         ;
       }
       else if((Map[People_x-1][People_y]==Map[Box_x][Box_y]&&Map[Box_x-1][Box_y]==1)||(Map[People_x-1][People_y]==Map[Box_x1][Box_y1]&&Map[Box_x1-1][Box_y1]==1)){
         ;
       }
       else if(Map[People_x-1][People_y]==6&&Map[Box_x1-1][Box_y1]==3){
         ;
       }
       else if(Map[People_x-1][People_y]==3&&Map[Box_x-1][Box_y]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat_x&&People_y==Seat_y&&People_x-1==Box_x&&People_y==Box_y){
           Map[Seat_x][Seat_y]=5;
           People_x--;
           Box_x--;
         }
        else if(People_x==Seat_x&&People_y==Seat_y&&People_x-1==Box_x1&&People_y==Box_y1){
           Map[Seat_x1][Seat_y1]=5;
           People_x--;
           Box_x1--;
         }
        else if(People_x==Seat_x1&&People_y==Seat_y1&&People_x-1==Box_x&&People_y==Box_y){
           Map[Seat_x][Seat_y]=7;
           People_x--;
           Box_x--;
         }
        else if(People_x==Seat_x1&&People_y==Seat_y1&&People_x-1==Box_x1&&People_y==Box_y1){
           Map[Seat_x1][Seat_y1]=7;
           People_x--;
           Box_x1--;
         }
       //}
       else if((People_x==Seat_x&&People_y==Seat_y&&Map[Seat_x-1][Seat_y]!=0)||(People_x==Seat_x&&People_y==Seat_y&&Map[Seat_x-1][Seat_y]!=1)){
         People_x--;
         Map[Seat_x][Seat_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat_x1&&People_y==Seat_y1&&Map[Seat_x1-1][Seat_y1]!=0)||(People_x==Seat_x1&&People_y==Seat_y1&&Map[Seat_x1-1][Seat_y1]!=1)){
         People_x--;
         Map[Seat_x1][Seat_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if(Map[Box_x-1][Box_y]==5&&Map[People_x-2][People_y]==5){
         Map[Seat_x][Seat_y]=3;
         Map[Box_x][Box_y]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x1-1][Box_y1]==5&&Map[People_x-2][People_y]==5){
         Map[Seat_x][Seat_y]=6;
         Map[Box_x1][Box_y1]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x-1][Box_y]==7&&Map[People_x-2][People_y]==7){
         Map[Seat_x1][Seat_y1]=3;
         Map[Box_x][Box_y]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x1-1][Box_y1]==7&&Map[People_x-2][People_y]==7){
         Map[Seat_x1][Seat_y1]=6;
         Map[Box_x1][Box_y1]=4;
         Map[People_x][People_y]=2;
       }
       else{
         if(Map[People_x-1][People_y]!=6&&Map[People_x-1][People_y]==3&&Map[Box_x-1][Box_y]!=0&&Map[Box_x-1][Box_y]!=1){
           People_x--;
           Box_x--;
           Map[People_x+1][People_y]=2;
           Map[Box_x+1][Box_y]=2;
         }
         /*else{
           People_x--;
           Map[People_x+1][People_y]=2;
         }*/
         else if(Map[People_x-1][People_y]==6&&Map[Box_x1-1][Box_y1]!=0&&Map[Box_x1-1][Box_y1]!=1){
           People_x--;
           Box_x1--;
           Map[People_x+1][People_y]=2;
           Map[Box_x1+1][Box_y1]=2;
         }
         else{
           People_x--;
           Map[People_x+1][People_y]=2;
         }
       }
     }
     if(input=='s'){
       if(People_x>7||Map[People_x+1][People_y]==1){
         ;
       }
       else if((Map[People_x+1][People_y]==Map[Box_x][Box_y]&&Map[Box_x+1][Box_y]==0)||(Map[People_x+1][People_y]==Map[Box_x1][Box_y1]&&Map[Box_x1+1][Box_y1]==0)){
         ;
       }
       else if((Map[People_x+1][People_y]==Map[Box_x][Box_y]&&Map[Box_x+1][Box_y]==1)||(Map[People_x+1][People_y]==Map[Box_x1][Box_y1]&&Map[Box_x1+1][Box_y1]==1)){
         ;
       }
       else if(Map[People_x+1][People_y]==6&&Map[Box_x1+1][Box_y1]==3){
         ;
       }
       else if(Map[People_x+1][People_y]==3&&Map[Box_x+1][Box_y]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){
        else if(People_x==Seat_x&&People_y==Seat_y&&People_x+1==Box_x&&People_y==Box_y){
           Map[Seat_x][Seat_y]=5;
           People_x++;
           Box_x++;
         }
        else if(People_x==Seat_x&&People_y==Seat_y&&People_x+1==Box_x1&&People_y==Box_y1){
           Map[Seat_x1][Seat_y1]=5;
           People_x++;
           Box_x1++;
         }
        else if(People_x==Seat_x1&&People_y==Seat_y1&&People_x+1==Box_x&&People_y==Box_y){
           Map[Seat_x][Seat_y]=7;
           People_x++;
           Box_x++;
         }
        else if(People_x==Seat_x1&&People_y==Seat_y1&&People_x+1==Box_x1&&People_y==Box_y1){
           Map[Seat_x1][Seat_y1]=7;
           People_x++;
           Box_x1++;
         }
      // }
       else if((People_x==Seat_x&&People_y==Seat_y&&Map[Seat_x+1][Seat_y]!=0)||(People_x==Seat_x&&People_y==Seat_y&&Map[Seat_x+1][Seat_y]!=1)){
         People_x++;
         Map[Seat_x][Seat_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat_x1&&People_y==Seat_y1&&Map[Seat_x1+1][Seat_y1]!=0)||(People_x==Seat_x1&&People_y==Seat_y1&&Map[Seat_x1+1][Seat_y1]!=1)){
         People_x++;
         Map[Seat_x1][Seat_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if(Map[Box_x+1][Box_y]==5&&Map[People_x+2][People_y]==5){
         Map[Seat_x][Seat_y]=3;
         Map[Box_x][Box_y]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x1+1][Box_y1]==5&&Map[People_x+2][People_y]==5){
         Map[Seat_x][Seat_y]=6;
         Map[Box_x1][Box_y1]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x+1][Box_y]==7&&Map[People_x+2][People_y]==7){
         Map[Seat_x1][Seat_y1]=3;
         Map[Box_x][Box_y]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x1+1][Box_y1]==7&&Map[People_x+2][People_y]==7){
         Map[Seat_x1][Seat_y1]=6;
         Map[Box_x1][Box_y1]=4;
         Map[People_x][People_y]=2;
       }
       else{
         if(Map[People_x+1][People_y]!=6&&Map[People_x+1][People_y]==3&&Map[Box_x+1][Box_y]!=0&&Map[Box_x+1][Box_y]!=1){
           People_x++;
           Box_x++;
           Map[People_x-1][People_y]=2;
           Map[Box_x-1][Box_y]=2;
         }
         /*else{
           People_x++;
           Map[People_x-1][People_y]=2;
         }*/
         else if(Map[People_x+1][People_y]==6&&Map[Box_x1+1][Box_y1]!=0&&Map[Box_x1+1][Box_y1]!=1){
           People_x++;
           Box_x1++;
           Map[People_x-1][People_y]=2;
           Map[Box_x1-1][Box_y1]=2;
         }
         else{
           People_x++;
           Map[People_x-1][People_y]=2;
         }
       }
     }
     if(input=='a'){
       if(People_y<2||Map[People_x][People_y-1]==1){
         ;
       }
       else if((Map[People_x][People_y-1]==Map[Box_x][Box_y]&&Map[Box_x][Box_y-1]==0)||(Map[People_x][People_y-1]==Map[Box_x1][Box_y1]&&Map[Box_x1][Box_y1-1]==0)){
         ;
       }
       else if((Map[People_x][People_y-1]==Map[Box_x][Box_y]&&Map[Box_x][Box_y-1]==1)||(Map[People_x][People_y-1]==Map[Box_x1][Box_y1]&&Map[Box_x1][Box_y1-1]==1)){
         ;
       }
       else if(Map[People_x][People_y-1]==6&&Map[Box_x1][Box_y1-1]==3){
         ;
       }
       else if(Map[People_x][People_y-1]==3&&Map[Box_x][Box_y-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_y-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_y-2!=0)||
     //(People_x==Seat_x1&&People_y==Seat_y1&&People_y-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_y-2!=0)){
        else if(People_x==Seat_x&&People_y==Seat_y&&People_x==Box_x&&People_y-1==Box_y){
           Map[Seat_x][Seat_y]=5;
           People_y--;
           Box_y--;
         }
        else if(People_x==Seat_x&&People_y==Seat_y&&People_x==Box_x1&&People_y-1==Box_y1){
           Map[Seat_x1][Seat_y1]=5;
           People_y--;
           Box_y1--;
         }
        else if(People_x==Seat_x1&&People_y==Seat_y1&&People_x==Box_x&&People_y-1==Box_y){
           Map[Seat_x][Seat_y]=7;
           People_y--;
           Box_y--;
         }
        else if(People_x==Seat_x1&&People_y==Seat_y1&&People_x==Box_x1&&People_y-1==Box_y1){
           Map[Seat_x1][Seat_y1]=7;
           People_y--;
           Box_y1--;
         }
      // }
       else if((People_x==Seat_x&&People_y==Seat_y&&Map[Seat_x][Seat_y-1]!=0)||(People_x==Seat_x&&People_y==Seat_y&&Map[Seat_x][Seat_y-1]!=1)){
         People_y--;
         Map[Seat_x][Seat_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat_x1&&People_y==Seat_y1&&Map[Seat_x1][Seat_y1-1]!=0)||(People_x==Seat_x1&&People_y==Seat_y1&&Map[Seat_x1][Seat_y1-1]!=1)){
         People_y--;
         Map[Seat_x1][Seat_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if(Map[Box_x][Box_y-1]==5&&Map[People_x][People_y-2]==5){
         Map[Seat_x][Seat_y]=3;
         Map[Box_x][Box_y]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x1][Box_y1-1]==5&&Map[People_x][People_y-2]==5){
         Map[Seat_x][Seat_y]=6;
         Map[Box_x1][Box_y1]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x][Box_y-1]==7&&Map[People_x][People_y-2]==7){
         Map[Seat_x1][Seat_y1]=3;
         Map[Box_x][Box_y]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x1][Box_y1-1]==7&&Map[People_x][People_y-2]==7){
         Map[Seat_x1][Seat_y1]=6;
         Map[Box_x1][Box_y1]=4;
         Map[People_x][People_y]=2;
       }
       else{
         if(Map[People_x][People_y-1]!=6&&Map[People_x][People_y-1]==3&&Map[Box_x][Box_y-1]!=0&&Map[Box_x][Box_y-1]!=1){
           People_y--;
           Box_y--;
           Map[People_x][People_y+1]=2;
           Map[Box_x][Box_y+1]=2;
         }
         /*else{
           People_y--;
           Map[People_x][People_y+1]=2;
         }*/
         else if(Map[People_x][People_y-1]==6&&Map[Box_x1][Box_y1-1]!=0&&Map[Box_x1][Box_y1-1]!=1){
           People_y--;
           Box_y1--;
           Map[People_x][People_y+1]=2;
           Map[Box_x1][Box_y1+1]=2;
         }
         else{
           People_y--;
           Map[People_x][People_y+1]=2;
         }
       }
     }
     if(input=='d'){
       if(People_y>10||Map[People_x][People_y+1]==1){
         ;
       }
       else if((Map[People_x][People_y+1]==Map[Box_x][Box_y]&&Map[Box_x][Box_y+1]==0)||(Map[People_x][People_y+1]==Map[Box_x1][Box_y1]&&Map[Box_x1][Box_y1+1]==0)){
         ;
       }
       else if((Map[People_x][People_y+1]==Map[Box_x][Box_y]&&Map[Box_x][Box_y+1]==1)||(Map[People_x][People_y+1]==Map[Box_x1][Box_y1]&&Map[Box_x1][Box_y1+1]==1)){
         ;
       }
       else if(Map[People_x][People_y+1]==6&&Map[Box_x1][Box_y1+1]==3){
         ;
       }
       else if(Map[People_x][People_y+1]==3&&Map[Box_x][Box_y+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_y+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_y+2!=0)||
     //(People_x==Seat_x1&&People_y==Seat_y1&&People_y+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_y+2!=0)){
       else if(People_x==Seat_x&&People_y==Seat_y&&People_x==Box_x&&People_y+1==Box_y){
           Map[Seat_x][Seat_y]=5;
           People_y++;
           Box_y++;
         }
        else if(People_x==Seat_x&&People_y==Seat_y&&People_x==Box_x1&&People_y+1==Box_y1){
           Map[Seat_x1][Seat_y1]=5;
           People_y++;
           Box_y1++;
         }
        else if(People_x==Seat_x1&&People_y==Seat_y1&&People_x==Box_x&&People_y+1==Box_y){
           Map[Seat_x][Seat_y]=7;
           People_y++;
           Box_y++;
         }
        else if(People_x==Seat_x1&&People_y==Seat_y1&&People_x==Box_x1&&People_y+1==Box_y1){
           Map[Seat_x1][Seat_y1]=7;
           People_y++;
           Box_y1++;
         }
      // }
       else if((People_x==Seat_x&&People_y==Seat_y&&Map[Seat_x][Seat_y+1]!=0)||(People_x==Seat_x&&People_y==Seat_y&&Map[Seat_x][Seat_y+1]!=1)){
         People_y++;
         Map[Seat_x][Seat_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat_x1&&People_y==Seat_y1&&Map[Seat_x1][Seat_y1+1]!=0)||(People_x==Seat_x1&&People_y==Seat_y1&&Map[Seat_x1][Seat_y1+1]!=1)){
         People_y++;
         Map[Seat_x1][Seat_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if(Map[Box_x][Box_y+1]==5&&Map[People_x][People_y+2]==5){
         Map[Seat_x][Seat_y]=3;
         Map[Box_x][Box_y]=4;
         Map[People_x][People_y-1]=2;
       }
       else if(Map[Box_x1][Box_y1+1]==5&&Map[People_x][People_y+2]==5){
         Map[Seat_x][Seat_y]=6;
         Map[Box_x1][Box_y1]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x][Box_y+1]==7&&Map[People_x][People_y+2]==7){
         Map[Seat_x1][Seat_y1]=3;
         Map[Box_x][Box_y]=4;
         Map[People_x][People_y]=2;
       }
       else if(Map[Box_x1][Box_y1+1]==7&&Map[People_x][People_y+2]==7){
         Map[Seat_x1][Seat_y1]=6;
         Map[Box_x1][Box_y1]=4;
         Map[People_x][People_y]=2;
       }
       else{
         if(Map[People_x][People_y+1]!=6&&Map[People_x][People_y+1]==3&&Map[Box_x][Box_y+1]!=0&&Map[Box_x][Box_y+1]!=1){
           People_y++;
           Box_y++;
           Map[People_x][People_y-1]=2;
           Map[Box_x][Box_y-1]=2;
         }
         /*else{
           People_y++;
           Map[People_x][People_y-1]=2;
         }*/
         else if(Map[People_x][People_y+1]==6&&Map[Box_x1][Box_y1+1]!=0&&Map[Box_x1][Box_y1+1]!=1){
           People_y++;
           Box_y1++;
           Map[People_x][People_y-1]=2;
           Map[Box_x1][Box_y1-1]=2;
         }
         else{
           People_y++;
           Map[People_x][People_y-1]=2;
         }
       }
     }
   }
}


int Box2_x,Box2_y;
int Box2_x1,Box2_y1;
int Box2_x2,Box2_y2;
int Seat2_x,Seat2_y;
int Seat2_x1,Seat2_y1;
int Seat2_x2,Seat2_y2;
int Map2[MAPMAX][MAPMAX+3] = {
  {2,2,2,2,2,2,2,2,2,2,2,2,2},
  {2,1,1,1,1,1,1,1,1,1,2,2,2},
  {2,1,2,2,2,2,2,2,2,1,2,2,2},
  {2,1,2,2,2,1,1,2,2,1,1,1,2},
  {2,1,1,1,2,1,1,1,2,2,2,1,2},
  {0,1,1,1,2,1,1,1,1,1,2,1,2},
  {0,2,1,2,2,2,1,1,1,1,2,1,2},
  {0,2,2,2,2,2,1,1,1,1,2,1,2},
  {0,2,2,2,2,2,2,2,2,2,2,1,2},
  {0,0,0,0,0,0,0,0,0,0,0,0,2},
};
void Map_Start2()
{
      Map2[People_x][People_y]=4;
      Map2[Box2_x][Box2_y]=3;
      Map2[Box2_x1][Box2_y1]=6;
      Map2[Box2_x2][Box2_y2]=9;
}
void Seat_Set2()
{
  if(Map2[Seat2_x][Seat2_y]!=8){
    Map2[Seat2_x][Seat2_y]=5;
  }
  if(Map2[Seat2_x1][Seat2_y1]!=8){
      Map2[Seat2_x1][Seat2_y1]=7;
  }
  if(Map2[Seat2_x2][Seat2_y2]!=8){
    Map2[Seat2_x2][Seat2_y2]=10;
  }
}
void Creat_Seat2()
{
  People_x=2;
  People_y=2;
  Box2_x=7;
  Box2_y=2;
  Box2_x1=8;
  Box2_y1=9;
  Box2_x2=3;
  Box2_y2=3;
  Seat2_x=6;
  Seat2_y=1;
  Seat2_x1=7;
  Seat2_y1=1;
  Seat2_x2=8;
  Seat2_y2=1;
  Map2[Seat2_x][Seat2_y]=5;
  Map2[Seat2_x1][Seat2_y1]=7;
  Map2[Seat2_x2][Seat2_y2]=10;
}
void HideCursor2()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy2(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
int Search_Box2()
{
  if(Box2_x==Seat2_x&&Box2_y==Seat2_y&&Box2_x1==Seat2_x1&&Box2_y1==Seat2_y1&&Box2_x2==Seat2_x2&&Box2_y2==Seat2_y2){
    return 1;
  }
  if(Box2_x==Seat2_x&&Box2_y==Seat2_y&&Box2_x1==Seat2_x2&&Box2_y1==Seat2_y2&&Box2_x2==Seat2_x1&&Box2_y2==Seat2_y1){
    return 1;
  }
  if(Box2_x==Seat2_x1&&Box2_y==Seat2_y1&&Box2_x1==Seat2_x&&Box2_y1==Seat2_y&&Box2_x2==Seat2_x2&&Box2_y2==Seat2_y2){
    return 1;
  }
  if(Box2_x==Seat2_x2&&Box2_y==Seat2_y2&&Box2_x1==Seat2_x1&&Box2_y1==Seat2_y1&&Box2_x2==Seat2_x&&Box2_y2==Seat2_y){
    return 1;
  }
  if(Box2_x==Seat2_x1&&Box2_y==Seat2_y1&&Box2_x1==Seat2_x2&&Box2_y1==Seat2_y2&&Box2_x2==Seat2_x&&Box2_y2==Seat2_y){
    return 1;
  }
  if(Box2_x==Seat2_x2&&Box2_y==Seat2_y2&&Box2_x1==Seat2_x&&Box2_y1==Seat2_y&&Box2_x2==Seat2_x1&&Box2_y2==Seat2_y1){
    return 1;
  }
}
void Creat_Map2()
{
  gotoxy(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map2[i][j]==0){
        cout<<"■";
      }
      if(Map2[i][j]==1){
        cout<<"■";
      }
      if(Map2[i][j]==2){
        cout<<"  ";
      }
      if(Map2[i][j]==3){
        cout<<"□";
      }
      if(Map2[i][j]==4){
        cout<<"♀";
      }
      if(Map2[i][j]==5){
        cout<<"●";
      }
      if(Map2[i][j]==7){
        cout<<"●";
      }
      if(Map2[i][j]==6){
        cout<<"□";
      }
      if(Map2[i][j]==8){
        cout<<"□";
      }
      if(Map2[i][j]==9){
        cout<<"□";
      }
      if(Map2[i][j]==10){
        cout<<"●";
      }
    }
    cout<<endl;
  }
  cout<<"Game two"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move2()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map2[People_x-1][People_y]==1){
         ;
       }
       else if((Map2[People_x-1][People_y]==Map2[Box2_x][Box2_y]&&Map2[Box2_x-1][Box2_y]==0)||(Map2[People_x-1][People_y]==Map2[Box2_x1][Box2_y1]&&Map2[Box2_x1-1][Box2_y1]==0)
     ||(Map2[People_x-1][People_y]==Map2[Box2_x2][Box2_y2]&&Map2[Box2_x2-1][Box2_y2]==0)){
         ;
       }
       else if((Map2[People_x-1][People_y]==Map2[Box2_x][Box2_y]&&Map2[Box2_x-1][Box2_y]==1)||(Map2[People_x-1][People_y]==Map2[Box2_x1][Box2_y1]&&Map2[Box2_x1-1][Box2_y1]==1)
     ||(Map2[People_x-1][People_y]==Map2[Box2_x2][Box2_y2]&&Map2[Box2_x2-1][Box2_y2]==1)){
         ;
       }
       else if(Map2[People_x-1][People_y]==6&&Map2[Box2_x1-1][Box2_y1]==3){
         ;
       }
       else if(Map2[People_x-1][People_y]==6&&Map2[Box2_x1-1][Box2_y1]==9){
         ;
       }
       else if(Map2[People_x-1][People_y]==3&&Map2[Box2_x-1][Box2_y]==6){
         ;
       }
       else if(Map2[People_x-1][People_y]==3&&Map2[Box2_x-1][Box2_y]==9){
         ;
       }
       else if(Map2[People_x-1][People_y]==9&&Map2[Box2_x2-1][Box2_y2]==3){
         ;
       }
       else if(Map2[People_x-1][People_y]==9&&Map2[Box2_x2-1][Box2_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x-1==Box2_x&&People_y==Box2_y){
           Map2[Seat2_x][Seat2_y]=5;
           People_x--;
           Box2_x--;
         }
        else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x-1==Box2_x1&&People_y==Box2_y1){
           Map2[Seat2_x][Seat2_y]=5;
           People_x--;
           Box2_x1--;
         }
         else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x-1==Box2_x2&&People_y==Box2_y2){
            Map2[Seat2_x][Seat2_y]=5;
            People_x--;
            Box2_x2--;
          }
        else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x-1==Box2_x&&People_y==Box2_y){
           Map2[Seat2_x1][Seat2_y1]=7;
           People_x--;
           Box2_x--;
         }
        else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x-1==Box2_x1&&People_y==Box2_y1){
           Map2[Seat2_x1][Seat2_y1]=7;
           People_x--;
           Box2_x1--;
         }
         else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x-1==Box2_x2&&People_y==Box2_y2){
            Map2[Seat2_x1][Seat2_y1]=7;
            People_x--;
            Box2_x2--;
          }
         else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x-1==Box2_x&&People_y==Box2_y){
            Map2[Seat2_x2][Seat2_y2]=10;
            People_x--;
            Box2_x--;
          }
          else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x-1==Box2_x1&&People_y==Box2_y1){
             Map2[Seat2_x2][Seat2_y2]=10;
             People_x--;
             Box2_x1--;
           }
           else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x-1==Box2_x2&&People_y==Box2_y2){
              Map2[Seat2_x2][Seat2_y2]=10;
              People_x--;
              Box2_x2--;
            }
       //}


       else if((People_x==Seat2_x&&People_y==Seat2_y&&Map2[Seat2_x-1][Seat2_y]!=0)||(People_x==Seat2_x&&People_y==Seat2_y&&Map2[Seat2_x-1][Seat2_y]!=1)){
         People_x--;
         Map2[Seat2_x][Seat2_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat2_x1&&People_y==Seat2_y1&&Map2[Seat2_x1-1][Seat2_y1]!=0)||(People_x==Seat2_x1&&People_y==Seat2_y1&&Map2[Seat2_x1-1][Seat2_y1]!=1)){
         People_x--;
         Map2[Seat2_x1][Seat2_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat2_x2&&People_y==Seat2_y2&&Map2[Seat2_x2-1][Seat2_y2]!=0)||(People_x==Seat2_x2&&People_y==Seat2_y2&&Map2[Seat2_x2-1][Seat2_y2]!=1)){
         People_x--;
         Map2[Seat2_x2][Seat2_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map2[Box2_x-1][Box2_y]==5&&Map2[People_x-2][People_y]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x-1][Box2_y]==7&&Map2[People_x-2][People_y]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x-1][Box2_y]==10&&Map2[People_x-2][People_y]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1-1][Box2_y1]==5&&Map2[People_x-2][People_y]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1-1][Box2_y1]==7&&Map2[People_x-2][People_y]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1-1][Box2_y1]==10&&Map2[People_x-2][People_y]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2-1][Box2_y2]==5&&Map2[People_x-2][People_y]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2-1][Box2_y2]==7&&Map2[People_x-2][People_y]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2-1][Box2_y2]==10&&Map2[People_x-2][People_y]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }

        else if(Map2[People_x-1][People_y]!=6&&Map2[People_x-1][People_y]==3&&Map2[People_x-1][People_y]!=9&&Map2[Box2_x-1][Box2_y]!=0&&Map2[Box2_x-1][Box2_y]!=1){
           People_x--;
           Box2_x--;
           Map2[People_x+1][People_y]=2;
           Map2[Box2_x+1][Box2_y]=2;
         }
        else if(Map2[People_x-1][People_y]==6&Map2[People_x-1][People_y]!=3&&Map2[People_x-1][People_y]!=9&&Map2[Box2_x1-1][Box2_y1]!=0&&Map2[Box2_x1-1][Box2_y1]!=1){
           People_x--;
           Box2_x1--;
           Map2[People_x+1][People_y]=2;
           Map2[Box2_x1+1][Box2_y1]=2;
         }
         else if(Map2[People_x-1][People_y]!=6&Map2[People_x-1][People_y]!=3&&Map2[People_x-1][People_y]==9&&Map2[Box2_x1-1][Box2_y1]!=0&&Map2[Box2_x1-1][Box2_y1]!=1){
            People_x--;
            Box2_x2--;
            Map2[People_x+1][People_y]=2;
            Map2[Box2_x2+1][Box2_y2]=2;
          }
         else{
           People_x--;
           Map2[People_x+1][People_y]=2;
         }
     }
     if(input=='s'){
       if(People_x>7||Map2[People_x+1][People_y]==1){
         ;
       }
       else if((Map2[People_x+1][People_y]==Map2[Box2_x][Box2_y]&&Map2[Box2_x+1][Box2_y]==0)||(Map2[People_x+1][People_y]==Map2[Box2_x1][Box2_y1]&&Map2[Box2_x1+1][Box2_y1]==0)
     ||(Map2[People_x+1][People_y]==Map2[Box2_x2][Box2_y2]&&Map2[Box2_x2+1][Box2_y2]==0)){
         ;
       }
       else if((Map2[People_x+1][People_y]==Map2[Box2_x][Box2_y]&&Map2[Box2_x+1][Box2_y]==1)||(Map2[People_x+1][People_y]==Map2[Box2_x1][Box2_y1]&&Map2[Box2_x1+1][Box2_y1]==1)
     ||(Map2[People_x+1][People_y]==Map2[Box2_x2][Box2_y2]&&Map2[Box2_x2+1][Box2_y2]==1)){
         ;
       }
       else if(Map2[People_x+1][People_y]==6&&Map2[Box2_x1+1][Box2_y1]==3){
         ;
       }
       else if(Map2[People_x+1][People_y]==6&&Map2[Box2_x1+1][Box2_y1]==9){
         ;
       }
       else if(Map2[People_x+1][People_y]==3&&Map2[Box2_x+1][Box2_y]==6){
         ;
       }
       else if(Map2[People_x+1][People_y]==3&&Map2[Box2_x+1][Box2_y]==9){
         ;
       }
       else if(Map2[People_x+1][People_y]==9&&Map2[Box2_x2+1][Box2_y2]==3){
         ;
       }
       else if(Map2[People_x+1][People_y]==9&&Map2[Box2_x2+1][Box2_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){


       else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x+1==Box2_x&&People_y==Box2_y){
          Map2[Seat2_x][Seat2_y]=5;
          People_x++;
          Box2_x++;
        }
       else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x+1==Box2_x1&&People_y==Box2_y1){
          Map2[Seat2_x][Seat2_y]=5;
          People_x++;
          Box2_x1++;
        }
        else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x+1==Box2_x2&&People_y==Box2_y2){
           Map2[Seat2_x][Seat2_y]=5;
           People_x++;
           Box2_x2++;
         }
       else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x+1==Box2_x&&People_y==Box2_y){
          Map2[Seat2_x1][Seat2_y1]=7;
          People_x++;
          Box2_x++;
        }
       else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x+1==Box2_x1&&People_y==Box2_y1){
          Map2[Seat2_x1][Seat2_y1]=7;
          People_x++;
          Box2_x1++;
        }
        else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x+1==Box2_x2&&People_y==Box2_y2){
           Map2[Seat2_x1][Seat2_y1]=7;
           People_x++;
           Box2_x2++;
         }
        else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x+1==Box2_x&&People_y==Box2_y){
           Map2[Seat2_x2][Seat2_y2]=10;
           People_x++;
           Box2_x++;
         }else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x+1==Box2_x1&&People_y==Box2_y1){
            Map2[Seat2_x2][Seat2_y2]=10;
            People_x++;
            Box2_x1++;
          }
          else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x+1==Box2_x2&&People_y==Box2_y2){
             Map2[Seat2_x2][Seat2_y2]=10;
             People_x++;
             Box2_x2++;
           }
      // }


       else if((People_x==Seat2_x&&People_y==Seat2_y&&Map2[Seat2_x+1][Seat2_y]!=0)||(People_x==Seat2_x&&People_y==Seat2_y&&Map2[Seat2_x+1][Seat2_y]!=1)){
         People_x++;
         Map2[Seat2_x][Seat2_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat2_x1&&People_y==Seat2_y1&&Map2[Seat2_x1+1][Seat2_y1]!=0)||(People_x==Seat2_x1&&People_y==Seat2_y1&&Map2[Seat2_x1+1][Seat2_y1]!=1)){
         People_x++;
         Map2[Seat2_x1][Seat2_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat2_x2&&People_y==Seat2_y2&&Map2[Seat2_x2+1][Seat2_y1]!=0)||(People_x==Seat2_x2&&People_y==Seat2_y2&&Map2[Seat2_x2+1][Seat2_y2]!=1)){
         People_x++;
         Map2[Seat2_x2][Seat2_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map2[Box2_x+1][Box2_y]==5&&Map2[People_x+2][People_y]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x+1][Box2_y]==7&&Map2[People_x+2][People_y]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x+1][Box2_y]==10&&Map2[People_x+2][People_y]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1+1][Box2_y1]==5&&Map2[People_x+2][People_y]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1+1][Box2_y1]==7&&Map2[People_x+2][People_y]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1+1][Box2_y1]==10&&Map2[People_x+2][People_y]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2+1][Box2_y2]==5&&Map2[People_x+2][People_y]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2+1][Box2_y2]==7&&Map2[People_x+2][People_y]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2+1][Box2_y2]==10&&Map2[People_x+2][People_y]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }


       else if(Map2[People_x+1][People_y]!=6&&Map2[People_x+1][People_y]==3&&Map2[People_x+1][People_y]!=9&&Map2[Box2_x+1][Box2_y]!=0&&Map2[Box2_x+1][Box2_y]!=1){
          People_x++;
          Box2_x++;
          Map2[People_x-1][People_y]=2;
          Map2[Box2_x-1][Box2_y]=2;
        }
       else if(Map2[People_x+1][People_y]==6&Map2[People_x+1][People_y]!=3&&Map2[People_x+1][People_y]!=9&&Map2[Box2_x1+1][Box2_y1]!=0&&Map2[Box2_x1+1][Box2_y1]!=1){
          People_x++;
          Box2_x1++;
          Map2[People_x-1][People_y]=2;
          Map2[Box2_x1-1][Box2_y1]=2;
        }
        else if(Map2[People_x+1][People_y]!=6&Map2[People_x+1][People_y]!=3&&Map2[People_x+1][People_y]==9&&Map2[Box2_x2+1][Box2_y2]!=0&&Map2[Box2_x2+1][Box2_y2]!=1){
           People_x++;
           Box2_x2++;
           Map2[People_x-1][People_y]=2;
           Map2[Box2_x2-1][Box2_y2]=2;
         }
         else{
           People_x++;
           Map2[People_x-1][People_y]=2;
         }
     }
     if(input=='a'){
       if(People_y<2||Map2[People_x][People_y-1]==1){
         ;
       }
       else if((Map2[People_x][People_y-1]==Map2[Box2_x][Box2_y]&&Map2[Box2_x][Box2_y-1]==0)||
       (Map2[People_x][People_y-1]==Map2[Box2_x1][Box2_y1]&&Map2[Box2_x1][Box2_y1-1]==0)
       ||(Map2[People_x][People_y-1]==Map2[Box2_x2][Box2_y2]&&Map2[Box2_x2][Box2_y2-1]==0)){
         ;
       }
       else if((Map2[People_x][People_y-1]==Map2[Box2_x][Box2_y]&&Map2[Box2_x][Box2_y-1]==1)||
       (Map2[People_x][People_y-1]==Map2[Box2_x1][Box2_y1]&&Map2[Box2_x1][Box2_y1-1]==1)
       ||(Map2[People_x][People_y-1]==Map2[Box2_x2][Box2_y2]&&Map2[Box2_x2][Box2_y2-1]==1)){
         ;
       }
       else if(Map2[People_x][People_y-1]==6&&Map2[Box2_x1][Box2_y1-1]==3){
         ;
       }
       else if(Map2[People_x][People_y-1]==6&&Map2[Box2_x1][Box2_y1-1]==9){
         ;
       }
       else if(Map2[People_x][People_y-1]==3&&Map2[Box2_x][Box2_y-1]==6){
         ;
       }
       else if(Map2[People_x][People_y-1]==3&&Map2[Box2_x][Box2_y-1]==9){
         ;
       }
       else if(Map2[People_x][People_y-1]==9&&Map2[Box2_x2][Box2_y2-1]==3){
         ;
       }
       else if(Map2[People_x][People_y-1]==9&&Map2[Box2_x2][Box2_y2-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x==Box2_x&&People_y-1==Box2_y){
           Map2[Seat2_x][Seat2_y]=5;
           People_y--;
           Box2_y--;
         }
        else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x==Box2_x1&&People_y-1==Box2_y1){
           Map2[Seat2_x][Seat2_y]=5;
           People_y--;
           Box2_y1--;
         }
         else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x==Box2_x2&&People_y-1==Box2_y2){
            Map2[Seat2_x][Seat2_y]=5;
            People_y--;
            Box2_y2--;
          }
        else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x==Box2_x&&People_y-1==Box2_y){
           Map2[Seat2_x1][Seat2_y1]=7;
           People_y--;
           Box2_y--;
         }
        else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x==Box2_x1&&People_y-1==Box2_y1){
           Map2[Seat2_x1][Seat2_y1]=7;
           People_y--;
           Box2_y1--;
         }
         else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x==Box2_x2&&People_y-1==Box2_y2){
            Map2[Seat2_x1][Seat2_y1]=7;
            People_y--;
            Box2_y2--;
          }
         else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x==Box2_x&&People_y-1==Box2_y){
            Map2[Seat2_x2][Seat2_y2]=10;
            People_y--;
            Box2_y--;
          }else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x==Box2_x1&&People_y-1==Box2_y1){
             Map2[Seat2_x2][Seat2_y2]=10;
             People_y--;
             Box2_y1--;
           }
           else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x==Box2_x2&&People_y-1==Box2_y2){
              Map2[Seat2_x2][Seat2_y2]=10;
              People_y--;
              Box2_y2--;
            }
       //}


       else if((People_x==Seat2_x&&People_y==Seat2_y&&Map2[Seat2_x][Seat2_y-1]!=0)||(People_x==Seat2_x&&People_y==Seat2_y&&Map2[Seat2_x][Seat2_y-1]!=1)){
         People_y--;
         Map2[Seat2_x][Seat2_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat2_x1&&People_y==Seat2_y1&&Map2[Seat2_x1][Seat2_y1-1]!=0)||(People_x==Seat2_x1&&People_y==Seat2_y1&&Map2[Seat2_x1][Seat2_y1-1]!=1)){
         People_y--;
         Map2[Seat2_x1][Seat2_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat2_x2&&People_y==Seat2_y2&&Map2[Seat2_x2][Seat2_y2-1]!=0)||(People_x==Seat2_x2&&People_y==Seat2_y2&&Map2[Seat2_x2][Seat2_y2-1]!=1)){
         People_y--;
         Map2[Seat2_x2][Seat2_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map2[Box2_x][Box2_y-1]==5&&Map2[People_x][People_y-2]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1][Box2_y1-1]==5&&Map2[People_x][People_y-2]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2][Box2_y2-1]==5&&Map2[People_x][People_y-2]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x][Box2_y-1]==7&&Map2[People_x][People_y-2]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1][Box2_y1-1]==7&&Map2[People_x][People_y-2]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2][Box2_y2-1]==7&&Map2[People_x][People_y-2]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1][Box2_y1-1]==10&&Map2[People_x][People_y-2]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x][Box2_y-1]==10&&Map2[People_x][People_y-2]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2][Box2_y2-1]==10&&Map2[People_x][People_y-2]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }

        else if(Map2[People_x][People_y-1]!=6&&Map2[People_x][People_y-1]==3&&Map2[People_x][People_y-1]!=9&&Map2[Box2_x][Box2_y-1]!=0&&Map2[Box2_x][Box2_y-1]!=1){
           People_y--;
           Box2_y--;
           Map2[People_x][People_y+1]=2;
           Map2[Box2_x][Box2_y+1]=2;
         }
        else if(Map2[People_x][People_y-1]==6&Map2[People_x][People_y-1]!=3&&Map2[People_x][People_y-1]!=9&&Map2[Box2_x1][Box2_y1-1]!=0&&Map2[Box2_x1][Box2_y1-1]!=1){
           People_y--;
           Box2_y1--;
           Map2[People_x][People_y+1]=2;
           Map2[Box2_x1][Box2_y1+1]=2;
         }
         else if(Map2[People_x][People_y-1]!=6&Map2[People_x][People_y-1]!=3&&Map2[People_x][People_y-1]==9&&Map2[Box2_x2][Box2_y2-1]!=0&&Map2[Box2_x2][Box2_y2-1]!=1){
            People_y--;
            Box2_y2--;
            Map2[People_x][People_y+1]=2;
            Map2[Box2_x2][Box2_y2+1]=2;
          }
         else{
           People_y--;
           Map2[People_x][People_y+1]=2;
         }
     }
     if(input=='d'){
       if(People_y>10||Map2[People_x][People_y+1]==1){
         ;
       }
       else if((Map2[People_x][People_y+1]==Map2[Box2_x][Box2_y]&&Map2[Box2_x][Box2_y+1]==0)
       ||(Map2[People_x][People_y+1]==Map2[Box2_x1][Box2_y1]&&Map2[Box2_x1][Box2_y1+1]==0)
       ||(Map2[People_x][People_y+1]==Map2[Box2_x2][Box2_y2]&&Map2[Box2_x2][Box2_y2+1]==0)){
         ;
       }
       else if((Map2[People_x][People_y+1]==Map2[Box2_x][Box2_y]&&Map2[Box2_x][Box2_y+1]==1)
       ||(Map2[People_x][People_y+1]==Map2[Box2_x1][Box2_y1]&&Map2[Box2_x1][Box2_y1+1]==1)
       ||(Map2[People_x][People_y+1]==Map2[Box2_x2][Box2_y2]&&Map2[Box2_x2][Box2_y2+1]==1)){
         ;
       }
       else if(Map2[People_x][People_y+1]==6&&Map2[Box2_x1][Box2_y1+1]==3){
         ;
       }
       else if(Map2[People_x][People_y+1]==6&&Map2[Box2_x1][Box2_y1+1]==9){
         ;
       }
       else if(Map2[People_x][People_y+1]==3&&Map2[Box2_x][Box2_y+1]==6){
         ;
       }
       else if(Map2[People_x][People_y+1]==3&&Map2[Box2_x][Box2_y+1]==9){
         ;
       }
       else if(Map2[People_x][People_y+1]==9&&Map2[Box2_x2][Box2_y2+1]==3){
         ;
       }
       else if(Map2[People_x][People_y+1]==9&&Map2[Box2_x2][Box2_y2+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x==Box2_x&&People_y+1==Box2_y){
           Map2[Seat2_x][Seat2_y]=5;
           People_y++;
           Box2_y++;
         }
        else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x==Box2_x1&&People_y+1==Box2_y1){
           Map2[Seat2_x][Seat2_y]=5;
           People_y++;
           Box2_y1++;
         }
         else if(People_x==Seat2_x&&People_y==Seat2_y&&People_x==Box2_x2&&People_y+1==Box2_y2){
            Map2[Seat2_x][Seat2_y]=5;
            People_y++;
            Box2_y2++;
          }
        else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x==Box2_x&&People_y+1==Box2_y){
           Map2[Seat2_x1][Seat2_y1]=7;
           People_y++;
           Box2_y++;
         }
        else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x==Box2_x1&&People_y+1==Box2_y1){
           Map2[Seat2_x1][Seat2_y1]=7;
           People_y++;
           Box2_y1++;
         }
         else if(People_x==Seat2_x1&&People_y==Seat2_y1&&People_x==Box2_x2&&People_y+1==Box2_y2){
            Map2[Seat2_x1][Seat2_y1]=7;
            People_y++;
            Box2_y2++;
          }
         else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x==Box2_x&&People_y+1==Box2_y){
            Map2[Seat2_x2][Seat2_y2]=10;
            People_y++;
            Box2_y++;
          }else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x==Box2_x1&&People_y+1==Box2_y1){
             Map2[Seat2_x2][Seat2_y2]=10;
             People_y++;
             Box2_y1++;
           }
           else if(People_x==Seat2_x2&&People_y==Seat2_y2&&People_x==Box2_x2&&People_y+1==Box2_y2){
              Map2[Seat2_x2][Seat2_y2]=10;
              People_y++;
              Box2_y2++;
            }
       //}


       else if((People_x==Seat2_x&&People_y==Seat2_y&&Map2[Seat2_x][Seat2_y+1]!=0)||(People_x==Seat2_x&&People_y==Seat2_y&&Map2[Seat2_x][Seat2_y+1]!=1)){
         People_y++;
         Map2[Seat2_x][Seat2_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat2_x1&&People_y==Seat2_y1&&Map2[Seat2_x1][Seat2_y1+1]!=0)||(People_x==Seat2_x1&&People_y==Seat2_y1&&Map2[Seat2_x1][Seat2_y1+1]!=1)){
         People_y++;
         Map2[Seat2_x1][Seat2_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat2_x2&&People_y==Seat2_y2&&Map2[Seat2_x2][Seat2_y2+1]!=0)||(People_x==Seat2_x2&&People_y==Seat2_y2&&Map2[Seat2_x2][Seat2_y2+1]!=1)){
         People_y++;
         Map2[Seat2_x2][Seat2_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map2[Box2_x][Box2_y+1]==5&&Map2[People_x][People_y+2]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x][Box2_y+1]==7&&Map2[People_x][People_y+2]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x][Box2_y+1]==10&&Map2[People_x][People_y+2]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x][Box2_y]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1][Box2_y1+1]==5&&Map2[People_x][People_y+2]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1][Box2_y1+1]==7&&Map2[People_x][People_y+2]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x1][Box2_y1+1]==10&&Map2[People_x][People_y+2]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x1][Box2_y1]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2][Box2_y2+1]==5&&Map2[People_x][People_y+2]==5){
         Map2[Seat2_x][Seat2_y]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2][Box2_y2+1]==7&&Map2[People_x][People_y+2]==7){
         Map2[Seat2_x1][Seat2_y1]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }
       else if(Map2[Box2_x2][Box2_y2+1]==10&&Map2[People_x][People_y+2]==10){
         Map2[Seat2_x2][Seat2_y2]=8;
         Map2[Box2_x2][Box2_y2]=4;
         Map2[People_x][People_y]=2;
       }

        else if(Map2[People_x][People_y+1]!=6&&Map2[People_x][People_y+1]==3&&Map2[People_x][People_y+1]!=9&&Map2[Box2_x][Box2_y+1]!=0&&Map2[Box2_x][Box2_y+1]!=1){
           People_y++;
           Box2_y++;
           Map2[People_x][People_y-1]=2;
           Map2[Box2_x][Box2_y-1]=2;
         }
        else if(Map2[People_x][People_y+1]==6&Map2[People_x][People_y+1]!=3&&Map2[People_x][People_y+1]!=9&&Map2[Box2_x1][Box2_y1+1]!=0&&Map2[Box2_x1][Box2_y1+1]!=1){
           People_y++;
           Box2_y1++;
           Map2[People_x][People_y-1]=2;
           Map2[Box2_x1][Box2_y1-1]=2;
         }
         else if(Map2[People_x][People_y+1]!=6&Map2[People_x][People_y+1]!=3&&Map2[People_x][People_y+1]==9&&Map2[Box2_x2][Box2_y2+1]!=0&&Map2[Box2_x2][Box2_y2+1]!=1){
            People_y++;
            Box2_y2++;
            Map2[People_x][People_y-1]=2;
            Map2[Box2_x2][Box2_y2-1]=2;
          }
         else{
           People_y++;
           Map2[People_x][People_y-1]=2;
         }
     }
   }
}



//game 3
int Box3_x,Box3_y;
int Box3_x1,Box3_y1;
int Box3_x2,Box3_y2;
int Seat3_x,Seat3_y;
int Seat3_x1,Seat3_y1;
int Seat3_x2,Seat3_y2;
int Map3[MAPMAX][MAPMAX+3] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,2,2,2,2,2,2,2,1,1,2,2,0},
  {0,1,1,1,2,1,1,2,1,2,2,2,0},
  {0,1,1,1,2,1,1,2,2,2,2,2,0},
  {0,2,2,2,2,2,2,2,2,2,2,2,0},
  {0,2,1,2,2,1,1,1,1,1,2,2,0},
  {0,2,2,2,2,2,2,2,2,2,2,2,0},
  {0,2,1,1,1,2,2,1,1,1,1,1,0},
  {0,2,2,2,2,2,1,1,2,2,2,2,2},
  {0,0,0,0,0,0,0,0,2,2,2,2,2},
};
void Map_Start3()
{
      Map3[People_x][People_y]=4;
      Map3[Box3_x][Box3_y]=3;
      Map3[Box3_x1][Box3_y1]=6;
      Map3[Box3_x2][Box3_y2]=9;
}
void Seat_Set3()
{
  if(Map3[Seat3_x][Seat3_y]!=8){
    Map3[Seat3_x][Seat3_y]=5;
  }
  if(Map3[Seat3_x1][Seat3_y1]!=8){
      Map3[Seat3_x1][Seat3_y1]=7;
  }
  if(Map3[Seat3_x2][Seat3_y2]!=8){
    Map3[Seat3_x2][Seat3_y2]=10;
  }
}
void Creat_Seat3()
{
  People_x=1;
  People_y=1;
  Box3_x=3;
  Box3_y=8;
  Box3_x1=6;
  Box3_y1=10;
  Box3_x2=2;
  Box3_y2=10;
  Seat3_x=7;
  Seat3_y=1;
  Seat3_x1=6;
  Seat3_y1=4;
  Seat3_x2=4;
  Seat3_y2=2;
  Map3[Seat3_x][Seat3_y]=5;
  Map3[Seat3_x1][Seat3_y1]=7;
  Map3[Seat3_x2][Seat3_y2]=10;
}
void HideCursor3()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy3(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
int Search_Box3()
{
  if(Box3_x==Seat3_x&&Box3_y==Seat3_y&&Box3_x1==Seat3_x1&&Box3_y1==Seat3_y1&&Box3_x2==Seat3_x2&&Box3_y2==Seat3_y2){
    return 1;
  }
  if(Box3_x==Seat3_x&&Box3_y==Seat3_y&&Box3_x1==Seat3_x2&&Box3_y1==Seat3_y2&&Box3_x2==Seat3_x1&&Box3_y2==Seat3_y1){
    return 1;
  }
  if(Box3_x==Seat3_x1&&Box3_y==Seat3_y1&&Box3_x1==Seat3_x&&Box3_y1==Seat3_y&&Box3_x2==Seat3_x2&&Box3_y2==Seat3_y2){
    return 1;
  }
  if(Box3_x==Seat3_x2&&Box3_y==Seat3_y2&&Box3_x1==Seat3_x1&&Box3_y1==Seat3_y1&&Box3_x2==Seat3_x&&Box3_y2==Seat3_y){
    return 1;
  }
  if(Box3_x==Seat3_x1&&Box3_y==Seat3_y1&&Box3_x1==Seat3_x2&&Box3_y1==Seat3_y2&&Box3_x2==Seat3_x&&Box3_y2==Seat3_y){
    return 1;
  }
  if(Box3_x==Seat3_x2&&Box3_y==Seat3_y2&&Box3_x1==Seat3_x&&Box3_y1==Seat3_y&&Box3_x2==Seat3_x1&&Box3_y2==Seat3_y1){
    return 1;
  }
}
void Creat_Map3()
{
  gotoxy3(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map3[i][j]==0){
        cout<<"■";
      }
      if(Map3[i][j]==1){
        cout<<"■";
      }
      if(Map3[i][j]==2){
        cout<<"  ";
      }
      if(Map3[i][j]==3){
        cout<<"□";
      }
      if(Map3[i][j]==4){
        cout<<"♀";
      }
      if(Map3[i][j]==5){
        cout<<"●";
      }
      if(Map3[i][j]==7){
        cout<<"●";
      }
      if(Map3[i][j]==6){
        cout<<"□";
      }
      if(Map3[i][j]==8){
        cout<<"□";
      }
      if(Map3[i][j]==9){
        cout<<"□";
      }
      if(Map3[i][j]==10){
        cout<<"●";
      }
    }
    cout<<endl;
  }
  cout<<"game three"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move3()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map3[People_x-1][People_y]==1){
         ;
       }
       else if((Map3[People_x-1][People_y]==Map3[Box3_x][Box3_y]&&Map3[Box3_x-1][Box3_y]==0)||(Map3[People_x-1][People_y]==Map3[Box3_x1][Box3_y1]&&Map3[Box3_x1-1][Box3_y1]==0)
     ||(Map3[People_x-1][People_y]==Map3[Box3_x2][Box3_y2]&&Map3[Box3_x2-1][Box3_y2]==0)){
         ;
       }
       else if((Map3[People_x-1][People_y]==Map3[Box3_x][Box3_y]&&Map3[Box3_x-1][Box3_y]==1)||(Map3[People_x-1][People_y]==Map3[Box3_x1][Box3_y1]&&Map3[Box3_x1-1][Box3_y1]==1)
     ||(Map3[People_x-1][People_y]==Map3[Box3_x2][Box3_y2]&&Map3[Box3_x2-1][Box3_y2]==1)){
         ;
       }
       else if(Map3[People_x-1][People_y]==6&&Map3[Box3_x1-1][Box3_y1]==3){
         ;
       }
       else if(Map3[People_x-1][People_y]==6&&Map3[Box3_x1-1][Box3_y1]==9){
         ;
       }
       else if(Map3[People_x-1][People_y]==3&&Map3[Box3_x-1][Box3_y]==6){
         ;
       }
       else if(Map3[People_x-1][People_y]==3&&Map3[Box3_x-1][Box3_y]==9){
         ;
       }
       else if(Map3[People_x-1][People_y]==9&&Map3[Box3_x2-1][Box3_y2]==3){
         ;
       }
       else if(Map3[People_x-1][People_y]==9&&Map3[Box3_x2-1][Box3_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x-1==Box3_x&&People_y==Box3_y){
           Map3[Seat3_x][Seat3_y]=5;
           People_x--;
           Box3_x--;
         }
        else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x-1==Box3_x1&&People_y==Box3_y1){
           Map3[Seat3_x][Seat3_y]=5;
           People_x--;
           Box3_x1--;
         }
         else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x-1==Box3_x2&&People_y==Box3_y2){
            Map3[Seat3_x][Seat3_y]=5;
            People_x--;
            Box3_x2--;
          }
        else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x-1==Box3_x&&People_y==Box3_y){
           Map3[Seat3_x1][Seat3_y1]=7;
           People_x--;
           Box3_x--;
         }
        else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x-1==Box3_x1&&People_y==Box3_y1){
           Map3[Seat3_x1][Seat3_y1]=7;
           People_x--;
           Box3_x1--;
         }
         else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x-1==Box3_x2&&People_y==Box3_y2){
            Map3[Seat3_x1][Seat3_y1]=7;
            People_x--;
            Box3_x2--;
          }
         else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x-1==Box3_x&&People_y==Box3_y){
            Map3[Seat3_x2][Seat3_y2]=10;
            People_x--;
            Box3_x--;
          }
          else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x-1==Box3_x1&&People_y==Box3_y1){
             Map3[Seat3_x2][Seat3_y2]=10;
             People_x--;
             Box3_x1--;
           }
           else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x-1==Box3_x2&&People_y==Box3_y2){
              Map3[Seat3_x2][Seat3_y2]=10;
              People_x--;
              Box3_x2--;
            }
       //}


       else if((People_x==Seat3_x&&People_y==Seat3_y&&Map3[Seat3_x-1][Seat3_y]!=0)||(People_x==Seat3_x&&People_y==Seat3_y&&Map3[Seat3_x-1][Seat3_y]!=1)){
         People_x--;
         Map3[Seat3_x][Seat3_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat3_x1&&People_y==Seat3_y1&&Map3[Seat3_x1-1][Seat3_y1]!=0)||(People_x==Seat3_x1&&People_y==Seat3_y1&&Map3[Seat3_x1-1][Seat3_y1]!=1)){
         People_x--;
         Map3[Seat3_x1][Seat3_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat3_x2&&People_y==Seat3_y2&&Map3[Seat3_x2-1][Seat3_y2]!=0)||(People_x==Seat3_x2&&People_y==Seat3_y2&&Map3[Seat3_x2-1][Seat3_y2]!=1)){
         People_x--;
         Map3[Seat3_x2][Seat3_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map3[Box3_x-1][Box3_y]==5&&Map3[People_x-2][People_y]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x-1][Box3_y]==7&&Map3[People_x-2][People_y]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x-1][Box3_y]==10&&Map3[People_x-2][People_y]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1-1][Box3_y1]==5&&Map3[People_x-2][People_y]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1-1][Box3_y1]==7&&Map3[People_x-2][People_y]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1-1][Box3_y1]==10&&Map3[People_x-2][People_y]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2-1][Box3_y2]==5&&Map3[People_x-2][People_y]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2-1][Box3_y2]==7&&Map3[People_x-2][People_y]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2-1][Box3_y2]==10&&Map3[People_x-2][People_y]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }

        else if(Map3[People_x-1][People_y]!=6&&Map3[People_x-1][People_y]==3&&Map3[People_x-1][People_y]!=9&&Map3[Box3_x-1][Box3_y]!=0&&Map3[Box3_x-1][Box3_y]!=1){
           People_x--;
           Box3_x--;
           Map3[People_x+1][People_y]=2;
           Map3[Box3_x+1][Box3_y]=2;
         }
        else if(Map3[People_x-1][People_y]==6&Map3[People_x-1][People_y]!=3&&Map3[People_x-1][People_y]!=9&&Map3[Box3_x1-1][Box3_y1]!=0&&Map3[Box3_x1-1][Box3_y1]!=1){
           People_x--;
           Box3_x1--;
           Map3[People_x+1][People_y]=2;
           Map3[Box3_x1+1][Box3_y1]=2;
         }
         else if(Map3[People_x-1][People_y]!=6&Map3[People_x-1][People_y]!=3&&Map3[People_x-1][People_y]==9&&Map3[Box3_x1-1][Box3_y1]!=0&&Map3[Box3_x1-1][Box3_y1]!=1){
            People_x--;
            Box3_x2--;
            Map3[People_x+1][People_y]=2;
            Map3[Box3_x2+1][Box3_y2]=2;
          }
         else{
           People_x--;
           Map3[People_x+1][People_y]=2;
         }
     }
     if(input=='s'){
       if(People_x>7||Map3[People_x+1][People_y]==1){
         ;
       }
       else if((Map3[People_x+1][People_y]==Map3[Box3_x][Box3_y]&&Map3[Box3_x+1][Box3_y]==0)||(Map3[People_x+1][People_y]==Map3[Box3_x1][Box3_y1]&&Map3[Box3_x1+1][Box3_y1]==0)
     ||(Map3[People_x+1][People_y]==Map3[Box3_x2][Box3_y2]&&Map3[Box3_x2+1][Box3_y2]==0)){
         ;
       }
       else if((Map3[People_x+1][People_y]==Map3[Box3_x][Box3_y]&&Map3[Box3_x+1][Box3_y]==1)||(Map3[People_x+1][People_y]==Map3[Box3_x1][Box3_y1]&&Map3[Box3_x1+1][Box3_y1]==1)
     ||(Map3[People_x+1][People_y]==Map3[Box3_x2][Box3_y2]&&Map3[Box3_x2+1][Box3_y2]==1)){
         ;
       }
       else if(Map3[People_x+1][People_y]==6&&Map3[Box3_x1+1][Box3_y1]==3){
         ;
       }
       else if(Map3[People_x+1][People_y]==6&&Map3[Box3_x1+1][Box3_y1]==9){
         ;
       }
       else if(Map3[People_x+1][People_y]==3&&Map3[Box3_x+1][Box3_y]==6){
         ;
       }
       else if(Map3[People_x+1][People_y]==3&&Map3[Box3_x+1][Box3_y]==9){
         ;
       }
       else if(Map3[People_x+1][People_y]==9&&Map3[Box3_x2+1][Box3_y2]==3){
         ;
       }
       else if(Map3[People_x+1][People_y]==9&&Map3[Box3_x2+1][Box3_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){


       else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x+1==Box3_x&&People_y==Box3_y){
          Map3[Seat3_x][Seat3_y]=5;
          People_x++;
          Box3_x++;
        }
       else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x+1==Box3_x1&&People_y==Box3_y1){
          Map3[Seat3_x][Seat3_y]=5;
          People_x++;
          Box3_x1++;
        }
        else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x+1==Box3_x2&&People_y==Box3_y2){
           Map3[Seat3_x][Seat3_y]=5;
           People_x++;
           Box3_x2++;
         }
       else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x+1==Box3_x&&People_y==Box3_y){
          Map3[Seat3_x1][Seat3_y1]=7;
          People_x++;
          Box3_x++;
        }
       else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x+1==Box3_x1&&People_y==Box3_y1){
          Map3[Seat3_x1][Seat3_y1]=7;
          People_x++;
          Box3_x1++;
        }
        else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x+1==Box3_x2&&People_y==Box3_y2){
           Map3[Seat3_x1][Seat3_y1]=7;
           People_x++;
           Box3_x2++;
         }
        else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x+1==Box3_x&&People_y==Box3_y){
           Map3[Seat3_x2][Seat3_y2]=10;
           People_x++;
           Box3_x++;
         }else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x+1==Box3_x1&&People_y==Box3_y1){
            Map3[Seat3_x2][Seat3_y2]=10;
            People_x++;
            Box3_x1++;
          }
          else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x+1==Box3_x2&&People_y==Box3_y2){
             Map3[Seat3_x2][Seat3_y2]=10;
             People_x++;
             Box3_x2++;
           }
      // }


       else if((People_x==Seat3_x&&People_y==Seat3_y&&Map3[Seat3_x+1][Seat3_y]!=0)||(People_x==Seat3_x&&People_y==Seat3_y&&Map3[Seat3_x+1][Seat3_y]!=1)){
         People_x++;
         Map3[Seat3_x][Seat3_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat3_x1&&People_y==Seat3_y1&&Map3[Seat3_x1+1][Seat3_y1]!=0)||(People_x==Seat3_x1&&People_y==Seat3_y1&&Map3[Seat3_x1+1][Seat3_y1]!=1)){
         People_x++;
         Map3[Seat3_x1][Seat3_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat3_x2&&People_y==Seat3_y2&&Map3[Seat3_x2+1][Seat3_y1]!=0)||(People_x==Seat3_x2&&People_y==Seat3_y2&&Map3[Seat3_x2+1][Seat3_y2]!=1)){
         People_x++;
         Map3[Seat3_x2][Seat3_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map3[Box3_x+1][Box3_y]==5&&Map3[People_x+2][People_y]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x+1][Box3_y]==7&&Map3[People_x+2][People_y]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x+1][Box3_y]==10&&Map3[People_x+2][People_y]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1+1][Box3_y1]==5&&Map3[People_x+2][People_y]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1+1][Box3_y1]==7&&Map3[People_x+2][People_y]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1+1][Box3_y1]==10&&Map3[People_x+2][People_y]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2+1][Box3_y2]==5&&Map3[People_x+2][People_y]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2+1][Box3_y2]==7&&Map3[People_x+2][People_y]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2+1][Box3_y2]==10&&Map3[People_x+2][People_y]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }


       else if(Map3[People_x+1][People_y]!=6&&Map3[People_x+1][People_y]==3&&Map3[People_x+1][People_y]!=9&&Map3[Box3_x+1][Box3_y]!=0&&Map3[Box3_x+1][Box3_y]!=1){
          People_x++;
          Box3_x++;
          Map3[People_x-1][People_y]=2;
          Map3[Box3_x-1][Box3_y]=2;
        }
       else if(Map3[People_x+1][People_y]==6&Map3[People_x+1][People_y]!=3&&Map3[People_x+1][People_y]!=9&&Map3[Box3_x1+1][Box3_y1]!=0&&Map3[Box3_x1+1][Box3_y1]!=1){
          People_x++;
          Box3_x1++;
          Map3[People_x-1][People_y]=2;
          Map3[Box3_x1-1][Box3_y1]=2;
        }
        else if(Map3[People_x+1][People_y]!=6&Map3[People_x+1][People_y]!=3&&Map3[People_x+1][People_y]==9&&Map3[Box3_x2+1][Box3_y2]!=0&&Map3[Box3_x2+1][Box3_y2]!=1){
           People_x++;
           Box3_x2++;
           Map3[People_x-1][People_y]=2;
           Map3[Box3_x2-1][Box3_y2]=2;
         }
         else{
           People_x++;
           Map3[People_x-1][People_y]=2;
         }
     }
     if(input=='a'){
       if(People_y<2||Map3[People_x][People_y-1]==1){
         ;
       }
       else if((Map3[People_x][People_y-1]==Map3[Box3_x][Box3_y]&&Map3[Box3_x][Box3_y-1]==0)||
       (Map3[People_x][People_y-1]==Map3[Box3_x1][Box3_y1]&&Map3[Box3_x1][Box3_y1-1]==0)
       ||(Map3[People_x][People_y-1]==Map3[Box3_x2][Box3_y2]&&Map3[Box3_x2][Box3_y2-1]==0)){
         ;
       }
       else if((Map3[People_x][People_y-1]==Map3[Box3_x][Box3_y]&&Map3[Box3_x][Box3_y-1]==1)||
       (Map3[People_x][People_y-1]==Map3[Box3_x1][Box3_y1]&&Map3[Box3_x1][Box3_y1-1]==1)
       ||(Map3[People_x][People_y-1]==Map3[Box3_x2][Box3_y2]&&Map3[Box3_x2][Box3_y2-1]==1)){
         ;
       }
       else if(Map3[People_x][People_y-1]==6&&Map3[Box3_x1][Box3_y1-1]==3){
         ;
       }
       else if(Map3[People_x][People_y-1]==6&&Map3[Box3_x1][Box3_y1-1]==9){
         ;
       }
       else if(Map3[People_x][People_y-1]==3&&Map3[Box3_x][Box3_y-1]==6){
         ;
       }
       else if(Map3[People_x][People_y-1]==3&&Map3[Box3_x][Box3_y-1]==9){
         ;
       }
       else if(Map3[People_x][People_y-1]==9&&Map3[Box3_x2][Box3_y2-1]==3){
         ;
       }
       else if(Map3[People_x][People_y-1]==9&&Map3[Box3_x2][Box3_y2-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x==Box3_x&&People_y-1==Box3_y){
           Map3[Seat3_x][Seat3_y]=5;
           People_y--;
           Box3_y--;
         }
        else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x==Box3_x1&&People_y-1==Box3_y1){
           Map3[Seat3_x][Seat3_y]=5;
           People_y--;
           Box3_y1--;
         }
         else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x==Box3_x2&&People_y-1==Box3_y2){
            Map3[Seat3_x][Seat3_y]=5;
            People_y--;
            Box3_y2--;
          }
        else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x==Box3_x&&People_y-1==Box3_y){
           Map3[Seat3_x1][Seat3_y1]=7;
           People_y--;
           Box3_y--;
         }
        else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x==Box3_x1&&People_y-1==Box3_y1){
           Map3[Seat3_x1][Seat3_y1]=7;
           People_y--;
           Box3_y1--;
         }
         else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x==Box3_x2&&People_y-1==Box3_y2){
            Map3[Seat3_x1][Seat3_y1]=7;
            People_y--;
            Box3_y2--;
          }
         else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x==Box3_x&&People_y-1==Box3_y){
            Map3[Seat3_x2][Seat3_y2]=10;
            People_y--;
            Box3_y--;
          }else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x==Box3_x1&&People_y-1==Box3_y1){
             Map3[Seat3_x2][Seat3_y2]=10;
             People_y--;
             Box3_y1--;
           }
           else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x==Box3_x2&&People_y-1==Box3_y2){
              Map3[Seat3_x2][Seat3_y2]=10;
              People_y--;
              Box3_y2--;
            }
       //}


       else if((People_x==Seat3_x&&People_y==Seat3_y&&Map3[Seat3_x][Seat3_y-1]!=0)||(People_x==Seat3_x&&People_y==Seat3_y&&Map3[Seat3_x][Seat3_y-1]!=1)){
         People_y--;
         Map3[Seat3_x][Seat3_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat3_x1&&People_y==Seat3_y1&&Map3[Seat3_x1][Seat3_y1-1]!=0)||(People_x==Seat3_x1&&People_y==Seat3_y1&&Map3[Seat3_x1][Seat3_y1-1]!=1)){
         People_y--;
         Map3[Seat3_x1][Seat3_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat3_x2&&People_y==Seat3_y2&&Map3[Seat3_x2][Seat3_y2-1]!=0)||(People_x==Seat3_x2&&People_y==Seat3_y2&&Map3[Seat3_x2][Seat3_y2-1]!=1)){
         People_y--;
         Map3[Seat3_x2][Seat3_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map3[Box3_x][Box3_y-1]==5&&Map3[People_x][People_y-2]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1][Box3_y1-1]==5&&Map3[People_x][People_y-2]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2][Box3_y2-1]==5&&Map3[People_x][People_y-2]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x][Box3_y-1]==7&&Map3[People_x][People_y-2]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1][Box3_y1-1]==7&&Map3[People_x][People_y-2]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2][Box3_y2-1]==7&&Map3[People_x][People_y-2]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1][Box3_y1-1]==10&&Map3[People_x][People_y-2]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x][Box3_y-1]==10&&Map3[People_x][People_y-2]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2][Box3_y2-1]==10&&Map3[People_x][People_y-2]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }

        else if(Map3[People_x][People_y-1]!=6&&Map3[People_x][People_y-1]==3&&Map3[People_x][People_y-1]!=9&&Map3[Box3_x][Box3_y-1]!=0&&Map3[Box3_x][Box3_y-1]!=1){
           People_y--;
           Box3_y--;
           Map3[People_x][People_y+1]=2;
           Map3[Box3_x][Box3_y+1]=2;
         }
        else if(Map3[People_x][People_y-1]==6&Map3[People_x][People_y-1]!=3&&Map3[People_x][People_y-1]!=9&&Map3[Box3_x1][Box3_y1-1]!=0&&Map3[Box3_x1][Box3_y1-1]!=1){
           People_y--;
           Box3_y1--;
           Map3[People_x][People_y+1]=2;
           Map3[Box3_x1][Box3_y1+1]=2;
         }
         else if(Map3[People_x][People_y-1]!=6&Map3[People_x][People_y-1]!=3&&Map3[People_x][People_y-1]==9&&Map3[Box3_x2][Box3_y2-1]!=0&&Map3[Box3_x2][Box3_y2-1]!=1){
            People_y--;
            Box3_y2--;
            Map3[People_x][People_y+1]=2;
            Map3[Box3_x2][Box3_y2+1]=2;
          }
         else{
           People_y--;
           Map3[People_x][People_y+1]=2;
         }
     }
     if(input=='d'){
       if(People_y>10||Map3[People_x][People_y+1]==1){
         ;
       }
       else if((Map3[People_x][People_y+1]==Map3[Box3_x][Box3_y]&&Map3[Box3_x][Box3_y+1]==0)
       ||(Map3[People_x][People_y+1]==Map3[Box3_x1][Box3_y1]&&Map3[Box3_x1][Box3_y1+1]==0)
       ||(Map3[People_x][People_y+1]==Map3[Box3_x2][Box3_y2]&&Map3[Box3_x2][Box3_y2+1]==0)){
         ;
       }
       else if((Map3[People_x][People_y+1]==Map3[Box3_x][Box3_y]&&Map3[Box3_x][Box3_y+1]==1)
       ||(Map3[People_x][People_y+1]==Map3[Box3_x1][Box3_y1]&&Map3[Box3_x1][Box3_y1+1]==1)
       ||(Map3[People_x][People_y+1]==Map3[Box3_x2][Box3_y2]&&Map3[Box3_x2][Box3_y2+1]==1)){
         ;
       }
       else if(Map3[People_x][People_y+1]==6&&Map3[Box3_x1][Box3_y1+1]==3){
         ;
       }
       else if(Map3[People_x][People_y+1]==6&&Map3[Box3_x1][Box3_y1+1]==9){
         ;
       }
       else if(Map3[People_x][People_y+1]==3&&Map3[Box3_x][Box3_y+1]==6){
         ;
       }
       else if(Map3[People_x][People_y+1]==3&&Map3[Box3_x][Box3_y+1]==9){
         ;
       }
       else if(Map3[People_x][People_y+1]==9&&Map3[Box3_x2][Box3_y2+1]==3){
         ;
       }
       else if(Map3[People_x][People_y+1]==9&&Map3[Box3_x2][Box3_y2+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x==Box3_x&&People_y+1==Box3_y){
           Map3[Seat3_x][Seat3_y]=5;
           People_y++;
           Box3_y++;
         }
        else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x==Box3_x1&&People_y+1==Box3_y1){
           Map3[Seat3_x][Seat3_y]=5;
           People_y++;
           Box3_y1++;
         }
         else if(People_x==Seat3_x&&People_y==Seat3_y&&People_x==Box3_x2&&People_y+1==Box3_y2){
            Map3[Seat3_x][Seat3_y]=5;
            People_y++;
            Box3_y2++;
          }
        else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x==Box3_x&&People_y+1==Box3_y){
           Map3[Seat3_x1][Seat3_y1]=7;
           People_y++;
           Box3_y++;
         }
        else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x==Box3_x1&&People_y+1==Box3_y1){
           Map3[Seat3_x1][Seat3_y1]=7;
           People_y++;
           Box3_y1++;
         }
         else if(People_x==Seat3_x1&&People_y==Seat3_y1&&People_x==Box3_x2&&People_y+1==Box3_y2){
            Map3[Seat3_x1][Seat3_y1]=7;
            People_y++;
            Box3_y2++;
          }
         else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x==Box3_x&&People_y+1==Box3_y){
            Map3[Seat3_x2][Seat3_y2]=10;
            People_y++;
            Box3_y++;
          }else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x==Box3_x1&&People_y+1==Box3_y1){
             Map3[Seat3_x2][Seat3_y2]=10;
             People_y++;
             Box3_y1++;
           }
           else if(People_x==Seat3_x2&&People_y==Seat3_y2&&People_x==Box3_x2&&People_y+1==Box3_y2){
              Map3[Seat3_x2][Seat3_y2]=10;
              People_y++;
              Box3_y2++;
            }
       //}


       else if((People_x==Seat3_x&&People_y==Seat3_y&&Map3[Seat3_x][Seat3_y+1]!=0)||(People_x==Seat3_x&&People_y==Seat3_y&&Map3[Seat3_x][Seat3_y+1]!=1)){
         People_y++;
         Map3[Seat3_x][Seat3_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat3_x1&&People_y==Seat3_y1&&Map3[Seat3_x1][Seat3_y1+1]!=0)||(People_x==Seat3_x1&&People_y==Seat3_y1&&Map3[Seat3_x1][Seat3_y1+1]!=1)){
         People_y++;
         Map3[Seat3_x1][Seat3_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat3_x2&&People_y==Seat3_y2&&Map3[Seat3_x2][Seat3_y2+1]!=0)||(People_x==Seat3_x2&&People_y==Seat3_y2&&Map3[Seat3_x2][Seat3_y2+1]!=1)){
         People_y++;
         Map3[Seat3_x2][Seat3_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map3[Box3_x][Box3_y+1]==5&&Map3[People_x][People_y+2]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x][Box3_y+1]==7&&Map3[People_x][People_y+2]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x][Box3_y+1]==10&&Map3[People_x][People_y+2]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x][Box3_y]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1][Box3_y1+1]==5&&Map3[People_x][People_y+2]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1][Box3_y1+1]==7&&Map3[People_x][People_y+2]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x1][Box3_y1+1]==10&&Map3[People_x][People_y+2]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x1][Box3_y1]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2][Box3_y2+1]==5&&Map3[People_x][People_y+2]==5){
         Map3[Seat3_x][Seat3_y]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2][Box3_y2+1]==7&&Map3[People_x][People_y+2]==7){
         Map3[Seat3_x1][Seat3_y1]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }
       else if(Map3[Box3_x2][Box3_y2+1]==10&&Map3[People_x][People_y+2]==10){
         Map3[Seat3_x2][Seat3_y2]=8;
         Map3[Box3_x2][Box3_y2]=4;
         Map3[People_x][People_y]=2;
       }

        else if(Map3[People_x][People_y+1]!=6&&Map3[People_x][People_y+1]==3&&Map3[People_x][People_y+1]!=9&&Map3[Box3_x][Box3_y+1]!=0&&Map3[Box3_x][Box3_y+1]!=1){
           People_y++;
           Box3_y++;
           Map3[People_x][People_y-1]=2;
           Map3[Box3_x][Box3_y-1]=2;
         }
        else if(Map3[People_x][People_y+1]==6&Map3[People_x][People_y+1]!=3&&Map3[People_x][People_y+1]!=9&&Map3[Box3_x1][Box3_y1+1]!=0&&Map3[Box3_x1][Box3_y1+1]!=1){
           People_y++;
           Box3_y1++;
           Map3[People_x][People_y-1]=2;
           Map3[Box3_x1][Box3_y1-1]=2;
         }
         else if(Map3[People_x][People_y+1]!=6&Map3[People_x][People_y+1]!=3&&Map3[People_x][People_y+1]==9&&Map3[Box3_x2][Box3_y2+1]!=0&&Map3[Box3_x2][Box3_y2+1]!=1){
            People_y++;
            Box3_y2++;
            Map3[People_x][People_y-1]=2;
            Map3[Box3_x2][Box3_y2-1]=2;
          }
         else{
           People_y++;
           Map3[People_x][People_y-1]=2;
         }
     }
   }
}



//game 4
int Box4_x,Box4_y;
int Box4_x1,Box4_y1;
int Box4_x2,Box4_y2;
int Seat4_x,Seat4_y;
int Seat4_x1,Seat4_y1;
int Seat4_x2,Seat4_y2;
int Map4[MAPMAX][MAPMAX+3] = {
  {2,0,0,0,0,0,0,0,0,2,2,2,2},
  {0,1,2,2,2,2,2,2,1,2,2,2,2},
  {0,2,2,1,1,1,2,2,1,1,1,2,2},
  {0,1,2,1,1,1,2,2,2,2,1,2,2},
  {0,2,2,1,1,1,2,2,2,2,1,2,2},
  {0,1,1,2,2,2,2,1,1,2,1,2,2},
  {2,2,1,2,2,2,2,1,1,2,1,2,2},
  {2,2,1,2,2,2,2,2,2,2,1,2,2},
  {2,2,1,2,2,2,2,2,2,2,1,2,2},
  {2,2,1,0,0,0,0,0,0,0,0,2,2},
};
void Map_Start4()
{
      Map4[People_x][People_y]=4;
      Map4[Box4_x][Box4_y]=3;
      Map4[Box4_x1][Box4_y1]=6;
      Map4[Box4_x2][Box4_y2]=9;
}
void Seat_Set4()
{
  if(Map4[Seat4_x][Seat4_y]!=8){
    Map4[Seat4_x][Seat4_y]=5;
  }
  if(Map4[Seat4_x1][Seat4_y1]!=8){
      Map4[Seat4_x1][Seat4_y1]=7;
  }
  if(Map4[Seat4_x2][Seat4_y2]!=8){
    Map4[Seat4_x2][Seat4_y2]=10;
  }
}
void Creat_Seat4()
{
  People_x=2;
  People_y=1;
  Box4_x=3;
  Box4_y=8;
  Box4_x1=4;
  Box4_y1=8;
  Box4_x2=6;
  Box4_y2=6;
  Seat4_x=7;
  Seat4_y=7;
  Seat4_x1=7;
  Seat4_y1=8;
  Seat4_x2=8;
  Seat4_y2=8;
  Map4[Seat4_x][Seat4_y]=5;
  Map4[Seat4_x1][Seat4_y1]=7;
  Map4[Seat4_x2][Seat4_y2]=10;
}
void HideCursor4()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy4(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
int Search_Box4()
{
  if(Box4_x==Seat4_x&&Box4_y==Seat4_y&&Box4_x1==Seat4_x1&&Box4_y1==Seat4_y1&&Box4_x2==Seat4_x2&&Box4_y2==Seat4_y2){
    return 1;
  }
  if(Box4_x==Seat4_x&&Box4_y==Seat4_y&&Box4_x1==Seat4_x2&&Box4_y1==Seat4_y2&&Box4_x2==Seat4_x1&&Box4_y2==Seat4_y1){
    return 1;
  }
  if(Box4_x==Seat4_x1&&Box4_y==Seat4_y1&&Box4_x1==Seat4_x&&Box4_y1==Seat4_y&&Box4_x2==Seat4_x2&&Box4_y2==Seat4_y2){
    return 1;
  }
  if(Box4_x==Seat4_x2&&Box4_y==Seat4_y2&&Box4_x1==Seat4_x1&&Box4_y1==Seat4_y1&&Box4_x2==Seat4_x&&Box4_y2==Seat4_y){
    return 1;
  }
  if(Box4_x==Seat4_x1&&Box4_y==Seat4_y1&&Box4_x1==Seat4_x2&&Box4_y1==Seat4_y2&&Box4_x2==Seat4_x&&Box4_y2==Seat4_y){
    return 1;
  }
  if(Box4_x==Seat4_x2&&Box4_y==Seat4_y2&&Box4_x1==Seat4_x&&Box4_y1==Seat4_y&&Box4_x2==Seat4_x1&&Box4_y2==Seat4_y1){
    return 1;
  }
}
void Creat_Map4()
{
  gotoxy4(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map4[i][j]==0){
        cout<<"■";
      }
      if(Map4[i][j]==1){
        cout<<"■";
      }
      if(Map4[i][j]==2){
        cout<<"  ";
      }
      if(Map4[i][j]==3){
        cout<<"□";
      }
      if(Map4[i][j]==4){
        cout<<"♀";
      }
      if(Map4[i][j]==5){
        cout<<"●";
      }
      if(Map4[i][j]==7){
        cout<<"●";
      }
      if(Map4[i][j]==6){
        cout<<"□";
      }
      if(Map4[i][j]==8){
        cout<<"□";
      }
      if(Map4[i][j]==9){
        cout<<"□";
      }
      if(Map4[i][j]==10){
        cout<<"●";
      }
    }
    cout<<endl;
  }
  cout<<"game four"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move4()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map4[People_x-1][People_y]==1){
         ;
       }
       else if((Map4[People_x-1][People_y]==Map4[Box4_x][Box4_y]&&Map4[Box4_x-1][Box4_y]==0)||(Map4[People_x-1][People_y]==Map4[Box4_x1][Box4_y1]&&Map4[Box4_x1-1][Box4_y1]==0)
     ||(Map4[People_x-1][People_y]==Map4[Box4_x2][Box4_y2]&&Map4[Box4_x2-1][Box4_y2]==0)){
         ;
       }
       else if((Map4[People_x-1][People_y]==Map4[Box4_x][Box4_y]&&Map4[Box4_x-1][Box4_y]==1)||(Map4[People_x-1][People_y]==Map4[Box4_x1][Box4_y1]&&Map4[Box4_x1-1][Box4_y1]==1)
     ||(Map4[People_x-1][People_y]==Map4[Box4_x2][Box4_y2]&&Map4[Box4_x2-1][Box4_y2]==1)){
         ;
       }
       else if(Map4[People_x-1][People_y]==6&&Map4[Box4_x1-1][Box4_y1]==3){
         ;
       }
       else if(Map4[People_x-1][People_y]==6&&Map4[Box4_x1-1][Box4_y1]==9){
         ;
       }
       else if(Map4[People_x-1][People_y]==3&&Map4[Box4_x-1][Box4_y]==6){
         ;
       }
       else if(Map4[People_x-1][People_y]==3&&Map4[Box4_x-1][Box4_y]==9){
         ;
       }
       else if(Map4[People_x-1][People_y]==9&&Map4[Box4_x2-1][Box4_y2]==3){
         ;
       }
       else if(Map4[People_x-1][People_y]==9&&Map4[Box4_x2-1][Box4_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x-1==Box4_x&&People_y==Box4_y){
           Map4[Seat4_x][Seat4_y]=5;
           People_x--;
           Box4_x--;
         }
        else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x-1==Box4_x1&&People_y==Box4_y1){
           Map4[Seat4_x][Seat4_y]=5;
           People_x--;
           Box4_x1--;
         }
         else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x-1==Box4_x2&&People_y==Box4_y2){
            Map4[Seat4_x][Seat4_y]=5;
            People_x--;
            Box4_x2--;
          }
        else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x-1==Box4_x&&People_y==Box4_y){
           Map4[Seat4_x1][Seat4_y1]=7;
           People_x--;
           Box4_x--;
         }
        else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x-1==Box4_x1&&People_y==Box4_y1){
           Map4[Seat4_x1][Seat4_y1]=7;
           People_x--;
           Box4_x1--;
         }
         else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x-1==Box4_x2&&People_y==Box4_y2){
            Map4[Seat4_x1][Seat4_y1]=7;
            People_x--;
            Box4_x2--;
          }
         else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x-1==Box4_x&&People_y==Box4_y){
            Map4[Seat4_x2][Seat4_y2]=10;
            People_x--;
            Box4_x--;
          }
          else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x-1==Box4_x1&&People_y==Box4_y1){
             Map4[Seat4_x2][Seat4_y2]=10;
             People_x--;
             Box4_x1--;
           }
           else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x-1==Box4_x2&&People_y==Box4_y2){
              Map4[Seat4_x2][Seat4_y2]=10;
              People_x--;
              Box4_x2--;
            }
       //}


       else if((People_x==Seat4_x&&People_y==Seat4_y&&Map4[Seat4_x-1][Seat4_y]!=0)||(People_x==Seat4_x&&People_y==Seat4_y&&Map4[Seat4_x-1][Seat4_y]!=1)){
         People_x--;
         Map4[Seat4_x][Seat4_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat4_x1&&People_y==Seat4_y1&&Map4[Seat4_x1-1][Seat4_y1]!=0)||(People_x==Seat4_x1&&People_y==Seat4_y1&&Map4[Seat4_x1-1][Seat4_y1]!=1)){
         People_x--;
         Map4[Seat4_x1][Seat4_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat4_x2&&People_y==Seat4_y2&&Map4[Seat4_x2-1][Seat4_y2]!=0)||(People_x==Seat4_x2&&People_y==Seat4_y2&&Map4[Seat4_x2-1][Seat4_y2]!=1)){
         People_x--;
         Map4[Seat4_x2][Seat4_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map4[Box4_x-1][Box4_y]==5&&Map4[People_x-2][People_y]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x-1][Box4_y]==7&&Map4[People_x-2][People_y]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x-1][Box4_y]==10&&Map4[People_x-2][People_y]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1-1][Box4_y1]==5&&Map4[People_x-2][People_y]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1-1][Box4_y1]==7&&Map4[People_x-2][People_y]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1-1][Box4_y1]==10&&Map4[People_x-2][People_y]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2-1][Box4_y2]==5&&Map4[People_x-2][People_y]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2-1][Box4_y2]==7&&Map4[People_x-2][People_y]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2-1][Box4_y2]==10&&Map4[People_x-2][People_y]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }

        else if(Map4[People_x-1][People_y]!=6&&Map4[People_x-1][People_y]==3&&Map4[People_x-1][People_y]!=9&&Map4[Box4_x-1][Box4_y]!=0&&Map4[Box4_x-1][Box4_y]!=1){
           People_x--;
           Box4_x--;
           Map4[People_x+1][People_y]=2;
           Map4[Box4_x+1][Box4_y]=2;
         }
        else if(Map4[People_x-1][People_y]==6&Map4[People_x-1][People_y]!=3&&Map4[People_x-1][People_y]!=9&&Map4[Box4_x1-1][Box4_y1]!=0&&Map4[Box4_x1-1][Box4_y1]!=1){
           People_x--;
           Box4_x1--;
           Map4[People_x+1][People_y]=2;
           Map4[Box4_x1+1][Box4_y1]=2;
         }
         else if(Map4[People_x-1][People_y]!=6&Map4[People_x-1][People_y]!=3&&Map4[People_x-1][People_y]==9&&Map4[Box4_x1-1][Box4_y1]!=0&&Map4[Box4_x1-1][Box4_y1]!=1){
            People_x--;
            Box4_x2--;
            Map4[People_x+1][People_y]=2;
            Map4[Box4_x2+1][Box4_y2]=2;
          }
         else{
           People_x--;
           Map4[People_x+1][People_y]=2;
         }
     }
     if(input=='s'){
       if(People_x>7||Map4[People_x+1][People_y]==1){
         ;
       }
       else if((Map4[People_x+1][People_y]==Map4[Box4_x][Box4_y]&&Map4[Box4_x+1][Box4_y]==0)||(Map4[People_x+1][People_y]==Map4[Box4_x1][Box4_y1]&&Map4[Box4_x1+1][Box4_y1]==0)
     ||(Map4[People_x+1][People_y]==Map4[Box4_x2][Box4_y2]&&Map4[Box4_x2+1][Box4_y2]==0)){
         ;
       }
       else if((Map4[People_x+1][People_y]==Map4[Box4_x][Box4_y]&&Map4[Box4_x+1][Box4_y]==1)||(Map4[People_x+1][People_y]==Map4[Box4_x1][Box4_y1]&&Map4[Box4_x1+1][Box4_y1]==1)
     ||(Map4[People_x+1][People_y]==Map4[Box4_x2][Box4_y2]&&Map4[Box4_x2+1][Box4_y2]==1)){
         ;
       }
       else if(Map4[People_x+1][People_y]==6&&Map4[Box4_x1+1][Box4_y1]==3){
         ;
       }
       else if(Map4[People_x+1][People_y]==6&&Map4[Box4_x1+1][Box4_y1]==9){
         ;
       }
       else if(Map4[People_x+1][People_y]==3&&Map4[Box4_x+1][Box4_y]==6){
         ;
       }
       else if(Map4[People_x+1][People_y]==3&&Map4[Box4_x+1][Box4_y]==9){
         ;
       }
       else if(Map4[People_x+1][People_y]==9&&Map4[Box4_x2+1][Box4_y2]==3){
         ;
       }
       else if(Map4[People_x+1][People_y]==9&&Map4[Box4_x2+1][Box4_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){


       else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x+1==Box4_x&&People_y==Box4_y){
          Map4[Seat4_x][Seat4_y]=5;
          People_x++;
          Box4_x++;
        }
       else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x+1==Box4_x1&&People_y==Box4_y1){
          Map4[Seat4_x][Seat4_y]=5;
          People_x++;
          Box4_x1++;
        }
        else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x+1==Box4_x2&&People_y==Box4_y2){
           Map4[Seat4_x][Seat4_y]=5;
           People_x++;
           Box4_x2++;
         }
       else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x+1==Box4_x&&People_y==Box4_y){
          Map4[Seat4_x1][Seat4_y1]=7;
          People_x++;
          Box4_x++;
        }
       else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x+1==Box4_x1&&People_y==Box4_y1){
          Map4[Seat4_x1][Seat4_y1]=7;
          People_x++;
          Box4_x1++;
        }
        else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x+1==Box4_x2&&People_y==Box4_y2){
           Map4[Seat4_x1][Seat4_y1]=7;
           People_x++;
           Box4_x2++;
         }
        else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x+1==Box4_x&&People_y==Box4_y){
           Map4[Seat4_x2][Seat4_y2]=10;
           People_x++;
           Box4_x++;
         }else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x+1==Box4_x1&&People_y==Box4_y1){
            Map4[Seat4_x2][Seat4_y2]=10;
            People_x++;
            Box4_x1++;
          }
          else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x+1==Box4_x2&&People_y==Box4_y2){
             Map4[Seat4_x2][Seat4_y2]=10;
             People_x++;
             Box4_x2++;
           }
      // }


       else if((People_x==Seat4_x&&People_y==Seat4_y&&Map4[Seat4_x+1][Seat4_y]!=0)||(People_x==Seat4_x&&People_y==Seat4_y&&Map4[Seat4_x+1][Seat4_y]!=1)){
         People_x++;
         Map4[Seat4_x][Seat4_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat4_x1&&People_y==Seat4_y1&&Map4[Seat4_x1+1][Seat4_y1]!=0)||(People_x==Seat4_x1&&People_y==Seat4_y1&&Map4[Seat4_x1+1][Seat4_y1]!=1)){
         People_x++;
         Map4[Seat4_x1][Seat4_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat4_x2&&People_y==Seat4_y2&&Map4[Seat4_x2+1][Seat4_y1]!=0)||(People_x==Seat4_x2&&People_y==Seat4_y2&&Map4[Seat4_x2+1][Seat4_y2]!=1)){
         People_x++;
         Map4[Seat4_x2][Seat4_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map4[Box4_x+1][Box4_y]==5&&Map4[People_x+2][People_y]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x+1][Box4_y]==7&&Map4[People_x+2][People_y]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x+1][Box4_y]==10&&Map4[People_x+2][People_y]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1+1][Box4_y1]==5&&Map4[People_x+2][People_y]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1+1][Box4_y1]==7&&Map4[People_x+2][People_y]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1+1][Box4_y1]==10&&Map4[People_x+2][People_y]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2+1][Box4_y2]==5&&Map4[People_x+2][People_y]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2+1][Box4_y2]==7&&Map4[People_x+2][People_y]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2+1][Box4_y2]==10&&Map4[People_x+2][People_y]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }


       else if(Map4[People_x+1][People_y]!=6&&Map4[People_x+1][People_y]==3&&Map4[People_x+1][People_y]!=9&&Map4[Box4_x+1][Box4_y]!=0&&Map4[Box4_x+1][Box4_y]!=1){
          People_x++;
          Box4_x++;
          Map4[People_x-1][People_y]=2;
          Map4[Box4_x-1][Box4_y]=2;
        }
       else if(Map4[People_x+1][People_y]==6&Map4[People_x+1][People_y]!=3&&Map4[People_x+1][People_y]!=9&&Map4[Box4_x1+1][Box4_y1]!=0&&Map4[Box4_x1+1][Box4_y1]!=1){
          People_x++;
          Box4_x1++;
          Map4[People_x-1][People_y]=2;
          Map4[Box4_x1-1][Box4_y1]=2;
        }
        else if(Map4[People_x+1][People_y]!=6&Map4[People_x+1][People_y]!=3&&Map4[People_x+1][People_y]==9&&Map4[Box4_x2+1][Box4_y2]!=0&&Map4[Box4_x2+1][Box4_y2]!=1){
           People_x++;
           Box4_x2++;
           Map4[People_x-1][People_y]=2;
           Map4[Box4_x2-1][Box4_y2]=2;
         }
         else{
           People_x++;
           Map4[People_x-1][People_y]=2;
         }
     }
     if(input=='a'){
       if(People_y<2||Map4[People_x][People_y-1]==1){
         ;
       }
       else if((Map4[People_x][People_y-1]==Map4[Box4_x][Box4_y]&&Map4[Box4_x][Box4_y-1]==0)||
       (Map4[People_x][People_y-1]==Map4[Box4_x1][Box4_y1]&&Map4[Box4_x1][Box4_y1-1]==0)
       ||(Map4[People_x][People_y-1]==Map4[Box4_x2][Box4_y2]&&Map4[Box4_x2][Box4_y2-1]==0)){
         ;
       }
       else if((Map4[People_x][People_y-1]==Map4[Box4_x][Box4_y]&&Map4[Box4_x][Box4_y-1]==1)||
       (Map4[People_x][People_y-1]==Map4[Box4_x1][Box4_y1]&&Map4[Box4_x1][Box4_y1-1]==1)
       ||(Map4[People_x][People_y-1]==Map4[Box4_x2][Box4_y2]&&Map4[Box4_x2][Box4_y2-1]==1)){
         ;
       }
       else if(Map4[People_x][People_y-1]==6&&Map4[Box4_x1][Box4_y1-1]==3){
         ;
       }
       else if(Map4[People_x][People_y-1]==6&&Map4[Box4_x1][Box4_y1-1]==9){
         ;
       }
       else if(Map4[People_x][People_y-1]==3&&Map4[Box4_x][Box4_y-1]==6){
         ;
       }
       else if(Map4[People_x][People_y-1]==3&&Map4[Box4_x][Box4_y-1]==9){
         ;
       }
       else if(Map4[People_x][People_y-1]==9&&Map4[Box4_x2][Box4_y2-1]==3){
         ;
       }
       else if(Map4[People_x][People_y-1]==9&&Map4[Box4_x2][Box4_y2-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x==Box4_x&&People_y-1==Box4_y){
           Map4[Seat4_x][Seat4_y]=5;
           People_y--;
           Box4_y--;
         }
        else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x==Box4_x1&&People_y-1==Box4_y1){
           Map4[Seat4_x][Seat4_y]=5;
           People_y--;
           Box4_y1--;
         }
         else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x==Box4_x2&&People_y-1==Box4_y2){
            Map4[Seat4_x][Seat4_y]=5;
            People_y--;
            Box4_y2--;
          }
        else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x==Box4_x&&People_y-1==Box4_y){
           Map4[Seat4_x1][Seat4_y1]=7;
           People_y--;
           Box4_y--;
         }
        else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x==Box4_x1&&People_y-1==Box4_y1){
           Map4[Seat4_x1][Seat4_y1]=7;
           People_y--;
           Box4_y1--;
         }
         else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x==Box4_x2&&People_y-1==Box4_y2){
            Map4[Seat4_x1][Seat4_y1]=7;
            People_y--;
            Box4_y2--;
          }
         else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x==Box4_x&&People_y-1==Box4_y){
            Map4[Seat4_x2][Seat4_y2]=10;
            People_y--;
            Box4_y--;
          }else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x==Box4_x1&&People_y-1==Box4_y1){
             Map4[Seat4_x2][Seat4_y2]=10;
             People_y--;
             Box4_y1--;
           }
           else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x==Box4_x2&&People_y-1==Box4_y2){
              Map4[Seat4_x2][Seat4_y2]=10;
              People_y--;
              Box4_y2--;
            }
       //}


       else if((People_x==Seat4_x&&People_y==Seat4_y&&Map4[Seat4_x][Seat4_y-1]!=0)||(People_x==Seat4_x&&People_y==Seat4_y&&Map4[Seat4_x][Seat4_y-1]!=1)){
         People_y--;
         Map4[Seat4_x][Seat4_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat4_x1&&People_y==Seat4_y1&&Map4[Seat4_x1][Seat4_y1-1]!=0)||(People_x==Seat4_x1&&People_y==Seat4_y1&&Map4[Seat4_x1][Seat4_y1-1]!=1)){
         People_y--;
         Map4[Seat4_x1][Seat4_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat4_x2&&People_y==Seat4_y2&&Map4[Seat4_x2][Seat4_y2-1]!=0)||(People_x==Seat4_x2&&People_y==Seat4_y2&&Map4[Seat4_x2][Seat4_y2-1]!=1)){
         People_y--;
         Map4[Seat4_x2][Seat4_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map4[Box4_x][Box4_y-1]==5&&Map4[People_x][People_y-2]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1][Box4_y1-1]==5&&Map4[People_x][People_y-2]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2][Box4_y2-1]==5&&Map4[People_x][People_y-2]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x][Box4_y-1]==7&&Map4[People_x][People_y-2]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1][Box4_y1-1]==7&&Map4[People_x][People_y-2]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2][Box4_y2-1]==7&&Map4[People_x][People_y-2]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1][Box4_y1-1]==10&&Map4[People_x][People_y-2]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x][Box4_y-1]==10&&Map4[People_x][People_y-2]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2][Box4_y2-1]==10&&Map4[People_x][People_y-2]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }

        else if(Map4[People_x][People_y-1]!=6&&Map4[People_x][People_y-1]==3&&Map4[People_x][People_y-1]!=9&&Map4[Box4_x][Box4_y-1]!=0&&Map4[Box4_x][Box4_y-1]!=1){
           People_y--;
           Box4_y--;
           Map4[People_x][People_y+1]=2;
           Map4[Box4_x][Box4_y+1]=2;
         }
        else if(Map4[People_x][People_y-1]==6&Map4[People_x][People_y-1]!=3&&Map4[People_x][People_y-1]!=9&&Map4[Box4_x1][Box4_y1-1]!=0&&Map4[Box4_x1][Box4_y1-1]!=1){
           People_y--;
           Box4_y1--;
           Map4[People_x][People_y+1]=2;
           Map4[Box4_x1][Box4_y1+1]=2;
         }
         else if(Map4[People_x][People_y-1]!=6&Map4[People_x][People_y-1]!=3&&Map4[People_x][People_y-1]==9&&Map4[Box4_x2][Box4_y2-1]!=0&&Map4[Box4_x2][Box4_y2-1]!=1){
            People_y--;
            Box4_y2--;
            Map4[People_x][People_y+1]=2;
            Map4[Box4_x2][Box4_y2+1]=2;
          }
         else{
           People_y--;
           Map4[People_x][People_y+1]=2;
         }
     }
     if(input=='d'){
       if(People_y>10||Map4[People_x][People_y+1]==1){
         ;
       }
       else if((Map4[People_x][People_y+1]==Map4[Box4_x][Box4_y]&&Map4[Box4_x][Box4_y+1]==0)
       ||(Map4[People_x][People_y+1]==Map4[Box4_x1][Box4_y1]&&Map4[Box4_x1][Box4_y1+1]==0)
       ||(Map4[People_x][People_y+1]==Map4[Box4_x2][Box4_y2]&&Map4[Box4_x2][Box4_y2+1]==0)){
         ;
       }
       else if((Map4[People_x][People_y+1]==Map4[Box4_x][Box4_y]&&Map4[Box4_x][Box4_y+1]==1)
       ||(Map4[People_x][People_y+1]==Map4[Box4_x1][Box4_y1]&&Map4[Box4_x1][Box4_y1+1]==1)
       ||(Map4[People_x][People_y+1]==Map4[Box4_x2][Box4_y2]&&Map4[Box4_x2][Box4_y2+1]==1)){
         ;
       }
       else if(Map4[People_x][People_y+1]==6&&Map4[Box4_x1][Box4_y1+1]==3){
         ;
       }
       else if(Map4[People_x][People_y+1]==6&&Map4[Box4_x1][Box4_y1+1]==9){
         ;
       }
       else if(Map4[People_x][People_y+1]==3&&Map4[Box4_x][Box4_y+1]==6){
         ;
       }
       else if(Map4[People_x][People_y+1]==3&&Map4[Box4_x][Box4_y+1]==9){
         ;
       }
       else if(Map4[People_x][People_y+1]==9&&Map4[Box4_x2][Box4_y2+1]==3){
         ;
       }
       else if(Map4[People_x][People_y+1]==9&&Map4[Box4_x2][Box4_y2+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x==Box4_x&&People_y+1==Box4_y){
           Map4[Seat4_x][Seat4_y]=5;
           People_y++;
           Box4_y++;
         }
        else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x==Box4_x1&&People_y+1==Box4_y1){
           Map4[Seat4_x][Seat4_y]=5;
           People_y++;
           Box4_y1++;
         }
         else if(People_x==Seat4_x&&People_y==Seat4_y&&People_x==Box4_x2&&People_y+1==Box4_y2){
            Map4[Seat4_x][Seat4_y]=5;
            People_y++;
            Box4_y2++;
          }
        else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x==Box4_x&&People_y+1==Box4_y){
           Map4[Seat4_x1][Seat4_y1]=7;
           People_y++;
           Box4_y++;
         }
        else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x==Box4_x1&&People_y+1==Box4_y1){
           Map4[Seat4_x1][Seat4_y1]=7;
           People_y++;
           Box4_y1++;
         }
         else if(People_x==Seat4_x1&&People_y==Seat4_y1&&People_x==Box4_x2&&People_y+1==Box4_y2){
            Map4[Seat4_x1][Seat4_y1]=7;
            People_y++;
            Box4_y2++;
          }
         else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x==Box4_x&&People_y+1==Box4_y){
            Map4[Seat4_x2][Seat4_y2]=10;
            People_y++;
            Box4_y++;
          }else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x==Box4_x1&&People_y+1==Box4_y1){
             Map4[Seat4_x2][Seat4_y2]=10;
             People_y++;
             Box4_y1++;
           }
           else if(People_x==Seat4_x2&&People_y==Seat4_y2&&People_x==Box4_x2&&People_y+1==Box4_y2){
              Map4[Seat4_x2][Seat4_y2]=10;
              People_y++;
              Box4_y2++;
            }
       //}


       else if((People_x==Seat4_x&&People_y==Seat4_y&&Map4[Seat4_x][Seat4_y+1]!=0)||(People_x==Seat4_x&&People_y==Seat4_y&&Map4[Seat4_x][Seat4_y+1]!=1)){
         People_y++;
         Map4[Seat4_x][Seat4_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat4_x1&&People_y==Seat4_y1&&Map4[Seat4_x1][Seat4_y1+1]!=0)||(People_x==Seat4_x1&&People_y==Seat4_y1&&Map4[Seat4_x1][Seat4_y1+1]!=1)){
         People_y++;
         Map4[Seat4_x1][Seat4_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat4_x2&&People_y==Seat4_y2&&Map4[Seat4_x2][Seat4_y2+1]!=0)||(People_x==Seat4_x2&&People_y==Seat4_y2&&Map4[Seat4_x2][Seat4_y2+1]!=1)){
         People_y++;
         Map4[Seat4_x2][Seat4_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map4[Box4_x][Box4_y+1]==5&&Map4[People_x][People_y+2]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x][Box4_y+1]==7&&Map4[People_x][People_y+2]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x][Box4_y+1]==10&&Map4[People_x][People_y+2]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x][Box4_y]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1][Box4_y1+1]==5&&Map4[People_x][People_y+2]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1][Box4_y1+1]==7&&Map4[People_x][People_y+2]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x1][Box4_y1+1]==10&&Map4[People_x][People_y+2]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x1][Box4_y1]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2][Box4_y2+1]==5&&Map4[People_x][People_y+2]==5){
         Map4[Seat4_x][Seat4_y]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2][Box4_y2+1]==7&&Map4[People_x][People_y+2]==7){
         Map4[Seat4_x1][Seat4_y1]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }
       else if(Map4[Box4_x2][Box4_y2+1]==10&&Map4[People_x][People_y+2]==10){
         Map4[Seat4_x2][Seat4_y2]=8;
         Map4[Box4_x2][Box4_y2]=4;
         Map4[People_x][People_y]=2;
       }

        else if(Map4[People_x][People_y+1]!=6&&Map4[People_x][People_y+1]==3&&Map4[People_x][People_y+1]!=9&&Map4[Box4_x][Box4_y+1]!=0&&Map4[Box4_x][Box4_y+1]!=1){
           People_y++;
           Box4_y++;
           Map4[People_x][People_y-1]=2;
           Map4[Box4_x][Box4_y-1]=2;
         }
        else if(Map4[People_x][People_y+1]==6&Map4[People_x][People_y+1]!=3&&Map4[People_x][People_y+1]!=9&&Map4[Box4_x1][Box4_y1+1]!=0&&Map4[Box4_x1][Box4_y1+1]!=1){
           People_y++;
           Box4_y1++;
           Map4[People_x][People_y-1]=2;
           Map4[Box4_x1][Box4_y1-1]=2;
         }
         else if(Map4[People_x][People_y+1]!=6&Map4[People_x][People_y+1]!=3&&Map4[People_x][People_y+1]==9&&Map4[Box4_x2][Box4_y2+1]!=0&&Map4[Box4_x2][Box4_y2+1]!=1){
            People_y++;
            Box4_y2++;
            Map4[People_x][People_y-1]=2;
            Map4[Box4_x2][Box4_y2-1]=2;
          }
         else{
           People_y++;
           Map4[People_x][People_y-1]=2;
         }
     }
   }
}



//game 5
int Box5_x,Box5_y;
int Box5_x1,Box5_y1;
int Box5_x2,Box5_y2;
int Seat5_x,Seat5_y;
int Seat5_x1,Seat5_y1;
int Seat5_x2,Seat5_y2;
int Map5[MAPMAX][MAPMAX+3] = {
  {2,2,0,0,0,0,0,0,0,2,2,2,2},
  {2,2,1,2,2,2,2,2,1,2,2,2,2},
  {2,2,1,1,1,1,2,2,1,1,1,2,2},
  {0,1,1,1,1,1,2,2,2,2,1,2,2},
  {0,2,2,2,2,1,2,2,2,2,1,2,2},
  {0,1,1,2,2,1,2,2,1,2,1,2,2},
  {2,2,1,2,2,1,2,2,1,1,1,2,2},
  {2,2,1,2,2,2,2,2,1,2,2,2,2},
  {2,2,1,2,2,2,2,1,1,2,2,2,2},
  {2,2,0,0,0,0,0,0,2,2,2,2,2},
};
void Map_Start5()
{
      Map5[People_x][People_y]=4;
      Map5[Box5_x][Box5_y]=3;
      Map5[Box5_x1][Box5_y1]=6;
      Map5[Box5_x2][Box5_y2]=9;
}
void Seat_Set5()
{
  if(Map5[Seat5_x][Seat5_y]!=8){
    Map5[Seat5_x][Seat5_y]=5;
  }
  if(Map5[Seat5_x1][Seat5_y1]!=8){
      Map5[Seat5_x1][Seat5_y1]=7;
  }
  if(Map5[Seat5_x2][Seat5_y2]!=8){
    Map5[Seat5_x2][Seat5_y2]=10;
  }
}
void Creat_Seat5()
{
  People_x=1;
  People_y=3;
  Box5_x=3;
  Box5_y=8;
  Box5_x1=4;
  Box5_y1=8;
  Box5_x2=6;
  Box5_y2=6;
  Seat5_x=4;
  Seat5_y=1;
  Seat5_x1=5;
  Seat5_y1=8;
  Seat5_x2=8;
  Seat5_y2=3;
  Map5[Seat5_x][Seat5_y]=5;
  Map5[Seat5_x1][Seat5_y1]=7;
  Map5[Seat5_x2][Seat5_y2]=10;
}
void HideCursor5()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy5(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
int Search_Box5()
{
  if(Box5_x==Seat5_x&&Box5_y==Seat5_y&&Box5_x1==Seat5_x1&&Box5_y1==Seat5_y1&&Box5_x2==Seat5_x2&&Box5_y2==Seat5_y2){
    return 1;
  }
  if(Box5_x==Seat5_x&&Box5_y==Seat5_y&&Box5_x1==Seat5_x2&&Box5_y1==Seat5_y2&&Box5_x2==Seat5_x1&&Box5_y2==Seat5_y1){
    return 1;
  }
  if(Box5_x==Seat5_x1&&Box5_y==Seat5_y1&&Box5_x1==Seat5_x&&Box5_y1==Seat5_y&&Box5_x2==Seat5_x2&&Box5_y2==Seat5_y2){
    return 1;
  }
  if(Box5_x==Seat5_x2&&Box5_y==Seat5_y2&&Box5_x1==Seat5_x1&&Box5_y1==Seat5_y1&&Box5_x2==Seat5_x&&Box5_y2==Seat5_y){
    return 1;
  }
  if(Box5_x==Seat5_x1&&Box5_y==Seat5_y1&&Box5_x1==Seat5_x2&&Box5_y1==Seat5_y2&&Box5_x2==Seat5_x&&Box5_y2==Seat5_y){
    return 1;
  }
  if(Box5_x==Seat5_x2&&Box5_y==Seat5_y2&&Box5_x1==Seat5_x&&Box5_y1==Seat5_y&&Box5_x2==Seat5_x1&&Box5_y2==Seat5_y1){
    return 1;
  }
}
void Creat_Map5()
{
  gotoxy5(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map5[i][j]==0){
        cout<<"■";
      }
      if(Map5[i][j]==1){
        cout<<"■";
      }
      if(Map5[i][j]==2){
        cout<<"  ";
      }
      if(Map5[i][j]==3){
        cout<<"□";
      }
      if(Map5[i][j]==4){
        cout<<"♀";
      }
      if(Map5[i][j]==5){
        cout<<"●";
      }
      if(Map5[i][j]==7){
        cout<<"●";
      }
      if(Map5[i][j]==6){
        cout<<"□";
      }
      if(Map5[i][j]==8){
        cout<<"□";
      }
      if(Map5[i][j]==9){
        cout<<"□";
      }
      if(Map5[i][j]==10){
        cout<<"●";
      }
    }
    cout<<endl;
  }
  cout<<"game five"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move5()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map5[People_x-1][People_y]==1){
         ;
       }
       else if((Map5[People_x-1][People_y]==Map5[Box5_x][Box5_y]&&Map5[Box5_x-1][Box5_y]==0)||(Map5[People_x-1][People_y]==Map5[Box5_x1][Box5_y1]&&Map5[Box5_x1-1][Box5_y1]==0)
     ||(Map5[People_x-1][People_y]==Map5[Box5_x2][Box5_y2]&&Map5[Box5_x2-1][Box5_y2]==0)){
         ;
       }
       else if((Map5[People_x-1][People_y]==Map5[Box5_x][Box5_y]&&Map5[Box5_x-1][Box5_y]==1)||(Map5[People_x-1][People_y]==Map5[Box5_x1][Box5_y1]&&Map5[Box5_x1-1][Box5_y1]==1)
     ||(Map5[People_x-1][People_y]==Map5[Box5_x2][Box5_y2]&&Map5[Box5_x2-1][Box5_y2]==1)){
         ;
       }
       else if(Map5[People_x-1][People_y]==6&&Map5[Box5_x1-1][Box5_y1]==3){
         ;
       }
       else if(Map5[People_x-1][People_y]==6&&Map5[Box5_x1-1][Box5_y1]==9){
         ;
       }
       else if(Map5[People_x-1][People_y]==3&&Map5[Box5_x-1][Box5_y]==6){
         ;
       }
       else if(Map5[People_x-1][People_y]==3&&Map5[Box5_x-1][Box5_y]==9){
         ;
       }
       else if(Map5[People_x-1][People_y]==9&&Map5[Box5_x2-1][Box5_y2]==3){
         ;
       }
       else if(Map5[People_x-1][People_y]==9&&Map5[Box5_x2-1][Box5_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x-1==Box5_x&&People_y==Box5_y){
           Map5[Seat5_x][Seat5_y]=5;
           People_x--;
           Box5_x--;
         }
        else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x-1==Box5_x1&&People_y==Box5_y1){
           Map5[Seat5_x][Seat5_y]=5;
           People_x--;
           Box5_x1--;
         }
         else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x-1==Box5_x2&&People_y==Box5_y2){
            Map5[Seat5_x][Seat5_y]=5;
            People_x--;
            Box5_x2--;
          }
        else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x-1==Box5_x&&People_y==Box5_y){
           Map5[Seat5_x1][Seat5_y1]=7;
           People_x--;
           Box5_x--;
         }
        else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x-1==Box5_x1&&People_y==Box5_y1){
           Map5[Seat5_x1][Seat5_y1]=7;
           People_x--;
           Box5_x1--;
         }
         else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x-1==Box5_x2&&People_y==Box5_y2){
            Map5[Seat5_x1][Seat5_y1]=7;
            People_x--;
            Box5_x2--;
          }
         else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x-1==Box5_x&&People_y==Box5_y){
            Map5[Seat5_x2][Seat5_y2]=10;
            People_x--;
            Box5_x--;
          }
          else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x-1==Box5_x1&&People_y==Box5_y1){
             Map5[Seat5_x2][Seat5_y2]=10;
             People_x--;
             Box5_x1--;
           }
           else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x-1==Box5_x2&&People_y==Box5_y2){
              Map5[Seat5_x2][Seat5_y2]=10;
              People_x--;
              Box5_x2--;
            }
       //}


       else if((People_x==Seat5_x&&People_y==Seat5_y&&Map5[Seat5_x-1][Seat5_y]!=0)||(People_x==Seat5_x&&People_y==Seat5_y&&Map5[Seat5_x-1][Seat5_y]!=1)){
         People_x--;
         Map5[Seat5_x][Seat5_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat5_x1&&People_y==Seat5_y1&&Map5[Seat5_x1-1][Seat5_y1]!=0)||(People_x==Seat5_x1&&People_y==Seat5_y1&&Map5[Seat5_x1-1][Seat5_y1]!=1)){
         People_x--;
         Map5[Seat5_x1][Seat5_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat5_x2&&People_y==Seat5_y2&&Map5[Seat5_x2-1][Seat5_y2]!=0)||(People_x==Seat5_x2&&People_y==Seat5_y2&&Map5[Seat5_x2-1][Seat5_y2]!=1)){
         People_x--;
         Map5[Seat5_x2][Seat5_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map5[Box5_x-1][Box5_y]==5&&Map5[People_x-2][People_y]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x-1][Box5_y]==7&&Map5[People_x-2][People_y]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x-1][Box5_y]==10&&Map5[People_x-2][People_y]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1-1][Box5_y1]==5&&Map5[People_x-2][People_y]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1-1][Box5_y1]==7&&Map5[People_x-2][People_y]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1-1][Box5_y1]==10&&Map5[People_x-2][People_y]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2-1][Box5_y2]==5&&Map5[People_x-2][People_y]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2-1][Box5_y2]==7&&Map5[People_x-2][People_y]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2-1][Box5_y2]==10&&Map5[People_x-2][People_y]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }

        else if(Map5[People_x-1][People_y]!=6&&Map5[People_x-1][People_y]==3&&Map5[People_x-1][People_y]!=9&&Map5[Box5_x-1][Box5_y]!=0&&Map5[Box5_x-1][Box5_y]!=1){
           People_x--;
           Box5_x--;
           Map5[People_x+1][People_y]=2;
           Map5[Box5_x+1][Box5_y]=2;
         }
        else if(Map5[People_x-1][People_y]==6&Map5[People_x-1][People_y]!=3&&Map5[People_x-1][People_y]!=9&&Map5[Box5_x1-1][Box5_y1]!=0&&Map5[Box5_x1-1][Box5_y1]!=1){
           People_x--;
           Box5_x1--;
           Map5[People_x+1][People_y]=2;
           Map5[Box5_x1+1][Box5_y1]=2;
         }
         else if(Map5[People_x-1][People_y]!=6&Map5[People_x-1][People_y]!=3&&Map5[People_x-1][People_y]==9&&Map5[Box5_x1-1][Box5_y1]!=0&&Map5[Box5_x1-1][Box5_y1]!=1){
            People_x--;
            Box5_x2--;
            Map5[People_x+1][People_y]=2;
            Map5[Box5_x2+1][Box5_y2]=2;
          }
         else{
           People_x--;
           Map5[People_x+1][People_y]=2;
         }
     }
     if(input=='s'){
       if(People_x>7||Map5[People_x+1][People_y]==1){
         ;
       }
       else if((Map5[People_x+1][People_y]==Map5[Box5_x][Box5_y]&&Map5[Box5_x+1][Box5_y]==0)||(Map5[People_x+1][People_y]==Map5[Box5_x1][Box5_y1]&&Map5[Box5_x1+1][Box5_y1]==0)
     ||(Map5[People_x+1][People_y]==Map5[Box5_x2][Box5_y2]&&Map5[Box5_x2+1][Box5_y2]==0)){
         ;
       }
       else if((Map5[People_x+1][People_y]==Map5[Box5_x][Box5_y]&&Map5[Box5_x+1][Box5_y]==1)||(Map5[People_x+1][People_y]==Map5[Box5_x1][Box5_y1]&&Map5[Box5_x1+1][Box5_y1]==1)
     ||(Map5[People_x+1][People_y]==Map5[Box5_x2][Box5_y2]&&Map5[Box5_x2+1][Box5_y2]==1)){
         ;
       }
       else if(Map5[People_x+1][People_y]==6&&Map5[Box5_x1+1][Box5_y1]==3){
         ;
       }
       else if(Map5[People_x+1][People_y]==6&&Map5[Box5_x1+1][Box5_y1]==9){
         ;
       }
       else if(Map5[People_x+1][People_y]==3&&Map5[Box5_x+1][Box5_y]==6){
         ;
       }
       else if(Map5[People_x+1][People_y]==3&&Map5[Box5_x+1][Box5_y]==9){
         ;
       }
       else if(Map5[People_x+1][People_y]==9&&Map5[Box5_x2+1][Box5_y2]==3){
         ;
       }
       else if(Map5[People_x+1][People_y]==9&&Map5[Box5_x2+1][Box5_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){


       else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x+1==Box5_x&&People_y==Box5_y){
          Map5[Seat5_x][Seat5_y]=5;
          People_x++;
          Box5_x++;
        }
       else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x+1==Box5_x1&&People_y==Box5_y1){
          Map5[Seat5_x][Seat5_y]=5;
          People_x++;
          Box5_x1++;
        }
        else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x+1==Box5_x2&&People_y==Box5_y2){
           Map5[Seat5_x][Seat5_y]=5;
           People_x++;
           Box5_x2++;
         }
       else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x+1==Box5_x&&People_y==Box5_y){
          Map5[Seat5_x1][Seat5_y1]=7;
          People_x++;
          Box5_x++;
        }
       else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x+1==Box5_x1&&People_y==Box5_y1){
          Map5[Seat5_x1][Seat5_y1]=7;
          People_x++;
          Box5_x1++;
        }
        else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x+1==Box5_x2&&People_y==Box5_y2){
           Map5[Seat5_x1][Seat5_y1]=7;
           People_x++;
           Box5_x2++;
         }
        else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x+1==Box5_x&&People_y==Box5_y){
           Map5[Seat5_x2][Seat5_y2]=10;
           People_x++;
           Box5_x++;
         }else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x+1==Box5_x1&&People_y==Box5_y1){
            Map5[Seat5_x2][Seat5_y2]=10;
            People_x++;
            Box5_x1++;
          }
          else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x+1==Box5_x2&&People_y==Box5_y2){
             Map5[Seat5_x2][Seat5_y2]=10;
             People_x++;
             Box5_x2++;
           }
      // }


       else if((People_x==Seat5_x&&People_y==Seat5_y&&Map5[Seat5_x+1][Seat5_y]!=0)||(People_x==Seat5_x&&People_y==Seat5_y&&Map5[Seat5_x+1][Seat5_y]!=1)){
         People_x++;
         Map5[Seat5_x][Seat5_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat5_x1&&People_y==Seat5_y1&&Map5[Seat5_x1+1][Seat5_y1]!=0)||(People_x==Seat5_x1&&People_y==Seat5_y1&&Map5[Seat5_x1+1][Seat5_y1]!=1)){
         People_x++;
         Map5[Seat5_x1][Seat5_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat5_x2&&People_y==Seat5_y2&&Map5[Seat5_x2+1][Seat5_y1]!=0)||(People_x==Seat5_x2&&People_y==Seat5_y2&&Map5[Seat5_x2+1][Seat5_y2]!=1)){
         People_x++;
         Map5[Seat5_x2][Seat5_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map5[Box5_x+1][Box5_y]==5&&Map5[People_x+2][People_y]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x+1][Box5_y]==7&&Map5[People_x+2][People_y]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x+1][Box5_y]==10&&Map5[People_x+2][People_y]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1+1][Box5_y1]==5&&Map5[People_x+2][People_y]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1+1][Box5_y1]==7&&Map5[People_x+2][People_y]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1+1][Box5_y1]==10&&Map5[People_x+2][People_y]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2+1][Box5_y2]==5&&Map5[People_x+2][People_y]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2+1][Box5_y2]==7&&Map5[People_x+2][People_y]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2+1][Box5_y2]==10&&Map5[People_x+2][People_y]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }


       else if(Map5[People_x+1][People_y]!=6&&Map5[People_x+1][People_y]==3&&Map5[People_x+1][People_y]!=9&&Map5[Box5_x+1][Box5_y]!=0&&Map5[Box5_x+1][Box5_y]!=1){
          People_x++;
          Box5_x++;
          Map5[People_x-1][People_y]=2;
          Map5[Box5_x-1][Box5_y]=2;
        }
       else if(Map5[People_x+1][People_y]==6&Map5[People_x+1][People_y]!=3&&Map5[People_x+1][People_y]!=9&&Map5[Box5_x1+1][Box5_y1]!=0&&Map5[Box5_x1+1][Box5_y1]!=1){
          People_x++;
          Box5_x1++;
          Map5[People_x-1][People_y]=2;
          Map5[Box5_x1-1][Box5_y1]=2;
        }
        else if(Map5[People_x+1][People_y]!=6&Map5[People_x+1][People_y]!=3&&Map5[People_x+1][People_y]==9&&Map5[Box5_x2+1][Box5_y2]!=0&&Map5[Box5_x2+1][Box5_y2]!=1){
           People_x++;
           Box5_x2++;
           Map5[People_x-1][People_y]=2;
           Map5[Box5_x2-1][Box5_y2]=2;
         }
         else{
           People_x++;
           Map5[People_x-1][People_y]=2;
         }
     }
     if(input=='a'){
       if(People_y<2||Map5[People_x][People_y-1]==1){
         ;
       }
       else if((Map5[People_x][People_y-1]==Map5[Box5_x][Box5_y]&&Map5[Box5_x][Box5_y-1]==0)||
       (Map5[People_x][People_y-1]==Map5[Box5_x1][Box5_y1]&&Map5[Box5_x1][Box5_y1-1]==0)
       ||(Map5[People_x][People_y-1]==Map5[Box5_x2][Box5_y2]&&Map5[Box5_x2][Box5_y2-1]==0)){
         ;
       }
       else if((Map5[People_x][People_y-1]==Map5[Box5_x][Box5_y]&&Map5[Box5_x][Box5_y-1]==1)||
       (Map5[People_x][People_y-1]==Map5[Box5_x1][Box5_y1]&&Map5[Box5_x1][Box5_y1-1]==1)
       ||(Map5[People_x][People_y-1]==Map5[Box5_x2][Box5_y2]&&Map5[Box5_x2][Box5_y2-1]==1)){
         ;
       }
       else if(Map5[People_x][People_y-1]==6&&Map5[Box5_x1][Box5_y1-1]==3){
         ;
       }
       else if(Map5[People_x][People_y-1]==6&&Map5[Box5_x1][Box5_y1-1]==9){
         ;
       }
       else if(Map5[People_x][People_y-1]==3&&Map5[Box5_x][Box5_y-1]==6){
         ;
       }
       else if(Map5[People_x][People_y-1]==3&&Map5[Box5_x][Box5_y-1]==9){
         ;
       }
       else if(Map5[People_x][People_y-1]==9&&Map5[Box5_x2][Box5_y2-1]==3){
         ;
       }
       else if(Map5[People_x][People_y-1]==9&&Map5[Box5_x2][Box5_y2-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x==Box5_x&&People_y-1==Box5_y){
           Map5[Seat5_x][Seat5_y]=5;
           People_y--;
           Box5_y--;
         }
        else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x==Box5_x1&&People_y-1==Box5_y1){
           Map5[Seat5_x][Seat5_y]=5;
           People_y--;
           Box5_y1--;
         }
         else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x==Box5_x2&&People_y-1==Box5_y2){
            Map5[Seat5_x][Seat5_y]=5;
            People_y--;
            Box5_y2--;
          }
        else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x==Box5_x&&People_y-1==Box5_y){
           Map5[Seat5_x1][Seat5_y1]=7;
           People_y--;
           Box5_y--;
         }
        else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x==Box5_x1&&People_y-1==Box5_y1){
           Map5[Seat5_x1][Seat5_y1]=7;
           People_y--;
           Box5_y1--;
         }
         else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x==Box5_x2&&People_y-1==Box5_y2){
            Map5[Seat5_x1][Seat5_y1]=7;
            People_y--;
            Box5_y2--;
          }
         else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x==Box5_x&&People_y-1==Box5_y){
            Map5[Seat5_x2][Seat5_y2]=10;
            People_y--;
            Box5_y--;
          }else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x==Box5_x1&&People_y-1==Box5_y1){
             Map5[Seat5_x2][Seat5_y2]=10;
             People_y--;
             Box5_y1--;
           }
           else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x==Box5_x2&&People_y-1==Box5_y2){
              Map5[Seat5_x2][Seat5_y2]=10;
              People_y--;
              Box5_y2--;
            }
       //}


       else if((People_x==Seat5_x&&People_y==Seat5_y&&Map5[Seat5_x][Seat5_y-1]!=0)||(People_x==Seat5_x&&People_y==Seat5_y&&Map5[Seat5_x][Seat5_y-1]!=1)){
         People_y--;
         Map5[Seat5_x][Seat5_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat5_x1&&People_y==Seat5_y1&&Map5[Seat5_x1][Seat5_y1-1]!=0)||(People_x==Seat5_x1&&People_y==Seat5_y1&&Map5[Seat5_x1][Seat5_y1-1]!=1)){
         People_y--;
         Map5[Seat5_x1][Seat5_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat5_x2&&People_y==Seat5_y2&&Map5[Seat5_x2][Seat5_y2-1]!=0)||(People_x==Seat5_x2&&People_y==Seat5_y2&&Map5[Seat5_x2][Seat5_y2-1]!=1)){
         People_y--;
         Map5[Seat5_x2][Seat5_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map5[Box5_x][Box5_y-1]==5&&Map5[People_x][People_y-2]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1][Box5_y1-1]==5&&Map5[People_x][People_y-2]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2][Box5_y2-1]==5&&Map5[People_x][People_y-2]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x][Box5_y-1]==7&&Map5[People_x][People_y-2]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1][Box5_y1-1]==7&&Map5[People_x][People_y-2]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2][Box5_y2-1]==7&&Map5[People_x][People_y-2]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1][Box5_y1-1]==10&&Map5[People_x][People_y-2]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x][Box5_y-1]==10&&Map5[People_x][People_y-2]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2][Box5_y2-1]==10&&Map5[People_x][People_y-2]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }

        else if(Map5[People_x][People_y-1]!=6&&Map5[People_x][People_y-1]==3&&Map5[People_x][People_y-1]!=9&&Map5[Box5_x][Box5_y-1]!=0&&Map5[Box5_x][Box5_y-1]!=1){
           People_y--;
           Box5_y--;
           Map5[People_x][People_y+1]=2;
           Map5[Box5_x][Box5_y+1]=2;
         }
        else if(Map5[People_x][People_y-1]==6&Map5[People_x][People_y-1]!=3&&Map5[People_x][People_y-1]!=9&&Map5[Box5_x1][Box5_y1-1]!=0&&Map5[Box5_x1][Box5_y1-1]!=1){
           People_y--;
           Box5_y1--;
           Map5[People_x][People_y+1]=2;
           Map5[Box5_x1][Box5_y1+1]=2;
         }
         else if(Map5[People_x][People_y-1]!=6&Map5[People_x][People_y-1]!=3&&Map5[People_x][People_y-1]==9&&Map5[Box5_x2][Box5_y2-1]!=0&&Map5[Box5_x2][Box5_y2-1]!=1){
            People_y--;
            Box5_y2--;
            Map5[People_x][People_y+1]=2;
            Map5[Box5_x2][Box5_y2+1]=2;
          }
         else{
           People_y--;
           Map5[People_x][People_y+1]=2;
         }
     }
     if(input=='d'){
       if(People_y>10||Map5[People_x][People_y+1]==1){
         ;
       }
       else if((Map5[People_x][People_y+1]==Map5[Box5_x][Box5_y]&&Map5[Box5_x][Box5_y+1]==0)
       ||(Map5[People_x][People_y+1]==Map5[Box5_x1][Box5_y1]&&Map5[Box5_x1][Box5_y1+1]==0)
       ||(Map5[People_x][People_y+1]==Map5[Box5_x2][Box5_y2]&&Map5[Box5_x2][Box5_y2+1]==0)){
         ;
       }
       else if((Map5[People_x][People_y+1]==Map5[Box5_x][Box5_y]&&Map5[Box5_x][Box5_y+1]==1)
       ||(Map5[People_x][People_y+1]==Map5[Box5_x1][Box5_y1]&&Map5[Box5_x1][Box5_y1+1]==1)
       ||(Map5[People_x][People_y+1]==Map5[Box5_x2][Box5_y2]&&Map5[Box5_x2][Box5_y2+1]==1)){
         ;
       }
       else if(Map5[People_x][People_y+1]==6&&Map5[Box5_x1][Box5_y1+1]==3){
         ;
       }
       else if(Map5[People_x][People_y+1]==6&&Map5[Box5_x1][Box5_y1+1]==9){
         ;
       }
       else if(Map5[People_x][People_y+1]==3&&Map5[Box5_x][Box5_y+1]==6){
         ;
       }
       else if(Map5[People_x][People_y+1]==3&&Map5[Box5_x][Box5_y+1]==9){
         ;
       }
       else if(Map5[People_x][People_y+1]==9&&Map5[Box5_x2][Box5_y2+1]==3){
         ;
       }
       else if(Map5[People_x][People_y+1]==9&&Map5[Box5_x2][Box5_y2+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x==Box5_x&&People_y+1==Box5_y){
           Map5[Seat5_x][Seat5_y]=5;
           People_y++;
           Box5_y++;
         }
        else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x==Box5_x1&&People_y+1==Box5_y1){
           Map5[Seat5_x][Seat5_y]=5;
           People_y++;
           Box5_y1++;
         }
         else if(People_x==Seat5_x&&People_y==Seat5_y&&People_x==Box5_x2&&People_y+1==Box5_y2){
            Map5[Seat5_x][Seat5_y]=5;
            People_y++;
            Box5_y2++;
          }
        else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x==Box5_x&&People_y+1==Box5_y){
           Map5[Seat5_x1][Seat5_y1]=7;
           People_y++;
           Box5_y++;
         }
        else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x==Box5_x1&&People_y+1==Box5_y1){
           Map5[Seat5_x1][Seat5_y1]=7;
           People_y++;
           Box5_y1++;
         }
         else if(People_x==Seat5_x1&&People_y==Seat5_y1&&People_x==Box5_x2&&People_y+1==Box5_y2){
            Map5[Seat5_x1][Seat5_y1]=7;
            People_y++;
            Box5_y2++;
          }
         else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x==Box5_x&&People_y+1==Box5_y){
            Map5[Seat5_x2][Seat5_y2]=10;
            People_y++;
            Box5_y++;
          }else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x==Box5_x1&&People_y+1==Box5_y1){
             Map5[Seat5_x2][Seat5_y2]=10;
             People_y++;
             Box5_y1++;
           }
           else if(People_x==Seat5_x2&&People_y==Seat5_y2&&People_x==Box5_x2&&People_y+1==Box5_y2){
              Map5[Seat5_x2][Seat5_y2]=10;
              People_y++;
              Box5_y2++;
            }
       //}


       else if((People_x==Seat5_x&&People_y==Seat5_y&&Map5[Seat5_x][Seat5_y+1]!=0)||(People_x==Seat5_x&&People_y==Seat5_y&&Map5[Seat5_x][Seat5_y+1]!=1)){
         People_y++;
         Map5[Seat5_x][Seat5_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat5_x1&&People_y==Seat5_y1&&Map5[Seat5_x1][Seat5_y1+1]!=0)||(People_x==Seat5_x1&&People_y==Seat5_y1&&Map5[Seat5_x1][Seat5_y1+1]!=1)){
         People_y++;
         Map5[Seat5_x1][Seat5_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat5_x2&&People_y==Seat5_y2&&Map5[Seat5_x2][Seat5_y2+1]!=0)||(People_x==Seat5_x2&&People_y==Seat5_y2&&Map5[Seat5_x2][Seat5_y2+1]!=1)){
         People_y++;
         Map5[Seat5_x2][Seat5_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map5[Box5_x][Box5_y+1]==5&&Map5[People_x][People_y+2]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x][Box5_y+1]==7&&Map5[People_x][People_y+2]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x][Box5_y+1]==10&&Map5[People_x][People_y+2]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x][Box5_y]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1][Box5_y1+1]==5&&Map5[People_x][People_y+2]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1][Box5_y1+1]==7&&Map5[People_x][People_y+2]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x1][Box5_y1+1]==10&&Map5[People_x][People_y+2]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x1][Box5_y1]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2][Box5_y2+1]==5&&Map5[People_x][People_y+2]==5){
         Map5[Seat5_x][Seat5_y]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2][Box5_y2+1]==7&&Map5[People_x][People_y+2]==7){
         Map5[Seat5_x1][Seat5_y1]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }
       else if(Map5[Box5_x2][Box5_y2+1]==10&&Map5[People_x][People_y+2]==10){
         Map5[Seat5_x2][Seat5_y2]=8;
         Map5[Box5_x2][Box5_y2]=4;
         Map5[People_x][People_y]=2;
       }

        else if(Map5[People_x][People_y+1]!=6&&Map5[People_x][People_y+1]==3&&Map5[People_x][People_y+1]!=9&&Map5[Box5_x][Box5_y+1]!=0&&Map5[Box5_x][Box5_y+1]!=1){
           People_y++;
           Box5_y++;
           Map5[People_x][People_y-1]=2;
           Map5[Box5_x][Box5_y-1]=2;
         }
        else if(Map5[People_x][People_y+1]==6&Map5[People_x][People_y+1]!=3&&Map5[People_x][People_y+1]!=9&&Map5[Box5_x1][Box5_y1+1]!=0&&Map5[Box5_x1][Box5_y1+1]!=1){
           People_y++;
           Box5_y1++;
           Map5[People_x][People_y-1]=2;
           Map5[Box5_x1][Box5_y1-1]=2;
         }
         else if(Map5[People_x][People_y+1]!=6&Map5[People_x][People_y+1]!=3&&Map5[People_x][People_y+1]==9&&Map5[Box5_x2][Box5_y2+1]!=0&&Map5[Box5_x2][Box5_y2+1]!=1){
            People_y++;
            Box5_y2++;
            Map5[People_x][People_y-1]=2;
            Map5[Box5_x2][Box5_y2-1]=2;
          }
         else{
           People_y++;
           Map5[People_x][People_y-1]=2;
         }
     }
   }
}


//game 6
int Box6_x,Box6_y;
int Box6_x1,Box6_y1;
int Box6_x2,Box6_y2;
int Seat6_x,Seat6_y;
int Seat6_x1,Seat6_y1;
int Seat6_x2,Seat6_y2;
int Map6[MAPMAX][MAPMAX+3] = {
  {2,2,0,0,0,0,0,0,0,0,0,0,2},
  {2,1,1,2,2,2,2,2,2,2,2,1,2},
  {0,1,2,2,2,1,1,1,1,2,2,1,2},
  {0,2,2,2,2,1,2,2,1,2,2,1,0},
  {0,1,1,1,2,1,1,1,1,2,2,2,0},
  {0,2,2,2,2,1,2,2,2,2,2,1,0},
  {0,1,1,1,2,2,2,2,2,2,2,2,0},
  {2,2,2,1,2,1,2,1,1,1,2,1,0},
  {2,2,2,1,2,2,2,1,2,1,1,1,2},
  {2,2,2,0,0,0,0,0,2,2,2,2,2},
};
void Map_Start6()
{
      Map6[People_x][People_y]=4;
      Map6[Box6_x][Box6_y]=3;
      Map6[Box6_x1][Box6_y1]=6;
      Map6[Box6_x2][Box6_y2]=9;
}
void Seat_Set6()
{
  if(Map6[Seat6_x][Seat6_y]!=8){
    Map6[Seat6_x][Seat6_y]=5;
  }
  if(Map6[Seat6_x1][Seat6_y1]!=8){
      Map6[Seat6_x1][Seat6_y1]=7;
  }
  if(Map6[Seat6_x2][Seat6_y2]!=8){
    Map6[Seat6_x2][Seat6_y2]=10;
  }
}
void Creat_Seat6()
{
  People_x=1;
  People_y=3;
  Box6_x=3;
  Box6_y=3;
  Box6_x1=3;
  Box6_y1=9;
  Box6_x2=6;
  Box6_y2=5;
  Seat6_x=1;
  Seat6_y=6;
  Seat6_x1=7;
  Seat6_y1=6;
  Seat6_x2=5;
  Seat6_y2=7;
  Map6[Seat6_x][Seat6_y]=5;
  Map6[Seat6_x1][Seat6_y1]=7;
  Map6[Seat6_x2][Seat6_y2]=10;
}
void HideCursor6()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy6(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
int Search_Box6()
{
  if(Box6_x==Seat6_x&&Box6_y==Seat6_y&&Box6_x1==Seat6_x1&&Box6_y1==Seat6_y1&&Box6_x2==Seat6_x2&&Box6_y2==Seat6_y2){
    return 1;
  }
  if(Box6_x==Seat6_x&&Box6_y==Seat6_y&&Box6_x1==Seat6_x2&&Box6_y1==Seat6_y2&&Box6_x2==Seat6_x1&&Box6_y2==Seat6_y1){
    return 1;
  }
  if(Box6_x==Seat6_x1&&Box6_y==Seat6_y1&&Box6_x1==Seat6_x&&Box6_y1==Seat6_y&&Box6_x2==Seat6_x2&&Box6_y2==Seat6_y2){
    return 1;
  }
  if(Box6_x==Seat6_x2&&Box6_y==Seat6_y2&&Box6_x1==Seat6_x1&&Box6_y1==Seat6_y1&&Box6_x2==Seat6_x&&Box6_y2==Seat6_y){
    return 1;
  }
  if(Box6_x==Seat6_x1&&Box6_y==Seat6_y1&&Box6_x1==Seat6_x2&&Box6_y1==Seat6_y2&&Box6_x2==Seat6_x&&Box6_y2==Seat6_y){
    return 1;
  }
  if(Box6_x==Seat6_x2&&Box6_y==Seat6_y2&&Box6_x1==Seat6_x&&Box6_y1==Seat6_y&&Box6_x2==Seat6_x1&&Box6_y2==Seat6_y1){
    return 1;
  }
}
void Creat_Map6()
{
  gotoxy6(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map6[i][j]==0){
        cout<<"■";
      }
      if(Map6[i][j]==1){
        cout<<"■";
      }
      if(Map6[i][j]==2){
        cout<<"  ";
      }
      if(Map6[i][j]==3){
        cout<<"□";
      }
      if(Map6[i][j]==4){
        cout<<"♀";
      }
      if(Map6[i][j]==5){
        cout<<"●";
      }
      if(Map6[i][j]==7){
        cout<<"●";
      }
      if(Map6[i][j]==6){
        cout<<"□";
      }
      if(Map6[i][j]==8){
        cout<<"□";
      }
      if(Map6[i][j]==9){
        cout<<"□";
      }
      if(Map6[i][j]==10){
        cout<<"●";
      }
    }
    cout<<endl;
  }
  cout<<"game six"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move6()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map6[People_x-1][People_y]==1){
         ;
       }
       else if((Map6[People_x-1][People_y]==Map6[Box6_x][Box6_y]&&Map6[Box6_x-1][Box6_y]==0)||(Map6[People_x-1][People_y]==Map6[Box6_x1][Box6_y1]&&Map6[Box6_x1-1][Box6_y1]==0)
     ||(Map6[People_x-1][People_y]==Map6[Box6_x2][Box6_y2]&&Map6[Box6_x2-1][Box6_y2]==0)){
         ;
       }
       else if((Map6[People_x-1][People_y]==Map6[Box6_x][Box6_y]&&Map6[Box6_x-1][Box6_y]==1)||(Map6[People_x-1][People_y]==Map6[Box6_x1][Box6_y1]&&Map6[Box6_x1-1][Box6_y1]==1)
     ||(Map6[People_x-1][People_y]==Map6[Box6_x2][Box6_y2]&&Map6[Box6_x2-1][Box6_y2]==1)){
         ;
       }
       else if(Map6[People_x-1][People_y]==6&&Map6[Box6_x1-1][Box6_y1]==3){
         ;
       }
       else if(Map6[People_x-1][People_y]==6&&Map6[Box6_x1-1][Box6_y1]==9){
         ;
       }
       else if(Map6[People_x-1][People_y]==3&&Map6[Box6_x-1][Box6_y]==6){
         ;
       }
       else if(Map6[People_x-1][People_y]==3&&Map6[Box6_x-1][Box6_y]==9){
         ;
       }
       else if(Map6[People_x-1][People_y]==9&&Map6[Box6_x2-1][Box6_y2]==3){
         ;
       }
       else if(Map6[People_x-1][People_y]==9&&Map6[Box6_x2-1][Box6_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x-1==Box6_x&&People_y==Box6_y){
           Map6[Seat6_x][Seat6_y]=5;
           People_x--;
           Box6_x--;
         }
        else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x-1==Box6_x1&&People_y==Box6_y1){
           Map6[Seat6_x][Seat6_y]=5;
           People_x--;
           Box6_x1--;
         }
         else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x-1==Box6_x2&&People_y==Box6_y2){
            Map6[Seat6_x][Seat6_y]=5;
            People_x--;
            Box6_x2--;
          }
        else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x-1==Box6_x&&People_y==Box6_y){
           Map6[Seat6_x1][Seat6_y1]=7;
           People_x--;
           Box6_x--;
         }
        else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x-1==Box6_x1&&People_y==Box6_y1){
           Map6[Seat6_x1][Seat6_y1]=7;
           People_x--;
           Box6_x1--;
         }
         else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x-1==Box6_x2&&People_y==Box6_y2){
            Map6[Seat6_x1][Seat6_y1]=7;
            People_x--;
            Box6_x2--;
          }
         else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x-1==Box6_x&&People_y==Box6_y){
            Map6[Seat6_x2][Seat6_y2]=10;
            People_x--;
            Box6_x--;
          }
          else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x-1==Box6_x1&&People_y==Box6_y1){
             Map6[Seat6_x2][Seat6_y2]=10;
             People_x--;
             Box6_x1--;
           }
           else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x-1==Box6_x2&&People_y==Box6_y2){
              Map6[Seat6_x2][Seat6_y2]=10;
              People_x--;
              Box6_x2--;
            }
       //}


       else if((People_x==Seat6_x&&People_y==Seat6_y&&Map6[Seat6_x-1][Seat6_y]!=0)||(People_x==Seat6_x&&People_y==Seat6_y&&Map6[Seat6_x-1][Seat6_y]!=1)){
         People_x--;
         Map6[Seat6_x][Seat6_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat6_x1&&People_y==Seat6_y1&&Map6[Seat6_x1-1][Seat6_y1]!=0)||(People_x==Seat6_x1&&People_y==Seat6_y1&&Map6[Seat6_x1-1][Seat6_y1]!=1)){
         People_x--;
         Map6[Seat6_x1][Seat6_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat6_x2&&People_y==Seat6_y2&&Map6[Seat6_x2-1][Seat6_y2]!=0)||(People_x==Seat6_x2&&People_y==Seat6_y2&&Map6[Seat6_x2-1][Seat6_y2]!=1)){
         People_x--;
         Map6[Seat6_x2][Seat6_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map6[Box6_x-1][Box6_y]==5&&Map6[People_x-2][People_y]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x-1][Box6_y]==7&&Map6[People_x-2][People_y]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x-1][Box6_y]==10&&Map6[People_x-2][People_y]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1-1][Box6_y1]==5&&Map6[People_x-2][People_y]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1-1][Box6_y1]==7&&Map6[People_x-2][People_y]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1-1][Box6_y1]==10&&Map6[People_x-2][People_y]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2-1][Box6_y2]==5&&Map6[People_x-2][People_y]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2-1][Box6_y2]==7&&Map6[People_x-2][People_y]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2-1][Box6_y2]==10&&Map6[People_x-2][People_y]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }

        else if(Map6[People_x-1][People_y]!=6&&Map6[People_x-1][People_y]==3&&Map6[People_x-1][People_y]!=9&&Map6[Box6_x-1][Box6_y]!=0&&Map6[Box6_x-1][Box6_y]!=1){
           People_x--;
           Box6_x--;
           Map6[People_x+1][People_y]=2;
           Map6[Box6_x+1][Box6_y]=2;
         }
        else if(Map6[People_x-1][People_y]==6&Map6[People_x-1][People_y]!=3&&Map6[People_x-1][People_y]!=9&&Map6[Box6_x1-1][Box6_y1]!=0&&Map6[Box6_x1-1][Box6_y1]!=1){
           People_x--;
           Box6_x1--;
           Map6[People_x+1][People_y]=2;
           Map6[Box6_x1+1][Box6_y1]=2;
         }
         else if(Map6[People_x-1][People_y]!=6&Map6[People_x-1][People_y]!=3&&Map6[People_x-1][People_y]==9&&Map6[Box6_x1-1][Box6_y1]!=0&&Map6[Box6_x1-1][Box6_y1]!=1){
            People_x--;
            Box6_x2--;
            Map6[People_x+1][People_y]=2;
            Map6[Box6_x2+1][Box6_y2]=2;
          }
         else{
           People_x--;
           Map6[People_x+1][People_y]=2;
         }
     }
     if(input=='s'){
       if(People_x>7||Map6[People_x+1][People_y]==1){
         ;
       }
       else if((Map6[People_x+1][People_y]==Map6[Box6_x][Box6_y]&&Map6[Box6_x+1][Box6_y]==0)||(Map6[People_x+1][People_y]==Map6[Box6_x1][Box6_y1]&&Map6[Box6_x1+1][Box6_y1]==0)
     ||(Map6[People_x+1][People_y]==Map6[Box6_x2][Box6_y2]&&Map6[Box6_x2+1][Box6_y2]==0)){
         ;
       }
       else if((Map6[People_x+1][People_y]==Map6[Box6_x][Box6_y]&&Map6[Box6_x+1][Box6_y]==1)||(Map6[People_x+1][People_y]==Map6[Box6_x1][Box6_y1]&&Map6[Box6_x1+1][Box6_y1]==1)
     ||(Map6[People_x+1][People_y]==Map6[Box6_x2][Box6_y2]&&Map6[Box6_x2+1][Box6_y2]==1)){
         ;
       }
       else if(Map6[People_x+1][People_y]==6&&Map6[Box6_x1+1][Box6_y1]==3){
         ;
       }
       else if(Map6[People_x+1][People_y]==6&&Map6[Box6_x1+1][Box6_y1]==9){
         ;
       }
       else if(Map6[People_x+1][People_y]==3&&Map6[Box6_x+1][Box6_y]==6){
         ;
       }
       else if(Map6[People_x+1][People_y]==3&&Map6[Box6_x+1][Box6_y]==9){
         ;
       }
       else if(Map6[People_x+1][People_y]==9&&Map6[Box6_x2+1][Box6_y2]==3){
         ;
       }
       else if(Map6[People_x+1][People_y]==9&&Map6[Box6_x2+1][Box6_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){


       else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x+1==Box6_x&&People_y==Box6_y){
          Map6[Seat6_x][Seat6_y]=5;
          People_x++;
          Box6_x++;
        }
       else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x+1==Box6_x1&&People_y==Box6_y1){
          Map6[Seat6_x][Seat6_y]=5;
          People_x++;
          Box6_x1++;
        }
        else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x+1==Box6_x2&&People_y==Box6_y2){
           Map6[Seat6_x][Seat6_y]=5;
           People_x++;
           Box6_x2++;
         }
       else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x+1==Box6_x&&People_y==Box6_y){
          Map6[Seat6_x1][Seat6_y1]=7;
          People_x++;
          Box6_x++;
        }
       else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x+1==Box6_x1&&People_y==Box6_y1){
          Map6[Seat6_x1][Seat6_y1]=7;
          People_x++;
          Box6_x1++;
        }
        else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x+1==Box6_x2&&People_y==Box6_y2){
           Map6[Seat6_x1][Seat6_y1]=7;
           People_x++;
           Box6_x2++;
         }
        else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x+1==Box6_x&&People_y==Box6_y){
           Map6[Seat6_x2][Seat6_y2]=10;
           People_x++;
           Box6_x++;
         }else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x+1==Box6_x1&&People_y==Box6_y1){
            Map6[Seat6_x2][Seat6_y2]=10;
            People_x++;
            Box6_x1++;
          }
          else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x+1==Box6_x2&&People_y==Box6_y2){
             Map6[Seat6_x2][Seat6_y2]=10;
             People_x++;
             Box6_x2++;
           }
      // }


       else if((People_x==Seat6_x&&People_y==Seat6_y&&Map6[Seat6_x+1][Seat6_y]!=0)||(People_x==Seat6_x&&People_y==Seat6_y&&Map6[Seat6_x+1][Seat6_y]!=1)){
         People_x++;
         Map6[Seat6_x][Seat6_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat6_x1&&People_y==Seat6_y1&&Map6[Seat6_x1+1][Seat6_y1]!=0)||(People_x==Seat6_x1&&People_y==Seat6_y1&&Map6[Seat6_x1+1][Seat6_y1]!=1)){
         People_x++;
         Map6[Seat6_x1][Seat6_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat6_x2&&People_y==Seat6_y2&&Map6[Seat6_x2+1][Seat6_y1]!=0)||(People_x==Seat6_x2&&People_y==Seat6_y2&&Map6[Seat6_x2+1][Seat6_y2]!=1)){
         People_x++;
         Map6[Seat6_x2][Seat6_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map6[Box6_x+1][Box6_y]==5&&Map6[People_x+2][People_y]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x+1][Box6_y]==7&&Map6[People_x+2][People_y]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x+1][Box6_y]==10&&Map6[People_x+2][People_y]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1+1][Box6_y1]==5&&Map6[People_x+2][People_y]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1+1][Box6_y1]==7&&Map6[People_x+2][People_y]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1+1][Box6_y1]==10&&Map6[People_x+2][People_y]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2+1][Box6_y2]==5&&Map6[People_x+2][People_y]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2+1][Box6_y2]==7&&Map6[People_x+2][People_y]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2+1][Box6_y2]==10&&Map6[People_x+2][People_y]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }


       else if(Map6[People_x+1][People_y]!=6&&Map6[People_x+1][People_y]==3&&Map6[People_x+1][People_y]!=9&&Map6[Box6_x+1][Box6_y]!=0&&Map6[Box6_x+1][Box6_y]!=1){
          People_x++;
          Box6_x++;
          Map6[People_x-1][People_y]=2;
          Map6[Box6_x-1][Box6_y]=2;
        }
       else if(Map6[People_x+1][People_y]==6&Map6[People_x+1][People_y]!=3&&Map6[People_x+1][People_y]!=9&&Map6[Box6_x1+1][Box6_y1]!=0&&Map6[Box6_x1+1][Box6_y1]!=1){
          People_x++;
          Box6_x1++;
          Map6[People_x-1][People_y]=2;
          Map6[Box6_x1-1][Box6_y1]=2;
        }
        else if(Map6[People_x+1][People_y]!=6&Map6[People_x+1][People_y]!=3&&Map6[People_x+1][People_y]==9&&Map6[Box6_x2+1][Box6_y2]!=0&&Map6[Box6_x2+1][Box6_y2]!=1){
           People_x++;
           Box6_x2++;
           Map6[People_x-1][People_y]=2;
           Map6[Box6_x2-1][Box6_y2]=2;
         }
         else{
           People_x++;
           Map6[People_x-1][People_y]=2;
         }
     }
     if(input=='a'){
       if(People_y<2||Map6[People_x][People_y-1]==1){
         ;
       }
       else if((Map6[People_x][People_y-1]==Map6[Box6_x][Box6_y]&&Map6[Box6_x][Box6_y-1]==0)||
       (Map6[People_x][People_y-1]==Map6[Box6_x1][Box6_y1]&&Map6[Box6_x1][Box6_y1-1]==0)
       ||(Map6[People_x][People_y-1]==Map6[Box6_x2][Box6_y2]&&Map6[Box6_x2][Box6_y2-1]==0)){
         ;
       }
       else if((Map6[People_x][People_y-1]==Map6[Box6_x][Box6_y]&&Map6[Box6_x][Box6_y-1]==1)||
       (Map6[People_x][People_y-1]==Map6[Box6_x1][Box6_y1]&&Map6[Box6_x1][Box6_y1-1]==1)
       ||(Map6[People_x][People_y-1]==Map6[Box6_x2][Box6_y2]&&Map6[Box6_x2][Box6_y2-1]==1)){
         ;
       }
       else if(Map6[People_x][People_y-1]==6&&Map6[Box6_x1][Box6_y1-1]==3){
         ;
       }
       else if(Map6[People_x][People_y-1]==6&&Map6[Box6_x1][Box6_y1-1]==9){
         ;
       }
       else if(Map6[People_x][People_y-1]==3&&Map6[Box6_x][Box6_y-1]==6){
         ;
       }
       else if(Map6[People_x][People_y-1]==3&&Map6[Box6_x][Box6_y-1]==9){
         ;
       }
       else if(Map6[People_x][People_y-1]==9&&Map6[Box6_x2][Box6_y2-1]==3){
         ;
       }
       else if(Map6[People_x][People_y-1]==9&&Map6[Box6_x2][Box6_y2-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x==Box6_x&&People_y-1==Box6_y){
           Map6[Seat6_x][Seat6_y]=5;
           People_y--;
           Box6_y--;
         }
        else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x==Box6_x1&&People_y-1==Box6_y1){
           Map6[Seat6_x][Seat6_y]=5;
           People_y--;
           Box6_y1--;
         }
         else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x==Box6_x2&&People_y-1==Box6_y2){
            Map6[Seat6_x][Seat6_y]=5;
            People_y--;
            Box6_y2--;
          }
        else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x==Box6_x&&People_y-1==Box6_y){
           Map6[Seat6_x1][Seat6_y1]=7;
           People_y--;
           Box6_y--;
         }
        else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x==Box6_x1&&People_y-1==Box6_y1){
           Map6[Seat6_x1][Seat6_y1]=7;
           People_y--;
           Box6_y1--;
         }
         else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x==Box6_x2&&People_y-1==Box6_y2){
            Map6[Seat6_x1][Seat6_y1]=7;
            People_y--;
            Box6_y2--;
          }
         else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x==Box6_x&&People_y-1==Box6_y){
            Map6[Seat6_x2][Seat6_y2]=10;
            People_y--;
            Box6_y--;
          }else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x==Box6_x1&&People_y-1==Box6_y1){
             Map6[Seat6_x2][Seat6_y2]=10;
             People_y--;
             Box6_y1--;
           }
           else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x==Box6_x2&&People_y-1==Box6_y2){
              Map6[Seat6_x2][Seat6_y2]=10;
              People_y--;
              Box6_y2--;
            }
       //}


       else if((People_x==Seat6_x&&People_y==Seat6_y&&Map6[Seat6_x][Seat6_y-1]!=0)||(People_x==Seat6_x&&People_y==Seat6_y&&Map6[Seat6_x][Seat6_y-1]!=1)){
         People_y--;
         Map6[Seat6_x][Seat6_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat6_x1&&People_y==Seat6_y1&&Map6[Seat6_x1][Seat6_y1-1]!=0)||(People_x==Seat6_x1&&People_y==Seat6_y1&&Map6[Seat6_x1][Seat6_y1-1]!=1)){
         People_y--;
         Map6[Seat6_x1][Seat6_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat6_x2&&People_y==Seat6_y2&&Map6[Seat6_x2][Seat6_y2-1]!=0)||(People_x==Seat6_x2&&People_y==Seat6_y2&&Map6[Seat6_x2][Seat6_y2-1]!=1)){
         People_y--;
         Map6[Seat6_x2][Seat6_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map6[Box6_x][Box6_y-1]==5&&Map6[People_x][People_y-2]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1][Box6_y1-1]==5&&Map6[People_x][People_y-2]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2][Box6_y2-1]==5&&Map6[People_x][People_y-2]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x][Box6_y-1]==7&&Map6[People_x][People_y-2]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1][Box6_y1-1]==7&&Map6[People_x][People_y-2]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2][Box6_y2-1]==7&&Map6[People_x][People_y-2]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1][Box6_y1-1]==10&&Map6[People_x][People_y-2]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x][Box6_y-1]==10&&Map6[People_x][People_y-2]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2][Box6_y2-1]==10&&Map6[People_x][People_y-2]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }

        else if(Map6[People_x][People_y-1]!=6&&Map6[People_x][People_y-1]==3&&Map6[People_x][People_y-1]!=9&&Map6[Box6_x][Box6_y-1]!=0&&Map6[Box6_x][Box6_y-1]!=1){
           People_y--;
           Box6_y--;
           Map6[People_x][People_y+1]=2;
           Map6[Box6_x][Box6_y+1]=2;
         }
        else if(Map6[People_x][People_y-1]==6&Map6[People_x][People_y-1]!=3&&Map6[People_x][People_y-1]!=9&&Map6[Box6_x1][Box6_y1-1]!=0&&Map6[Box6_x1][Box6_y1-1]!=1){
           People_y--;
           Box6_y1--;
           Map6[People_x][People_y+1]=2;
           Map6[Box6_x1][Box6_y1+1]=2;
         }
         else if(Map6[People_x][People_y-1]!=6&Map6[People_x][People_y-1]!=3&&Map6[People_x][People_y-1]==9&&Map6[Box6_x2][Box6_y2-1]!=0&&Map6[Box6_x2][Box6_y2-1]!=1){
            People_y--;
            Box6_y2--;
            Map6[People_x][People_y+1]=2;
            Map6[Box6_x2][Box6_y2+1]=2;
          }
         else{
           People_y--;
           Map6[People_x][People_y+1]=2;
         }
     }
     if(input=='d'){
       if(People_y>10||Map6[People_x][People_y+1]==1){
         ;
       }
       else if((Map6[People_x][People_y+1]==Map6[Box6_x][Box6_y]&&Map6[Box6_x][Box6_y+1]==0)
       ||(Map6[People_x][People_y+1]==Map6[Box6_x1][Box6_y1]&&Map6[Box6_x1][Box6_y1+1]==0)
       ||(Map6[People_x][People_y+1]==Map6[Box6_x2][Box6_y2]&&Map6[Box6_x2][Box6_y2+1]==0)){
         ;
       }
       else if((Map6[People_x][People_y+1]==Map6[Box6_x][Box6_y]&&Map6[Box6_x][Box6_y+1]==1)
       ||(Map6[People_x][People_y+1]==Map6[Box6_x1][Box6_y1]&&Map6[Box6_x1][Box6_y1+1]==1)
       ||(Map6[People_x][People_y+1]==Map6[Box6_x2][Box6_y2]&&Map6[Box6_x2][Box6_y2+1]==1)){
         ;
       }
       else if(Map6[People_x][People_y+1]==6&&Map6[Box6_x1][Box6_y1+1]==3){
         ;
       }
       else if(Map6[People_x][People_y+1]==6&&Map6[Box6_x1][Box6_y1+1]==9){
         ;
       }
       else if(Map6[People_x][People_y+1]==3&&Map6[Box6_x][Box6_y+1]==6){
         ;
       }
       else if(Map6[People_x][People_y+1]==3&&Map6[Box6_x][Box6_y+1]==9){
         ;
       }
       else if(Map6[People_x][People_y+1]==9&&Map6[Box6_x2][Box6_y2+1]==3){
         ;
       }
       else if(Map6[People_x][People_y+1]==9&&Map6[Box6_x2][Box6_y2+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x==Box6_x&&People_y+1==Box6_y){
           Map6[Seat6_x][Seat6_y]=5;
           People_y++;
           Box6_y++;
         }
        else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x==Box6_x1&&People_y+1==Box6_y1){
           Map6[Seat6_x][Seat6_y]=5;
           People_y++;
           Box6_y1++;
         }
         else if(People_x==Seat6_x&&People_y==Seat6_y&&People_x==Box6_x2&&People_y+1==Box6_y2){
            Map6[Seat6_x][Seat6_y]=5;
            People_y++;
            Box6_y2++;
          }
        else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x==Box6_x&&People_y+1==Box6_y){
           Map6[Seat6_x1][Seat6_y1]=7;
           People_y++;
           Box6_y++;
         }
        else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x==Box6_x1&&People_y+1==Box6_y1){
           Map6[Seat6_x1][Seat6_y1]=7;
           People_y++;
           Box6_y1++;
         }
         else if(People_x==Seat6_x1&&People_y==Seat6_y1&&People_x==Box6_x2&&People_y+1==Box6_y2){
            Map6[Seat6_x1][Seat6_y1]=7;
            People_y++;
            Box6_y2++;
          }
         else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x==Box6_x&&People_y+1==Box6_y){
            Map6[Seat6_x2][Seat6_y2]=10;
            People_y++;
            Box6_y++;
          }else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x==Box6_x1&&People_y+1==Box6_y1){
             Map6[Seat6_x2][Seat6_y2]=10;
             People_y++;
             Box6_y1++;
           }
           else if(People_x==Seat6_x2&&People_y==Seat6_y2&&People_x==Box6_x2&&People_y+1==Box6_y2){
              Map6[Seat6_x2][Seat6_y2]=10;
              People_y++;
              Box6_y2++;
            }
       //}


       else if((People_x==Seat6_x&&People_y==Seat6_y&&Map6[Seat6_x][Seat6_y+1]!=0)||(People_x==Seat6_x&&People_y==Seat6_y&&Map6[Seat6_x][Seat6_y+1]!=1)){
         People_y++;
         Map6[Seat6_x][Seat6_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat6_x1&&People_y==Seat6_y1&&Map6[Seat6_x1][Seat6_y1+1]!=0)||(People_x==Seat6_x1&&People_y==Seat6_y1&&Map6[Seat6_x1][Seat6_y1+1]!=1)){
         People_y++;
         Map6[Seat6_x1][Seat6_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat6_x2&&People_y==Seat6_y2&&Map6[Seat6_x2][Seat6_y2+1]!=0)||(People_x==Seat6_x2&&People_y==Seat6_y2&&Map6[Seat6_x2][Seat6_y2+1]!=1)){
         People_y++;
         Map6[Seat6_x2][Seat6_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map6[Box6_x][Box6_y+1]==5&&Map6[People_x][People_y+2]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x][Box6_y+1]==7&&Map6[People_x][People_y+2]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x][Box6_y+1]==10&&Map6[People_x][People_y+2]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x][Box6_y]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1][Box6_y1+1]==5&&Map6[People_x][People_y+2]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1][Box6_y1+1]==7&&Map6[People_x][People_y+2]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x1][Box6_y1+1]==10&&Map6[People_x][People_y+2]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x1][Box6_y1]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2][Box6_y2+1]==5&&Map6[People_x][People_y+2]==5){
         Map6[Seat6_x][Seat6_y]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2][Box6_y2+1]==7&&Map6[People_x][People_y+2]==7){
         Map6[Seat6_x1][Seat6_y1]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }
       else if(Map6[Box6_x2][Box6_y2+1]==10&&Map6[People_x][People_y+2]==10){
         Map6[Seat6_x2][Seat6_y2]=8;
         Map6[Box6_x2][Box6_y2]=4;
         Map6[People_x][People_y]=2;
       }

        else if(Map6[People_x][People_y+1]!=6&&Map6[People_x][People_y+1]==3&&Map6[People_x][People_y+1]!=9&&Map6[Box6_x][Box6_y+1]!=0&&Map6[Box6_x][Box6_y+1]!=1){
           People_y++;
           Box6_y++;
           Map6[People_x][People_y-1]=2;
           Map6[Box6_x][Box6_y-1]=2;
         }
        else if(Map6[People_x][People_y+1]==6&Map6[People_x][People_y+1]!=3&&Map6[People_x][People_y+1]!=9&&Map6[Box6_x1][Box6_y1+1]!=0&&Map6[Box6_x1][Box6_y1+1]!=1){
           People_y++;
           Box6_y1++;
           Map6[People_x][People_y-1]=2;
           Map6[Box6_x1][Box6_y1-1]=2;
         }
         else if(Map6[People_x][People_y+1]!=6&Map6[People_x][People_y+1]!=3&&Map6[People_x][People_y+1]==9&&Map6[Box6_x2][Box6_y2+1]!=0&&Map6[Box6_x2][Box6_y2+1]!=1){
            People_y++;
            Box6_y2++;
            Map6[People_x][People_y-1]=2;
            Map6[Box6_x2][Box6_y2-1]=2;
          }
         else{
           People_y++;
           Map6[People_x][People_y-1]=2;
         }
     }
   }
}


//game7
int Box7_x,Box7_y;
int Box7_x1,Box7_y1;
int Box7_x2,Box7_y2;
int Seat7_x,Seat7_y;
int Seat7_x1,Seat7_y1;
int Seat7_x2,Seat7_y2;
int Map7[MAPMAX][MAPMAX+3] = {
  {2,2,0,0,0,0,0,0,0,0,0,0,2},
  {2,1,1,2,2,2,2,2,2,2,2,1,2},
  {0,1,2,2,2,1,1,1,1,2,2,1,2},
  {0,2,2,2,2,1,2,2,1,2,2,1,0},
  {0,1,1,1,2,1,1,1,1,2,2,2,0},
  {0,2,2,2,2,1,2,2,2,2,2,1,0},
  {0,1,1,1,2,2,2,2,2,2,2,2,0},
  {2,2,2,1,2,1,2,1,1,1,2,1,0},
  {2,2,2,1,2,2,2,1,2,1,1,1,2},
  {2,2,2,0,0,0,0,0,2,2,2,2,2},
};
void Map_Start7()
{
      Map7[People_x][People_y]=4;
      Map7[Box7_x][Box7_y]=3;
      Map7[Box7_x1][Box7_y1]=6;
      Map7[Box7_x2][Box7_y2]=9;
}
void Seat_Set7()
{
  if(Map7[Seat7_x][Seat7_y]!=8){
    Map7[Seat7_x][Seat7_y]=5;
  }
  if(Map7[Seat7_x1][Seat7_y1]!=8){
      Map7[Seat7_x1][Seat7_y1]=7;
  }
  if(Map7[Seat7_x2][Seat7_y2]!=8){
    Map7[Seat7_x2][Seat7_y2]=10;
  }
}
void Creat_Seat7()
{
  People_x=1;
  People_y=3;
  Box7_x=3;
  Box7_y=3;
  Box7_x1=3;
  Box7_y1=9;
  Box7_x2=6;
  Box7_y2=5;
  Seat7_x=1;
  Seat7_y=6;
  Seat7_x1=7;
  Seat7_y1=6;
  Seat7_x2=5;
  Seat7_y2=7;
  Map7[Seat7_x][Seat7_y]=5;
  Map7[Seat7_x1][Seat7_y1]=7;
  Map7[Seat7_x2][Seat7_y2]=10;
}
void HideCursor7()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy7(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
int Search_Box7()
{
  if(Box7_x==Seat7_x&&Box7_y==Seat7_y&&Box7_x1==Seat7_x1&&Box7_y1==Seat7_y1&&Box7_x2==Seat7_x2&&Box7_y2==Seat7_y2){
    return 1;
  }
  if(Box7_x==Seat7_x&&Box7_y==Seat7_y&&Box7_x1==Seat7_x2&&Box7_y1==Seat7_y2&&Box7_x2==Seat7_x1&&Box7_y2==Seat7_y1){
    return 1;
  }
  if(Box7_x==Seat7_x1&&Box7_y==Seat7_y1&&Box7_x1==Seat7_x&&Box7_y1==Seat7_y&&Box7_x2==Seat7_x2&&Box7_y2==Seat7_y2){
    return 1;
  }
  if(Box7_x==Seat7_x2&&Box7_y==Seat7_y2&&Box7_x1==Seat7_x1&&Box7_y1==Seat7_y1&&Box7_x2==Seat7_x&&Box7_y2==Seat7_y){
    return 1;
  }
  if(Box7_x==Seat7_x1&&Box7_y==Seat7_y1&&Box7_x1==Seat7_x2&&Box7_y1==Seat7_y2&&Box7_x2==Seat7_x&&Box7_y2==Seat7_y){
    return 1;
  }
  if(Box7_x==Seat7_x2&&Box7_y==Seat7_y2&&Box7_x1==Seat7_x&&Box7_y1==Seat7_y&&Box7_x2==Seat7_x1&&Box7_y2==Seat7_y1){
    return 1;
  }
}
void Creat_Map7()
{
  gotoxy7(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map7[i][j]==0){
        cout<<"■";
      }
      if(Map7[i][j]==1){
        cout<<"■";
      }
      if(Map7[i][j]==2){
        cout<<"  ";
      }
      if(Map7[i][j]==3){
        cout<<"□";
      }
      if(Map7[i][j]==4){
        cout<<"♀";
      }
      if(Map7[i][j]==5){
        cout<<"●";
      }
      if(Map7[i][j]==7){
        cout<<"●";
      }
      if(Map7[i][j]==6){
        cout<<"□";
      }
      if(Map7[i][j]==8){
        cout<<"□";
      }
      if(Map7[i][j]==9){
        cout<<"□";
      }
      if(Map7[i][j]==10){
        cout<<"●";
      }
    }
    cout<<endl;
  }
  cout<<"game seven"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move7()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map7[People_x-1][People_y]==1){
         ;
       }
       else if((Map7[People_x-1][People_y]==Map7[Box7_x][Box7_y]&&Map7[Box7_x-1][Box7_y]==0)||(Map7[People_x-1][People_y]==Map7[Box7_x1][Box7_y1]&&Map7[Box7_x1-1][Box7_y1]==0)
     ||(Map7[People_x-1][People_y]==Map7[Box7_x2][Box7_y2]&&Map7[Box7_x2-1][Box7_y2]==0)){
         ;
       }
       else if((Map7[People_x-1][People_y]==Map7[Box7_x][Box7_y]&&Map7[Box7_x-1][Box7_y]==1)||(Map7[People_x-1][People_y]==Map7[Box7_x1][Box7_y1]&&Map7[Box7_x1-1][Box7_y1]==1)
     ||(Map7[People_x-1][People_y]==Map7[Box7_x2][Box7_y2]&&Map7[Box7_x2-1][Box7_y2]==1)){
         ;
       }
       else if(Map7[People_x-1][People_y]==6&&Map7[Box7_x1-1][Box7_y1]==3){
         ;
       }
       else if(Map7[People_x-1][People_y]==6&&Map7[Box7_x1-1][Box7_y1]==9){
         ;
       }
       else if(Map7[People_x-1][People_y]==3&&Map7[Box7_x-1][Box7_y]==6){
         ;
       }
       else if(Map7[People_x-1][People_y]==3&&Map7[Box7_x-1][Box7_y]==9){
         ;
       }
       else if(Map7[People_x-1][People_y]==9&&Map7[Box7_x2-1][Box7_y2]==3){
         ;
       }
       else if(Map7[People_x-1][People_y]==9&&Map7[Box7_x2-1][Box7_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x-1==Box7_x&&People_y==Box7_y){
           Map7[Seat7_x][Seat7_y]=5;
           People_x--;
           Box7_x--;
         }
        else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x-1==Box7_x1&&People_y==Box7_y1){
           Map7[Seat7_x][Seat7_y]=5;
           People_x--;
           Box7_x1--;
         }
         else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x-1==Box7_x2&&People_y==Box7_y2){
            Map7[Seat7_x][Seat7_y]=5;
            People_x--;
            Box7_x2--;
          }
        else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x-1==Box7_x&&People_y==Box7_y){
           Map7[Seat7_x1][Seat7_y1]=7;
           People_x--;
           Box7_x--;
         }
        else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x-1==Box7_x1&&People_y==Box7_y1){
           Map7[Seat7_x1][Seat7_y1]=7;
           People_x--;
           Box7_x1--;
         }
         else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x-1==Box7_x2&&People_y==Box7_y2){
            Map7[Seat7_x1][Seat7_y1]=7;
            People_x--;
            Box7_x2--;
          }
         else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x-1==Box7_x&&People_y==Box7_y){
            Map7[Seat7_x2][Seat7_y2]=10;
            People_x--;
            Box7_x--;
          }
          else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x-1==Box7_x1&&People_y==Box7_y1){
             Map7[Seat7_x2][Seat7_y2]=10;
             People_x--;
             Box7_x1--;
           }
           else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x-1==Box7_x2&&People_y==Box7_y2){
              Map7[Seat7_x2][Seat7_y2]=10;
              People_x--;
              Box7_x2--;
            }
       //}


       else if((People_x==Seat7_x&&People_y==Seat7_y&&Map7[Seat7_x-1][Seat7_y]!=0)||(People_x==Seat7_x&&People_y==Seat7_y&&Map7[Seat7_x-1][Seat7_y]!=1)){
         People_x--;
         Map7[Seat7_x][Seat7_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat7_x1&&People_y==Seat7_y1&&Map7[Seat7_x1-1][Seat7_y1]!=0)||(People_x==Seat7_x1&&People_y==Seat7_y1&&Map7[Seat7_x1-1][Seat7_y1]!=1)){
         People_x--;
         Map7[Seat7_x1][Seat7_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat7_x2&&People_y==Seat7_y2&&Map7[Seat7_x2-1][Seat7_y2]!=0)||(People_x==Seat7_x2&&People_y==Seat7_y2&&Map7[Seat7_x2-1][Seat7_y2]!=1)){
         People_x--;
         Map7[Seat7_x2][Seat7_y2]=7;
         //Map[People_x][People_y]=2;
       }
       else if(Map7[Box7_x-1][Box7_y]==5&&Map7[People_x-2][People_y]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x-1][Box7_y]==7&&Map7[People_x-2][People_y]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x-1][Box7_y]==10&&Map7[People_x-2][People_y]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1-1][Box7_y1]==5&&Map7[People_x-2][People_y]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1-1][Box7_y1]==7&&Map7[People_x-2][People_y]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1-1][Box7_y1]==10&&Map7[People_x-2][People_y]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2-1][Box7_y2]==5&&Map7[People_x-2][People_y]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2-1][Box7_y2]==7&&Map7[People_x-2][People_y]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2-1][Box7_y2]==10&&Map7[People_x-2][People_y]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }

        else if(Map7[People_x-1][People_y]!=6&&Map7[People_x-1][People_y]==3&&Map7[People_x-1][People_y]!=9&&Map7[Box7_x-1][Box7_y]!=0&&Map7[Box7_x-1][Box7_y]!=1){
           People_x--;
           Box7_x--;
           Map7[People_x+1][People_y]=2;
           Map7[Box7_x+1][Box7_y]=2;
         }
        else if(Map7[People_x-1][People_y]==6&Map7[People_x-1][People_y]!=3&&Map7[People_x-1][People_y]!=9&&Map7[Box7_x1-1][Box7_y1]!=0&&Map7[Box7_x1-1][Box7_y1]!=1){
           People_x--;
           Box7_x1--;
           Map7[People_x+1][People_y]=2;
           Map7[Box7_x1+1][Box7_y1]=2;
         }
         else if(Map7[People_x-1][People_y]!=6&Map7[People_x-1][People_y]!=3&&Map7[People_x-1][People_y]==9&&Map7[Box7_x1-1][Box7_y1]!=0&&Map7[Box7_x1-1][Box7_y1]!=1){
            People_x--;
            Box7_x2--;
            Map7[People_x+1][People_y]=2;
            Map7[Box7_x2+1][Box7_y2]=2;
          }
         else{
           People_x--;
           Map7[People_x+1][People_y]=2;
         }
     }
     if(input=='s'){
       if(People_x>7||Map7[People_x+1][People_y]==1){
         ;
       }
       else if((Map7[People_x+1][People_y]==Map7[Box7_x][Box7_y]&&Map7[Box7_x+1][Box7_y]==0)||(Map7[People_x+1][People_y]==Map7[Box7_x1][Box7_y1]&&Map7[Box7_x1+1][Box7_y1]==0)
     ||(Map7[People_x+1][People_y]==Map7[Box7_x2][Box7_y2]&&Map7[Box7_x2+1][Box7_y2]==0)){
         ;
       }
       else if((Map7[People_x+1][People_y]==Map7[Box7_x][Box7_y]&&Map7[Box7_x+1][Box7_y]==1)||(Map7[People_x+1][People_y]==Map7[Box7_x1][Box7_y1]&&Map7[Box7_x1+1][Box7_y1]==1)
     ||(Map7[People_x+1][People_y]==Map7[Box7_x2][Box7_y2]&&Map7[Box7_x2+1][Box7_y2]==1)){
         ;
       }
       else if(Map7[People_x+1][People_y]==6&&Map7[Box7_x1+1][Box7_y1]==3){
         ;
       }
       else if(Map7[People_x+1][People_y]==6&&Map7[Box7_x1+1][Box7_y1]==9){
         ;
       }
       else if(Map7[People_x+1][People_y]==3&&Map7[Box7_x+1][Box7_y]==6){
         ;
       }
       else if(Map7[People_x+1][People_y]==3&&Map7[Box7_x+1][Box7_y]==9){
         ;
       }
       else if(Map7[People_x+1][People_y]==9&&Map7[Box7_x2+1][Box7_y2]==3){
         ;
       }
       else if(Map7[People_x+1][People_y]==9&&Map7[Box7_x2+1][Box7_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){


       else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x+1==Box7_x&&People_y==Box7_y){
          Map7[Seat7_x][Seat7_y]=5;
          People_x++;
          Box7_x++;
        }
       else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x+1==Box7_x1&&People_y==Box7_y1){
          Map7[Seat7_x][Seat7_y]=5;
          People_x++;
          Box7_x1++;
        }
        else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x+1==Box7_x2&&People_y==Box7_y2){
           Map7[Seat7_x][Seat7_y]=5;
           People_x++;
           Box7_x2++;
         }
       else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x+1==Box7_x&&People_y==Box7_y){
          Map7[Seat7_x1][Seat7_y1]=7;
          People_x++;
          Box7_x++;
        }
       else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x+1==Box7_x1&&People_y==Box7_y1){
          Map7[Seat7_x1][Seat7_y1]=7;
          People_x++;
          Box7_x1++;
        }
        else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x+1==Box7_x2&&People_y==Box7_y2){
           Map7[Seat7_x1][Seat7_y1]=7;
           People_x++;
           Box7_x2++;
         }
        else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x+1==Box7_x&&People_y==Box7_y){
           Map7[Seat7_x2][Seat7_y2]=10;
           People_x++;
           Box7_x++;
         }else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x+1==Box7_x1&&People_y==Box7_y1){
            Map7[Seat7_x2][Seat7_y2]=10;
            People_x++;
            Box7_x1++;
          }
          else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x+1==Box7_x2&&People_y==Box7_y2){
             Map7[Seat7_x2][Seat7_y2]=10;
             People_x++;
             Box7_x2++;
           }
      // }


       else if((People_x==Seat7_x&&People_y==Seat7_y&&Map7[Seat7_x+1][Seat7_y]!=0)||(People_x==Seat7_x&&People_y==Seat7_y&&Map7[Seat7_x+1][Seat7_y]!=1)){
         People_x++;
         Map7[Seat7_x][Seat7_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat7_x1&&People_y==Seat7_y1&&Map7[Seat7_x1+1][Seat7_y1]!=0)||(People_x==Seat7_x1&&People_y==Seat7_y1&&Map7[Seat7_x1+1][Seat7_y1]!=1)){
         People_x++;
         Map7[Seat7_x1][Seat7_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat7_x2&&People_y==Seat7_y2&&Map7[Seat7_x2+1][Seat7_y1]!=0)||(People_x==Seat7_x2&&People_y==Seat7_y2&&Map7[Seat7_x2+1][Seat7_y2]!=1)){
         People_x++;
         Map7[Seat7_x2][Seat7_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map7[Box7_x+1][Box7_y]==5&&Map7[People_x+2][People_y]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x+1][Box7_y]==7&&Map7[People_x+2][People_y]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x+1][Box7_y]==10&&Map7[People_x+2][People_y]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1+1][Box7_y1]==5&&Map7[People_x+2][People_y]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1+1][Box7_y1]==7&&Map7[People_x+2][People_y]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1+1][Box7_y1]==10&&Map7[People_x+2][People_y]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2+1][Box7_y2]==5&&Map7[People_x+2][People_y]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2+1][Box7_y2]==7&&Map7[People_x+2][People_y]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2+1][Box7_y2]==10&&Map7[People_x+2][People_y]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }


       else if(Map7[People_x+1][People_y]!=6&&Map7[People_x+1][People_y]==3&&Map7[People_x+1][People_y]!=9&&Map7[Box7_x+1][Box7_y]!=0&&Map7[Box7_x+1][Box7_y]!=1){
          People_x++;
          Box7_x++;
          Map7[People_x-1][People_y]=2;
          Map7[Box7_x-1][Box7_y]=2;
        }
       else if(Map7[People_x+1][People_y]==6&Map7[People_x+1][People_y]!=3&&Map7[People_x+1][People_y]!=9&&Map7[Box7_x1+1][Box7_y1]!=0&&Map7[Box7_x1+1][Box7_y1]!=1){
          People_x++;
          Box7_x1++;
          Map7[People_x-1][People_y]=2;
          Map7[Box7_x1-1][Box7_y1]=2;
        }
        else if(Map7[People_x+1][People_y]!=6&Map7[People_x+1][People_y]!=3&&Map7[People_x+1][People_y]==9&&Map7[Box7_x2+1][Box7_y2]!=0&&Map7[Box7_x2+1][Box7_y2]!=1){
           People_x++;
           Box7_x2++;
           Map7[People_x-1][People_y]=2;
           Map7[Box7_x2-1][Box7_y2]=2;
         }
         else{
           People_x++;
           Map7[People_x-1][People_y]=2;
         }
     }
     if(input=='a'){
       if(People_y<2||Map7[People_x][People_y-1]==1){
         ;
       }
       else if((Map7[People_x][People_y-1]==Map7[Box7_x][Box7_y]&&Map7[Box7_x][Box7_y-1]==0)||
       (Map7[People_x][People_y-1]==Map7[Box7_x1][Box7_y1]&&Map7[Box7_x1][Box7_y1-1]==0)
       ||(Map7[People_x][People_y-1]==Map7[Box7_x2][Box7_y2]&&Map7[Box7_x2][Box7_y2-1]==0)){
         ;
       }
       else if((Map7[People_x][People_y-1]==Map7[Box7_x][Box7_y]&&Map7[Box7_x][Box7_y-1]==1)||
       (Map7[People_x][People_y-1]==Map7[Box7_x1][Box7_y1]&&Map7[Box7_x1][Box7_y1-1]==1)
       ||(Map7[People_x][People_y-1]==Map7[Box7_x2][Box7_y2]&&Map7[Box7_x2][Box7_y2-1]==1)){
         ;
       }
       else if(Map7[People_x][People_y-1]==6&&Map7[Box7_x1][Box7_y1-1]==3){
         ;
       }
       else if(Map7[People_x][People_y-1]==6&&Map7[Box7_x1][Box7_y1-1]==9){
         ;
       }
       else if(Map7[People_x][People_y-1]==3&&Map7[Box7_x][Box7_y-1]==6){
         ;
       }
       else if(Map7[People_x][People_y-1]==3&&Map7[Box7_x][Box7_y-1]==9){
         ;
       }
       else if(Map7[People_x][People_y-1]==9&&Map7[Box7_x2][Box7_y2-1]==3){
         ;
       }
       else if(Map7[People_x][People_y-1]==9&&Map7[Box7_x2][Box7_y2-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x==Box7_x&&People_y-1==Box7_y){
           Map7[Seat7_x][Seat7_y]=5;
           People_y--;
           Box7_y--;
         }
        else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x==Box7_x1&&People_y-1==Box7_y1){
           Map7[Seat7_x][Seat7_y]=5;
           People_y--;
           Box7_y1--;
         }
         else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x==Box7_x2&&People_y-1==Box7_y2){
            Map7[Seat7_x][Seat7_y]=5;
            People_y--;
            Box7_y2--;
          }
        else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x==Box7_x&&People_y-1==Box7_y){
           Map7[Seat7_x1][Seat7_y1]=7;
           People_y--;
           Box7_y--;
         }
        else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x==Box7_x1&&People_y-1==Box7_y1){
           Map7[Seat7_x1][Seat7_y1]=7;
           People_y--;
           Box7_y1--;
         }
         else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x==Box7_x2&&People_y-1==Box7_y2){
            Map7[Seat7_x1][Seat7_y1]=7;
            People_y--;
            Box7_y2--;
          }
         else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x==Box7_x&&People_y-1==Box7_y){
            Map7[Seat7_x2][Seat7_y2]=10;
            People_y--;
            Box7_y--;
          }else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x==Box7_x1&&People_y-1==Box7_y1){
             Map7[Seat7_x2][Seat7_y2]=10;
             People_y--;
             Box7_y1--;
           }
           else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x==Box7_x2&&People_y-1==Box7_y2){
              Map7[Seat7_x2][Seat7_y2]=10;
              People_y--;
              Box7_y2--;
            }
       //}


       else if((People_x==Seat7_x&&People_y==Seat7_y&&Map7[Seat7_x][Seat7_y-1]!=0)||(People_x==Seat7_x&&People_y==Seat7_y&&Map7[Seat7_x][Seat7_y-1]!=1)){
         People_y--;
         Map7[Seat7_x][Seat7_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat7_x1&&People_y==Seat7_y1&&Map7[Seat7_x1][Seat7_y1-1]!=0)||(People_x==Seat7_x1&&People_y==Seat7_y1&&Map7[Seat7_x1][Seat7_y1-1]!=1)){
         People_y--;
         Map7[Seat7_x1][Seat7_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat7_x2&&People_y==Seat7_y2&&Map7[Seat7_x2][Seat7_y2-1]!=0)||(People_x==Seat7_x2&&People_y==Seat7_y2&&Map7[Seat7_x2][Seat7_y2-1]!=1)){
         People_y--;
         Map7[Seat7_x2][Seat7_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map7[Box7_x][Box7_y-1]==5&&Map7[People_x][People_y-2]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1][Box7_y1-1]==5&&Map7[People_x][People_y-2]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2][Box7_y2-1]==5&&Map7[People_x][People_y-2]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x][Box7_y-1]==7&&Map7[People_x][People_y-2]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1][Box7_y1-1]==7&&Map7[People_x][People_y-2]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2][Box7_y2-1]==7&&Map7[People_x][People_y-2]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1][Box7_y1-1]==10&&Map7[People_x][People_y-2]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x][Box7_y-1]==10&&Map7[People_x][People_y-2]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2][Box7_y2-1]==10&&Map7[People_x][People_y-2]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }

        else if(Map7[People_x][People_y-1]!=6&&Map7[People_x][People_y-1]==3&&Map7[People_x][People_y-1]!=9&&Map7[Box7_x][Box7_y-1]!=0&&Map7[Box7_x][Box7_y-1]!=1){
           People_y--;
           Box7_y--;
           Map7[People_x][People_y+1]=2;
           Map7[Box7_x][Box7_y+1]=2;
         }
        else if(Map7[People_x][People_y-1]==6&Map7[People_x][People_y-1]!=3&&Map7[People_x][People_y-1]!=9&&Map7[Box7_x1][Box7_y1-1]!=0&&Map7[Box7_x1][Box7_y1-1]!=1){
           People_y--;
           Box7_y1--;
           Map7[People_x][People_y+1]=2;
           Map7[Box7_x1][Box7_y1+1]=2;
         }
         else if(Map7[People_x][People_y-1]!=6&Map7[People_x][People_y-1]!=3&&Map7[People_x][People_y-1]==9&&Map7[Box7_x2][Box7_y2-1]!=0&&Map7[Box7_x2][Box7_y2-1]!=1){
            People_y--;
            Box7_y2--;
            Map7[People_x][People_y+1]=2;
            Map7[Box7_x2][Box7_y2+1]=2;
          }
         else{
           People_y--;
           Map7[People_x][People_y+1]=2;
         }
     }
     if(input=='d'){
       if(People_y>10||Map7[People_x][People_y+1]==1){
         ;
       }
       else if((Map7[People_x][People_y+1]==Map7[Box7_x][Box7_y]&&Map7[Box7_x][Box7_y+1]==0)
       ||(Map7[People_x][People_y+1]==Map7[Box7_x1][Box7_y1]&&Map7[Box7_x1][Box7_y1+1]==0)
       ||(Map7[People_x][People_y+1]==Map7[Box7_x2][Box7_y2]&&Map7[Box7_x2][Box7_y2+1]==0)){
         ;
       }
       else if((Map7[People_x][People_y+1]==Map7[Box7_x][Box7_y]&&Map7[Box7_x][Box7_y+1]==1)
       ||(Map7[People_x][People_y+1]==Map7[Box7_x1][Box7_y1]&&Map7[Box7_x1][Box7_y1+1]==1)
       ||(Map7[People_x][People_y+1]==Map7[Box7_x2][Box7_y2]&&Map7[Box7_x2][Box7_y2+1]==1)){
         ;
       }
       else if(Map7[People_x][People_y+1]==6&&Map7[Box7_x1][Box7_y1+1]==3){
         ;
       }
       else if(Map7[People_x][People_y+1]==6&&Map7[Box7_x1][Box7_y1+1]==9){
         ;
       }
       else if(Map7[People_x][People_y+1]==3&&Map7[Box7_x][Box7_y+1]==6){
         ;
       }
       else if(Map7[People_x][People_y+1]==3&&Map7[Box7_x][Box7_y+1]==9){
         ;
       }
       else if(Map7[People_x][People_y+1]==9&&Map7[Box7_x2][Box7_y2+1]==3){
         ;
       }
       else if(Map7[People_x][People_y+1]==9&&Map7[Box7_x2][Box7_y2+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x==Box7_x&&People_y+1==Box7_y){
           Map7[Seat7_x][Seat7_y]=5;
           People_y++;
           Box7_y++;
         }
        else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x==Box7_x1&&People_y+1==Box7_y1){
           Map7[Seat7_x][Seat7_y]=5;
           People_y++;
           Box7_y1++;
         }
         else if(People_x==Seat7_x&&People_y==Seat7_y&&People_x==Box7_x2&&People_y+1==Box7_y2){
            Map7[Seat7_x][Seat7_y]=5;
            People_y++;
            Box7_y2++;
          }
        else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x==Box7_x&&People_y+1==Box7_y){
           Map7[Seat7_x1][Seat7_y1]=7;
           People_y++;
           Box7_y++;
         }
        else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x==Box7_x1&&People_y+1==Box7_y1){
           Map7[Seat7_x1][Seat7_y1]=7;
           People_y++;
           Box7_y1++;
         }
         else if(People_x==Seat7_x1&&People_y==Seat7_y1&&People_x==Box7_x2&&People_y+1==Box7_y2){
            Map7[Seat7_x1][Seat7_y1]=7;
            People_y++;
            Box7_y2++;
          }
         else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x==Box7_x&&People_y+1==Box7_y){
            Map7[Seat7_x2][Seat7_y2]=10;
            People_y++;
            Box7_y++;
          }else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x==Box7_x1&&People_y+1==Box7_y1){
             Map7[Seat7_x2][Seat7_y2]=10;
             People_y++;
             Box7_y1++;
           }
           else if(People_x==Seat7_x2&&People_y==Seat7_y2&&People_x==Box7_x2&&People_y+1==Box7_y2){
              Map7[Seat7_x2][Seat7_y2]=10;
              People_y++;
              Box7_y2++;
            }
       //}


       else if((People_x==Seat7_x&&People_y==Seat7_y&&Map7[Seat7_x][Seat7_y+1]!=0)||(People_x==Seat7_x&&People_y==Seat7_y&&Map7[Seat7_x][Seat7_y+1]!=1)){
         People_y++;
         Map7[Seat7_x][Seat7_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat7_x1&&People_y==Seat7_y1&&Map7[Seat7_x1][Seat7_y1+1]!=0)||(People_x==Seat7_x1&&People_y==Seat7_y1&&Map7[Seat7_x1][Seat7_y1+1]!=1)){
         People_y++;
         Map7[Seat7_x1][Seat7_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat7_x2&&People_y==Seat7_y2&&Map7[Seat7_x2][Seat7_y2+1]!=0)||(People_x==Seat7_x2&&People_y==Seat7_y2&&Map7[Seat7_x2][Seat7_y2+1]!=1)){
         People_y++;
         Map7[Seat7_x2][Seat7_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map7[Box7_x][Box7_y+1]==5&&Map7[People_x][People_y+2]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x][Box7_y+1]==7&&Map7[People_x][People_y+2]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x][Box7_y+1]==10&&Map7[People_x][People_y+2]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x][Box7_y]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1][Box7_y1+1]==5&&Map7[People_x][People_y+2]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1][Box7_y1+1]==7&&Map7[People_x][People_y+2]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x1][Box7_y1+1]==10&&Map7[People_x][People_y+2]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x1][Box7_y1]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2][Box7_y2+1]==5&&Map7[People_x][People_y+2]==5){
         Map7[Seat7_x][Seat7_y]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2][Box7_y2+1]==7&&Map7[People_x][People_y+2]==7){
         Map7[Seat7_x1][Seat7_y1]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }
       else if(Map7[Box7_x2][Box7_y2+1]==10&&Map7[People_x][People_y+2]==10){
         Map7[Seat7_x2][Seat7_y2]=8;
         Map7[Box7_x2][Box7_y2]=4;
         Map7[People_x][People_y]=2;
       }

        else if(Map7[People_x][People_y+1]!=6&&Map7[People_x][People_y+1]==3&&Map7[People_x][People_y+1]!=9&&Map7[Box7_x][Box7_y+1]!=0&&Map7[Box7_x][Box7_y+1]!=1){
           People_y++;
           Box7_y++;
           Map7[People_x][People_y-1]=2;
           Map7[Box7_x][Box7_y-1]=2;
         }
        else if(Map7[People_x][People_y+1]==6&Map7[People_x][People_y+1]!=3&&Map7[People_x][People_y+1]!=9&&Map7[Box7_x1][Box7_y1+1]!=0&&Map7[Box7_x1][Box7_y1+1]!=1){
           People_y++;
           Box7_y1++;
           Map7[People_x][People_y-1]=2;
           Map7[Box7_x1][Box7_y1-1]=2;
         }
         else if(Map7[People_x][People_y+1]!=6&Map7[People_x][People_y+1]!=3&&Map7[People_x][People_y+1]==9&&Map7[Box7_x2][Box7_y2+1]!=0&&Map7[Box7_x2][Box7_y2+1]!=1){
            People_y++;
            Box7_y2++;
            Map7[People_x][People_y-1]=2;
            Map7[Box7_x2][Box7_y2-1]=2;
          }
         else{
           People_y++;
           Map7[People_x][People_y-1]=2;
         }
     }
   }
}



int Box8_x,Box8_y;
int Box8_x1,Box8_y1;
int Box8_x2,Box8_y2;
int Seat8_x,Seat8_y;
int Seat8_x1,Seat8_y1;
int Seat8_x2,Seat8_y2;
int Map8[MAPMAX][MAPMAX+3] = {
  {2,2,0,0,0,0,0,0,0,0,0,0,2},
  {2,1,1,2,2,2,2,2,2,2,2,1,2},
  {0,1,2,2,2,1,1,1,1,2,2,1,2},
  {0,2,2,2,2,1,2,2,1,2,2,1,0},
  {0,1,1,1,2,1,1,1,1,2,2,2,0},
  {0,2,2,2,2,1,2,2,2,2,2,1,0},
  {0,1,1,1,2,2,2,2,2,2,2,2,0},
  {2,2,2,1,2,1,2,1,1,1,2,1,0},
  {2,2,2,1,2,2,2,1,2,1,1,1,2},
  {2,2,2,0,0,0,0,0,2,2,2,2,2},
};
void Map_Start8()
{
      Map8[People_x][People_y]=4;
      Map8[Box8_x][Box8_y]=3;
      Map8[Box8_x1][Box8_y1]=6;
      Map8[Box8_x2][Box8_y2]=9;
}
void Seat_Set8()
{
  if(Map8[Seat8_x][Seat8_y]!=8){
    Map8[Seat8_x][Seat8_y]=5;
  }
  if(Map8[Seat8_x1][Seat8_y1]!=8){
      Map8[Seat8_x1][Seat8_y1]=7;
  }
  if(Map8[Seat8_x2][Seat8_y2]!=8){
    Map8[Seat8_x2][Seat8_y2]=10;
  }
}
void Creat_Seat8()
{
  People_x=1;
  People_y=3;
  Box8_x=3;
  Box8_y=3;
  Box8_x1=3;
  Box8_y1=9;
  Box8_x2=6;
  Box8_y2=5;
  Seat8_x=1;
  Seat8_y=6;
  Seat8_x1=7;
  Seat8_y1=6;
  Seat8_x2=5;
  Seat8_y2=7;
  Map8[Seat8_x][Seat8_y]=5;
  Map8[Seat8_x1][Seat8_y1]=7;
  Map8[Seat8_x2][Seat8_y2]=10;
}
void HideCursor8()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy8(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
int Search_Box8()
{
  if(Box8_x==Seat8_x&&Box8_y==Seat8_y&&Box8_x1==Seat8_x1&&Box8_y1==Seat8_y1&&Box8_x2==Seat8_x2&&Box8_y2==Seat8_y2){
    return 1;
  }
  if(Box8_x==Seat8_x&&Box8_y==Seat8_y&&Box8_x1==Seat8_x2&&Box8_y1==Seat8_y2&&Box8_x2==Seat8_x1&&Box8_y2==Seat8_y1){
    return 1;
  }
  if(Box8_x==Seat8_x1&&Box8_y==Seat8_y1&&Box8_x1==Seat8_x&&Box8_y1==Seat8_y&&Box8_x2==Seat8_x2&&Box8_y2==Seat8_y2){
    return 1;
  }
  if(Box8_x==Seat8_x2&&Box8_y==Seat8_y2&&Box8_x1==Seat8_x1&&Box8_y1==Seat8_y1&&Box8_x2==Seat8_x&&Box8_y2==Seat8_y){
    return 1;
  }
  if(Box8_x==Seat8_x1&&Box8_y==Seat8_y1&&Box8_x1==Seat8_x2&&Box8_y1==Seat8_y2&&Box8_x2==Seat8_x&&Box8_y2==Seat8_y){
    return 1;
  }
  if(Box8_x==Seat8_x2&&Box8_y==Seat8_y2&&Box8_x1==Seat8_x&&Box8_y1==Seat8_y&&Box8_x2==Seat8_x1&&Box8_y2==Seat8_y1){
    return 1;
  }
}
void Creat_Map8()
{
  gotoxy8(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map8[i][j]==0){
        cout<<"■";
      }
      if(Map8[i][j]==1){
        cout<<"■";
      }
      if(Map8[i][j]==2){
        cout<<"  ";
      }
      if(Map8[i][j]==3){
        cout<<"□";
      }
      if(Map8[i][j]==4){
        cout<<"♀";
      }
      if(Map8[i][j]==5){
        cout<<"●";
      }
      if(Map8[i][j]==7){
        cout<<"●";
      }
      if(Map8[i][j]==6){
        cout<<"□";
      }
      if(Map8[i][j]==8){
        cout<<"□";
      }
      if(Map8[i][j]==9){
        cout<<"□";
      }
      if(Map8[i][j]==10){
        cout<<"●";
      }
    }
    cout<<endl;
  }
  cout<<"game eight"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move8()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map8[People_x-1][People_y]==1){
         ;
       }
       else if((Map8[People_x-1][People_y]==Map8[Box8_x][Box8_y]&&Map8[Box8_x-1][Box8_y]==0)||(Map8[People_x-1][People_y]==Map8[Box8_x1][Box8_y1]&&Map8[Box8_x1-1][Box8_y1]==0)
     ||(Map8[People_x-1][People_y]==Map8[Box8_x2][Box8_y2]&&Map8[Box8_x2-1][Box8_y2]==0)){
         ;
       }
       else if((Map8[People_x-1][People_y]==Map8[Box8_x][Box8_y]&&Map8[Box8_x-1][Box8_y]==1)||(Map8[People_x-1][People_y]==Map8[Box8_x1][Box8_y1]&&Map8[Box8_x1-1][Box8_y1]==1)
     ||(Map8[People_x-1][People_y]==Map8[Box8_x2][Box8_y2]&&Map8[Box8_x2-1][Box8_y2]==1)){
         ;
       }
       else if(Map8[People_x-1][People_y]==6&&Map8[Box8_x1-1][Box8_y1]==3){
         ;
       }
       else if(Map8[People_x-1][People_y]==6&&Map8[Box8_x1-1][Box8_y1]==9){
         ;
       }
       else if(Map8[People_x-1][People_y]==3&&Map8[Box8_x-1][Box8_y]==6){
         ;
       }
       else if(Map8[People_x-1][People_y]==3&&Map8[Box8_x-1][Box8_y]==9){
         ;
       }
       else if(Map8[People_x-1][People_y]==9&&Map8[Box8_x2-1][Box8_y2]==3){
         ;
       }
       else if(Map8[People_x-1][People_y]==9&&Map8[Box8_x2-1][Box8_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x-1==Box8_x&&People_y==Box8_y){
           Map8[Seat8_x][Seat8_y]=5;
           People_x--;
           Box8_x--;
         }
        else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x-1==Box8_x1&&People_y==Box8_y1){
           Map8[Seat8_x][Seat8_y]=5;
           People_x--;
           Box8_x1--;
         }
         else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x-1==Box8_x2&&People_y==Box8_y2){
            Map8[Seat8_x][Seat8_y]=5;
            People_x--;
            Box8_x2--;
          }
        else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x-1==Box8_x&&People_y==Box8_y){
           Map8[Seat8_x1][Seat8_y1]=7;
           People_x--;
           Box8_x--;
         }
        else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x-1==Box8_x1&&People_y==Box8_y1){
           Map8[Seat8_x1][Seat8_y1]=7;
           People_x--;
           Box8_x1--;
         }
         else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x-1==Box8_x2&&People_y==Box8_y2){
            Map8[Seat8_x1][Seat8_y1]=7;
            People_x--;
            Box8_x2--;
          }
         else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x-1==Box8_x&&People_y==Box8_y){
            Map8[Seat8_x2][Seat8_y2]=10;
            People_x--;
            Box8_x--;
          }
          else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x-1==Box8_x1&&People_y==Box8_y1){
             Map8[Seat8_x2][Seat8_y2]=10;
             People_x--;
             Box8_x1--;
           }
           else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x-1==Box8_x2&&People_y==Box8_y2){
              Map8[Seat8_x2][Seat8_y2]=10;
              People_x--;
              Box8_x2--;
            }
       //}


       else if((People_x==Seat8_x&&People_y==Seat8_y&&Map8[Seat8_x-1][Seat8_y]!=0)||(People_x==Seat8_x&&People_y==Seat8_y&&Map8[Seat8_x-1][Seat8_y]!=1)){
         People_x--;
         Map8[Seat8_x][Seat8_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat8_x1&&People_y==Seat8_y1&&Map8[Seat8_x1-1][Seat8_y1]!=0)||(People_x==Seat8_x1&&People_y==Seat8_y1&&Map8[Seat8_x1-1][Seat8_y1]!=1)){
         People_x--;
         Map8[Seat8_x1][Seat8_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat8_x2&&People_y==Seat8_y2&&Map8[Seat8_x2-1][Seat8_y2]!=0)||(People_x==Seat8_x2&&People_y==Seat8_y2&&Map8[Seat8_x2-1][Seat8_y2]!=1)){
         People_x--;
         Map8[Seat8_x2][Seat8_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map8[Box8_x-1][Box8_y]==5&&Map8[People_x-2][People_y]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x-1][Box8_y]==7&&Map8[People_x-2][People_y]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x-1][Box8_y]==10&&Map8[People_x-2][People_y]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1-1][Box8_y1]==5&&Map8[People_x-2][People_y]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1-1][Box8_y1]==7&&Map8[People_x-2][People_y]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1-1][Box8_y1]==10&&Map8[People_x-2][People_y]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2-1][Box8_y2]==5&&Map8[People_x-2][People_y]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2-1][Box8_y2]==7&&Map8[People_x-2][People_y]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2-1][Box8_y2]==10&&Map8[People_x-2][People_y]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }

        else if(Map8[People_x-1][People_y]!=6&&Map8[People_x-1][People_y]==3&&Map8[People_x-1][People_y]!=9&&Map8[Box8_x-1][Box8_y]!=0&&Map8[Box8_x-1][Box8_y]!=1){
           People_x--;
           Box8_x--;
           Map8[People_x+1][People_y]=2;
           Map8[Box8_x+1][Box8_y]=2;
         }
        else if(Map8[People_x-1][People_y]==6&Map8[People_x-1][People_y]!=3&&Map8[People_x-1][People_y]!=9&&Map8[Box8_x1-1][Box8_y1]!=0&&Map8[Box8_x1-1][Box8_y1]!=1){
           People_x--;
           Box8_x1--;
           Map8[People_x+1][People_y]=2;
           Map8[Box8_x1+1][Box8_y1]=2;
         }
         else if(Map8[People_x-1][People_y]!=6&Map8[People_x-1][People_y]!=3&&Map8[People_x-1][People_y]==9&&Map8[Box8_x1-1][Box8_y1]!=0&&Map8[Box8_x1-1][Box8_y1]!=1){
            People_x--;
            Box8_x2--;
            Map8[People_x+1][People_y]=2;
            Map8[Box8_x2+1][Box8_y2]=2;
          }
         else{
           People_x--;
           Map8[People_x+1][People_y]=2;
         }
     }
     if(input=='s'){
       if(People_x>7||Map8[People_x+1][People_y]==1){
         ;
       }
       else if((Map8[People_x+1][People_y]==Map8[Box8_x][Box8_y]&&Map8[Box8_x+1][Box8_y]==0)||(Map8[People_x+1][People_y]==Map8[Box8_x1][Box8_y1]&&Map8[Box8_x1+1][Box8_y1]==0)
     ||(Map8[People_x+1][People_y]==Map8[Box8_x2][Box8_y2]&&Map8[Box8_x2+1][Box8_y2]==0)){
         ;
       }
       else if((Map8[People_x+1][People_y]==Map8[Box8_x][Box8_y]&&Map8[Box8_x+1][Box8_y]==1)||(Map8[People_x+1][People_y]==Map8[Box8_x1][Box8_y1]&&Map8[Box8_x1+1][Box8_y1]==1)
     ||(Map8[People_x+1][People_y]==Map8[Box8_x2][Box8_y2]&&Map8[Box8_x2+1][Box8_y2]==1)){
         ;
       }
       else if(Map8[People_x+1][People_y]==6&&Map8[Box8_x1+1][Box8_y1]==3){
         ;
       }
       else if(Map8[People_x+1][People_y]==6&&Map8[Box8_x1+1][Box8_y1]==9){
         ;
       }
       else if(Map8[People_x+1][People_y]==3&&Map8[Box8_x+1][Box8_y]==6){
         ;
       }
       else if(Map8[People_x+1][People_y]==3&&Map8[Box8_x+1][Box8_y]==9){
         ;
       }
       else if(Map8[People_x+1][People_y]==9&&Map8[Box8_x2+1][Box8_y2]==3){
         ;
       }
       else if(Map8[People_x+1][People_y]==9&&Map8[Box8_x2+1][Box8_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){


       else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x+1==Box8_x&&People_y==Box8_y){
          Map8[Seat8_x][Seat8_y]=5;
          People_x++;
          Box8_x++;
        }
       else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x+1==Box8_x1&&People_y==Box8_y1){
          Map8[Seat8_x][Seat8_y]=5;
          People_x++;
          Box8_x1++;
        }
        else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x+1==Box8_x2&&People_y==Box8_y2){
           Map8[Seat8_x][Seat8_y]=5;
           People_x++;
           Box8_x2++;
         }
       else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x+1==Box8_x&&People_y==Box8_y){
          Map8[Seat8_x1][Seat8_y1]=7;
          People_x++;
          Box8_x++;
        }
       else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x+1==Box8_x1&&People_y==Box8_y1){
          Map8[Seat8_x1][Seat8_y1]=7;
          People_x++;
          Box8_x1++;
        }
        else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x+1==Box8_x2&&People_y==Box8_y2){
           Map8[Seat8_x1][Seat8_y1]=7;
           People_x++;
           Box8_x2++;
         }
        else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x+1==Box8_x&&People_y==Box8_y){
           Map8[Seat8_x2][Seat8_y2]=10;
           People_x++;
           Box8_x++;
         }else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x+1==Box8_x1&&People_y==Box8_y1){
            Map8[Seat8_x2][Seat8_y2]=10;
            People_x++;
            Box8_x1++;
          }
          else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x+1==Box8_x2&&People_y==Box8_y2){
             Map8[Seat8_x2][Seat8_y2]=10;
             People_x++;
             Box8_x2++;
           }
      // }


       else if((People_x==Seat8_x&&People_y==Seat8_y&&Map8[Seat8_x+1][Seat8_y]!=0)||(People_x==Seat8_x&&People_y==Seat8_y&&Map8[Seat8_x+1][Seat8_y]!=1)){
         People_x++;
         Map8[Seat8_x][Seat8_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat8_x1&&People_y==Seat8_y1&&Map8[Seat8_x1+1][Seat8_y1]!=0)||(People_x==Seat8_x1&&People_y==Seat8_y1&&Map8[Seat8_x1+1][Seat8_y1]!=1)){
         People_x++;
         Map8[Seat8_x1][Seat8_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat8_x2&&People_y==Seat8_y2&&Map8[Seat8_x2+1][Seat8_y1]!=0)||(People_x==Seat8_x2&&People_y==Seat8_y2&&Map8[Seat8_x2+1][Seat8_y2]!=1)){
         People_x++;
         Map8[Seat8_x2][Seat8_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map8[Box8_x+1][Box8_y]==5&&Map8[People_x+2][People_y]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x+1][Box8_y]==7&&Map8[People_x+2][People_y]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x+1][Box8_y]==10&&Map8[People_x+2][People_y]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1+1][Box8_y1]==5&&Map8[People_x+2][People_y]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1+1][Box8_y1]==7&&Map8[People_x+2][People_y]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1+1][Box8_y1]==10&&Map8[People_x+2][People_y]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2+1][Box8_y2]==5&&Map8[People_x+2][People_y]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2+1][Box8_y2]==7&&Map8[People_x+2][People_y]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2+1][Box8_y2]==10&&Map8[People_x+2][People_y]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }


       else if(Map8[People_x+1][People_y]!=6&&Map8[People_x+1][People_y]==3&&Map8[People_x+1][People_y]!=9&&Map8[Box8_x+1][Box8_y]!=0&&Map8[Box8_x+1][Box8_y]!=1){
          People_x++;
          Box8_x++;
          Map8[People_x-1][People_y]=2;
          Map8[Box8_x-1][Box8_y]=2;
        }
       else if(Map8[People_x+1][People_y]==6&Map8[People_x+1][People_y]!=3&&Map8[People_x+1][People_y]!=9&&Map8[Box8_x1+1][Box8_y1]!=0&&Map8[Box8_x1+1][Box8_y1]!=1){
          People_x++;
          Box8_x1++;
          Map8[People_x-1][People_y]=2;
          Map8[Box8_x1-1][Box8_y1]=2;
        }
        else if(Map8[People_x+1][People_y]!=6&Map8[People_x+1][People_y]!=3&&Map8[People_x+1][People_y]==9&&Map8[Box8_x2+1][Box8_y2]!=0&&Map8[Box8_x2+1][Box8_y2]!=1){
           People_x++;
           Box8_x2++;
           Map8[People_x-1][People_y]=2;
           Map8[Box8_x2-1][Box8_y2]=2;
         }
         else{
           People_x++;
           Map8[People_x-1][People_y]=2;
         }
     }
     if(input=='a'){
       if(People_y<2||Map8[People_x][People_y-1]==1){
         ;
       }
       else if((Map8[People_x][People_y-1]==Map8[Box8_x][Box8_y]&&Map8[Box8_x][Box8_y-1]==0)||
       (Map8[People_x][People_y-1]==Map8[Box8_x1][Box8_y1]&&Map8[Box8_x1][Box8_y1-1]==0)
       ||(Map8[People_x][People_y-1]==Map8[Box8_x2][Box8_y2]&&Map8[Box8_x2][Box8_y2-1]==0)){
         ;
       }
       else if((Map8[People_x][People_y-1]==Map8[Box8_x][Box8_y]&&Map8[Box8_x][Box8_y-1]==1)||
       (Map8[People_x][People_y-1]==Map8[Box8_x1][Box8_y1]&&Map8[Box8_x1][Box8_y1-1]==1)
       ||(Map8[People_x][People_y-1]==Map8[Box8_x2][Box8_y2]&&Map8[Box8_x2][Box8_y2-1]==1)){
         ;
       }
       else if(Map8[People_x][People_y-1]==6&&Map8[Box8_x1][Box8_y1-1]==3){
         ;
       }
       else if(Map8[People_x][People_y-1]==6&&Map8[Box8_x1][Box8_y1-1]==9){
         ;
       }
       else if(Map8[People_x][People_y-1]==3&&Map8[Box8_x][Box8_y-1]==6){
         ;
       }
       else if(Map8[People_x][People_y-1]==3&&Map8[Box8_x][Box8_y-1]==9){
         ;
       }
       else if(Map8[People_x][People_y-1]==9&&Map8[Box8_x2][Box8_y2-1]==3){
         ;
       }
       else if(Map8[People_x][People_y-1]==9&&Map8[Box8_x2][Box8_y2-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x==Box8_x&&People_y-1==Box8_y){
           Map8[Seat8_x][Seat8_y]=5;
           People_y--;
           Box8_y--;
         }
        else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x==Box8_x1&&People_y-1==Box8_y1){
           Map8[Seat8_x][Seat8_y]=5;
           People_y--;
           Box8_y1--;
         }
         else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x==Box8_x2&&People_y-1==Box8_y2){
            Map8[Seat8_x][Seat8_y]=5;
            People_y--;
            Box8_y2--;
          }
        else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x==Box8_x&&People_y-1==Box8_y){
           Map8[Seat8_x1][Seat8_y1]=7;
           People_y--;
           Box8_y--;
         }
        else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x==Box8_x1&&People_y-1==Box8_y1){
           Map8[Seat8_x1][Seat8_y1]=7;
           People_y--;
           Box8_y1--;
         }
         else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x==Box8_x2&&People_y-1==Box8_y2){
            Map8[Seat8_x1][Seat8_y1]=7;
            People_y--;
            Box8_y2--;
          }
         else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x==Box8_x&&People_y-1==Box8_y){
            Map8[Seat8_x2][Seat8_y2]=10;
            People_y--;
            Box8_y--;
          }else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x==Box8_x1&&People_y-1==Box8_y1){
             Map8[Seat8_x2][Seat8_y2]=10;
             People_y--;
             Box8_y1--;
           }
           else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x==Box8_x2&&People_y-1==Box8_y2){
              Map8[Seat8_x2][Seat8_y2]=10;
              People_y--;
              Box8_y2--;
            }
       //}


       else if((People_x==Seat8_x&&People_y==Seat8_y&&Map8[Seat8_x][Seat8_y-1]!=0)||(People_x==Seat8_x&&People_y==Seat8_y&&Map8[Seat8_x][Seat8_y-1]!=1)){
         People_y--;
         Map8[Seat8_x][Seat8_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat8_x1&&People_y==Seat8_y1&&Map8[Seat8_x1][Seat8_y1-1]!=0)||(People_x==Seat8_x1&&People_y==Seat8_y1&&Map8[Seat8_x1][Seat8_y1-1]!=1)){
         People_y--;
         Map8[Seat8_x1][Seat8_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat8_x2&&People_y==Seat8_y2&&Map8[Seat8_x2][Seat8_y2-1]!=0)||(People_x==Seat8_x2&&People_y==Seat8_y2&&Map8[Seat8_x2][Seat8_y2-1]!=1)){
         People_y--;
         Map8[Seat8_x2][Seat8_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map8[Box8_x][Box8_y-1]==5&&Map8[People_x][People_y-2]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1][Box8_y1-1]==5&&Map8[People_x][People_y-2]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2][Box8_y2-1]==5&&Map8[People_x][People_y-2]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x][Box8_y-1]==7&&Map8[People_x][People_y-2]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1][Box8_y1-1]==7&&Map8[People_x][People_y-2]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2][Box8_y2-1]==7&&Map8[People_x][People_y-2]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1][Box8_y1-1]==10&&Map8[People_x][People_y-2]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x][Box8_y-1]==10&&Map8[People_x][People_y-2]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2][Box8_y2-1]==10&&Map8[People_x][People_y-2]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }

        else if(Map8[People_x][People_y-1]!=6&&Map8[People_x][People_y-1]==3&&Map8[People_x][People_y-1]!=9&&Map8[Box8_x][Box8_y-1]!=0&&Map8[Box8_x][Box8_y-1]!=1){
           People_y--;
           Box8_y--;
           Map8[People_x][People_y+1]=2;
           Map8[Box8_x][Box8_y+1]=2;
         }
        else if(Map8[People_x][People_y-1]==6&Map8[People_x][People_y-1]!=3&&Map8[People_x][People_y-1]!=9&&Map8[Box8_x1][Box8_y1-1]!=0&&Map8[Box8_x1][Box8_y1-1]!=1){
           People_y--;
           Box8_y1--;
           Map8[People_x][People_y+1]=2;
           Map8[Box8_x1][Box8_y1+1]=2;
         }
         else if(Map8[People_x][People_y-1]!=6&Map8[People_x][People_y-1]!=3&&Map8[People_x][People_y-1]==9&&Map8[Box8_x2][Box8_y2-1]!=0&&Map8[Box8_x2][Box8_y2-1]!=1){
            People_y--;
            Box8_y2--;
            Map8[People_x][People_y+1]=2;
            Map8[Box8_x2][Box8_y2+1]=2;
          }
         else{
           People_y--;
           Map8[People_x][People_y+1]=2;
         }
     }
     if(input=='d'){
       if(People_y>10||Map8[People_x][People_y+1]==1){
         ;
       }
       else if((Map8[People_x][People_y+1]==Map8[Box8_x][Box8_y]&&Map8[Box8_x][Box8_y+1]==0)
       ||(Map8[People_x][People_y+1]==Map8[Box8_x1][Box8_y1]&&Map8[Box8_x1][Box8_y1+1]==0)
       ||(Map8[People_x][People_y+1]==Map8[Box8_x2][Box8_y2]&&Map8[Box8_x2][Box8_y2+1]==0)){
         ;
       }
       else if((Map8[People_x][People_y+1]==Map8[Box8_x][Box8_y]&&Map8[Box8_x][Box8_y+1]==1)
       ||(Map8[People_x][People_y+1]==Map8[Box8_x1][Box8_y1]&&Map8[Box8_x1][Box8_y1+1]==1)
       ||(Map8[People_x][People_y+1]==Map8[Box8_x2][Box8_y2]&&Map8[Box8_x2][Box8_y2+1]==1)){
         ;
       }
       else if(Map8[People_x][People_y+1]==6&&Map8[Box8_x1][Box8_y1+1]==3){
         ;
       }
       else if(Map8[People_x][People_y+1]==6&&Map8[Box8_x1][Box8_y1+1]==9){
         ;
       }
       else if(Map8[People_x][People_y+1]==3&&Map8[Box8_x][Box8_y+1]==6){
         ;
       }
       else if(Map8[People_x][People_y+1]==3&&Map8[Box8_x][Box8_y+1]==9){
         ;
       }
       else if(Map8[People_x][People_y+1]==9&&Map8[Box8_x2][Box8_y2+1]==3){
         ;
       }
       else if(Map8[People_x][People_y+1]==9&&Map8[Box8_x2][Box8_y2+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x==Box8_x&&People_y+1==Box8_y){
           Map8[Seat8_x][Seat8_y]=5;
           People_y++;
           Box8_y++;
         }
        else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x==Box8_x1&&People_y+1==Box8_y1){
           Map8[Seat8_x][Seat8_y]=5;
           People_y++;
           Box8_y1++;
         }
         else if(People_x==Seat8_x&&People_y==Seat8_y&&People_x==Box8_x2&&People_y+1==Box8_y2){
            Map8[Seat8_x][Seat8_y]=5;
            People_y++;
            Box8_y2++;
          }
        else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x==Box8_x&&People_y+1==Box8_y){
           Map8[Seat8_x1][Seat8_y1]=7;
           People_y++;
           Box8_y++;
         }
        else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x==Box8_x1&&People_y+1==Box8_y1){
           Map8[Seat8_x1][Seat8_y1]=7;
           People_y++;
           Box8_y1++;
         }
         else if(People_x==Seat8_x1&&People_y==Seat8_y1&&People_x==Box8_x2&&People_y+1==Box8_y2){
            Map8[Seat8_x1][Seat8_y1]=7;
            People_y++;
            Box8_y2++;
          }
         else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x==Box8_x&&People_y+1==Box8_y){
            Map8[Seat8_x2][Seat8_y2]=10;
            People_y++;
            Box8_y++;
          }else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x==Box8_x1&&People_y+1==Box8_y1){
             Map8[Seat8_x2][Seat8_y2]=10;
             People_y++;
             Box8_y1++;
           }
           else if(People_x==Seat8_x2&&People_y==Seat8_y2&&People_x==Box8_x2&&People_y+1==Box8_y2){
              Map8[Seat8_x2][Seat8_y2]=10;
              People_y++;
              Box8_y2++;
            }
       //}


       else if((People_x==Seat8_x&&People_y==Seat8_y&&Map8[Seat8_x][Seat8_y+1]!=0)||(People_x==Seat8_x&&People_y==Seat8_y&&Map8[Seat8_x][Seat8_y+1]!=1)){
         People_y++;
         Map8[Seat8_x][Seat8_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat8_x1&&People_y==Seat8_y1&&Map8[Seat8_x1][Seat8_y1+1]!=0)||(People_x==Seat8_x1&&People_y==Seat8_y1&&Map8[Seat8_x1][Seat8_y1+1]!=1)){
         People_y++;
         Map8[Seat8_x1][Seat8_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat8_x2&&People_y==Seat8_y2&&Map8[Seat8_x2][Seat8_y2+1]!=0)||(People_x==Seat8_x2&&People_y==Seat8_y2&&Map8[Seat8_x2][Seat8_y2+1]!=1)){
         People_y++;
         Map8[Seat8_x2][Seat8_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map8[Box8_x][Box8_y+1]==5&&Map8[People_x][People_y+2]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x][Box8_y+1]==7&&Map8[People_x][People_y+2]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x][Box8_y+1]==10&&Map8[People_x][People_y+2]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x][Box8_y]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1][Box8_y1+1]==5&&Map8[People_x][People_y+2]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1][Box8_y1+1]==7&&Map8[People_x][People_y+2]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x1][Box8_y1+1]==10&&Map8[People_x][People_y+2]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x1][Box8_y1]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2][Box8_y2+1]==5&&Map8[People_x][People_y+2]==5){
         Map8[Seat8_x][Seat8_y]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2][Box8_y2+1]==7&&Map8[People_x][People_y+2]==7){
         Map8[Seat8_x1][Seat8_y1]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }
       else if(Map8[Box8_x2][Box8_y2+1]==10&&Map8[People_x][People_y+2]==10){
         Map8[Seat8_x2][Seat8_y2]=8;
         Map8[Box8_x2][Box8_y2]=4;
         Map8[People_x][People_y]=2;
       }

        else if(Map8[People_x][People_y+1]!=6&&Map8[People_x][People_y+1]==3&&Map8[People_x][People_y+1]!=9&&Map8[Box8_x][Box8_y+1]!=0&&Map8[Box8_x][Box8_y+1]!=1){
           People_y++;
           Box8_y++;
           Map8[People_x][People_y-1]=2;
           Map8[Box8_x][Box8_y-1]=2;
         }
        else if(Map8[People_x][People_y+1]==6&Map8[People_x][People_y+1]!=3&&Map8[People_x][People_y+1]!=9&&Map8[Box8_x1][Box8_y1+1]!=0&&Map8[Box8_x1][Box8_y1+1]!=1){
           People_y++;
           Box8_y1++;
           Map8[People_x][People_y-1]=2;
           Map8[Box8_x1][Box8_y1-1]=2;
         }
         else if(Map8[People_x][People_y+1]!=6&Map8[People_x][People_y+1]!=3&&Map8[People_x][People_y+1]==9&&Map8[Box8_x2][Box8_y2+1]!=0&&Map8[Box8_x2][Box8_y2+1]!=1){
            People_y++;
            Box8_y2++;
            Map8[People_x][People_y-1]=2;
            Map8[Box8_x2][Box8_y2-1]=2;
          }
         else{
           People_y++;
           Map8[People_x][People_y-1]=2;
         }
     }
   }
}


//game9
int Box9_x,Box9_y;
int Box9_x1,Box9_y1;
int Box9_x2,Box9_y2;
int Seat9_x,Seat9_y;
int Seat9_x1,Seat9_y1;
int Seat9_x2,Seat9_y2;
int Map9[MAPMAX][MAPMAX+3] = {
  {2,2,0,0,0,0,0,0,0,0,0,0,2},
  {2,1,1,2,2,2,2,2,2,2,2,1,2},
  {0,1,2,2,2,1,1,1,1,2,2,1,2},
  {0,2,2,2,2,1,2,2,1,2,2,1,0},
  {0,1,1,1,2,1,1,1,1,2,2,2,0},
  {0,2,2,2,2,1,2,2,2,2,2,1,0},
  {0,1,1,1,2,2,2,2,2,2,2,2,0},
  {2,2,2,1,2,1,2,1,1,1,2,1,0},
  {2,2,2,1,2,2,2,1,2,1,1,1,2},
  {2,2,2,0,0,0,0,0,2,2,2,2,2},
};
void Map_Start9()
{
      Map9[People_x][People_y]=4;
      Map9[Box9_x][Box9_y]=3;
      Map9[Box9_x1][Box9_y1]=6;
      Map9[Box9_x2][Box9_y2]=9;
}
void Seat_Set9()
{
  if(Map9[Seat9_x][Seat9_y]!=8){
    Map9[Seat9_x][Seat9_y]=5;
  }
  if(Map9[Seat9_x1][Seat9_y1]!=8){
      Map9[Seat9_x1][Seat9_y1]=7;
  }
  if(Map9[Seat9_x2][Seat9_y2]!=8){
    Map9[Seat9_x2][Seat9_y2]=10;
  }
}
void Creat_Seat9()
{
  People_x=1;
  People_y=3;
  Box9_x=3;
  Box9_y=3;
  Box9_x1=3;
  Box9_y1=9;
  Box9_x2=6;
  Box9_y2=5;
  Seat9_x=1;
  Seat9_y=6;
  Seat9_x1=7;
  Seat9_y1=6;
  Seat9_x2=5;
  Seat9_y2=7;
  Map9[Seat9_x][Seat9_y]=5;
  Map9[Seat9_x1][Seat9_y1]=7;
  Map9[Seat9_x2][Seat9_y2]=10;
}
void HideCursor9()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy9(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
int Search_Box9()
{
  if(Box9_x==Seat9_x&&Box9_y==Seat9_y&&Box9_x1==Seat9_x1&&Box9_y1==Seat9_y1&&Box9_x2==Seat9_x2&&Box9_y2==Seat9_y2){
    return 1;
  }
  if(Box9_x==Seat9_x&&Box9_y==Seat9_y&&Box9_x1==Seat9_x2&&Box9_y1==Seat9_y2&&Box9_x2==Seat9_x1&&Box9_y2==Seat9_y1){
    return 1;
  }
  if(Box9_x==Seat9_x1&&Box9_y==Seat9_y1&&Box9_x1==Seat9_x&&Box9_y1==Seat9_y&&Box9_x2==Seat9_x2&&Box9_y2==Seat9_y2){
    return 1;
  }
  if(Box9_x==Seat9_x2&&Box9_y==Seat9_y2&&Box9_x1==Seat9_x1&&Box9_y1==Seat9_y1&&Box9_x2==Seat9_x&&Box9_y2==Seat9_y){
    return 1;
  }
  if(Box9_x==Seat9_x1&&Box9_y==Seat9_y1&&Box9_x1==Seat9_x2&&Box9_y1==Seat9_y2&&Box9_x2==Seat9_x&&Box9_y2==Seat9_y){
    return 1;
  }
  if(Box9_x==Seat9_x2&&Box9_y==Seat9_y2&&Box9_x1==Seat9_x&&Box9_y1==Seat9_y&&Box9_x2==Seat9_x1&&Box9_y2==Seat9_y1){
    return 1;
  }
}
void Creat_Map9()
{
  gotoxy9(0, 0);
  for(int i = 0;i<MAPMAX ;i++){
    for(int j = 0;j<MAPMAX+3 ;j++){
      if(Map9[i][j]==0){
        cout<<"■";
      }
      if(Map9[i][j]==1){
        cout<<"■";
      }
      if(Map9[i][j]==2){
        cout<<"  ";
      }
      if(Map9[i][j]==3){
        cout<<"□";
      }
      if(Map9[i][j]==4){
        cout<<"♀";
      }
      if(Map9[i][j]==5){
        cout<<"●";
      }
      if(Map9[i][j]==7){
        cout<<"●";
      }
      if(Map9[i][j]==6){
        cout<<"□";
      }
      if(Map9[i][j]==8){
        cout<<"□";
      }
      if(Map9[i][j]==9){
        cout<<"□";
      }
      if(Map9[i][j]==10){
        cout<<"●";
      }
    }
    cout<<endl;
  }
  cout<<"game nine"<<endl;
  cout<<"W A S D控制上 左 下 右"<<endl;
  cout<<"将箱子推到白点处即游戏成功"<<endl;
}
void People_Move9()
{
  char input;
   if (kbhit()){
     input = getch();
     if(input=='w'){
       if(People_x<2||Map9[People_x-1][People_y]==1){
         ;
       }
       else if((Map9[People_x-1][People_y]==Map9[Box9_x][Box9_y]&&Map9[Box9_x-1][Box9_y]==0)||(Map9[People_x-1][People_y]==Map9[Box9_x1][Box9_y1]&&Map9[Box9_x1-1][Box9_y1]==0)
     ||(Map9[People_x-1][People_y]==Map9[Box9_x2][Box9_y2]&&Map9[Box9_x2-1][Box9_y2]==0)){
         ;
       }
       else if((Map9[People_x-1][People_y]==Map9[Box9_x][Box9_y]&&Map9[Box9_x-1][Box9_y]==1)||(Map9[People_x-1][People_y]==Map9[Box9_x1][Box9_y1]&&Map9[Box9_x1-1][Box9_y1]==1)
     ||(Map9[People_x-1][People_y]==Map9[Box9_x2][Box9_y2]&&Map9[Box9_x2-1][Box9_y2]==1)){
         ;
       }
       else if(Map9[People_x-1][People_y]==6&&Map9[Box9_x1-1][Box9_y1]==3){
         ;
       }
       else if(Map9[People_x-1][People_y]==6&&Map9[Box9_x1-1][Box9_y1]==9){
         ;
       }
       else if(Map9[People_x-1][People_y]==3&&Map9[Box9_x-1][Box9_y]==6){
         ;
       }
       else if(Map9[People_x-1][People_y]==3&&Map9[Box9_x-1][Box9_y]==9){
         ;
       }
       else if(Map9[People_x-1][People_y]==9&&Map9[Box9_x2-1][Box9_y2]==3){
         ;
       }
       else if(Map9[People_x-1][People_y]==9&&Map9[Box9_x2-1][Box9_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x-1==Box9_x&&People_y==Box9_y){
           Map9[Seat9_x][Seat9_y]=5;
           People_x--;
           Box9_x--;
         }
        else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x-1==Box9_x1&&People_y==Box9_y1){
           Map9[Seat9_x][Seat9_y]=5;
           People_x--;
           Box9_x1--;
         }
         else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x-1==Box9_x2&&People_y==Box9_y2){
            Map9[Seat9_x][Seat9_y]=5;
            People_x--;
            Box9_x2--;
          }
        else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x-1==Box9_x&&People_y==Box9_y){
           Map9[Seat9_x1][Seat9_y1]=7;
           People_x--;
           Box9_x--;
         }
        else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x-1==Box9_x1&&People_y==Box9_y1){
           Map9[Seat9_x1][Seat9_y1]=7;
           People_x--;
           Box9_x1--;
         }
         else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x-1==Box9_x2&&People_y==Box9_y2){
            Map9[Seat9_x1][Seat9_y1]=7;
            People_x--;
            Box9_x2--;
          }
         else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x-1==Box9_x&&People_y==Box9_y){
            Map9[Seat9_x2][Seat9_y2]=10;
            People_x--;
            Box9_x--;
          }
          else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x-1==Box9_x1&&People_y==Box9_y1){
             Map9[Seat9_x2][Seat9_y2]=10;
             People_x--;
             Box9_x1--;
           }
           else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x-1==Box9_x2&&People_y==Box9_y2){
              Map9[Seat9_x2][Seat9_y2]=10;
              People_x--;
              Box9_x2--;
            }
       //}


       else if((People_x==Seat9_x&&People_y==Seat9_y&&Map9[Seat9_x-1][Seat9_y]!=0)||(People_x==Seat9_x&&People_y==Seat9_y&&Map9[Seat9_x-1][Seat9_y]!=1)){
         People_x--;
         Map9[Seat9_x][Seat9_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat9_x1&&People_y==Seat9_y1&&Map9[Seat9_x1-1][Seat9_y1]!=0)||(People_x==Seat9_x1&&People_y==Seat9_y1&&Map9[Seat9_x1-1][Seat9_y1]!=1)){
         People_x--;
         Map9[Seat9_x1][Seat9_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat9_x2&&People_y==Seat9_y2&&Map9[Seat9_x2-1][Seat9_y2]!=0)||(People_x==Seat9_x2&&People_y==Seat9_y2&&Map9[Seat9_x2-1][Seat9_y2]!=1)){
         People_x--;
         Map9[Seat9_x2][Seat9_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map9[Box9_x-1][Box9_y]==5&&Map9[People_x-2][People_y]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x-1][Box9_y]==7&&Map9[People_x-2][People_y]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x-1][Box9_y]==10&&Map9[People_x-2][People_y]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1-1][Box9_y1]==5&&Map9[People_x-2][People_y]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1-1][Box9_y1]==7&&Map9[People_x-2][People_y]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1-1][Box9_y1]==10&&Map9[People_x-2][People_y]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2-1][Box9_y2]==5&&Map9[People_x-2][People_y]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2-1][Box9_y2]==7&&Map9[People_x-2][People_y]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2-1][Box9_y2]==10&&Map9[People_x-2][People_y]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }

        else if(Map9[People_x-1][People_y]!=6&&Map9[People_x-1][People_y]==3&&Map9[People_x-1][People_y]!=9&&Map9[Box9_x-1][Box9_y]!=0&&Map9[Box9_x-1][Box9_y]!=1){
           People_x--;
           Box9_x--;
           Map9[People_x+1][People_y]=2;
           Map9[Box9_x+1][Box9_y]=2;
         }
        else if(Map9[People_x-1][People_y]==6&Map9[People_x-1][People_y]!=3&&Map9[People_x-1][People_y]!=9&&Map9[Box9_x1-1][Box9_y1]!=0&&Map9[Box9_x1-1][Box9_y1]!=1){
           People_x--;
           Box9_x1--;
           Map9[People_x+1][People_y]=2;
           Map9[Box9_x1+1][Box9_y1]=2;
         }
         else if(Map9[People_x-1][People_y]!=6&Map9[People_x-1][People_y]!=3&&Map9[People_x-1][People_y]==9&&Map9[Box9_x1-1][Box9_y1]!=0&&Map9[Box9_x1-1][Box9_y1]!=1){
            People_x--;
            Box9_x2--;
            Map9[People_x+1][People_y]=2;
            Map9[Box9_x2+1][Box9_y2]=2;
          }
         else{
           People_x--;
           Map9[People_x+1][People_y]=2;
         }
     }
     if(input=='s'){
       if(People_x>7||Map9[People_x+1][People_y]==1){
         ;
       }
       else if((Map9[People_x+1][People_y]==Map9[Box9_x][Box9_y]&&Map9[Box9_x+1][Box9_y]==0)||(Map9[People_x+1][People_y]==Map9[Box9_x1][Box9_y1]&&Map9[Box9_x1+1][Box9_y1]==0)
     ||(Map9[People_x+1][People_y]==Map9[Box9_x2][Box9_y2]&&Map9[Box9_x2+1][Box9_y2]==0)){
         ;
       }
       else if((Map9[People_x+1][People_y]==Map9[Box9_x][Box9_y]&&Map9[Box9_x+1][Box9_y]==1)||(Map9[People_x+1][People_y]==Map9[Box9_x1][Box9_y1]&&Map9[Box9_x1+1][Box9_y1]==1)
     ||(Map9[People_x+1][People_y]==Map9[Box9_x2][Box9_y2]&&Map9[Box9_x2+1][Box9_y2]==1)){
         ;
       }
       else if(Map9[People_x+1][People_y]==6&&Map9[Box9_x1+1][Box9_y1]==3){
         ;
       }
       else if(Map9[People_x+1][People_y]==6&&Map9[Box9_x1+1][Box9_y1]==9){
         ;
       }
       else if(Map9[People_x+1][People_y]==3&&Map9[Box9_x+1][Box9_y]==6){
         ;
       }
       else if(Map9[People_x+1][People_y]==3&&Map9[Box9_x+1][Box9_y]==9){
         ;
       }
       else if(Map9[People_x+1][People_y]==9&&Map9[Box9_x2+1][Box9_y2]==3){
         ;
       }
       else if(Map9[People_x+1][People_y]==9&&Map9[Box9_x2+1][Box9_y2]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x+2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x+2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x+2!=0)){


       else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x+1==Box9_x&&People_y==Box9_y){
          Map9[Seat9_x][Seat9_y]=5;
          People_x++;
          Box9_x++;
        }
       else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x+1==Box9_x1&&People_y==Box9_y1){
          Map9[Seat9_x][Seat9_y]=5;
          People_x++;
          Box9_x1++;
        }
        else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x+1==Box9_x2&&People_y==Box9_y2){
           Map9[Seat9_x][Seat9_y]=5;
           People_x++;
           Box9_x2++;
         }
       else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x+1==Box9_x&&People_y==Box9_y){
          Map9[Seat9_x1][Seat9_y1]=7;
          People_x++;
          Box9_x++;
        }
       else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x+1==Box9_x1&&People_y==Box9_y1){
          Map9[Seat9_x1][Seat9_y1]=7;
          People_x++;
          Box9_x1++;
        }
        else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x+1==Box9_x2&&People_y==Box9_y2){
           Map9[Seat9_x1][Seat9_y1]=7;
           People_x++;
           Box9_x2++;
         }
        else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x+1==Box9_x&&People_y==Box9_y){
           Map9[Seat9_x2][Seat9_y2]=10;
           People_x++;
           Box9_x++;
         }else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x+1==Box9_x1&&People_y==Box9_y1){
            Map9[Seat9_x2][Seat9_y2]=10;
            People_x++;
            Box9_x1++;
          }
          else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x+1==Box9_x2&&People_y==Box9_y2){
             Map9[Seat9_x2][Seat9_y2]=10;
             People_x++;
             Box9_x2++;
           }
      // }


       else if((People_x==Seat9_x&&People_y==Seat9_y&&Map9[Seat9_x+1][Seat9_y]!=0)||(People_x==Seat9_x&&People_y==Seat9_y&&Map9[Seat9_x+1][Seat9_y]!=1)){
         People_x++;
         Map9[Seat9_x][Seat9_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat9_x1&&People_y==Seat9_y1&&Map9[Seat9_x1+1][Seat9_y1]!=0)||(People_x==Seat9_x1&&People_y==Seat9_y1&&Map9[Seat9_x1+1][Seat9_y1]!=1)){
         People_x++;
         Map9[Seat9_x1][Seat9_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat9_x2&&People_y==Seat9_y2&&Map9[Seat9_x2+1][Seat9_y1]!=0)||(People_x==Seat9_x2&&People_y==Seat9_y2&&Map9[Seat9_x2+1][Seat9_y2]!=1)){
         People_x++;
         Map9[Seat9_x2][Seat9_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map9[Box9_x+1][Box9_y]==5&&Map9[People_x+2][People_y]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x+1][Box9_y]==7&&Map9[People_x+2][People_y]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x+1][Box9_y]==10&&Map9[People_x+2][People_y]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1+1][Box9_y1]==5&&Map9[People_x+2][People_y]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1+1][Box9_y1]==7&&Map9[People_x+2][People_y]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1+1][Box9_y1]==10&&Map9[People_x+2][People_y]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2+1][Box9_y2]==5&&Map9[People_x+2][People_y]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2+1][Box9_y2]==7&&Map9[People_x+2][People_y]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2+1][Box9_y2]==10&&Map9[People_x+2][People_y]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }


       else if(Map9[People_x+1][People_y]!=6&&Map9[People_x+1][People_y]==3&&Map9[People_x+1][People_y]!=9&&Map9[Box9_x+1][Box9_y]!=0&&Map9[Box9_x+1][Box9_y]!=1){
          People_x++;
          Box9_x++;
          Map9[People_x-1][People_y]=2;
          Map9[Box9_x-1][Box9_y]=2;
        }
       else if(Map9[People_x+1][People_y]==6&Map9[People_x+1][People_y]!=3&&Map9[People_x+1][People_y]!=9&&Map9[Box9_x1+1][Box9_y1]!=0&&Map9[Box9_x1+1][Box9_y1]!=1){
          People_x++;
          Box9_x1++;
          Map9[People_x-1][People_y]=2;
          Map9[Box9_x1-1][Box9_y1]=2;
        }
        else if(Map9[People_x+1][People_y]!=6&Map9[People_x+1][People_y]!=3&&Map9[People_x+1][People_y]==9&&Map9[Box9_x2+1][Box9_y2]!=0&&Map9[Box9_x2+1][Box9_y2]!=1){
           People_x++;
           Box9_x2++;
           Map9[People_x-1][People_y]=2;
           Map9[Box9_x2-1][Box9_y2]=2;
         }
         else{
           People_x++;
           Map9[People_x-1][People_y]=2;
         }
     }
     if(input=='a'){
       if(People_y<2||Map9[People_x][People_y-1]==1){
         ;
       }
       else if((Map9[People_x][People_y-1]==Map9[Box9_x][Box9_y]&&Map9[Box9_x][Box9_y-1]==0)||
       (Map9[People_x][People_y-1]==Map9[Box9_x1][Box9_y1]&&Map9[Box9_x1][Box9_y1-1]==0)
       ||(Map9[People_x][People_y-1]==Map9[Box9_x2][Box9_y2]&&Map9[Box9_x2][Box9_y2-1]==0)){
         ;
       }
       else if((Map9[People_x][People_y-1]==Map9[Box9_x][Box9_y]&&Map9[Box9_x][Box9_y-1]==1)||
       (Map9[People_x][People_y-1]==Map9[Box9_x1][Box9_y1]&&Map9[Box9_x1][Box9_y1-1]==1)
       ||(Map9[People_x][People_y-1]==Map9[Box9_x2][Box9_y2]&&Map9[Box9_x2][Box9_y2-1]==1)){
         ;
       }
       else if(Map9[People_x][People_y-1]==6&&Map9[Box9_x1][Box9_y1-1]==3){
         ;
       }
       else if(Map9[People_x][People_y-1]==6&&Map9[Box9_x1][Box9_y1-1]==9){
         ;
       }
       else if(Map9[People_x][People_y-1]==3&&Map9[Box9_x][Box9_y-1]==6){
         ;
       }
       else if(Map9[People_x][People_y-1]==3&&Map9[Box9_x][Box9_y-1]==9){
         ;
       }
       else if(Map9[People_x][People_y-1]==9&&Map9[Box9_x2][Box9_y2-1]==3){
         ;
       }
       else if(Map9[People_x][People_y-1]==9&&Map9[Box9_x2][Box9_y2-1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x==Box9_x&&People_y-1==Box9_y){
           Map9[Seat9_x][Seat9_y]=5;
           People_y--;
           Box9_y--;
         }
        else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x==Box9_x1&&People_y-1==Box9_y1){
           Map9[Seat9_x][Seat9_y]=5;
           People_y--;
           Box9_y1--;
         }
         else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x==Box9_x2&&People_y-1==Box9_y2){
            Map9[Seat9_x][Seat9_y]=5;
            People_y--;
            Box9_y2--;
          }
        else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x==Box9_x&&People_y-1==Box9_y){
           Map9[Seat9_x1][Seat9_y1]=7;
           People_y--;
           Box9_y--;
         }
        else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x==Box9_x1&&People_y-1==Box9_y1){
           Map9[Seat9_x1][Seat9_y1]=7;
           People_y--;
           Box9_y1--;
         }
         else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x==Box9_x2&&People_y-1==Box9_y2){
            Map9[Seat9_x1][Seat9_y1]=7;
            People_y--;
            Box9_y2--;
          }
         else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x==Box9_x&&People_y-1==Box9_y){
            Map9[Seat9_x2][Seat9_y2]=10;
            People_y--;
            Box9_y--;
          }else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x==Box9_x1&&People_y-1==Box9_y1){
             Map9[Seat9_x2][Seat9_y2]=10;
             People_y--;
             Box9_y1--;
           }
           else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x==Box9_x2&&People_y-1==Box9_y2){
              Map9[Seat9_x2][Seat9_y2]=10;
              People_y--;
              Box9_y2--;
            }
       //}


       else if((People_x==Seat9_x&&People_y==Seat9_y&&Map9[Seat9_x][Seat9_y-1]!=0)||(People_x==Seat9_x&&People_y==Seat9_y&&Map9[Seat9_x][Seat9_y-1]!=1)){
         People_y--;
         Map9[Seat9_x][Seat9_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat9_x1&&People_y==Seat9_y1&&Map9[Seat9_x1][Seat9_y1-1]!=0)||(People_x==Seat9_x1&&People_y==Seat9_y1&&Map9[Seat9_x1][Seat9_y1-1]!=1)){
         People_y--;
         Map9[Seat9_x1][Seat9_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat9_x2&&People_y==Seat9_y2&&Map9[Seat9_x2][Seat9_y2-1]!=0)||(People_x==Seat9_x2&&People_y==Seat9_y2&&Map9[Seat9_x2][Seat9_y2-1]!=1)){
         People_y--;
         Map9[Seat9_x2][Seat9_y2]=10;
         //Map[People_x][People_y]=2;
       }


       else if(Map9[Box9_x][Box9_y-1]==5&&Map9[People_x][People_y-2]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1][Box9_y1-1]==5&&Map9[People_x][People_y-2]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2][Box9_y2-1]==5&&Map9[People_x][People_y-2]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x][Box9_y-1]==7&&Map9[People_x][People_y-2]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1][Box9_y1-1]==7&&Map9[People_x][People_y-2]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2][Box9_y2-1]==7&&Map9[People_x][People_y-2]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1][Box9_y1-1]==10&&Map9[People_x][People_y-2]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x][Box9_y-1]==10&&Map9[People_x][People_y-2]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2][Box9_y2-1]==10&&Map9[People_x][People_y-2]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }

        else if(Map9[People_x][People_y-1]!=6&&Map9[People_x][People_y-1]==3&&Map9[People_x][People_y-1]!=9&&Map9[Box9_x][Box9_y-1]!=0&&Map9[Box9_x][Box9_y-1]!=1){
           People_y--;
           Box9_y--;
           Map9[People_x][People_y+1]=2;
           Map9[Box9_x][Box9_y+1]=2;
         }
        else if(Map9[People_x][People_y-1]==6&Map9[People_x][People_y-1]!=3&&Map9[People_x][People_y-1]!=9&&Map9[Box9_x1][Box9_y1-1]!=0&&Map9[Box9_x1][Box9_y1-1]!=1){
           People_y--;
           Box9_y1--;
           Map9[People_x][People_y+1]=2;
           Map9[Box9_x1][Box9_y1+1]=2;
         }
         else if(Map9[People_x][People_y-1]!=6&Map9[People_x][People_y-1]!=3&&Map9[People_x][People_y-1]==9&&Map9[Box9_x2][Box9_y2-1]!=0&&Map9[Box9_x2][Box9_y2-1]!=1){
            People_y--;
            Box9_y2--;
            Map9[People_x][People_y+1]=2;
            Map9[Box9_x2][Box9_y2+1]=2;
          }
         else{
           People_y--;
           Map9[People_x][People_y+1]=2;
         }
     }
     if(input=='d'){
       if(People_y>10||Map9[People_x][People_y+1]==1){
         ;
       }
       else if((Map9[People_x][People_y+1]==Map9[Box9_x][Box9_y]&&Map9[Box9_x][Box9_y+1]==0)
       ||(Map9[People_x][People_y+1]==Map9[Box9_x1][Box9_y1]&&Map9[Box9_x1][Box9_y1+1]==0)
       ||(Map9[People_x][People_y+1]==Map9[Box9_x2][Box9_y2]&&Map9[Box9_x2][Box9_y2+1]==0)){
         ;
       }
       else if((Map9[People_x][People_y+1]==Map9[Box9_x][Box9_y]&&Map9[Box9_x][Box9_y+1]==1)
       ||(Map9[People_x][People_y+1]==Map9[Box9_x1][Box9_y1]&&Map9[Box9_x1][Box9_y1+1]==1)
       ||(Map9[People_x][People_y+1]==Map9[Box9_x2][Box9_y2]&&Map9[Box9_x2][Box9_y2+1]==1)){
         ;
       }
       else if(Map9[People_x][People_y+1]==6&&Map9[Box9_x1][Box9_y1+1]==3){
         ;
       }
       else if(Map9[People_x][People_y+1]==6&&Map9[Box9_x1][Box9_y1+1]==9){
         ;
       }
       else if(Map9[People_x][People_y+1]==3&&Map9[Box9_x][Box9_y+1]==6){
         ;
       }
       else if(Map9[People_x][People_y+1]==3&&Map9[Box9_x][Box9_y+1]==9){
         ;
       }
       else if(Map9[People_x][People_y+1]==9&&Map9[Box9_x2][Box9_y2+1]==3){
         ;
       }
       else if(Map9[People_x][People_y+1]==9&&Map9[Box9_x2][Box9_y2+1]==6){
         ;
       }
       //else if((People_x==Seat_x&&People_y==Seat_y&&People_x-2!=1)||(People_x==Seat_x&&People_y==Seat_y&&People_x-2!=0)||
       //(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=1)||(People_x==Seat_x1&&People_y==Seat_y1&&People_x-2!=0)){
        else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x==Box9_x&&People_y+1==Box9_y){
           Map9[Seat9_x][Seat9_y]=5;
           People_y++;
           Box9_y++;
         }
        else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x==Box9_x1&&People_y+1==Box9_y1){
           Map9[Seat9_x][Seat9_y]=5;
           People_y++;
           Box9_y1++;
         }
         else if(People_x==Seat9_x&&People_y==Seat9_y&&People_x==Box9_x2&&People_y+1==Box9_y2){
            Map9[Seat9_x][Seat9_y]=5;
            People_y++;
            Box9_y2++;
          }
        else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x==Box9_x&&People_y+1==Box9_y){
           Map9[Seat9_x1][Seat9_y1]=7;
           People_y++;
           Box9_y++;
         }
        else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x==Box9_x1&&People_y+1==Box9_y1){
           Map9[Seat9_x1][Seat9_y1]=7;
           People_y++;
           Box9_y1++;
         }
         else if(People_x==Seat9_x1&&People_y==Seat9_y1&&People_x==Box9_x2&&People_y+1==Box9_y2){
            Map9[Seat9_x1][Seat9_y1]=7;
            People_y++;
            Box9_y2++;
          }
         else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x==Box9_x&&People_y+1==Box9_y){
            Map9[Seat9_x2][Seat9_y2]=10;
            People_y++;
            Box9_y++;
          }else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x==Box9_x1&&People_y+1==Box9_y1){
             Map9[Seat9_x2][Seat9_y2]=10;
             People_y++;
             Box9_y1++;
           }
           else if(People_x==Seat9_x2&&People_y==Seat9_y2&&People_x==Box9_x2&&People_y+1==Box9_y2){
              Map9[Seat9_x2][Seat9_y2]=10;
              People_y++;
              Box9_y2++;
            }
       //}


       else if((People_x==Seat9_x&&People_y==Seat9_y&&Map9[Seat9_x][Seat9_y+1]!=0)||(People_x==Seat9_x&&People_y==Seat9_y&&Map9[Seat9_x][Seat9_y+1]!=1)){
         People_y++;
         Map9[Seat9_x][Seat9_y]=5;
        // Map[People_x][People_y]=2;
       }
       else if((People_x==Seat9_x1&&People_y==Seat9_y1&&Map9[Seat9_x1][Seat9_y1+1]!=0)||(People_x==Seat9_x1&&People_y==Seat9_y1&&Map9[Seat9_x1][Seat9_y1+1]!=1)){
         People_y++;
         Map9[Seat9_x1][Seat9_y1]=7;
         //Map[People_x][People_y]=2;
       }
       else if((People_x==Seat9_x2&&People_y==Seat9_y2&&Map9[Seat9_x2][Seat9_y2+1]!=0)||(People_x==Seat9_x2&&People_y==Seat9_y2&&Map9[Seat9_x2][Seat9_y2+1]!=1)){
         People_y++;
         Map9[Seat9_x2][Seat9_y2]=7;
         //Map[People_x][People_y]=2;
       }


       else if(Map9[Box9_x][Box9_y+1]==5&&Map9[People_x][People_y+2]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x][Box9_y+1]==7&&Map9[People_x][People_y+2]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x][Box9_y+1]==10&&Map9[People_x][People_y+2]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x][Box9_y]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1][Box9_y1+1]==5&&Map9[People_x][People_y+2]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1][Box9_y1+1]==7&&Map9[People_x][People_y+2]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x1][Box9_y1+1]==10&&Map9[People_x][People_y+2]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x1][Box9_y1]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2][Box9_y2+1]==5&&Map9[People_x][People_y+2]==5){
         Map9[Seat9_x][Seat9_y]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2][Box9_y2+1]==7&&Map9[People_x][People_y+2]==7){
         Map9[Seat9_x1][Seat9_y1]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }
       else if(Map9[Box9_x2][Box9_y2+1]==10&&Map9[People_x][People_y+2]==10){
         Map9[Seat9_x2][Seat9_y2]=8;
         Map9[Box9_x2][Box9_y2]=4;
         Map9[People_x][People_y]=2;
       }

        else if(Map9[People_x][People_y+1]!=6&&Map9[People_x][People_y+1]==3&&Map9[People_x][People_y+1]!=9&&Map9[Box9_x][Box9_y+1]!=0&&Map9[Box9_x][Box9_y+1]!=1){
           People_y++;
           Box9_y++;
           Map9[People_x][People_y-1]=2;
           Map9[Box9_x][Box9_y-1]=2;
         }
        else if(Map9[People_x][People_y+1]==6&Map9[People_x][People_y+1]!=3&&Map9[People_x][People_y+1]!=9&&Map9[Box9_x1][Box9_y1+1]!=0&&Map9[Box9_x1][Box9_y1+1]!=1){
           People_y++;
           Box9_y1++;
           Map9[People_x][People_y-1]=2;
           Map9[Box9_x1][Box9_y1-1]=2;
         }
         else if(Map9[People_x][People_y+1]!=6&Map9[People_x][People_y+1]!=3&&Map9[People_x][People_y+1]==9&&Map9[Box9_x2][Box9_y2+1]!=0&&Map9[Box9_x2][Box9_y2+1]!=1){
            People_y++;
            Box9_y2++;
            Map9[People_x][People_y-1]=2;
            Map9[Box9_x2][Box9_y2-1]=2;
          }
         else{
           People_y++;
           Map9[People_x][People_y-1]=2;
         }
     }
   }
}
void Game9()//...
{
  Creat_Seat9();
  while(1){
    Seat_Set9();
    HideCursor9();
    Map8[MAPMAX][MAPMAX+3];
    Map_Start9();
    Creat_Map9();
    if(Search_Box9()==1){
      system("CLS");
      Game9();
    }
    People_Move9();
  }
}
void Game8()   //....
{
  Creat_Seat8();
  while(1){
    Seat_Set8();
    HideCursor8();
    Map8[MAPMAX][MAPMAX+3];
    Map_Start8();
    Creat_Map8();
    if(Search_Box8()==1){
      system("CLS");
      Game9();
    }
    People_Move8();
  }
}
void Game7()    //...
{
  Creat_Seat7();
  while(1){
    Seat_Set7();
    HideCursor7();
    Map7[MAPMAX][MAPMAX+3];
    Map_Start7();
    Creat_Map7();
    if(Search_Box7()==1){
      system("CLS");
      Game8();
    }
    People_Move7();
  }
}
void Game6()
{
  Creat_Seat6();
  while(1){
    Seat_Set6();
    HideCursor6();
    Map6[MAPMAX][MAPMAX+3];
    Map_Start6();
    Creat_Map6();
    if(Search_Box6()==1){
      system("CLS");
      Game7();
    }
    People_Move6();
  }
}
void Game5()
{
  Creat_Seat5();
  while(1){
    Seat_Set5();
    HideCursor5();
    Map5[MAPMAX][MAPMAX+3];
    Map_Start5();
    Creat_Map5();
    if(Search_Box5()==1){
      system("CLS");
      Game6();
    }
    People_Move5();
  }
}
void Game4()
{
  Creat_Seat4();
  while(1){
    Seat_Set4();
    HideCursor4();
    Map4[MAPMAX][MAPMAX+3];
    Map_Start4();
    Creat_Map4();
    if(Search_Box4()==1){
      Game5();
    }
    People_Move4();
  }
}
void Game3()
{
  Creat_Seat3();
  while(1){
    Seat_Set3();
    HideCursor3();
    Map3[MAPMAX][MAPMAX+3];
    Map_Start3();
    Creat_Map3();
    if(Search_Box3()==1){
      system("CLS");
      Game4();
    }
    People_Move3();
  }
}
void Game2()
{
  Creat_Seat2();
  while(1){
    Seat_Set2();
    HideCursor2();
    Map2[MAPMAX][MAPMAX+3];
    Map_Start2();
    Creat_Map2();
    if(Search_Box2()==1){
      Game3();
    }
    People_Move2();
  }
}
void Game()
{
  Creat_Seat();
  while(1){
    HideCursor();
    Map[MAPMAX][MAPMAX+3];
    Map_Start();
    Creat_Map();
    if(Search_Box()==1){
      Game2();
    }
    People_Move();
  }
}
int meun()
{
  int Choose;
  for(int i =0;i<50;i++){
    cout<<"*";
  }
  cout<<endl;
  cout<<"                    推箱子                 "<<endl;
  cout<<"                  1.开始游戏               "<<endl;
  cout<<"                  2.选择关卡               "<<endl;
  cout<<"                  3.退出游戏               "<<endl;
  for(int i =0;i<50;i++){
    cout<<"*";
  }
  cout<<endl;
  cout<<"请选择：";
  cin>>Choose;
  return Choose;
}
void Chose_Game_Pass()
{
  int chose;
  cout<<"Please chose game pass"<<endl;
  for(int i = 1;i<=MAP_PASS;i++){
    if(i<=9){
      cout<<"--->"<<i<<"    "<<"第"<<i<<"关"<<endl;
    }
    else{
      cout<<"--->"<<i<<"   "<<"第"<<i<<"关"<<endl;
    }
  }
  cin>>chose;
  if(chose==1){
    Game();
  }
  else if(chose==2){
    system("CLS");
    Game2();
  }
  else if(chose==3){
    system("CLS");
    Game3();
  }
  else if(chose==4){
    system("CLS");
    Game4();
  }
  else if(chose==5){
    system("CLS");
    Game5();
  }
  else if(chose==6){
    system("CLS");
    Game6();
  }
  else if(chose==7){
    system("CLS");
    Game7();
  }
  else if(chose==8){
    system("CLS");
    Game8();
  }
  else if(chose==9){
    system("CLS");
    Game9();
  }
}
int main()
{
  Here:
  int alter=meun();
  if(alter==1){
    system("CLS");
    Game();
  }
  else if(alter==2){
    Chose_Game_Pass();
  }
  else if(alter==3){
    cout<<"Good Bye"<<endl;
    exit(0);
  }
  else{
    cout<<"wrong! please chose again"<<endl;
    goto Here;
  }
  return 0;
}
