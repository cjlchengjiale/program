#include<stdio.h>
#include<stdlib.h>
typedef struct qnode
{
  struct qnode* next;
  int data;
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
qnode* creatnode(int data)
{
  qnode* node = (qnode*)malloc(sizeof(qnode));
  node->data = data;
  node->next = NULL;
  return node;
}
void queuepush(queue* q,int data)
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
int queuefront(queue* q)
{
  //if(q->front)
    return q->front->data;
}
int queueback(queue* q)
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

int main()
{
  queue Queue;
  queueinit(&Queue);
  for(int i = 0;i<5;i++)
  {
    queuepush(&Queue,i+1);
  }
  for(int i = 0;i<5;i++)
  {
    printf("%d ",Queue.front->data);
    queuepop(&Queue);
  }
  queuedestory(&Queue);
  return 0;
}

//Õ»µÄÊµÏÖ

typedef struct {
    queue q;
} MyStack;
MyStack* myStackCreate() {
     MyStack* ms = ( MyStack*)malloc(sizeof( MyStack));
     queueinit(&ms->q);
     return ms;
}
void myStackPush(MyStack* obj, int x) {
    queuepush(&obj->q,x);
}
int myStackPop(MyStack* obj) {
    int ret = 0;
    while(queuesize(&obj->q)>1)
    {
        int front = queuefront(&obj->q);
        queuepop(&obj->q);
        queuepush(&obj->q,front);
    }
    ret = queuefront(&obj->q);
    queuepop(&obj->q);
    return ret;
}
int myStackTop(MyStack* obj) {
    return queueback(&obj->q);
}
bool myStackEmpty(MyStack* obj) {
    return queueempty(&obj->q);
}
void myStackFree(MyStack* obj) {
    queuedestory(&obj->q);
    free(obj);
}
