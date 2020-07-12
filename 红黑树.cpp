#include<iostream>
#include<utility>
using namespace std;
enum color
{
  BLACK,
  RED
};
template<class K,class V>
struct RBnode
{
  pair<K,V> _value;
  color _color;
  RBnode<K,V>* _parent;
  RBnode<K,V>* _left;
  RBnode<K,V>* _right;

  RBnode(const pair<K,V>& value = pair<K,V>())
    :_value(value)
    ,_color(RED)
    ,_parent(nullptr)
    ,_left(nullptr)
    ,_right(nullptr)
  {}

};
template<class K, class V>
class RBtree
{
public:
  typedef RBnode<K,V> node;
  RBtree()
    :_header(new node)
  {
    _header->_left = _header->_right = _header;
  }
  bool insert(const pair<K,V>& val)
  {
    //空树
    if(_header->_parent == nullptr)
    {
      node* root = new node(val);
      root->_color = BLACK;//根节点黑色
      _header->_parent = root;
      root->_parent = _header;
      _header->_left = root;
      _header->_right = root;
      return true;
    }
    //非空树
    node* cur = _header->_parent;
    node* parent = nullptr;
    while(cur)
    {
      parent = cur;
      if(cur->_value.first == val.first)
        return false;
      if(cur->_value.first<val.first)
      {
        cur = cur->_right;
      }
      else
      {
        cur = cur->_left;
      }
    }
    cur = new node(val);
    if(parent->_value.first<val.first)
      parent->_right = cur;
    else
      parent->_left = cur;
    cur->_parent = parent;
    //调整
    while(cur != _header->_parent && cur->_parent->_color == RED)
    {
      node* p = cur->_parent;
      node* g = p->_parent;
      if(g->_left == p)
      {
        node* u = g->_right;
        if(u&&u->_color == RED)
        {
          //修改颜色
          u->_color = p->_color = BLACK;
          g->_color = RED;
          //继续向上查看
          cur = g;
        }
        else
        {
          if(cur == p->_right)
          {
            rotatel(p);
            swap(cur,p);
          }
          //cur再p的左边 右旋
          rotater(g);
          //修改颜色
          p->_color = BLACK;
          g->_color = RED;
          break;
        }
      }
      if(g->_right == p)
      {
        node* u = g->_left;
        if(u&&u->_color == RED)
        {
          u->_color = p->_color = BLACK;
          g->_color = RED;
          cur = g;
        }
        else
        {
          if(cur==p->_left)
          {
            rotater(p);
            swap(cur,p);
          }
          rotatel(g);
          g->_color = RED;
          p->_color = BLACK;
          break;
        }
      }
    }
    _header->_parent->_color = BLACK;
    _header->_left = leftmost();
    _header->_right = rightmost();
    return true;
  }
  node* leftmost()
  {
    node* cur = _header->_parent;
    while(cur&&cur->_left)
      cur = cur->_left;
    return cur;
  }
  node* rightmost()
  {
    node* cur = _header->_parent;
    while(cur&&cur->_right)
      cur = cur->_right;
    return cur;
  }
  void rotater(node* parent)//右旋
  {
    node* subl = parent->_left;
    node* sublr = subl->_right;
    subl->_right = parent;
    parent->_left = sublr;
    if(sublr)
      sublr->_parent = parent;
    if(parent == _header->_parent)
    {
      _header->_parent = subl;
      subl->_parent = _header;
    }
    else
    {
      node* g = parent->_parent;
      subl->_parent = g;
      if(g->_left == parent)
        g->_left = subl;
      else
        g->_right = subl;
    }
    parent->_parent = subl;
  }
  void rotatel(node* parent)
  {
    node* subr = parent->_right;
    node* subrl = subr->_left;
    subr->_left = parent;
    parent->_right = subrl;
    if(subrl)
      subrl->_parent = parent;
    if(parent == _header->_parent)
    {
      _header->_parent = subr;
      subr->_parent = _header;
    }
    else
    {
      node* prev = parent->_parent;
      subr->_parent = prev;
      if(prev->_left == parent)
        prev->_left = subr;
      else
        prev->_right = subr;
    }
    parent->_parent = subr;
  }
  void p()
  {
    pprint(_header->_parent);
  }
  void pprint(node* cur)
  {
    //node* cur = _header->_parent;
    if(cur)
    {
      pprint(cur->_left);
      cout<<cur->_value.first<<" "<<cur->_value.second<<endl;
      pprint(cur->_right);
    }
  }
private:
  node* _header;
};
void test()
{
  RBtree<int,int> rbt;
  cout<<rbt.insert(make_pair(1,1));
  cout<<rbt.insert(make_pair(2,1));
  cout<<rbt.insert(make_pair(3,1));
  cout<<rbt.insert(make_pair(4,1));
  cout<<rbt.insert(make_pair(5,1));
  cout<<rbt.insert(make_pair(0,1));
  cout<<rbt.insert(make_pair(9,1));
  cout<<rbt.insert(make_pair(8,1));
  cout<<rbt.insert(make_pair(7,1));
  cout<<rbt.insert(make_pair(6,1))<<endl;
  rbt.p();
}
int main()
{
  test();
}
