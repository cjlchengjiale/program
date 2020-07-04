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
void test7()
{
  string str("123");
  // str.push_back('a');
  // str.append(2,'b');
  // str.append("abcdefg");
  // string str2;
  // str2.append(str);
  // string s3;
  // s3.append(str,3,2);//第三个位置开始插入两个
  string s4;
  s4+='8';
  s4+="666";
  s4+=str;
  string::iterator it = s4.begin();
  while(it != s4.end())
  {
    cout<<*it;
    ++it;
  }
  cout<<endl;
}
void test9()
{
  string s = "0123456789";
  s.replace(3,5,"aa");//012aa89
  cout<<s<<endl;
  s.replace(s.begin() + 1,s.end() - 1,"a");//0a9
  cout<<s;

  string s2("abc");
  s2.swap(s);//交换两个字符串；
  swap(s2,s);

}
void test10()
{
  string str = "aaaabbaaaaa.txt";
  size_t size = str.find("abba");//从头开始查找
  size_t pos = str.rfind('.');//从后开始查找
  cout<<size<<" "<<pos<<endl;
  string str2 = str.substr(pos + 1,str.size() - pos - 1);
  cout<<str2<<endl;
}
void test11()
{
  string s = "9";
  string s2 = "123";
  string s3 = "1234";
  bool ret = s>s2;//比较字符串大小,比较ASII值比较大小，和长度无关，从的哥字符开始，逐字符比较，
  cout<<ret<<endl;
}
void test12()
{
  string s;
  //cin>>s;
  getline(cin,s);
  cout<<s<<endl;
  int i = 0;
  int k = 0;
  while(s[i]!='\0')
  {
    if(s[i]==' ')
    {
      k++;
    }
    i++;
  }
  //getline(cin,s,',');//可读取换行，遇到‘,’，结束
  cout<<s<<endl<<k<<endl;
}
bool ischar(const char& ch)
{
  return (ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z');
}
string reverseOnlyLetters(string S)
{
  int begin = 0;
  int end = S.size() - 1;
  while(begin<end)
  {
    while(begin<end&&!ischar(S[begin]))
      ++begin;
    while(begin<end&&!ischar(S[end]))
      --end;
    if(begin<end)
    {
      swap(S[begin],S[end]);
      ++begin;
      --end;
    }
  }
}
int firstUniqChar(string s)
{
  int num[26] = {0};
  for(const auto& ch:s)
  {
    num[ch-'a']++;
  }
  for(int i = 0;i<s.size();i++)
  {
    if(num[s[i] - 'a']==1)
      return i;
  }
  return -1;
}
bool isvalid(const char& ch)
{
  return (ch>='a'&&ch<='z')||(ch>='0'&&ch<='9');
}
bool isPslindrome(string s)
{
  if(s.empty())
    return true;
    for(char& ch:s)
    {
      if(ch>='A'&&ch<='Z')
        ch += 32;
    }
    int begin = 0;
    int end = s.size() - 1;
    while(begin < end)
    {
      while(begin < end && isvalid(s[begin]))
        ++begin;
      while(begin < end && isvalid(s[end]))
        --end;
        if(s[begin] != s[end])
        {
            return false;
        }
    }
    return true;
}
string addStrings(string num1,string num2)
{
  int begin1 = num1.size() - 1;
  int begin2 = num2.size() - 1;
  int step = 0;
  string sum;
  while(begin1>=0||begin2>=0)
  {
    int cur = step;
    if(begin1>=0)
      cur += num1[begin1--] - '0';
    if(begin2 >= 0)
      cur += num2[begin2--] - '0';
    if(cur>9)
    {
      step = 1;
      cur -= 10;
    }
    else
      step = 0;
    sum.insert(0,1,cur + '0');
  }
  if(step == 1)
    sum.insert(0,1,'1');
  return sum;
}
int main()
{
  //test();
  //test2();
  // test6();
  // test7();
   // test9();
  test10();
  // test11();
  // test12();
  return 0;
}
