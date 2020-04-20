#include<stdlib.h>
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
bool is(struct TreeNode* p,struct TreeNode* q)
{
    if(p==NULL&&q==NULL)
        return true;
    if(p==NULL||q==NULL)
        return false;
    return p->val==q->val
    &&is(p->left,q->right)
    &&is(p->right,q->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root==NULL)
        return true;
    return is(root->left,root->right);
}
