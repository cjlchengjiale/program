#include<iostream>
#include<map>
#include<vector>
using namespace std;
template<class T>
struct bstnode
{
  //typedef bstnode<T> node;
   T _val;
   bstnode<T>* _left;
   bstnode<T>* _right;
   bstnode(const T& val = T())
    :_val(val)
    ,_left(nullptr)
    ,_right(nullptr)
    {}
};
//template<class T>
// struct node
// {
//   //typedef root<T> node;
//   struct bstnode<T>* r;
// };
template<class T>
class bsttree
{
  typedef bstnode<T> node;
public:
  node* _root = nullptr;
public:
  bool insert(const T& val)
  {
    if(_root == nullptr)
    {
      _root = new node(val);
      return true;
    }
    node* cur = _root;
    node* parent  = nullptr;
    while(cur)
    {
      parent = cur;
      if(cur->_val == val)
        return false;
      else if(cur->_val < val)
        cur = cur->_right;
      else
        cur = cur->_left;
    }
    cur = new node(val);
    if(parent->_val < val)
      parent->_right  = cur;
    else
      parent->_left = cur;
    return true;
  }
  bool ersese(const T& val)
  {
    node* cur = _root;
    node* parent = nullptr;
    while(cur)
    {
      if(cur->_val == val)
        break;
      else if(cur->_val < val)
      {
        parent = cur;
        cur = cur->_right;
      }
      else
      {
        parent = cur;
        cur = cur->_left;
      }
    }
    if(cur == nullptr)
      return false;
    //删除
    //1.叶子
    if(cur->_left == cur->_right&&cur->_right == nullptr)
    {
      if(cur == _root)
      {
        _root = nullptr;
      }
      else
      {
        if(parent->_left == cur)
          parent->_left = nullptr;
        else
          parent->_right = nullptr;
      }
      delete cur;
    }
    else if(cur->_left == nullptr)
    {
      if(cur == _root)
      {
        _root = cur->_right;
      }
      else
      {
        if(parent->_left == cur)
          parent->_left = cur->_right;
        else
          parent->_right = cur->_right;
      }
      delete cur;
    }
    else if(cur->_right == nullptr)
    {
      if(cur == _root)
      {
        _root = cur->_left;
      }
      else
      {
        if(parent->_left == cur)
          parent->_left = cur->_left;
        else
          parent->_right = cur->_left;
      }
      delete cur;
    }
    else
    {
      //左右孩子都存在
      //找最左或最右结点
      //找右子树的最左节点
      node* leftmostchild = cur->_right;
      node* parent = cur;
      while(leftmostchild->_left)
      {
        parent = leftmostchild;
        leftmostchild = leftmostchild->_left;
      }
      //值替换
      cur->_val = leftmostchild->_val;
      //删除最左或最右结点
      if(parent->_left==leftmostchild)
        parent->_left = leftmostchild->_right;
      else
        parent->_right = leftmostchild->_right;
      //parent->_left = leftmostchild->_val;
      delete leftmostchild;
    }
    return true;
  }
  void print()
  {
    _inorder(_root);
  }
  void _inorder(node* root)
  {
    if(root)
    {
      _inorder(root->_left);
      cout<<root->_val<<" ";
      _inorder(root->_right);
    }
  }
  void destory(node* root)
  {
    if(root)
    {
      destory(root->_left);
      destory(root->_right);
      delete root;
    }
  }
  ~bsttree()
  {
    destory(_root);
  }
  void cpytree(node* root)
  {
    if(root)
    {
      insert(root->_val);
      cpytree(root->_left);
      cpytree(root->_right);
    }
  }
  bsttree()
  :_root(nullptr)
  {}
  bsttree(const bsttree<T>& bst)
  {
    cpytree(bst);
  }
};
