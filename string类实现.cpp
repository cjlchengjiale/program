#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class String
{
public:
  String()//无参构造
  :_str(new char[16]),
  _size(0),
  _capacity(0)
  {
    _str[_size] = '\0';
  }
  String(const char* str)//带参构造
  {
    _size = strlen(str);
    _str = new char[_size + 1];
    strcpy(_str,str);
    _capacity = _size;
  }
    ~String()//析构函数
    {
      if(_str)
      {
        delete[] _str;
        _size = _capacity = 0;
        _str = nullptr;
      }
    }
    String(const String& str)
    :_str(new char[str._capacity + 1]),
    _size(str._size),
    _capacity(str._capacity)
    {
      strcpy(_str,str._str);
    }
    String& operator=(const String& str)
    {
      if(this != &str)
      {
        char* tmp = new char[str._capacity + 1];
        strcpy(tmp,str._str);
        delete[] _str;
        _str = tmp;
        _size = str._size;
        _capacity = str._capacity;
      }
      return *this;
    }
    void pushback(const char& ch)
    {
      if(_size == _capacity)
      {
        size_t newC = _capacity == 0?15:2*_capacity;
        reserve(newC);
      }
      _str[_size] = ch;
      ++_size;
      _str[_size] = '\0';
    }
    reserve(size_t n)
    {
      if(n > _capacity)
      {
        char* tmp = new char[n + 1];
        strcpy(tmp,_str);
        delete[] _str;
        _str = tmp;
        _capacity = n;
      }
    }
    typedef char* iterator;
    typedef const char* const_iterator;
    iterator begin()
    {
      return _str;
    }
    iterator end()
    {
      return _str + _size;
    }
    const_iterator begin() const
    {
      return _str;
    }
    const_iterator end() const
    {
      return _str + _size;
    }
    // char& operator[] (size_t pos)
    // {
    //   if(pos<_size)
    //     return _str(pos);
    // }
    // const char& operator[] (size_t pos) const
    // {
    //   if(pos<_size)
    //     return _str(pos);
    // }
    size_t size() const
    {
      return _size;
    }
    void Append(const char* str)
    {
      int len = strlen(str);
      if(_size + len >_capacity)
      {
        reserve(_size + len);
      }
      strcpy(_str + _size,str);
      _size+=len;
    }
    String& operator+=(const char& ch)
    {
      pushback(ch);
      return *this;
    }
    String& operator+=(const char* str)
    {
      Append(str);
      return *this;
    }
    void insert(size_t pos,const char& ch)
    {
      if(pos>_size)
        return ;
      if(_size == _capacity)
      {
        size_t newC = _capacity ==0?15:2 * _capacity;
      }
      size_t end = _size + 1;
      while(end>=pos)
      {
        _str[end] = _str[end - 1];
        --end;
      }
      _str[pos] = ch;
      ++_size;
    }
    void insert(size_t pos,const char* str)
    {
      int len = strlen(str);
      if(_size + len >_capacity)
      {
        reserve(_size + len);
      }
      size_t end = _size + len;
      while(end > pos + len - 1)
      {
        _str[end] = _str[end - len];
        --end;
      }
      for(int i = 0;i<len;++i)
      {
        _str[i + pos] = str[i];
      }
      _size += len;
    }
    void resize(size_t n,const char& ch = '\0')
    {
      if(n>_capacity)
      {
        reserve(n);
      }
      if(n>_size)
      {
        memset(_str + _size,ch,n - _size);
      }
      _size = n;
      _str[_size] = '\0';
    }
    void popback()
    {
      if(_size > 0)
      {
        _str[--_size] = '\0';
      }
    }
    void erase(size_t pos,size_t len)//删除子串
    {
      if(pos<_size)
      {
        if(pos + len >= _size)
        {
          _size = pos;
          _str[_size] = '\0';
        }
        else
        {
          for(int i = pos + len;i<=_size;++i)
          {
            _str[pos++] = _str[i];
          }
          _size = _size - len;
        }
      }
    }
    size_t find(const char* str)
    {
      char* ptr = strstr(_str,str);
      if(ptr)
        return ptr - _str;
      else
        return npos;
    }
    const char* c_str() const
    {
      return _str;
    }
private:
  char* _str;
  size_t _size;
  size_t _capacity;
  static const size_t npos;
};
const size_t String::npos = -1;
String operator+(const String& s,const String& str)
{
  String ret(s);
  ret+=str.c_str();
  return ret;
}
String operator+(const String& s,const char* str)
{
  String ret(s);
  ret+=str;
  return ret;
}
String operator+(const String& s,const char& ch)
{
  String ret(s);
  ret+=ch;
  return ret;
}
ostream& operator<<(ostream& cout,const String& str)
{
  for(const auto& ch:str)
    cout<<ch;
  return cout;
}
void test()
{
  String s("123456");
  String s1="dhkajdhak";
  s+="123456";
  s.insert(1,"a666666");
  String::iterator it = s.begin();
  for(char& ch:s)
  {
    cout<<ch;
  }
  cout<<endl;
  int a = s.find("a66");
  cout<<a<<endl;
}
int main()
{
  string s;
  test();
}
