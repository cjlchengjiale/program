#include<iostream>
#include<string>
#include<vector>
using namespace std;
void test()
{
  string str;
  string str2("123");//����
  string str3 = "123";//��������
  string str4("0123456789",5);//01234
  string cpy(str3);
  string str5(str4,2,2);//23
  string str6(10,'a');//10���ַ�a��������
  //��ֵ�������str6�Ѿ�����
  str6 = str5;//���str5������
  str6 = "111";
  str6 = 'x';
  //����������������Ԫ�ص�һ��ͨ���÷�ʽ������֧�ֵ����������������������ʹ�÷�ʽ��ȫ��ͬ
  //begin������:��һ��Ԫ�ص�λ��
  //end������:���һ��Ԫ�ص���һ��λ��
  //�������ķ�Χ����ҿ�[begin,end)
  //��������ʹ�÷�ʽ��������ָ���ʹ�÷�ʽ������ͨ�������û�ȡԪ�ص����ݣ�����ͨ��++��--����δ֪���ƶ�
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
  //�������ı�����ʽ
  string::iterator it = str.begin();
  while(it != str.end())
  {
    //������������
    cout<<*it<<" ";
    //*it = 'a';
    ++it;//����������ƶ�
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
  //   //������������
  //   cout<<*it<<" ";
  //   *it = 'a';
  //   ++it;//����������ƶ�
  // }

  //���������
  //���﷨ʵ������˵,�ײ�ʵ���Ǵ�λʵ��
  //rendָ���һ��Ԫ��ǰ���λ��
  //rbeginָ�����һ��Ԫ�ص�λ��
  string::reverse_iterator rit = str.rbegin();
  string::reverse_iterator rit1 = str.rbegin();
  while(rit != str.rend())
  {
    cout<<*rit<<" ";
    //�������������ǰ�ƶ�
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
  int ret = str.size();//������Ч�ַ�����
  ret = str.length();//������Ч�ַ��ĸ���
  ret = str.capacity();//���Դ�ŵ������Ч�ַ��ĸ���
  size_t maxsize = str.max_size();
  str.clear();//����ַ�
}
void test4()
{
  string str("0123456789");
  //resize(n)��n����size �Ҵ���������������   ���Ŀռ�+����+�ͷ�Դ�ռ�+�µ�λ�ø�ֵ(���û�и���ֵ�ַ���Ĭ�Ϻ�\0)
  //��n<szie:ֻ�޸�size
  //��n>szie��nС���������������ݣ����µ�λ�� +�޸�size
  str.resize(20);
  int size = str.size();
}
void test5()
{
  string str("0123456789");
  int size = str.size();
  int cap = str.capacity();
//�������������޸�sizeҲ����������
  str.reserve(20);//����������һ�����޸�size�����ݣ���������������ǰ������
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

  s.shrink_to_fit();//��С����
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
