#include<iostream>
#include<utility>
#include<time.h>
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
    //����
    if(_header->_parent == nullptr)
    {
      node* root = new node(val);
      root->_color = BLACK;//���ڵ��ɫ
      _header->_parent = root;
      root->_parent = _header;
      _header->_left = root;
      _header->_right = root;
      return true;
    }
    //�ǿ���
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
    //����
    while(cur != _header->_parent && cur->_parent->_color == RED)
    {
      node* p = cur->_parent;
      node* g = p->_parent;
      if(g->_left == p)
      {
        node* u = g->_right;
        if(u&&u->_color == RED)
        {
          //�޸���ɫ
          u->_color = p->_color = BLACK;
          g->_color = RED;
          //�������ϲ鿴
          cur = g;
        }
        else
        {
          if(cur == p->_right)
          {
            rotatel(p);
            swap(cur,p);
          }
          //cur��p����� ����
          rotater(g);
          //�޸���ɫ
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
  void rotater(node* parent)//����
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
  bool isrbtree()
  {
    node* root = _header->_parent;
    if(root == nullptr)
      return true;
    if(root->_color != BLACK)
      return false;
    int count = 0;
    node*cur = root;
    while(cur)
    {
      if(cur->_color == BLACK)
        ++count;
      cur = cur->_left;
    }
    int curcount = 0;
    return is_rbtree(root,count,curcount);
  }
  bool is_rbtree(node* root,int blackcount,int curcount)
  {
    if(root == nullptr)
    {
      if(blackcount != curcount)
        return false;
      return true;
    }
    if(root->_color == BLACK)
      ++curcount;
    node* parent = root->_parent;
    if(parent&&parent->_color == RED &&root->_color == RED)
    {
      cout<<"have red also"<<endl;
      return false;
    }
    return is_rbtree(root->_left,blackcount,curcount)
            &&is_rbtree(root->_right,blackcount,curcount);
  }
private:
  node* _header;
};
void test()
{
  RBtree<int,int> rbt;
  int n = 0;
  cin>>n;
  for(int i = 0;i<n;i++)
  {
    int tmp = rand()%10000;
    rbt.insert(make_pair(i,tmp));
  }
  cout<<rbt.isrbtree();
}
int main()
{
  //srand((unsigned int)time(NULL));
  test();
  system("pause");
}