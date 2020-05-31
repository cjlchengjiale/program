#include<iostream>
#include<string>
#include<vector>
using namespace std;
void test()
{
  string str;
  string str2("123");//常用
  string str3 = "123";//单参类型
  string str4("0123456789",5);//01234
  string cpy(str3);
  string str5(str4,2,2);//23
  string str6(10,'a');//10个字符a创建对象
  //赋值运算符，str6已经存在
  str6 = str5;//变成str5的内容
  str6 = "111";
  str6 = 'x';
  //迭代器：访问容器元素的一种通过用方式，所有支持迭代器的容器，其迭代器的使用方式完全相同
  //begin迭代器:第一个元素的位置
  //end迭代器:最后一个元素的下一个位置
  //迭代器的范围左闭右开[begin,end)
  //迭代器的使用方式：类似于指针的使用方式，可以通过解引用获取元素的内容，可以通过++，--进行未知的移动
  cout<<str2<<endl;
  cout<<str3<<endl;
  cout<<str4<<endl;
  cout<<str5<<endl;
  cout<<str6<<endl;
  cout<<str<<endl;
}
void test2()
{
  string str("0123456789");
  //迭代器的遍历方式
  string::iterator it = str.begin();
  while(it != str.end())
  {
    //迭代器解引用
    cout<<*it<<" ";
    //*it = 'a';
    ++it;//迭代器向后移动
  }
  cout<<endl;
  // vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
  // vector<int>::iterator vit = vec.begin();
  // while(vit != vec.end())
  // {
  //   cout<<*vit<<" ";
  //   vit++;
  // }
  // it = str.begin();
  // while(it != str.end())
  // {
  //   //迭代器解引用
  //   cout<<*it<<" ";
  //   *it = 'a';
  //   ++it;//迭代器向后移动
  // }

  //反向迭代器
  //从语法实现上来说,底层实现是错位实现
  //rend指向第一个元素前面的位置
  //rbegin指向最后一个元素的位置
  string::reverse_iterator rit = str.rbegin();
  string::reverse_iterator rit1 = str.rbegin();
  while(rit != str.rend())
  {
    cout<<*rit<<" ";
    //反向迭代器，向前移动
    ++rit;
  }
  cout<<endl;
  string::const_iterator cit = str.begin();
  string::const_iterator cit1 = str.cbegin();
  while(cit1 != str.cend())
  {
    cout<<*cit1<<" ";
    cit1++;
  }
  cout<<endl;
}
void printstring(const string& str)
{
  string::const_iterator it = str.begin();
  while(it != str.end())
  {
    cout<<*it<<" ";
    it++;
  }
}
void test3()
{
  string str("0123456789");
  int ret = str.size();//返回有效字符个数
  ret = str.length();//返回有效字符的个数
  ret = str.capacity();//可以存放的最大有效字符的个数
  size_t maxsize = str.max_size();
  str.clear();//清空字符
}
void test4()
{
  string str("0123456789");
  //resize(n)当n大于size 且大于容量，会增容   开心空间+拷贝+释放源空间+新的位置赋值(如果没有给赋值字符，默认黑\0)
  //当n<szie:只修改size
  //当n>szie但n小于容量，不会增容，给新的位置 +修改size
  str.resize(20);
  int size = str.size();
}
void test5()
{
  string str("0123456789");
  int size = str.size();
  int cap = str.capacity();
//增加容量，不修改size也不减少容量
  str.reserve(20);//调整容量，一定不修改size和内容，如果减少容量，是按需减少
  size = str.size();
  str.capacity();

  str.reserve(5);
  size = str.size();
  str.capacity();

}
void test6()
{
  string s;
  s.reserve(100);
  int size = s.size();
  int cap = s.capacity();

  s.shrink_to_fit();//缩小容量
  size = s.size();
  cap = s.capacity();
}
int main()
{
  //test();
  //test2();
  test3();
  return 0;
}
