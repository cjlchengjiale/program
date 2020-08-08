#include<iostream>
#include<vector>
using namespace std;
class uninfindset
{
public:
  uninfindset(size_t n)
  {
    _vec.resize(n,-1);
  }
  int find_root(int idx)
  {
    while(idx >= 0)
      idx = _vec[idx];
  }
  bool is_same_root(int x1,int x2)
  {
    int root1 = find_root(x1);
    int root2 = find_root(x2);

    if(root1 == root2)  return true;
    else return false;
  }
  bool Union(int x1,int x2)
  {
    int root1 = find_root(x1);
    int root2 = find_root(x2);
    //root为根额下标
    if(root1 == root2)  return false;
    _vec[root2] = root1;
    _vec[root1]+=_vec[root2];
    return true;
  }
  size_t root_num()
  {
    size_t num = 0;
    for(auto& e:_vec)
    {
      if(e<0) num++;
    }
    return num;
  }
private:
  vector<int> _vec;
};
