#include<stdio.h>
void swapnum(int* array,int begin,int end)
{
  int tmp = array[begin];
  array[begin] = array[end];
  array[end] = tmp;
}
//ѡ������(���Ż�)
void selectsort(int* array,int size)
{
  int start = 0;
  for(int i = 0;i<size;i++)
  {
    start = i;
    int min = i;
    for(int j = i + 1;j<size;j++)
    {
      if(array[min]>array[j])
        min = j;
    }
    swapnum(array,start,min);
  }
}
//ѡ������(�Ż�)
void selectsort2(int* array,int size)
{
  int start = 0,end = 0;
  for(int i = 0;i<size;i++)
  {
    start = i;
    end = size - 1;
    int min = i;
    int max = size - 1;
    for(int j = i + 1;j<size;j++)
    {
      //ÿ��ѡ��������С�Ľ�������
      if(array[min]>array[j])
        min = j;
      if(array[max]<array[j])
        max = j;
    }
    swapnum(array,start,min);
    swapnum(array,end,max);
  }
}
//ð������(���Ż�)
void bubblesort(int* array,int size)
{
  int nsize = size;
  while(nsize)
  {
    for(int i = 0;i<size-1;i++)
    {
      //��������ÿ�����ֵ����
      if(array[i+1]<array[i])
        swapnum(array,i+1,i);
    }
    nsize--;
  }
}
//ð������(�Ż�)
void bubblesort2(int* array,int size)
{
  int nsize = size;
  int flag = 0;
  while(nsize)
  {
    flag = 1;
    for(int i = 0;i<size-1;i++)
    {
      //��������ÿ�����ֵ����
      if(array[i+1]<array[i])
      {
        swapnum(array,i+1,i);
        flag = 0;
      }
    }
    nsize--;
    //��������ֱ������ѭ��
    if(flag == 1)
      break;
  }
}
/*
//����
void test()
{
  int num[10] = {2,5,6,546,8,9,23,456,123,-5};
  bubblesort2(num,10);
  for(int i = 0;i<10;i++)
  {
    printf("%d ",num[i]);
  }
}
int main()
{
  test();
  return 0;
}
*/
