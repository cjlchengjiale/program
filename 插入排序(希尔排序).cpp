#include<stdio.h>
#include<stdlib.h>
//插入排序
void insertsort(int* array,int size)
{
  int end = 0;
  int key = 0;
  for(int i = 0;i<size-1;i++)
  {
    end = i;//已排好序列的最后一个元素
    key = array[end+1];//待排序列的第一个元素
    //元素移动
    while(end>=0&&key<array[end])
    {
      array[end+1] = array[end];
      end--;
    }
    //插入
    array[end+1] = key;
  }
}
//希尔排序
void shellsort(int* array,int size)
{
  int gap = size/2;
  int end = 0,key = 0;
  //以步调gap进行多轮排序
  while(gap>1)
  {
    gap/=2;//确保最后一轮gap=1
    //插入排序
    for(int i = 0;i<size-gap;i++)
    {
      end = i;
      key = array[end+gap];
      while(end>=0&&key<array[end])
      {
        array[end+gap] = array[end];
        end-=gap;
      }
      array[end+gap] = key;
    }
  }
}
void printnum(int* array,int size)
{
  for(int i = 0;i<size;i++)
  {
    printf("%d ",array[i]);
  }
  printf("\n");
}
int main()
{
  int num = 0;
  scanf("%d",&num);
  int *array = (int*)malloc(sizeof(int)*num);
  for(int i = 0;i<num;i++)
  {
    scanf("%d",&array[i]);
  }
  shellsort(array,num);
  printnum(array,num);
  system("pause");
  return 0;
}
