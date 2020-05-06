#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//合并
void merge(int* array,int begin,int mid ,int end,int* tmp)
{
  int begin1 = begin,end1 = mid,begin2 = mid + 1,end2 = end;
  int idx = begin;
  while(begin1<=end1&&begin2<=end2)
  {
    if(array[begin1] <= array[begin2])
      tmp[idx++] = array[begin1++];
    else
      tmp[idx++] = array[begin2++];
  }
  //查看是否有剩余元素
  if(begin1 <= end1)
    memcpy(tmp + idx,array + begin1,sizeof(int)*(end1 - begin1 + 1));
  if(begin2 <= end2)
    memcpy(tmp + idx,array + begin2,sizeof(int)*(end2 - begin2 + 1));
  memcpy(array + begin,tmp + begin,sizeof(int)*(end - begin +1));
}

void mergesortr(int* array,int begin,int end,int* tmp)
{
  if(begin>=end)
    return ;
  int mid = begin + (end - begin)/2;
  mergesortr(array,begin,mid,tmp);
  mergesortr(array,mid + 1,end,tmp);
  merge(array,begin,mid,end,tmp);
}
//归并排序
void mergesort(int* array,int n)
{
  int* tmp = (int*)malloc(sizeof(int)*n);
  mergesortr(array,0,n-1,tmp);
  free(tmp);
}
void print(int* num,int n)
{
  for(int i = 0;i<n;i++)
  {
    printf("%d ",num[i]);
  }
  printf("\n");
}
