#include<iostream>
#include<stdio.h>
#include<windows.h>
using namespace std;
int whatyear(int year)
{
  if((year%4==0&&year%100!=0)||year%400==0)
    return 1;
  return 0;
}
int leapyearsum(int year)
{
  int sum = 0;
  for(int i = 2000;i<year;i++)
  {
    if((i%4==0&&i%100!=0)||i%400==0)
      sum++;
  }
  return sum;
}
void day()
{
  int days[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                  {31,29,31,30,31,30,31,31,30,31,30,31}};
  int year = 0;
  int mouth = 0;
  int day = 0;
  int choice = 0;
  int num = 0;
  int sum = 0;
  int day1 = 0;
  int day2 = 0;
  again:
  cout<<"please input year mouth"<<endl;
  cin>>year>>mouth;
  if(year<2000||mouth>12||mouth<1)
  {
    cout<<"input error after 1 second please input again"<<endl;
    Sleep(1000);
    system("CLS");
    goto again;
  }
  day1 = day;
  choice = whatyear(year);
  num = year-2000;
  sum = leapyearsum(year);
  num = num - sum;
  day = sum*366+num*365;
  if(choice==1)
    cout<<"闰年"<<endl;
  cout<<"平年"<<endl;
  if(choice == 1)
  {
    for(int i = 0;i<mouth-1;i++)
    {
      day += days[choice][i];
    }
    day = (day+5)%7;
    day2 = day;
    cout<<"     "<<year<<"年"<<" "<<mouth<<"月"<<endl;
    cout<<" 一 "<<"二 "<<"三 "<<"四 "<<"五 "<<"六 "<<"日"<<endl;
    for(int i = 1;i<=days[choice][mouth-1]+day;i++)
    {
      if(day2!=0)
      {
        cout<<"   ";
        day2--;
      }
      else
      {
        printf("%3d",i-day);
        if(i%7==0)
        cout<<endl;
      }
    }
    cout<<endl;
  }
  if(choice == 0)
  {
    for(int i = 0;i<mouth-1;i++)
    {
      day += days[choice][i];
    }
    day = (day+5)%7;
    day2 = day;
    cout<<"     "<<year<<"年"<<" "<<mouth<<"月"<<endl;
    cout<<" 一 "<<"二 "<<"三 "<<"四 "<<"五 "<<"六 "<<"日"<<endl;
    for(int i = 1;i<=days[choice][mouth-1]+day;i++)
    {
      if(day2!=0)
      {
        cout<<"   ";
        day2--;
      }
      else
      {
        printf("%3d",i-day);
        if(i%7==0)
        cout<<endl;
      }
    }
    cout<<endl;
  }
}

int main()
{
  day();
  return 0;
}
