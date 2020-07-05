#include<iostream>
#include<set>
#include<map>
#include<vector>
//#include<function>
using namespace std;
void print(set<int>& st)
{
  set<int>::iterator it = st.begin();
  while(it != st.end())
  {
    cout<<*it<<" ";
    it++;
  }
  cout<<endl;
}
void test()
{
  set<int> s;//空set
  int array[5] = {1,3,2,4,5};
  set<int> s2(array,array+5);
  int array1[5] = {11,2,3,7,16};
  set<int> cpy(s2);
  //迭代器，无论const是否修饰都不能改变set里面的值
  print(s2);
  //插入不会插入重复类型
  s2.insert(12);
  print(s2);
  s2.insert(s2.begin(),15);
  print(s2);
  s2.insert(array1,array1+5);
  print(s2);
  s2.erase(15);
  print(s2);
  s2.erase(s2.begin());//删除最左结点，而不是根也不是第一个插入的结点
  print(s2);
  s2.erase(--s2.end());
  print(s2);
  //s2.erase(s2.begin(),s2.end());//左闭右开的删除
  //删除会导致当前迭代器位置失效
  // auto it = s2.begin();
  // it = s2.erase(it);
  // cout<<*it;
  swap(s2,cpy);//交换两个set的内容
  print(s2);
  print(cpy);
  //find接口
  set<int>::iterator it = s2.find(3);
  if(it != s2.end())
    cout<<*it<<endl;
  else
    cout<<"no find"<<endl;
  it = s2.find(33);
  if(it != s2.end())
    cout<<*it<<endl;
  else
    cout<<"no find"<<endl;
  cout<<s2.count(3)<<endl;
  cout<<s2.count(300)<<endl;
}
void testmap()
{
  map<int,int> m;
  vector<int> v;
  map<vector<int>,int> m1;
  make_pair(2,3);
  for(int i = 10;i>=0;i--)
  {
    m1.insert(make_pair(vector<int>,3));
  }
  map<int,int>::iterator it = m.begin();
  while(it != m.end())
  {
    cout<<it->first<<"----"<<it->second<<endl;
    it++;
  }
  cout<<endl;
  m.find(5);
}
int main()
{
  // test();
  testmap();
}
