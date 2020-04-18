#include<stdio.h>
#include<stdlib.h>
typedef int hpdatatype;
void swap(hpdatatype* arry,int a,int b)  //孩子，父亲交换
{
  int tmp = arry[a];
   arry[a] = arry[b];
   arry[b] = tmp;
}
void shiftdownbig(hpdatatype* arry,int size,int parent)  //排列升序，则向下调整大堆
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
  //建堆
  for(int i = (n-2)/2;i>=0;--i)
  {
    shiftdownbig(arry,n,i);
  }
  //调整顺序，升序输出
  int end = n;
  while(end>1)
  {
    swap(arry,0,end-1);//交换根和最后一个结点
    --end;//堆大小假-1
    shiftdownbig(arry,end,0);//调整交换后的堆
  }
}
