#include<iostream>
using namespace std;
class person
{
public:
  virtual void buy()
  {
    cout<<"all"<<endl;
  }
  virtual ~person()
  {
    cout<<"clear person"<<endl;
  }
};
class student : public person
{
public:
  virtual void buy()
  {
    cout<<"123"<<endl;
  }
  ~student()
  {
    cout<<"clear student"<<endl;
  }
};
void fun(person& p)
{
  p.buy();
}
void test()
{
  person a;
  student b;
  // fun(a);
  // fun(b);
}
int main()
{
  test();
}
