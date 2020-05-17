#include<iostream>
using namespace std;
namespace num
{
  int a = 0;
  void sum(int a,int b)
  {
    int c = a + b;
    std::cout<<c<<endl;
  }
  int d = 15;
}
namespace sum
{
  int a = 20;
  void sum1(int a,int b)
  {
    int c = a + b + b;
    std::cout<<c<<endl;
  }
  int d = 50;
}
//缺省
namespace unhave
{
  int add(int a = 1,int b = 1)
  {
    return a + b;
  }
  int add1(int a,int b = 2,int c = 3)
  {
    return a + b + c;
  }
}
void test1()//缺省
{
  int a = 10;
  int b = 20;
  cout<<unhave::add()<<endl;
  cout<<unhave::add1(a,b,a)<<endl;
  cout<<unhave::add(a)<<endl;
  cout<<unhave::add1(a)<<endl;
}
//重载
namespace addnum
{
  int add(int a,int b)
  {
    return a + b;
  }
  float add(float a,float b)
  {
    return a + b;
  }
  int add(int a,int b,int c)
  {
    return a + b + c;
  }
  int add(int a,char b)
  {
    return a + b;
  }
  int add(char a,int b)
  {
    return a + b;
  }
}
void test()//重载
{
  int a = 1;
  int b = 2;
  float c = 1.5;
  float d = 2.5;
  char e = 'a';
  char f = 'z';
  cout<<addnum::add(a,b)<<endl;
  cout<<addnum::add(c,d)<<endl;
  cout<<addnum::add(a,b,a)<<endl;
  cout<<addnum::add(a,e)<<endl;
  cout<<addnum::add(f,a)<<endl;
}

namespace getin
{
  void swap(int& a,int& b)
  {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int& add(int& a)
  {
    return ++a;
  }
}
//引用
void test2()
{
  int a = 10;
  int b = 50;
  swap(a,b);
  int& c = getin::add(a);
  cout<<a<<b<<c<<endl;
}
using namespace sum;
int main()
{
  cout<<num::a<<endl;
  int b = 10;
  int c = 15;
  num::sum(b,c);
  cout<<num::d<<endl;
  cout<<a<<endl;
  sum1(b,c);
  char num[10] = "abcdef";
  char* p = num;
  int i = 0;
  while(num[i]!='\0')
  {
    cout<<num[i];
    i++;
  }
  cout<<p<<endl;
  const char* q = "abcd";
  cout<<q<<endl;
  test2();
  return 0;
}
