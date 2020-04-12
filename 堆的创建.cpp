#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int hpdatatype;
typedef struct heap
{
  hpdatatype* arry;
  int size;
  int capacity;
}heap;
void shiftdownsmall(hpdatatype* arry,int size,int parent);
//小堆的向下调整
void swap(hpdatatype* arry,int a,int b)
{
  int tmp = arry[a];
   arry[a] = arry[b];
   arry[b] = tmp;
}
void heapcreat(heap* hp,hpdatatype* arry,int size)
{
  hp->arry = (hpdatatype*)malloc(sizeof(hpdatatype)*size);
  memcpy(hp->arry,arry,sizeof(hpdatatype)*size);
  hp->size = size;
  hp->capacity = size;
  for(int parent = (size-2)/2;parent>=0;parent--)
  {
    shiftdownsmall(hp->arry,size,parent);
  }
}
//小堆向上调整
void shiftupsmall(hpdatatype* arry,int child)
{
  int parent =(child-1)/2;
  while(child>0)
  {
    if(arry[child]<arry[parent])
    {
      swap(arry,child,parent);
      child = parent;
      parent = (child-1)/2;
    }
    else
      break;
  }
}
//向下调整建小堆
void shiftdownsmall(hpdatatype* arry,int size,int parent)
{
  //左孩子位置
  int child = parent*2+1;
  //从左右孩子选一个最大的
  while(child<size)
  {
    if(child+1<size&&arry[child+1]<arry[child])
      ++child;
    //和父节点比较
    if(arry[child]<arry[parent])
    {
      swap(arry,child,parent);
      parent = child;
      child = parent*2+1;
    }
    else
      break;
  }
}
//向下调整建大堆
void shiftdownbig(hpdatatype* arry,int size,int parent)
{
  int child = 2*parent + 1;
  while(child<size)
  {
    if(child+1<size&&arry[child+1]>arry[child])
      ++child;
    if(arry[child]>arry[parent])
    {
      swap(arry,child,parent);
      parent = child;
      child = parent*2+1;
    }
    else
      break;
  }
}
//大堆向上调整
void shiftupbig(hpdatatype* arry,int child)
{
  int parent = (child-1)/2;
  while(child>0)
  {
    if(arry[child]>arry[parent])
    {
      swap(arry,child,parent);
      child = parent;
      parent = (child-1)/2;
    }
    else
      break;
  }
}
void heapprint(heap* hp)
{
  for(int i = 0;i<hp->size;i++)
  {
    printf("%d ",hp->arry[i]);
  }
}
