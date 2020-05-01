#include<stdio.h>
#include<stdlib.h>
void swap(int* array,int begin,int end)
{
  int tmp = array[begin];
  array[begin] = array[end];
  array[end] = tmp;
}
//霍尔划分
int partion(int* array,int begin,int end)
{
  int head = begin;
  int key = array[begin];
  while(begin<end)
  {
    while(begin<end&&array[end] >= key)
      end--;
    while(begin<end&&array[begin] <= key)
      begin++;
    swap(array,begin,end);
  }
  swap(array,begin,head);
  return begin;
}
//挖坑划分
int partion2(int* array,int begin,int end)
{
  int head = begin;
  int key = array[begin];
  while(begin<end)
  {
    while(begin<end&&array[end] >= key)
      end--;
    array[begin] = array[end];
    while(begin<end&&array[begin] <= key)
      begin++;
    array[end] = array[begin];
  }
  array[begin] = key;
  return begin;
}
//快慢指针
int partion3(int* array,int begin,int end)
{
  int prev = begin;
  int cur = prev + 1;
  int key = array[begin];
  while(cur<=end)
  {
    if(array[cur]<key&&++prev!=cur)//判断是否连续
      swap(array,cur,prev);
    ++cur;
  }
  swap(array,begin,prev);
  return prev;
}
//快排接口
void quicksort(int* array,int begin,int end)
{
  if(begin>=end)
    return ;
  int pos = partion3(array,begin,end);
  quicksort(array,begin,pos-1);
  quicksort(array,pos+1,end);
}
//测试
void test()
{
  int size = 0;
  scanf("%d",&size);
  int* array = (int*)malloc(sizeof(int)* size);
  for(int i = 0;i<size;i++)
  {
    scanf("%d",&array[i]);
  }
  quicksort(array,0,size-1);
  for(int i = 0;i<size;i++)
  {
    printf("%d ",array[i]);
  }
}
int main()
{
  test();
  return 0;
}
