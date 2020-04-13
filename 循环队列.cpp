#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
  int* arry;
  int front;
  int rear;
  int size;
  int k;
}cqueue;
cqueue* cqueuecreat(size_t k)
{
  cqueue* mq = (cqueue*)malloc(sizeof(cqueue));
  mq->arry = (int*)malloc(sizeof(int)*k);
  mq->size = 0;
  mq->front = mq->rear = 0;
  mq->k = k;
  return mq;
}
bool cqueueenqueue(cqueue* obj,int vaule)
{
  if(obj->size==obj->k)
    return false;
  obj->arry[obj->rear++] = vaule;
  if(obj->rear == obj->k)
    obj->rear = 0;
  obj->size++;
}
bool cququedequeue(cqueue* obj)
{
  if(obj->size==0)
    return false;
  ++obj->front;
  if(obj->front == obj->k)
    obj->front  = 0;
  --obj->size;
  return true;
}
int cqueuefront(cqueue* obj)
{
  if(obj->size==0)
    return -1;
  return obj->arry[obj->front];
}
int cqueuerear(cqueue* obj)
{
  if(obj->size==0)
    return -1;
  if(obj->rear == 0)
    return obj->arry[obj->k-1];
  return obj->arry[obj->rear-1];
}
bool cqueueisempty(cqueue* obj)
{
  if(obj->size==0)
    return true;
  return false;
}
bool cqueueisfull(cqueue* obj)
{
  if(obj->size == obj->k)
    return true;
  return false;
}
void cqueuefree(cqueue* obj)
{
  free(obj->arry);
  free(obj);
}
