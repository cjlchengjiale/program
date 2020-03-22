#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
#define MAX 9
#define MAXS MAX+2
#define SET MAX+5;
void menu()
{
  cout<<"*********************"<<endl;
  cout<<"    1.play 0.exit    "<<endl;
  cout<<"*********************"<<endl;
  srand((unsigned int)time(NULL));
}
void initboard(char board[MAXS][MAXS],int row,int col,char set)
{
  for(int i =0 ;i<row;i++){
    for(int k = 0;k<col;k++){
      board[i][k] = set;
    }
  }
}
void dispaly(char board[MAXS][MAXS],int row,int col)
{
  for(int i = 1;i<=MAX;i++){
    cout<<"    "<<i<<" ";
  }
  cout<<endl;
  cout<<" ";
  for(int i = 0;i<row;i++){
    cout<<"------";
  }
  cout<<endl;
  for(int i = 1;i<=row;i++){
    cout<<i<<"|";
    for(int j = 1;j<=col;j++){
      cout<<"  "<<board[i][j]<<"  ";
      if(j<col){
        cout<<"|";
      }
    }
    if(i<row){
      cout<<endl;
      cout<<"  ";
      for(int l = 0;l<row;l++){
        cout<<"-----";
        if(l<row-1){
          cout<<"+";
        }
      }
      cout<<endl;
    }
  }
  cout<<endl;
}
void setmine(char mine[MAXS][MAXS],int row,int col)
{
  int count = SET;
  while(count){
    int x = rand()%row+1;
    int y = rand()%col+1;
    if(mine[x][y]=='0'){
      mine[x][y]='1';
      count--;
    }
  }
}
int getmine(char mine[MAXS][MAXS],int x,int y)
{
  return (mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+mine[x][y-1]+mine[x][y+1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1])-8*'0';
}
void findmine(char mine[MAXS][MAXS],char show[MAXS][MAXS],int row,int col)
{
  int x = 0;
  int y = 0;
  int win = 0;
  int num = MAX*MAX-SET;
  while(win<=num){
    cout<<"请输入坐标"<<endl;
    cin>>x>>y;
    if(x>=1&&x<=row&&y>=1&&y<=col){
      if( mine[x][y]=='1'){
        cout<<"很遗憾你被炸死了"<<endl;
        dispaly(mine,row,col);
        break;
      }
      else{
        int cout = getmine(mine,x,y);
        show[x][y] = cout +'0';
        dispaly(show,row,col);
        win++;
      }
    }
    else{
      cout<<"输入坐标非法"<<endl;
    }
  }
  if(win==num){
    cout<<"恭喜你排雷成功"<<endl;
  }
}
void game()
{
  char mine[MAXS][MAXS];//存放雷
  char show[MAXS][MAXS];//存放排查出的雷
  initboard(mine,MAXS,MAXS,'0');
  initboard(show,MAXS,MAXS,'*');
  //dispaly(mine,MAX,MAX);
  dispaly(show,MAX,MAX);
  setmine(mine,MAX,MAX);
  //dispaly(mine,MAX,MAX);
  findmine(mine ,show,MAX,MAX);
}

void test()
{
  int choose = 0;
  do
  {
    menu();
    cout<<"请选择"<<endl;
    cin>>choose;
    switch(choose)
    {
      case 1:
      game();
      break;
      case 0:
      cout<<"退出游戏"<<endl;
      break;
      default:
      cout<<"选择错误"<<endl;
      break;
    }
  }while(choose);
}
int main()
{
  test();
  return 0;
}
