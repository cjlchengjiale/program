#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  struct node* left;
  struct node* right;
  char val;
}node;
typedef node* type;
typedef node* qtype;
typedef struct stack
{
  type *data;//����
  size_t size;//ջ�Ĵ�С
  size_t capacity;//ջ������
}stack;
typedef struct qnode
{
  struct qnode* next;
  qtype data;
}qnode;
typedef struct queue
{
  qnode* front;
  qnode* rear;
  int size;
}queue;
void queueinit(queue* q)
{
  q->front = q->rear = NULL;
  q->size = 0;
}
qnode* creatnode(qtype data)
{
  qnode* node = (qnode*)malloc(sizeof(qnode));
  node->data = data;
  node->next = NULL;
  return node;
}
void queuepush(queue* q,qtype data)
{
  qnode* node = creatnode(data);
  if(q->front==NULL)
    q->front = q->rear = node;
  else{
    q->rear->next = node;
    q->rear = node;
  }
  ++q->size;
}
void queuepop(queue* q)
{
  if(q->front)
  {
      qnode* next = q->front->next;
      free(q->front);
      q->front = next;
      if(q->front == NULL)
        q->rear = NULL;
        --q->size;
  }
}
qtype queuefront(queue* q)
{
  //if(q->front)
    return q->front->data;
}
qtype queueback(queue* q)
{
  //if(q->rear)
    return q->rear->data;
}
size_t queuesize(queue* q)
{
  /*int len = 0;
  qnode* p = q->front;
  while(p)
  {
    ++len;
    p = p->next;
  }*/
  return q->size;
}
int queueempty(queue* q)
{
  if(q->front==NULL)
    return 1;
  return 0;
}
void queuedestory(queue* q)
{
  qnode* p = q->front;
  while(p)
  {
    qnode* next = p->next;
    free(p);
    p = next;
  }
  q->front = q->rear = NULL;
  q->size = 0;
}
//ջ�ĳ�ʼ��
void stackinit(stack* st,size_t n)
{
  st->data = (type*)malloc(sizeof(type) * n);
  st->size = 0;
  st->capacity = n;
}
//��ջ
void stackpush(stack* st,type data)
{
  //�ж��Ƿ���Ҫ����
  if(st->size==st->capacity){
    st->capacity*=2;
    st->data = (type*)realloc(st->data,sizeof(type) * st->capacity);
  }
  //��ջ
  st->data[st->size++] = data;
}
//��ջ
void stackpop(stack* st)
{
  //��ǰ��С��һ
  if(st->size)
  --st->size;
}
//ȡջ��Ԫ��
type stacktop(stack* st)
{
  return st->data[st->size-1];
}
//ȡ��ǰջ�Ĵ�С
size_t stacksize(stack* st)
{
  return st->size;
}
//�ж�ջ�Ƿ�Ϊ��
int stackempty(stack* st)
{
  if(st->size==0)
    return 1;//��
  return 0;//�ǿ�
}
//����ջ
void stackdestory(stack* st)
{
  free(st->data);
  st->data = NULL;
  st->size = st->capacity = 0;
}
node* creattree(char* str,int* idx)
{
  if(str[*idx] != '#')
  {
    //�������ڵ�
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
//�ǵݹ��������
void BinaryTreePrevOrder(node* root)
{
  stack st;
  stackinit(&st,10);
  node* cur = root;
  node* top;
  while(cur||stackempty(&st)!= 1)
  {
    while(cur)
    {
      printf("%c ",cur->val);
      stackpush(&st,cur);
      cur = cur->left;
    }
    top = stacktop(&st);
    stackpop(&st);
    cur = top->right;
  }
}
//�ǵݹ��������
void BinaryTreeInOrder(node* root)
{
  stack st;
  stackinit(&st,10);
  node* cur = root;
  node* top;
  while(cur||stackempty(&st)!= 1)
  {
    //���������
    while(cur)
    {
      stackpush(&st,cur);
      cur = cur->left;
    }
    //��ȡջ��Ԫ��
    top = stacktop(&st);
    printf("%c ",top->val);
    stackpop(&st);
    //��ȡ�ұ�
    cur = top->right;
  }
}
//�ǵݹ��������
void BinaryTreePostOrder(node* root)
{
  stack st;
  stackinit(&st,10);
  node* cur = root;
  node* top = NULL;
  node* tmp = NULL;
  while(cur||stackempty(&st)!= 1)
  {
    while(cur)
    {
      stackpush(&st,cur);
      cur = cur->left;
    }
    top = stacktop(&st);
    cur = top->right;
    if(cur==NULL||cur==tmp)
    {
      if(cur==tmp)
        cur = NULL;
      printf("%c ",top->val);
      stackpop(&st);
      tmp=top;
    }
  }
}
//���Ĳ�α���
void BinaryTreeLevelOrder(node* root)
{
  queue q;
  queueinit(&q);
  if(root)
    queuepush(&q,root);
  while(queueempty(&q)!=1)
  {
    node* front = queuefront(&q);
    queuepop(&q);
    printf("%c ",front->val);
    if(front->left)
      queuepush(&q,front->left);
    if(front->right)
      queuepush(&q,front->right);
  }
}
//�ж��Ƿ�Ϊ��ȫ������
int BinaryTreeComplete(node* root)
{
  queue q;
  queueinit(&q);
  if(root)
    queuepush(&q,root);
  while(queueempty(&q)!=1)
  {
    node* front = queuefront(&q);
    queuepop(&q);
    if(front)
    {
      queuepush(&q,front->left);
      queuepush(&q,front->right);
    }
    else
      break;
  }
  while(queueempty(&q)!=1)
  {
    node* front = queuefront(&q);
    queuepop(&q);
    if(front)
      return -1;//������ȫ������
  }
  return 1;//����ȫ������
}
