#include<iostream>
#include<cstring>
using namespace std;
template <class T>
class Vector
{
public:
     Vector()
     :_start(nullptr),
     _finish(nullptr),
     _eos(nullptr)
     {}
     size_t size() const
     {
       return _finish - _start;
     }
     size_t capacity() const
     {
       return _eos - _start;
     }
     void pushback(const T& val)
     {
       if(_finish == _eos)
       {
         size_t newc = capacity() == 0?1:2*capacity();
         reserve(newc);
       }
       *_finish = val;
       ++_finish;
     }
    void reserve(size_t n)
     {
       if(n > capacity())
       {
         size_t oldsize = size();
         //开空间
          T* tmp = new T[n];
         //做拷贝,浅拷贝
          //memcpy(tmp,_start,sizeof(T)*size());
          //深拷贝
          for(int i = 0;i<size();i++)
          {
            tmp[i] = _start[i];
          }
         //释放原有空间
         delete[] _start;
         //更新容量
         _start = tmp;
         _finish = _start + oldsize;
         _eos = _start + n;
       }
     }
     T& operator[](size_t pos)
     {
       if(pos < size())
       {
         return _start[pos];
       }
     }
     const T& operator[](size_t pos) const
     {
       if(pos < size())
       {
         return _start[pos];
       }
     }
     typedef T* iterator;//可读可写
     typedef const T* const_iterator;//只读
     iterator begin()
     {
       return _start;
     }
     iterator end()
     {
       return _finish;
     }
     const_iterator begin() const
     {
       return _start;
     }
     const_iterator end() const
     {
       return _finish;
     }
     void resize(size_t n,const T& val = T())
     {
       if(n>capacity())
       {
         reserve(n);
       }
       if(n>size())
       {
         while(_finish != _start + n)
         {
           *_finish = val;
           ++_finish;
         }
       }
       _finish = _start + n;
     }
     void insert(iterator pos,const T& val)
     {
       if(_finish == _eos)
       {
         //保存当前位置与原始位置偏移量
         int len = pos -_start;
         size_t newc = capacity() ==0?1:2*capacity();
         reserve(newc);
         pos = _start + len;
       }
       if(pos >= _start && pos<= _finish)
       {
         iterator end = _finish;
         while(end>pos)
         {
           *end = *(end - 1);
           --end;
         }
         *pos = val;
         ++_finish;
       }
     }
     iterator erase(iterator pos)
     {
       if(pos>=_start&&pos<_finish)
       {
         iterator begin = pos;
         while(begin != _finish)
         {
           *begin = *(begin + 1);
           ++begin;
         }
         return pos;
       }
     }
private:
  T* _start;
  T* _finish;
  T* _eos;
};
template <class T>
void print(const Vector<T>& v)
{
  for(int i = 0;i<v.size();i++)
  {
    cout<<v[i]<<" ";
  }
}
void test()
{
  Vector<string> str;
  str.resize(5);
  Vector<string>::iterator it = str.begin();
  while(it!=str.end())
  {
    *it = 'a';
    cout<<*it<<" ";
    it++;
  }
  cout<<endl;
  for(string& s:str)
  {
    cout<<s<<" ";
  }
}
void test1()
{
  Vector<int> v;
  v.insert(v.end(),1);
  print(v);
}
void test2()
{
  Vector<int> v;
  v.insert(v.end(),1);
  v.insert(v.end(),2);
  v.insert(v.end(),3);
  v.insert(v.end(),4);
  v.insert(v.end(),5);
  Vector<int>::iterator it = v.begin();
  while(it !=v.end())
  {
    if(*it%2==1)
    {
      it = v.erase(it);
      ++it;
    }
    else{
      ++it;
    }
  }
  print(v);
}
int main()
{
  // test();
  // test1();
  test2();
}
