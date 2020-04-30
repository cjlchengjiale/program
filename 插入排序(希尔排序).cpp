#include<stdio.h>
#include<stdlib.h>
//��������
void insertsort(int* array,int size)
{
  int end = 0;
  int key = 0;
  for(int i = 0;i<size-1;i++)
  {
    end = i;//���ź����е����һ��Ԫ��
    key = array[end+1];//�������еĵ�һ��Ԫ��
    //Ԫ���ƶ�
    while(end>=0&&key<array[end])
    {
      array[end+1] = array[end];
      end--;
    }
    //����
    array[end+1] = key;
  }
}
//ϣ������
void shellsort(int* array,int size)
{
  int gap = size/2;
  int end = 0,key = 0;
  //�Բ���gap���ж�������
  while(gap>1)
  {
    gap/=2;//ȷ�����һ��gap=1
    //��������
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
