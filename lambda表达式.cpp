#include<iostream>
using namespace std;
void test()
{
	int a = 1;
	int b = 2;
  cout<<a<<" "<<b<<endl;
  //��ֵ��ʽ��׽���б����������ô�����ʽ��׽����a
  auto fun = [=,&a](int num)->int{
    //a��ֵ��ı�
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
