#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  int *data;//����
  size_t size;//ջ�Ĵ�С
  size_t capacity;//ջ������
}stack;
//ջ�ĳ�ʼ��
void stackinit(stack* st,size_t n)
{
  st->data = (int *)malloc(sizeof(int) * n);
  st->size = n;
  st->capacity = 0;
}
//��ջ
void stackpush(stack* st,int data)
{
  //�ж��Ƿ���Ҫ����
  if(st->size==st->capacity){
    st->capacity*=2;
    st->data = (int*)realloc(st->data,sizeof(int) * st->capacity);
  }
  //��ջ
  st->data[st->size++] = data;
}
//��ջ
void stackpop(stack* st)
{
  //��ǰ��ѧУ��һ
  if(st->size)
  --st->size;
}
//ȡջ��Ԫ��
int stacktop(stack* st)
{
  return st->data[st->size-1];
}
//ȡ��ǰջ�Ĵ�С
size_t stacksize(stack* st)
{
  return st->size;
}
//�ж�ջ�Ƿ�Ϊ��
int stackempty(stack* st)
{
  if(st->size==0)
    return 1;//��
  return 0;//�ǿ�
}
//����ջ
void stackdestory(stack* st)
{
  free(st->data);
  st->data = NULL;
  st->size = st->capacity = 0;
}
int main()
{
  stack* Stack;
  return 0;
}
