//开散列：指针数组+单链表
#include<vector>
#include<iostream>
using namespace std;
template<class K>
struct keyofvalue
{
  const K& operator()(const K& value)
  {
    return value;
  }
};
template<class V>
struct hashnode
{
  V _value;
  hashnode<V>* _next;
  hashnode(const V& val = V())
    :_value(val)
    ,_next(nullptr)
  {}
};
template<class K,class V,class keyofvalue>
class HashTable;
template<class K,class V,class keyofvalue>
struct hashiterator
{
  typedef hashnode<V> Node;
  typedef hashiterator<K,V,keyofvalue> self;
  typedef HashTable<K,V,keyofvalue> HT;
  Node* _node;
  HT* _ht;
  hashiterator(Node* node)
    :_node(node)
    ,_ht(nullptr)
  {}
  V& operator*()
  {
    return _node->_value;
  }
  V* operator->()
  {
    return &_node->_value;
  }
  bool operator!=(const self& it)
  {
    return _node != it._node;
  }
  self& operator++()
  {
    if(_node->_next)
      _node=_node->_next;
    else
    {
      //定位当前节点再哈希表中的位置
      keyofvalue kov;
      int idx = kov(_node->_value)%_ht->_table.size();
      ++idx;
      Node* cur = _ht->_table[idx];
      for(;idx<_ht->_size();idx++)
      {
        if(_ht->_table[idx])
        {
          _node = _ht->_table[idx];
          break;
        }
      }
      //判断是否找到一个非空链表头
      if(idx == _ht->size())
        _node = nullptr;
    }
    return *this;
  }
};
template<class K,class V,class keyofvalue>
class HashTable
{
public:
  template<class K,class V,class keyofvalue>
  friend struct hashiterator;
  typedef hashnode<V> node;
  typedef hashiterator<K,V,keyofvalue> iterator;
  iterator begin()
  {
    for(int i = 0;i<_table.size();i++)
    {
      node* cur = _table[i];
      if(cur)
        return iterator(cur,this);
    }
    return iterator(nullptr,this);
  }
  iterator end()
  {
    return iterator(nullptr,this);
  }
  bool insert(const V& value)
  {
    checkcapacity();
    keyofvalue kov;
    int idx = kov(value)%_table.size();
    node* cur = _table[idx];
    while(cur)
    {
      if(kov(cur->_value) == kov(value))
        return false;
      cur = cur->_next;
    }
    //插入
    cur = new node(value);
    cur->_next = _table[idx];
    _table[idx] = cur;
    ++_size;
    return true;
  }
  void checkcapacity()
  {
    if(_size == _table.size())
    {
      size_t newsize = _size ==0?5:2*_size;
      vector<node*> newht;
      newht.resize(newsize);
      keyofvalue kov;
      //遍历旧表中的非空单链表
      for(int i = 0;i<_table.size();i++)
      {
        node* cur = _table[i];
        while(cur)
        {
          //记录下一个位置
          node* next = cur->_next;
          //计算新的位置
          int idx = kov(cur->_value) % newht.size();
          //头插
          cur->_next = newht[idx];
          newht[idx] = cur;
          //处理下一个元素
          cur = next;
        }
        _table[i] = nullptr;
      }
    _table.swap(newht);
    }
  }
  node* find(const K& key)
  {
    if(_table.size()==0)
      return nullptr;
    int idx = key%_table.size();
    node* cur = _table[idx];
    keyofvalue kov;
    while(cur)
    {
      if(kov(cur->_value) == key)
        return cur;
      cur = cur->_next;
    }
    return nullptr;
  }
  bool erase(const K& key)
  {
    int idx = key%_table.size();
    node *cur = _table[idx];
    node* prev = nullptr;
    keyofvalue kov;
    if(cur==nullptr)
      return false;
    while(cur)
    {
      if(kov(_table[idx]->_value) == key)
      {
        cur = _table[idx]->_next;
        delete _table[idx];
        _table[idx] = cur;
        --_size;
        return true;
      }
      else
      {
        prev = cur;
        cur = cur->_next;
        if(kov(cur->_value) == key)
        {
          prev->_next = cur->_next;
          delete cur;
          --_size;
          return true;
        }
      }
    }
    return false;
  }
  void print()
  {
    for(int i = 0;i<_table.size();i++)
    {
      node* cur = _table[i];
      cout<<i<<"--->";
      while(cur)
      {
        cout<<cur->_value<<" ";
        cur = cur->_next;
      }
      cout<<endl;
    }
  }
private:
  vector<node*> _table;
  size_t _size = 0;
};
//unorderedmap
template<class K,class V>
class unorderedmap
{
  struct mapkeyofvalue
  {
    const K& operator()(const pair<K,V>& value)
    {
      return value.first;
    }
  };
public:
  bool insert(const pair<K,V>& value)
  {
    return _ht.insert(value);
  }
private:
  HashTable<int,pair<K,V>,mapkeyofvalue> _ht;
};
//unorderedset
template<class K>
class unorderedset
{
  struct setkeyofvalue
  {
    const K& operator()(const K& value)
    {
      return value;
    }
  };
public:
  bool insert(const K& value)
  {
    return _ht.insert(value);
  }
private:
  HashTable<K,K,setkeyofvalue> _ht;
};
int main()
{
  HashTable<int ,int ,keyofvalue<int>> ht;
  ht.insert(1);
  ht.insert(12);
  ht.insert(15);
  ht.insert(21);
  ht.insert(5);
  ht.insert(25);
  ht.insert(8);
  ht.insert(48);
  ht.insert(31);
  ht.insert(40);
  ht.print();
  ht.erase(5);
  ht.erase(6);
  ht.print();
}
