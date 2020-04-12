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
//С�ѵ����µ���
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
//С�����ϵ���
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
//���µ�����С��
void shiftdownsmall(hpdatatype* arry,int size,int parent)
{
  //����λ��
  int child = parent*2+1;
  //�����Һ���ѡһ������
  while(child<size)
  {
    if(child+1<size&&arry[child+1]<arry[child])
      ++child;
    //�͸��ڵ�Ƚ�
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
//���µ��������
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
//������ϵ���
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
