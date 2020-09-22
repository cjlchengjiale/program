#include<iostream>
using namespace std;
void test()
{
	int a = 1;
	int b = 2;
  cout<<a<<" "<<b<<endl;
  //以值形式捕捉所有变量，以引用传递形式捕捉变量a
  auto fun = [=,&a](int num)->int{
    //a的值会改变
    a = 5;
    return a + b + num;
  };
  cout<<fun(10)<<" "<<a<<" "<<b<<endl;
}
int main()
{
  test();
  return 0;
}
