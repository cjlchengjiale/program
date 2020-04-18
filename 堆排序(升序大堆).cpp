#include<stdio.h>
#include<stdlib.h>
typedef int hpdatatype;
void swap(hpdatatype* arry,int a,int b)  //���ӣ����׽���
{
  int tmp = arry[a];
   arry[a] = arry[b];
   arry[b] = tmp;
}
void shiftdownbig(hpdatatype* arry,int size,int parent)  //�������������µ������
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
void heapsort(int* arry,int n)
{
  //����
  for(int i = (n-2)/2;i>=0;--i)
  {
    shiftdownbig(arry,n,i);
  }
  //����˳���������
  int end = n;
  while(end>1)
  {
    swap(arry,0,end-1);//�����������һ�����
    --end;//�Ѵ�С��-1
    shiftdownbig(arry,end,0);//����������Ķ�
  }
}
