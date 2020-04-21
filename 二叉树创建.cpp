#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  struct node* left;
  struct node* right;
  char val;
}node;
node* creattree(char* str,int* idx)
{
  if(str[*idx] != '#')
  {
    //建立根节点
    node* root = (node*)malloc(sizeof(node));
    root->val = str[*idx];
    ++(*idx);
    root->left = creattree(str,idx);
    ++(*idx);
    root->right = creattree(str,idx);
    return root;
  }
  else
    return NULL;
}
void BinaryTreeDestory(node** root)
{
  node* cur = *root;
  if(cur)
  {
    BinaryTreeDestory(&cur->left);
    BinaryTreeDestory(&cur->right);
    free(cur);
    *root = NULL;
  }
}
int BinaryTreeSize(node* root)
{
  if(root == NULL)
    return 0;
  return BinaryTreeSize(root->left)+BinaryTreeSize(root->right)+1;
}
int BinaryTreeLeafSize(node* root)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL||root->right==NULL)
    return 1;
  return BinaryTreeLeafSize(root->left)+BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(node* root, int k)
{
  if(root==NULL)
    return 0;
  if(k==1)
    return 1;
  return BinaryTreeLevelKSize(root->left,k-1)+BinaryTreeLevelKSize(root->right,k-1);
}
node* BinaryTreeFind(node* root, char x)
{
  node* ret;
  if(root==NULL)
    return NULL;
  if(root->val == x)
    return root;
  ret = BinaryTreeFind(root->left,x);
  if(ret)
    return ret;
  return BinaryTreeFind(root->right,x);
}
void BinaryTreePrevOrder(node* root)
{
  if(root)
  {
    printf("%c ",root->val);
    BinaryTreePrevOrder(root->left);
    BinaryTreePrevOrder(root->right);
  }
}
void BinaryTreeInOrder(node* root)
{
  if(root)
  {
    BinaryTreePrevOrder(root->left);
    printf("%c ",root->val);
    BinaryTreePrevOrder(root->right);
  }
}
void BinaryTreePostOrder(node* root)
{
  if(root)
  {
    BinaryTreePrevOrder(root->left);
    BinaryTreePrevOrder(root->right);
    printf("%c ",root->val);
  }
}
