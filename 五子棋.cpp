#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
#define MAX 20
char board[MAX][MAX];
int meun()
{
 me:
 int choose,choose3=6;
 cout<<"========================="<<endl;
 cout<<"1   begain game"<<endl;
 cout<<"2   close  game"<<endl;
 cout<<"========================="<<endl;
 int choice;
 int choose2;
 cin>>choice;
 if(choice==2) exit(0);
 if(choice==1){
   if(choice==1){
     cout<<"========================="<<endl;
     cout<<"1   people vs people"<<endl;
     cout<<"2   people vs computer"<<endl;
     cout<<"3   return menu"<<endl;
     cout<<"========================="<<endl;
     cin>>choose;
     if(choose==1) return choose3;;
     if(choose==3) goto me;
     if(choose==2){
       cout<<"========================="<<endl;
       cout<<"1   people vs easycomputer"<<endl;
       cout<<"2   people vs middlecomputer"<<endl;
       cout<<"3   people vs difficultcomputer(正在开发暂时可对弈)"<<endl;
       cout<<"4   return menu"<<endl;
       cout<<"========================="<<endl;
       cin>>choose2;
       if(choose==4)
       goto me;
     }
   }
 }
 return choose2;
}
void fivechees()
{
 for(int i=0;i<MAX;i++){
   for(int k=0;k<MAX;k++){
     board[i][k]=' ';
   }
 }
 srand((unsigned int)time(NULL));
}
void print()
{
 for(int i=0;i<MAX;i++){
   if(i>=10){
     cout<<"   "<<i;
   }
   else cout<<"    "<<i;
 }
 cout<<endl;
 for(int i=0;i<MAX;++i){
   if(i>=10){
     cout<<i;
   }
   else cout<<i<<" ";
   for(int k=0;k<MAX;k++){
     cout<<"| "<<board[i][k]<<" |";
   }
   cout<<endl;
   cout<<"  ";
   for(int j=0;j<MAX;j++){
     cout<<"-----";
   }
   cout<<endl;
 }
}
void playermove()
{
 cout<<"请下子"<<endl;
 while(1){
   cout<<"请输入坐标";
   int col=0,row=0;
   cin>>row>>col;
   if(col<0||col>=MAX||row<0||row>=MAX) {
     cout<<"输入有误,请重新输入";
     continue;
   }
   if(board[row][col]!=' '){
     cout<<"wrong place input again"<<endl;
     continue;
   }
   board[row][col]='*';
   break;
 }
 cout<<"你已落子"<<endl;
}
void player1move()
{
 cout<<"玩家1请下子"<<endl;
 while(1){
   cout<<"请输入坐标";
   int col=0,row=0;
   cin>>row>>col;
   if(col<0||col>=MAX||row<0||row>=MAX) {
     cout<<"输入有误,请重新输入";
     continue;
   }
   if(board[row][col]!=' '){
     cout<<"wrong place input again"<<endl;
     continue;
   }
   board[row][col]='*';
   break;
 }
 cout<<"玩家1已落子"<<endl;
}
void player2move()
{
 cout<<"玩家2请下子"<<endl;
 while(1){
   cout<<"请输入坐标";
   int col=0,row=0;
   cin>>row>>col;
   if(col<0||col>=MAX||row<0||row>=MAX) {
     cout<<"输入有误,请重新输入";
     continue;
   }
   if(board[row][col]!=' '){
     cout<<"wrong place input again"<<endl;
     continue;
   }
   board[row][col]='#';
   break;
 }
 cout<<"玩家2已落子"<<endl;
}
void computermove()
{
 cout<<"轮到电脑下子"<<endl;
 while(1){
   int row=rand()%MAX;
   int col=rand()%MAX;
   if(board[row][col]!=' ') {
     cout<<"wrong place input again"<<endl;
     continue;
   }
   board[row][col]='#';
   break;
 }
 cout<<"电脑已落子"<<endl;
}
void AIcomputer()
{
 int c=0,d=0,number1=0,number2=0,number4=0,number3=0,number5=0,number6=0,number7=0,number8=0,number9=0,number10=0,number11=0;
 int number12=0,number13=0,number14=0,number15=0,number16=0,number17=0,number18=0,number19=0,number20=0,number21=0,number22=0;
 int number23=0,number24=0,number25=0,number26=0,number27=0;
 int num1=0;
 while(1){
   for(int i=1;i<MAX-1;i++){
     for(int k=0;k<MAX-2;k++){
       if(board[i][k]==board[i][k+2]&&board[i][k+2]==board[i+1][k+1]&&board[i][k]!=' '&&board[i][k+1]==' '){
         c=i;
         d=k+1;
         number23=1;
         cout<<c<<"!@#$^&&*()"<<d<<endl;
         break;
       }
     }
     if(number23==1) break;
   }
   for(int i=0;i<MAX-2;i++){
     for(int k=1;k<MAX-1;k++){
       if(board[i][k]==board[i+1][k-1]&&board[i+1][k-1]==board[i+1][k+1]&&board[i][k]!=' '&&board[i+1][k]==' '){
         c=i+1;
         d=k;
         number24=1;
         cout<<c<<"!@#$^=============&*()"<<d<<endl;
         break;
       }
     }
     if(number24==1) break;
   }
   for(int i=0;i<MAX-2;i++){
     for(int k=1;k<MAX-1;k++){
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k]&&board[i][k]!=' '&&board[i+1][k]==' '){
         c=i+1;
         d=k;
         number25=1;
         cout<<c<<"[[[[---------]]]]"<<d<<endl;
         break;
       }
     }
     if(number25==1) break;
   }
   for(int i=0;i<MAX-2;i++){
     for(int k=1;k<MAX-1;k++){
       if(board[i][k]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k]&&board[i][k]!=' '&&board[i+1][k]==' '){
         c=i+1;
         d=k;
         number26=1;
         cout<<c<<" {+++++}"<<d<<endl;
         break;
       }
     }
     if(number26==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i-1][k-1]&&board[i-1][k-1]==board[i-2][k-2]&&board[i][k-2]!=' '
         &&board[i][k]==' '){
           c=i;
           d=k;
           number15=1;
           cout<<i<<"      /////     "<<d<<endl;
           break;
         }
         if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i][k-2]!=' '
         &&board[i][k]==' '){
           c=i;
           d=k;
           number15=1;
           cout<<i<<"*****-----*****"<<d<<endl;
           break;
         }
         if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i][k-2]!=' '
         &&board[i][k]==' '){
           c=i;
           d=k;
           number15=1;
           cout<<i<<"--------+++++++++*****"<<d<<endl;
           break;
         }
         if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i][k-2]!=' '
         &&board[i][k]==' '){
           c=i;
           d=k;
           number15=1;
           cout<<c<<"/////////99999----"<<d<<endl;
           break;
         }
     }
     if(number15==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i-1][k-1]&&board[i-1][k-1]==board[i-2][k-2]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number16=1;
         cout<<c<<" ,,,,,,,"<<d<<endl;
         break;
       }
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number16=1;
         cout<<c<<" ,,,///..,,,,"<<d<<endl;
         break;
       }
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number16=1;
         cout<<c<<" ,,,///..,,,,,,''''''',"<<d<<endl;
         break;
       }
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number16=1;
         cout<<c<<" ,,,///..]]]]]]],,,,"<<d<<endl;
         break;
       }
     }
     if(number16==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i+2][k]==board[i+1][k]&&board[i+1][k]==board[i-1][k-1]&&board[i-1][k-1]==board[i-2][k-2]&&board[i+2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number17=1;
         cout<<c<<" ,,,+++,,,,"<<d<<endl;
         break;
       }
       if(board[i+2][k]==board[i+1][k]&&board[i+1][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number17=1;
         cout<<c<<" ,,,///..***,,---,,"<<d<<endl;
         break;
       }
       if(board[i+2][k]==board[i+1][k]&&board[i+1][k]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i+2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number17=1;
         cout<<c<<" ,,,///..,,/////***---,,,,''''''',"<<d<<endl;
         break;
       }
       if(board[i+2][k]==board[i+1][k]&&board[i+1][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i+2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number17=1;
         cout<<c<<" ,,,///..]]]]]]],,,,"<<d<<endl;
         break;
       }
     }
     if(number17==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k+2]==board[i][k+1]&&board[i][k+1]==board[i-1][k-1]&&board[i-1][k-1]==board[i-2][k-2]&&board[i][k+2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number18=1;
         cout<<c<<"          ,,,+++,,,,"<<d<<endl;
         break;
       }
       if(board[i][k+2]==board[i][k+1]&&board[i][k+1]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i][k+2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number18=1;
         cout<<c<<" ,]],,///..***,,---,,"<<d<<endl;
         break;
       }
       if(board[i][k+2]==board[i][k+1]&&board[i][k+1]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i][k+2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number18=1;
         cout<<c<<" ,,========,///..,,/////***---,,,,''''''',"<<d<<endl;
         break;
       }
       if(board[i][k+2]==board[i][k+1]&&board[i][k+1]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i][k+2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number18=1;
         cout<<c<<" ,--------,///..]]]]]]],,,,"<<d<<endl;
         break;
       }
     }
     if(number18==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k-2]!=' '&&board[i][k]==' '
       ||board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i-1][k]&&board[i-1][k]==board[i-2][k]&&board[i][k-2]!=' '&&board[i][k]==' '
       ||board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i][k-2]!=' '&&board[i][k]==' '
       ||board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i-2][k]!=' '&&board[i][k]==' '
       ||board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i-2][k]!=' '&&board[i][k]==' '
       ||board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i][k+1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number14=1;
         cout<<i<<"!!!!!><><><>!!!!!"<<d<<endl;
         break;
       }
     }
     if(number14==1) break;
   }
   for(int i=1;i<MAX;i++){
     for(int k=1;k<MAX;k++){
       if(board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i][k-1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number9=1;
         cout<<c<<"yyyyyyyyyyy"<<d<<endl;
       }
     }
     if(number9==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i-2][k-2]==board[i-1][k-1]&&board[i-1][k-1]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k-2]!=' '&&board[i][k]==' '
       ||board[i-2][k-2]==board[i-1][k-1]&&board[i-1][k-1]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i-2][k-2]!=' '&&board[i][k]==' '
       ||board[i-2][k+2]==board[i-1][k+1]&&board[i-1][k+1]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i-2][k+2]!=' '&&board[i][k]==' '
       ||board[i+2][k-2]==board[i+1][k-1]&&board[i+1][k-1]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k-2]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number27=1;
         cout<<c<<"~~~~%%%%%^^^^"<<d<<endl;
         break;
       }
     }
     if(number27==1) break;
   }
   /*for(int i=0;i<MAX;i++){
     for(int k=0;k<MAX-4;k++){
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+4]&&board[i][k]!=' '
       &&board[i][k+3]==' '){
         c=i;
         d=k+3;
         number10=1;
         cout<<c<<"uuuuuuuu"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k+3]==board[i][k+4]&&board[i][k]!=' '
       &&board[i][k+1]==' '){
         c=i;
         d=k+1;
         number10=1;
         cout<<c<<"                      "<<d<<endl;
         break;;
       }
     }
     if(number10==1) break;
   }*/
   /*for(int k=0;k<MAX;k++){
     for(int i=0;i<MAX-4;i++){
       if(board[i][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i+3][k]==board[i+4][k]&&board[i][k]!=' '
       &&board[i+1][k]==' '){
        c=i+1;
        d=k;
        number11=1;
        cout<<c<<"???????"<<d<<endl;
        break;
       }
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+4][k]&&board[i][k]!=' '
       &&board[i+3][k]==' '){
         c=i+3;
         d=k;
         number11=1;
         cout<<c<<" \\\\\\"<<d<<endl;
         break;
       }
     }
     if(number11==1) break;
   }*/
   /*for(int i=0;i<2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k-2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number19=1;
         cout<<c<<"||||||||||"<<d<<endl;
         break;
       }
     }
     if(number19==1) break;
   }
   for(int i=MAX-2;i<MAX;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k-2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number20=1;
         cout<<c<<"|||||------|||||"<<d<<endl;
         break;
       }
     }
     if(number20==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=0;k<2;k++){
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number21=1;
         cout<<c<<"|||||---||||---|||||"<<d<<endl;
         break;
       }
     }
     if(number21==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=MAX-2;k<MAX;k++){
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number21=1;
         cout<<c<<"\\\\\\|||||"<<d<<endl;
         break;
       }
     }
     if(number21==1) break;
   }*/
   for(int i=0;i<MAX;i++){
     for(int k=1;k<MAX-4;k++){
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k]!=' '&&board[i][k-1]=='#'
       &&board[i][k+4]!='#'){
         c=i;
         d=k+4;
         number1=1;
         cout<<c<<" "<<d<<endl;
         break;
       }
       if(board[i][k-1]==board[i][k]&&board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k]!=' '&&board[i][k+3]==' '){
         c=i;
         d=k+3;
         number1=1;
         cout<<c<<"@@@@@@@@@@@@"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+4]&&board[i][k]!=' '&&board[i][k+3]==' '){
         c=i;
         d=k+3;
         number1=1;
         cout<<c<<"!!!!!!!!!!!!!========^^^^-------"<<d<<endl;
         break;
       }
       if(board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k+3]==board[i][k+4]&&board[i][k+1]!=' '&&board[i][k]==' '
     ||board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k+1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number1=1;
         cout<<c<<"^^^^^^!!!!^^^^^^"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+3]&&board[i][k]!=' '&&board[i][k+2]==' '){
         c=i;
         d=k+2;
         number1=1;
         cout<<c<<"========^^^^"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k]!=' '&&board[i][k+1]==' '){
         c=i;
         d=k+1;
         number1=1;
         cout<<c<<"========^^^^-------"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k]!=' '&&board[i][k-1]==' '&&board[i][k+3]==' '){
         if(k-1<1){
           number5=1;
           c=i;
           d=k+3;
           cout<<c<<" ****  "<<d<<endl;
           break;
         }
         c=i;
         d=k-1;
         number1=1;
         cout<<c<<"*"<<d<<endl;
         break;
       }
     }
     if(number1==1||number5==1) break;
   }
   for(int k=0;k<MAX;k++){
     for(int i=1;i<MAX-4;i++){
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i][k]!=' '&&board[i-1][k]=='#'
       &&board[i+4][k]!='#'){
         c=i+4;
         d=k;
         number2=1;
         cout<<c<<"%%%%%%%%%%%%%%%%%%%"<<d<<endl;
         break;
       }
       if(board[i-1][k]==board[i][k]&&board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i][k]!=' '&&board[i+3][k]==' '){
         c=i+3;
         d=k;
         number2=1;
         cout<<c<<"+++++++++++++++"<<d<<endl;
         break;
       }
       if(board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i+3][k]==board[i+4][k]&&board[i+1][k]!=' '&&board[i][k]==' '
     ||board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i+1][k]!=' '&&board[i][k]==' '){
       c=i;
       d=k;
       number2=1;
       cout<<c<<"()()(()(()))"<<d<<endl;
       break;
       }
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+3][k]&&board[i][k]!=' '&&board[i+2][k]==' '){
         c=i+2;
         d=k;
         number2=1;
         cout<<c<<"()()((............)(()))"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i][k]!=' '&&board[i+1][k]==' '){
         c=i+1;
         d=k;
         number2=1;
         cout<<c<<"()()((............)(()))"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i][k]!=' '&&board[i-1][k]==' '&&board[i+3][k]==' '){
         if(i-1<1){
           number4=1;
           c=i+3;
           d=k;
           cout<<c<<"!!!!!!!!!!!!!!!"<<d<<endl;
           break;
         }
         c=i-1;
         d=k;
         cout<<c<<"///////"<<d<<endl;
         number2=1;
         break;
       }
     }
     if(number2==1||number4==1) break;
   }
   for(int i=1;i<MAX-4;i++){
     for(int k=1;k<MAX-4;k++){
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i][k]!=' '&&
       board[i+4][k+4]==' '&&board[i-1][k-1]=='#'){
         c=i+4;
         d=k+4;
         number3=1;
         cout<<c<<"$$$$$$$$$$$$$$$$$$"<<d<<endl;
         break;
       }
       if(board[i-1][k-1]==board[i][k]&&board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i][k]!=' '
       &&board[i+3][k+3]==' '){
         c=i+3;
         d=k+3;
         number3=1;
         cout<<c<<"))))))))))))"<<d<<endl;
         break;
       }
       if(board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i+3][k+3]==board[i+4][k+4]&&board[i+1][k+1]!=' '&&
       board[i][k]==' '||board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i+1][k+1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number3=1;
         cout<<c<<"_+_+_+_+_+_+_+_+"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+3][k+3]&&board[i][k]!=' '&&board[i+2][k+2]==' '){
         c=i+2;
         d=k+2;
         number3=1;
         cout<<c<<" /*/*////*/*/*/*/*/*-"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i][k]!=' '&&board[i+1][k+1]==' '){
         c=i+1;
         d=k+1;
         number3=1;
         cout<<c<<" (========)"<<d<<endl;
         break;
       }
       if(i==1&&k==MAX-5&&board[i-1][k]==board[i][k+1]&&board[i][k+1]==board[i+1][k+2]&&board[i+1][k+2]==board[i+2][k+3]
       &&board[i-1][k]!=' '&&board[i+3][k+4]==' '){
         c=i+3;
         d=MAX-1;
         number3=1;
         cout<<c<<" (===!!!!=====)"<<d<<endl;
         break;
       }
       if(i==1&&k==MAX-5&&board[i][k+1]==board[i+1][k+2]&&board[i+1][k+2]==board[i+2][k+3]&&board[i+2][k+3]==board[i+3][k+4]
       &&board[i][k+1]!=' '&&board[i-1][k]==' '){
         c=i-1;
         d=k;
         number3=1;
         cout<<c<<" (===!!!!== !!!===)"<<d<<endl;
         break;
       }
       if(i==MAX-5&&k==1){
         if(board[i+1][k]==board[i+2][k+1]&&board[i+2][k+1]==board[i+3][k+2]&&board[i+3][k+2]==board[i+4][k+3]&&board[i+1][k]!=' '
         &&board[i][k-1]==' '){
           c=i;
           d=k-1;
           number3=1;
           cout<<c<<" (===!!!!== !!!===)"<<d<<endl;
           break;
         }
         if(board[i][k-1]==board[i+1][k]&&board[i+1][k]==board[i+2][k+1]&&board[i+2][k+1]==board[i+3][k+2]&&board[i][k-1]!=' '
         &&board[i+4][k+3]==' '){
           c=i+4;
           d=k+3;
           number3=1;
           cout<<c<<" =======(===!!!!== !!!===)"<<d<<endl;
           break;
         }
       }
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i][k]!=' '&&board[i-1][k-1]==' '&&board[i+3][k+3]==' '){
         if(k-1<1||i-1<1 ){
           c=i+3;
           d=k+3;
           number6=1;
           cout<<c<<"-+-=-+-="<<d<<endl;
           break;
         }
         c=i-1;
         d=k-1;
         number3=1;
         cout<<c<<"(8)(8)(8)(8)"<<d<<endl;
         break;
       }
     }
     if(number3==1||number6==1) break;
   }
   for(int i=MAX-2;i>=4;i--){
     for(int k=1;k<MAX-4;k++){
       if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i][k]!=' '&&
       board[i-4][k+4]==' '&&board[i+1][k-1]=='#'){
         c=i-4;
         d=k+4;
         number7=1;
         cout<<c<<"_________________"<<d<<endl;
         break;
       }
       if(board[i+1][k-1]==board[i][k]&&board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i][k]!=' '
       &&board[i-3][k+3]==' '){
         c=i-3;
         d=k+3;
         cout<<c<<"=================="<<d<<endl;
         number7=1;
         break;
       }
       if(board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i-3][k+3]==board[i-4][k+4]&&board[i-1][k+1]!=' '
       &&board[i][k]==' '||board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i-1][k+1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number7=1;
         cout<<c<<".............."<<c<<endl;
         break;
       }
       if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-3][k+3]&&board[i][k]!=' '&&board[i-2][k+2]==' '){
         c=i-2;
         d=k+2;
         number7=1;
         cout<<c<<"--=-=-=-%%^&&&&&&&&"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i][k]!=' '&&board[i-1][k+1]==' '){
         c=i-1;
         d=k+1;
         number7=1;
         cout<<c<<"+++--+-+++++++++++"<<d<<endl;
         break;
       }
       if(i==4&&k==1){
         if(board[i][k-1]==board[i-1][k]&&board[i-1][k]==board[i-2][k+1]&&board[i-2][k+1]==board[i-3][k+2]&&board[i][k-1]!=' '
         &&board[i-4][k+3]==' '){
           c=i-4;
           d=k+3;
           number7=1;
           cout<<c<<"+++--+-++++!!!!!!+++++++"<<d<<endl;
           break;
         }
         if(board[i-1][k]==board[i-2][k+1]&&board[i-2][k+1]==board[i-3][k+2]&&board[i-3][k+2]==board[i-4][k+3]&&board[i-1][k]!=' '
         &&board[i][k-1]==' '){
           c=i;
           d=k-1;
           number7=1;
           cout<<c<<"+%%%%%++--+-++++!!!!!!+++++++"<<d<<endl;
           break;
         }
       }
       if(i==MAX-2&&k==MAX-5){
         if(board[i+1][k]==board[i][k+1]&&board[i][k+1]==board[i-1][k+2]&&board[i-1][k+2]==board[i-2][k+3]&&board[i+1][k]!=' '
         &&board[i-3][k+4]==' '){
           c=i-3;
           d=k+4;
           number7=1;
           cout<<c<<"+%%%%%++--+!!!!"<<d<<endl;
           break;
         }
         if(board[i][k+1]==board[i-1][k+2]&&board[i-1][k+2]==board[i-2][k+3]&&board[i-2][k+3]==board[i-3][k+4]&&board[i][k+1]!=' '
         &&board[i+1][k]==' '){
           c=i+1;
           d=k;
           number7=1;
           cout<<c<<"+%%%%%++--+!!!!(((((())))))"<<d<<endl;
           break;
         }
       }
       if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i][k]!=' '&&board[i+1][k-1]==' '&&board[i-3][k+3]==' '){
         if(i+3>MAX){
           c=i-3;
           d=k+3;
           number8=1;
           cout<<c<<"vvvvvvvvvvvv"<<d<<endl;
           break;
         }
         c=i+1;
         d=k-1;
         number7=1;
         cout<<c<<"iiiiiiiiiii"<<d<<endl;
         break;
       }
     }
     if(number7==1||number8==1) break;
   }
   for(int i=MAX-1;i>=4;i--){
     for(int k=0;k<MAX-4;k++){
       if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-4][k+4]&&board[i][k]!=' '
       &&board[i-3][k+3]==' '){
         c=i-3;
         d=k+3;
         number13=1;
         cout<<c<<" [[[[[[]]]]]]"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i-3][k+3]==board[i-4][k+4]&&board[i][k]!=' '
       &&board[i-1][k+1]==' '){
         c=i-1;
         d=k+1;
         number13=1;
         cout<<c<<"$%$%$&&*******((((()))))"<<d<<endl;
         break;
       }
     }
     if(number13==1) break;
   }
   for(int i=0;i<MAX-4;i++){
     for(int k=0;k<MAX-4;k++){
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+4][k+4]&&board[i][k]!=' '
       &&board[i+3][k+3]==' '){
         c=i+3;
         d=k+3;
         number12=1;
         cout<<c<<"<><><><><>"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i+3][k+3]==board[i+4][k+4]&&board[i][k]!=' '
       &&board[i+1][k+1]==' '){
         c=i+1;
         d=k+1;
         number12=1;
         cout<<c<<" >>>>>>>>"<<d<<endl;
         break;
       }
     }
     if(number12==1) break;
   }
   for(int i=0;i<MAX;i++){
     for(int k=0;k<MAX-4;k++){
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+4]&&board[i][k]!=' '
       &&board[i][k+3]==' '){
         c=i;
         d=k+3;
         number10=1;
         cout<<c<<"uuuuuuuu"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k+3]==board[i][k+4]&&board[i][k]!=' '
       &&board[i][k+1]==' '){
         c=i;
         d=k+1;
         number10=1;
         cout<<c<<"                      "<<d<<endl;
         break;;
       }
     }
     if(number10==1) break;
   }
   for(int k=0;k<MAX;k++){
     for(int i=0;i<MAX-4;i++){
       if(board[i][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i+3][k]==board[i+4][k]&&board[i][k]!=' '
       &&board[i+1][k]==' '){
        c=i+1;
        d=k;
        number11=1;
        cout<<c<<"???????"<<d<<endl;
        break;
       }
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+4][k]&&board[i][k]!=' '
       &&board[i+3][k]==' '){
         c=i+3;
         d=k;
         number11=1;
         cout<<c<<" \\\\\\"<<d<<endl;
         break;
       }
     }
     if(number11==1) break;
   }
   for(int i=0;i<2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k-2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number19=1;
         cout<<c<<"||||||||||"<<d<<endl;
         break;
       }
     }
     if(number19==1) break;
   }
   for(int i=MAX-2;i<MAX;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k-2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number20=1;
         cout<<c<<"|||||------|||||"<<d<<endl;
         break;
       }
     }
     if(number20==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=0;k<2;k++){
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number21=1;
         cout<<c<<"|||||---||||---|||||"<<d<<endl;
         break;
       }
     }
     if(number21==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=MAX-2;k<MAX;k++){
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number21=1;
         cout<<c<<"\\\\\\|||||"<<d<<endl;
         break;
       }
     }
     if(number21==1) break;
   }
   cout<<c<<" ****/*/* */*/*/*/*/*/*/ "<<d<<endl;
   if(number1==0&&number2==0&&number5==0&&number4==0&&number3==0&&number6==0&&number7==0&&number8==0&&number9==0&&number10==0&&
   number11==0&&number12==0&&number13==0&&number14==0&&number15==0&&number16==0&&number17==0&&number18==0&&number19==0&&number20==0
   &&number21==0&&number22==0&&number23==0&&number24==0&&number25==0&&number26==0&&number27==0){
     for(int i=1;i<MAX-1;i++){
       for(int k=1;k<MAX-1;k++){
         if(board[i][k]=='#'){
           cout<<"-----==-=-=-=-=------=====-------"<<endl;
           if(board[i][k+1]==' '){
             c=i;
             d=k+1;
             num1=1;
             cout<<c<<"&^^^^^^&"<<d<<endl;
             break;
           }
           if(board[i][k-1]==' '){
             c=i;
             d=k-1;
             num1=1;
             break;
           }
           if(board[i+1][k]==' '){
             c=i+1;
             d=k;
             num1=1;
             break;
           }
           if(board[i-1][k]==' '){
             c=i-1;
             d=k;
             num1=1;
             break;
           }
           if(board[i-1][k-1]==' '){
             c=i-1;
             d=k-1;
             num1=1;
             break;
           }
           if(board[i+1][k+1]==' '){
             c=i+1;
             d=k+1;
             num1=1;
             break;
           }
           if(board[i+1][k-1]==' '){
             c=i+1;
             d=k-1;
             num1=1;
             break;
           }
           if(board[i-1][k+1]==' '){
             c=i-1;
             d=k+1;
             num1=1;
             break;
           }
         }
       }
       if(num1==1) break;
     }
   /*  for(int i =1;i<MAX-1;i++){
       for(int k = 1;k<MAX-1;k++){
         if()
       }
     }*/
     if(num1==0){
       c=rand()%MAX;
       d=rand()%MAX;
       cout<<c<<"-------"<<d<<endl;
     }
     cout<<c<<"-------"<<d<<endl;
   }
   if(board[c][d]!=' ') {
     continue;
   }
   board[c][d]='#';
   break;
 }
 cout<<c<<"*************************"<<d<<endl;
}





void AImiddlecomputer()
{
 int c=0,d=0,number1=0,number2=0,number4=0,number3=0,number5=0,number6=0,number7=0,number8=0,number9=0,number10=0,number11=0;
 int number12=0,number13=0,number14=0,number15=0,number16=0,number17=0,number18=0,number19=0,number20=0,number21=0,number22=0;
 int number23=0,number24=0,number25=0,number26=0,number27=0;
 int num1=0;
 while(1){
   for(int i=1;i<MAX-1;i++){
     for(int k=0;k<MAX-2;k++){
       if(board[i][k]==board[i][k+2]&&board[i][k+2]==board[i+1][k+1]&&board[i][k]!=' '&&board[i][k+1]==' '){
         c=i;
         d=k+1;
         number23=1;
         cout<<c<<"!@#$^&&*()"<<d<<endl;
         break;
       }
     }
     if(number23==1) break;
   }
 /*//  for(int i=0;i<MAX-2;i++){
     for(int k=1;k<MAX-1;k++){
       if(board[i][k]==board[i+1][k-1]&&board[i+1][k-1]==board[i+1][k+1]&&board[i][k]!=' '&&board[i+1][k]==' '){
         c=i+1;
         d=k;
         number24=1;
         cout<<c<<"!@#$^=============&*()"<<d<<endl;
         break;
       }
     }
     if(number24==1) break;
   }*/
   for(int i=0;i<MAX-2;i++){
     for(int k=1;k<MAX-1;k++){
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k]&&board[i][k]!=' '&&board[i+1][k]==' '){
         c=i+1;
         d=k;
         number25=1;
         cout<<c<<"[[[[---------]]]]"<<d<<endl;
         break;
       }
     }
     if(number25==1) break;
   }
/*//    for(int i=0;i<MAX-2;i++){
     for(int k=1;k<MAX-1;k++){
       if(board[i][k]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k]&&board[i][k]!=' '&&board[i+1][k]==' '){
         c=i+1;
         d=k;
         number26=1;
         cout<<c<<" {+++++}"<<d<<endl;
         break;
       }
     }
     if(number26==1) break;
   }*/
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i-1][k-1]&&board[i-1][k-1]==board[i-2][k-2]&&board[i][k-2]!=' '
         &&board[i][k]==' '){
           c=i;
           d=k;
           number15=1;
           cout<<i<<"      /////     "<<d<<endl;
           break;
         }
         if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i][k-2]!=' '
         &&board[i][k]==' '){
           c=i;
           d=k;
           number15=1;
           cout<<i<<"*****-----*****"<<d<<endl;
           break;
         }
         if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i][k-2]!=' '
         &&board[i][k]==' '){
           c=i;
           d=k;
           number15=1;
           cout<<i<<"--------+++++++++*****"<<d<<endl;
           break;
         }
         if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i][k-2]!=' '
         &&board[i][k]==' '){
           c=i;
           d=k;
           number15=1;
           cout<<c<<"/////////99999----"<<d<<endl;
           break;
         }
     }
     if(number15==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i-1][k-1]&&board[i-1][k-1]==board[i-2][k-2]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number16=1;
         cout<<c<<" ,,,,,,,"<<d<<endl;
         break;
       }
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number16=1;
         cout<<c<<" ,,,///..,,,,"<<d<<endl;
         break;
       }
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number16=1;
         cout<<c<<" ,,,///..,,,,,,''''''',"<<d<<endl;
         break;
       }
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number16=1;
         cout<<c<<" ,,,///..]]]]]]],,,,"<<d<<endl;
         break;
       }
     }
     if(number16==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i+2][k]==board[i+1][k]&&board[i+1][k]==board[i-1][k-1]&&board[i-1][k-1]==board[i-2][k-2]&&board[i+2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number17=1;
         cout<<c<<" ,,,+++,,,,"<<d<<endl;
         break;
       }
       if(board[i+2][k]==board[i+1][k]&&board[i+1][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number17=1;
         cout<<c<<" ,,,///..***,,---,,"<<d<<endl;
         break;
       }
       if(board[i+2][k]==board[i+1][k]&&board[i+1][k]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i+2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number17=1;
         cout<<c<<" ,,,///..,,/////***---,,,,''''''',"<<d<<endl;
         break;
       }
       if(board[i+2][k]==board[i+1][k]&&board[i+1][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i+2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number17=1;
         cout<<c<<" ,,,///..]]]]]]],,,,"<<d<<endl;
         break;
       }
     }
     if(number17==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k+2]==board[i][k+1]&&board[i][k+1]==board[i-1][k-1]&&board[i-1][k-1]==board[i-2][k-2]&&board[i][k+2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number18=1;
         cout<<c<<"          ,,,+++,,,,"<<d<<endl;
         break;
       }
       if(board[i][k+2]==board[i][k+1]&&board[i][k+1]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i][k+2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number18=1;
         cout<<c<<" ,]],,///..***,,---,,"<<d<<endl;
         break;
       }
       if(board[i][k+2]==board[i][k+1]&&board[i][k+1]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i][k+2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number18=1;
         cout<<c<<" ,,========,///..,,/////***---,,,,''''''',"<<d<<endl;
         break;
       }
       if(board[i][k+2]==board[i][k+1]&&board[i][k+1]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i][k+2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number18=1;
         cout<<c<<" ,--------,///..]]]]]]],,,,"<<d<<endl;
         break;
       }
     }
     if(number18==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k-2]!=' '&&board[i][k]==' '
       ||board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i-1][k]&&board[i-1][k]==board[i-2][k]&&board[i][k-2]!=' '&&board[i][k]==' '
       ||board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i][k-2]!=' '&&board[i][k]==' '
       ||board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i-2][k]!=' '&&board[i][k]==' '
       ||board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i-2][k]!=' '&&board[i][k]==' '
       ||board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i][k+1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number14=1;
         cout<<i<<"!!!!!><><><>!!!!!"<<d<<endl;
         break;
       }
     }
     if(number14==1) break;
   }
/*//    for(int i=1;i<MAX;i++){
     for(int k=1;k<MAX;k++){
       if(board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i][k-1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number9=1;
         cout<<c<<"yyyyyyyyyyy"<<d<<endl;
       }
     }
     if(number9==1) break;
   }*/
   for(int i=2;i<MAX-2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i-2][k-2]==board[i-1][k-1]&&board[i-1][k-1]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k-2]!=' '&&board[i][k]==' '
       ||board[i-2][k-2]==board[i-1][k-1]&&board[i-1][k-1]==board[i+1][k-1]&&board[i+1][k-1]==board[i+2][k-2]&&board[i-2][k-2]!=' '&&board[i][k]==' '
       ||board[i-2][k+2]==board[i-1][k+1]&&board[i-1][k+1]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i-2][k+2]!=' '&&board[i][k]==' '
       ||board[i+2][k-2]==board[i+1][k-1]&&board[i+1][k-1]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k-2]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number27=1;
         cout<<c<<"~~~~%%%%%^^^^"<<d<<endl;
         break;
       }
     }
     if(number27==1) break;
   }
   for(int i=0;i<MAX;i++){
     for(int k=1;k<MAX-4;k++){
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k]!=' '&&board[i][k-1]=='#'
       &&board[i][k+4]!='#'){
         c=i;
         d=k+4;
         number1=1;
         cout<<c<<" "<<d<<endl;
         break;
       }
       if(board[i][k-1]==board[i][k]&&board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k]!=' '&&board[i][k+3]==' '){
         c=i;
         d=k+3;
         number1=1;
         cout<<c<<"@@@@@@@@@@@@"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+4]&&board[i][k]!=' '&&board[i][k+3]==' '){
         c=i;
         d=k+3;
         number1=1;
         cout<<c<<"!!!!!!!!!!!!!========^^^^-------"<<d<<endl;
         break;
       }
       if(board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k+3]==board[i][k+4]&&board[i][k+1]!=' '&&board[i][k]==' '
     ||board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k+1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number1=1;
         cout<<c<<"^^^^^^!!!!^^^^^^"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+3]&&board[i][k]!=' '&&board[i][k+2]==' '){
         c=i;
         d=k+2;
         number1=1;
         cout<<c<<"========^^^^"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k]!=' '&&board[i][k+1]==' '){
         c=i;
         d=k+1;
         number1=1;
         cout<<c<<"========^^^^-------"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k]!=' '&&board[i][k-1]==' '&&board[i][k+3]==' '){
         if(k-1<1){
           number5=1;
           c=i;
           d=k+3;
           cout<<c<<" ****  "<<d<<endl;
           break;
         }
         c=i;
         d=k-1;
         number1=1;
         cout<<c<<"*"<<d<<endl;
         break;
       }
     }
     if(number1==1||number5==1) break;
   }
   for(int k=0;k<MAX;k++){
     for(int i=1;i<MAX-4;i++){
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i][k]!=' '&&board[i-1][k]=='#'
       &&board[i+4][k]!='#'){
         c=i+4;
         d=k;
         number2=1;
         cout<<c<<"%%%%%%%%%%%%%%%%%%%"<<d<<endl;
         break;
       }
       if(board[i-1][k]==board[i][k]&&board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i][k]!=' '&&board[i+3][k]==' '){
         c=i+3;
         d=k;
         number2=1;
         cout<<c<<"+++++++++++++++"<<d<<endl;
         break;
       }
       if(board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i+3][k]==board[i+4][k]&&board[i+1][k]!=' '&&board[i][k]==' '
     ||board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i+1][k]!=' '&&board[i][k]==' '){
       c=i;
       d=k;
       number2=1;
       cout<<c<<"()()(()(()))"<<d<<endl;
       break;
       }
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+3][k]&&board[i][k]!=' '&&board[i+2][k]==' '){
         c=i+2;
         d=k;
         number2=1;
         cout<<c<<"()()((............)(()))"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i][k]!=' '&&board[i+1][k]==' '){
         c=i+1;
         d=k;
         number2=1;
         cout<<c<<"()()((............)(()))"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i][k]!=' '&&board[i-1][k]==' '&&board[i+3][k]==' '){
         if(i-1<1){
           number4=1;
           c=i+3;
           d=k;
           cout<<c<<"!!!!!!!!!!!!!!!"<<d<<endl;
           break;
         }
         c=i-1;
         d=k;
         cout<<c<<"///////"<<d<<endl;
         number2=1;
         break;
       }
     }
     if(number2==1||number4==1) break;
   }
   for(int i=1;i<MAX-4;i++){
     for(int k=1;k<MAX-4;k++){
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i][k]!=' '&&
       board[i+4][k+4]==' '&&board[i-1][k-1]=='#'){
         c=i+4;
         d=k+4;
         number3=1;
         cout<<c<<"$$$$$$$$$$$$$$$$$$"<<d<<endl;
         break;
       }
       if(board[i-1][k-1]==board[i][k]&&board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i][k]!=' '
       &&board[i+3][k+3]==' '){
         c=i+3;
         d=k+3;
         number3=1;
         cout<<c<<"))))))))))))"<<d<<endl;
         break;
       }
       if(board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i+3][k+3]==board[i+4][k+4]&&board[i+1][k+1]!=' '&&
       board[i][k]==' '||board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i+1][k+1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number3=1;
         cout<<c<<"_+_+_+_+_+_+_+_+"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+3][k+3]&&board[i][k]!=' '&&board[i+2][k+2]==' '){
         c=i+2;
         d=k+2;
         number3=1;
         cout<<c<<" /*/*////*/*/*/*/*/*-"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i][k]!=' '&&board[i+1][k+1]==' '){
         c=i+1;
         d=k+1;
         number3=1;
         cout<<c<<" (========)"<<d<<endl;
         break;
       }
       if(i==1&&k==MAX-5&&board[i-1][k]==board[i][k+1]&&board[i][k+1]==board[i+1][k+2]&&board[i+1][k+2]==board[i+2][k+3]
       &&board[i-1][k]!=' '&&board[i+3][k+4]==' '){
         c=i+3;
         d=MAX-1;
         number3=1;
         cout<<c<<" (===!!!!=====)"<<d<<endl;
         break;
       }
       if(i==1&&k==MAX-5&&board[i][k+1]==board[i+1][k+2]&&board[i+1][k+2]==board[i+2][k+3]&&board[i+2][k+3]==board[i+3][k+4]
       &&board[i][k+1]!=' '&&board[i-1][k]==' '){
         c=i-1;
         d=k;
         number3=1;
         cout<<c<<" (===!!!!== !!!===)"<<d<<endl;
         break;
       }
       if(i==MAX-5&&k==1){
         if(board[i+1][k]==board[i+2][k+1]&&board[i+2][k+1]==board[i+3][k+2]&&board[i+3][k+2]==board[i+4][k+3]&&board[i+1][k]!=' '
         &&board[i][k-1]==' '){
           c=i;
           d=k-1;
           number3=1;
           cout<<c<<" (===!!!!== !!!===)"<<d<<endl;
           break;
         }
         if(board[i][k-1]==board[i+1][k]&&board[i+1][k]==board[i+2][k+1]&&board[i+2][k+1]==board[i+3][k+2]&&board[i][k-1]!=' '
         &&board[i+4][k+3]==' '){
           c=i+4;
           d=k+3;
           number3=1;
           cout<<c<<" =======(===!!!!== !!!===)"<<d<<endl;
           break;
         }
       }
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i][k]!=' '&&board[i-1][k-1]==' '&&board[i+3][k+3]==' '){
         if(k-1<1||i-1<1 ){
           c=i+3;
           d=k+3;
           number6=1;
           cout<<c<<"-+-=-+-="<<d<<endl;
           break;
         }
         c=i-1;
         d=k-1;
         number3=1;
         cout<<c<<"(8)(8)(8)(8)"<<d<<endl;
         break;
       }
     }
     if(number3==1||number6==1) break;
   }
   for(int i=MAX-2;i>=4;i--){
     for(int k=1;k<MAX-4;k++){
       if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i][k]!=' '&&
       board[i-4][k+4]==' '&&board[i+1][k-1]=='#'){
         c=i-4;
         d=k+4;
         number7=1;
         cout<<c<<"_________________"<<d<<endl;
         break;
       }
       if(board[i+1][k-1]==board[i][k]&&board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i][k]!=' '
       &&board[i-3][k+3]==' '){
         c=i-3;
         d=k+3;
         cout<<c<<"=================="<<d<<endl;
         number7=1;
         break;
       }
       if(board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i-3][k+3]==board[i-4][k+4]&&board[i-1][k+1]!=' '
       &&board[i][k]==' '||board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i-1][k+1]!=' '&&board[i][k]==' '){
         c=i;
         d=k;
         number7=1;
         cout<<c<<".............."<<c<<endl;
         break;
       }
       if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-3][k+3]&&board[i][k]!=' '&&board[i-2][k+2]==' '){
         c=i-2;
         d=k+2;
         number7=1;
         cout<<c<<"--=-=-=-%%^&&&&&&&&"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i][k]!=' '&&board[i-1][k+1]==' '){
         c=i-1;
         d=k+1;
         number7=1;
         cout<<c<<"+++--+-+++++++++++"<<d<<endl;
         break;
       }
       if(i==4&&k==1){
         if(board[i][k-1]==board[i-1][k]&&board[i-1][k]==board[i-2][k+1]&&board[i-2][k+1]==board[i-3][k+2]&&board[i][k-1]!=' '
         &&board[i-4][k+3]==' '){
           c=i-4;
           d=k+3;
           number7=1;
           cout<<c<<"+++--+-++++!!!!!!+++++++"<<d<<endl;
           break;
         }
         if(board[i-1][k]==board[i-2][k+1]&&board[i-2][k+1]==board[i-3][k+2]&&board[i-3][k+2]==board[i-4][k+3]&&board[i-1][k]!=' '
         &&board[i][k-1]==' '){
           c=i;
           d=k-1;
           number7=1;
           cout<<c<<"+%%%%%++--+-++++!!!!!!+++++++"<<d<<endl;
           break;
         }
       }
       if(i==MAX-2&&k==MAX-5){
         if(board[i+1][k]==board[i][k+1]&&board[i][k+1]==board[i-1][k+2]&&board[i-1][k+2]==board[i-2][k+3]&&board[i+1][k]!=' '
         &&board[i-3][k+4]==' '){
           c=i-3;
           d=k+4;
           number7=1;
           cout<<c<<"+%%%%%++--+!!!!"<<d<<endl;
           break;
         }
         if(board[i][k+1]==board[i-1][k+2]&&board[i-1][k+2]==board[i-2][k+3]&&board[i-2][k+3]==board[i-3][k+4]&&board[i][k+1]!=' '
         &&board[i+1][k]==' '){
           c=i+1;
           d=k;
           number7=1;
           cout<<c<<"+%%%%%++--+!!!!(((((())))))"<<d<<endl;
           break;
         }
       }
       if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i][k]!=' '&&board[i+1][k-1]==' '&&board[i-3][k+3]==' '){
         if(i+3>MAX){
           c=i-3;
           d=k+3;
           number8=1;
           cout<<c<<"vvvvvvvvvvvv"<<d<<endl;
           break;
         }
         c=i+1;
         d=k-1;
         number7=1;
         cout<<c<<"iiiiiiiiiii"<<d<<endl;
         break;
       }
     }
     if(number7==1||number8==1) break;
   }
   for(int i=MAX-1;i>=4;i--){
     for(int k=0;k<MAX-4;k++){
       if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-4][k+4]&&board[i][k]!=' '
       &&board[i-3][k+3]==' '){
         c=i-3;
         d=k+3;
         number13=1;
         cout<<c<<" [[[[[[]]]]]]"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]&&board[i-3][k+3]==board[i-4][k+4]&&board[i][k]!=' '
       &&board[i-1][k+1]==' '){
         c=i-1;
         d=k+1;
         number13=1;
         cout<<c<<"$%$%$&&*******((((()))))"<<d<<endl;
         break;
       }
     }
     if(number13==1) break;
   }
   for(int i=0;i<MAX-4;i++){
     for(int k=0;k<MAX-4;k++){
       if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+4][k+4]&&board[i][k]!=' '
       &&board[i+3][k+3]==' '){
         c=i+3;
         d=k+3;
         number12=1;
         cout<<c<<"<><><><><>"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]&&board[i+3][k+3]==board[i+4][k+4]&&board[i][k]!=' '
       &&board[i+1][k+1]==' '){
         c=i+1;
         d=k+1;
         number12=1;
         cout<<c<<" >>>>>>>>"<<d<<endl;
         break;
       }
     }
     if(number12==1) break;
   }
   for(int i=0;i<MAX;i++){
     for(int k=0;k<MAX-4;k++){
       if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+4]&&board[i][k]!=' '
       &&board[i][k+3]==' '){
         c=i;
         d=k+3;
         number10=1;
         cout<<c<<"uuuuuuuu"<<d<<endl;
         break;
       }
       if(board[i][k]==board[i][k+2]&&board[i][k+2]==board[i][k+3]&&board[i][k+3]==board[i][k+4]&&board[i][k]!=' '
       &&board[i][k+1]==' '){
         c=i;
         d=k+1;
         number10=1;
         cout<<c<<"                      "<<d<<endl;
         break;;
       }
     }
     if(number10==1) break;
   }
   for(int k=0;k<MAX;k++){
     for(int i=0;i<MAX-4;i++){
       if(board[i][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]&&board[i+3][k]==board[i+4][k]&&board[i][k]!=' '
       &&board[i+1][k]==' '){
        c=i+1;
        d=k;
        number11=1;
        cout<<c<<"???????"<<d<<endl;
        break;
       }
       if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+4][k]&&board[i][k]!=' '
       &&board[i+3][k]==' '){
         c=i+3;
         d=k;
         number11=1;
         cout<<c<<" \\\\\\"<<d<<endl;
         break;
       }
     }
     if(number11==1) break;
   }
   for(int i=0;i<2;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k-2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number19=1;
         cout<<c<<"||||||||||"<<d<<endl;
         break;
       }
     }
     if(number19==1) break;
   }
   for(int i=MAX-2;i<MAX;i++){
     for(int k=2;k<MAX-2;k++){
       if(board[i][k-2]==board[i][k-1]&&board[i][k-1]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k-2]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number20=1;
         cout<<c<<"|||||------|||||"<<d<<endl;
         break;
       }
     }
     if(number20==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=0;k<2;k++){
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number21=1;
         cout<<c<<"|||||---||||---|||||"<<d<<endl;
         break;
       }
     }
     if(number21==1) break;
   }
   for(int i=2;i<MAX-2;i++){
     for(int k=MAX-2;k<MAX;k++){
       if(board[i-2][k]==board[i-1][k]&&board[i-1][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i-2][k]!=' '
       &&board[i][k]==' '){
         c=i;
         d=k;
         number21=1;
         cout<<c<<"\\\\\\|||||"<<d<<endl;
         break;
       }
     }
     if(number21==1) break;
   }
   cout<<c<<" ****/*/* */*/*/*/*/*/*/ "<<d<<endl;
   if(number1==0&&number2==0&&number5==0&&number4==0&&number3==0&&number6==0&&number7==0&&number8==0&&number9==0&&number10==0&&
   number11==0&&number12==0&&number13==0&&number14==0&&number15==0&&number16==0&&number17==0&&number18==0&&number19==0&&number20==0
   &&number21==0&&number22==0&&number23==0&&number24==0&&number25==0&&number26==0&&number27==0){
     c=rand()%MAX;
     d=rand()%MAX;
     /*for(int i=1;i<MAX-1;i++){
       for(int k=1;k<MAX-1;k++){
         if(board[i][k]=='#'){
           cout<<"-----==-=-=-=-=------=====-------"<<endl;
           if(board[i][k+1]==' '){
             c=i;
             d=k+1;
             num1=1;
             cout<<c<<"&^^^^^^&"<<d<<endl;
             break;
           }
           if(board[i][k-1]==' '){
             c=i;
             d=k-1;
             num1=1;
             break;
           }
           if(board[i+1][k]==' '){
             c=i+1;
             d=k;
             num1=1;
             break;
           }
           if(board[i-1][k]==' '){
             c=i-1;
             d=k;
             num1=1;
             break;
           }
           if(board[i-1][k-1]==' '){
             c=i-1;
             d=k-1;
             num1=1;
             break;
           }
           if(board[i+1][k+1]==' '){
             c=i+1;
             d=k+1;
             num1=1;
             break;
           }
           if(board[i+1][k-1]==' '){
             c=i+1;
             d=k-1;
             num1=1;
             break;
           }
           if(board[i-1][k+1]==' '){
             c=i-1;
             d=k+1;
             num1=1;
             break;
           }
         }
       }
       if(num1==1) break;
     }
     if(num1==0){
       c=rand()%MAX;
       d=rand()%MAX;
       cout<<c<<"-------"<<d<<endl;
     }*/
   }
   if(board[c][d]!=' ') {
     continue;
   }
   board[c][d]='#';
   break;
 }
 cout<<c<<"*************************"<<d<<endl;
}
void computerthink()
{
 int c,d;
 int num1=0;
 for(int i=1;i<MAX-1;i++){
   for(int k=1;k<MAX-1;k++){
     if(board[i][k]=='#'){
       if(board[i][k+1]==' '){
         c=i;
         d=k+1;
         num1=1;
         break;
       }
       if(board[i][k-1]==' '){
         c=i;
         d=k-1;
         num1=1;
         break;
       }
       if(board[i+1][k]==' '){
         c=i+1;
         d=k;
         num1=1;
         break;
       }
       if(board[i-1][k]==' '){
         c=i-1;
         d=k;
         num1=1;
         break;
       }
       if(board[i-1][k-1]==' '){
         c=i-1;
         d=k-1;
         num1=1;
         break;
       }
       if(board[i+1][k+1]==' '){
         c=i+1;
         d=k+1;
         num1=1;
         break;
       }
       if(board[i+1][k-1]){
         c=i+1;
         d=k-1;
         num1=1;
         break;
       }
       if(board[i-1][k+1]==' '){
         c=i-1;
         d=k+1;
         num1=1;
         break;
       }
     }
   }
   if(num1==1) break;
 }
}
char add()
{
 for(int i=0;i<MAX;i++){
   for(int k=0;k<MAX;k++){
     if(board[i][k]==' '){
       return 'q';
     }
   }
 }
 return 'p';
}
char search()
{
 int i=0,k=0;
//  cout<<i<<"**!!!*******!!!!!!!!"<<k<<endl;
 for(i=0;i<MAX;i++){
   for(k=0;k<MAX-4;k++){
     if(board[i][k]==board[i][k+1]&&board[i][k+1]==board[i][k+2]&&board[i][k+2]==board[i][k+3]
     &&board[i][k+3]==board[i][k+4]&&board[i][k]!=' '){
     //  cout<<i<<"**!!!"<<k<<endl;
       return board[i][k];
     }
   }
 }
//  cout<<i<<"!!!!!!*************!!!"<<k<<endl;
 for(k=0;k<MAX;k++){
   for(i=0;i<MAX-4;i++){
     if(board[i][k]==board[i+1][k]&&board[i+1][k]==board[i+2][k]&&board[i+2][k]==board[i+3][k]
     &&board[i+3][k]==board[i+4][k]&&board[i][k]!=' '){
     //  cout<<i<<"**!!!"<<k<<endl;
       return board[i][k];
     }
   }
 }
//  cout<<i<<"!!**!!!"<<k<<endl;
 for(i=0;i<MAX-4;i++){
   for(k=0;k<MAX-4;k++){
     if(board[i][k]==board[i+1][k+1]&&board[i+1][k+1]==board[i+2][k+2]&&board[i+2][k+2]==board[i+3][k+3]
     &&board[i+3][k+3]==board[i+4][k+4]&&board[i][k]!=' '){
     //  cout<<i<<"**!!!"<<k<<endl;
       return board[i][k];
     }
   }
 }
//  cout<<i<<"**!!!!!!!!!"<<k<<endl;
 for(i=4;i<MAX;i++){
   for(k=0;k<MAX-4;k++){
     if(board[i][k]==board[i-1][k+1]&&board[i-1][k+1]==board[i-2][k+2]&&board[i-2][k+2]==board[i-3][k+3]
     &&board[i-3][k+3]==board[i-4][k+4]&&board[i][k]!=' '){
     //  cout<<i<<"**!!!"<<k<<endl;
       return board[i][k];
     }
   }
 }
 //cout<<i<<"*!!!!*****!!!"<<k<<endl;
 return ' ';
}
void gamecomputer()
{
 char choose=' ';
 char check;
 fivechees();
 while(1){
   print();
   playermove();
   //AIcomputer();
   choose=search();
   //cout<<"*////**/"<<choose<<"/!!!*"<<endl;
   if(choose!=' '){
     check=add();
     if(check=='p'){
       break;
     }
   //  cout<<"*/*/*/"<<choose<<"//***//"<<endl;
     break;
   }
   //computermove();
   AIcomputer();
   choose=search();
 //  cout<<"*/////"<<choose<<"//////*"<<endl;
   if(choose!=' '){
     check=add();
     if(check=='p'){
       break;
     }
     break;
   }
 }
 print();
//  cout<<"//*//"<<choose<<"//*"<<endl;
 if(choose=='*'){
   cout<<"you win"<<endl;
 }
 if(choose=='#'){
   cout<<"rubish you lose"<<endl;
 }
 if(check=='p')
 cout<<"five five open"<<endl;
}
void gameeasycomputer()
{
 char choose=' ';
 char check;
 fivechees();
 while(1){
   print();
   playermove();
   choose=search();
   //cout<<"*////**/"<<choose<<"/!!!*"<<endl;
   if(choose!=' '){
     check=add();
     if(check=='p'){
       break;
     }
   //  cout<<"*/*/*/"<<choose<<"//***//"<<endl;
     break;
   }
   computermove();
 //  AIcomputer();
   choose=search();
 //  cout<<"*/////"<<choose<<"//////*"<<endl;
   if(choose!=' '){
     check=add();
     if(check=='p'){
       break;
     }
     break;
   }
 }
 print();
//  cout<<"//*//"<<choose<<"//*"<<endl;
 if(choose=='*'){
   cout<<"you win"<<endl;
 }
 if(choose=='#'){
   cout<<"rubish you lose"<<endl;
 }
 if(check=='p')
 cout<<"five five open"<<endl;
}
void gamemiddlecomputer()
{
 char choose=' ';
 char check;
 fivechees();
 while(1){
   print();
   playermove();
   choose=search();
   //cout<<"*////**/"<<choose<<"/!!!*"<<endl;
   if(choose!=' '){
     check=add();
     if(check=='p'){
       break;
     }
   //  cout<<"*/*/*/"<<choose<<"//***//"<<endl;
     break;
   }
   //computermove();
 //  AI1.0computer();
  AImiddlecomputer();
   choose=search();
 //  cout<<"*/////"<<choose<<"//////*"<<endl;
   if(choose!=' '){
     check=add();
     if(check=='p'){
       break;
     }
     break;
   }
 }
 print();
//  cout<<"//*//"<<choose<<"//*"<<endl;
 if(choose=='*'){
   cout<<"you win"<<endl;
 }
 if(choose=='#'){
   cout<<"rubish you lose"<<endl;
 }
 if(check=='p')
 cout<<"five five open"<<endl;
}
void gamepeople()
{
 char choose=' ';
 char check;
 fivechees();
 while(1){
   print();
   player1move();
   choose=search();
   if(choose!=' '){
     check=add();
     if(check=='p'){
       break;
     }
     break;
   }
   print();
   player2move();
   choose=search();
   if(choose!=' '){
     check=add();
     if(check=='p'){
       break;
     }
     break;
   }
 }
 print();
 if(choose=='*'){
   cout<<"player1 win"<<endl;
 }
 if(choose=='#'){
   cout<<"player2 win"<<endl;
 }
 if(check=='p')
 cout<<"five five open"<<endl;
}
int main()
{
 system("color F0");
 while(1){
   int decision=meun();
   if(decision==6){
     cout<<"你选择了人人对战"<<endl;
     gamepeople();
   }
   if(decision==1){
     cout<<"你选择了人与简单电脑对战"<<endl;
     gameeasycomputer();
   }
   if(decision==2){
     cout<<"你选择了人与中等电脑对战"<<endl;
     gamemiddlecomputer();
   }
   if(decision==3){
     cout<<"你选择了人与困难(正在开发健全中)电脑对战"<<endl;
     gamecomputer();
   }
   if(decision!=1&&decision!=2&&decision!=3&&decision!=4){
     cout<<"wrong input"<<endl;
     continue;
   }
 }
}
