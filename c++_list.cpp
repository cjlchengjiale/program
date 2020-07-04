#include<iostream>
using namespace std;
template<class T>
struct listnode
{
  T value;
  listnode<T>* _next;
  listnode<T>* _prev;
  listnode(const T& val = T())
  :value(val)
  ,_next(nullptr)
  ,_prev(nullptr)
  {}
};
template<class T>
struct listiterator
{
  typedef listnode<T> Node;
public:
  listiterator()
  :_node(_header)
  {}
  Node* _node;
};
template<class T>
class List
{
  typedef listnode<T> Node;
  typedef listiterator<T> iterator;
public:
  List()
  :_header(new Node)
  {
    _header->_next = _header;
    _header->_prev = _header;
  }
  // void creat()
  // {
  //   _header->_next = _header;
  //   _header->_prev = _header;
  // }
  void pushback(const T& val)
  {
    //cout<<"2"<<endl;
    Node* cur = new Node(val);
    Node* prev = _header->_prev;
    //cout<<"4"<<endl;
    cur->_next = _header;
  //  cout<<"6"<<endl;
    prev->_next = cur;
  //  cout<<"5"<<endl;
    cur->_prev = prev;
    _header->_prev = cur;
  //  cout<<"3"<<endl;
  }
  void pushfront(const T& val)
  {
    insert(begin(),val);
  }
  void popback()
  {
    erase(--end());
  }
  void popfront()
  {
    erase(begin());
  }
  void insert(iterator pos,const T& val)
  {
    Node* cur = new Node(val);
    Node* node = pos._node;
    node* prev = node->_prev;
    prev->_next = cur;
    cur->_prev = prev;
    cur->_next = node;
    node->_prev = cur;
  }
  iterator erase(iterator pos)
  {
    //不能删除头结点
    if(pos != end())
    {
      Node* node = pos._node;
      Node* prev = node->_prev;
      Node* next = node->_next;
      delete node;
      prev->_next = next;
      next->_prev = prev;
      return iterator(next);
    }
    return pos;
  }
  size_t size() const
  {
    size_t count = 0;
    Node* p = _header->_next;
    while(p != _header)
    {
      p = p->_next;
      ++count;
    }
    return count;
  }
  ~List()
  {
    if(_header)
    {
      clear();
      delete _header;
      _header = nullptr;
    }
  }
  void clear()
  {
    //清空所有非头结点
    Node* cur = _header->_next;
    while(cur != _header)
    {
      Node* next = cur->_next;
      delete cur;
      cur = next;
    }
    _header->_next = _header->_prev = _header;
  }
  List(const List<T>& lst)
  :_header(new Node)
  {
    _header->_next = _header->_prev = _header;
    for(const auto& e:lst)
    {
      pushback(e);
    }
  }
  List<T>& operator=(List<T> lst)
  {
    swap(_header,lst._header);
    return *this;
  }
  void print()
  {
    Node* p = _header->_next;
    while(p!=_header)
    {
      cout<<p->value<<" ";
      p = p->_next;
    }
  }
private:
  Node* _header;
};
template<class T>
void printlist(const List<T>& ls)
{

}
int main()
{
  List<int> lst;
  lst.pushback(1);
  lst.pushback(2);
  lst.pushback(3);
  lst.pushback(4);
  lst.print();
  cout<<lst.size()<<endl;
}
