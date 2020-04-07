#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  int *data;//数据
  size_t size;//栈的大小
  size_t capacity;//栈的容量
}stack;
//栈的初始化
void stackinit(stack* st,size_t n)
{
  st->data = (int *)malloc(sizeof(int) * n);
  st->size = n;
  st->capacity = 0;
}
//入栈
void stackpush(stack* st,int data)
{
  //判断是否需要扩容
  if(st->size==st->capacity){
    st->capacity*=2;
    st->data = (int*)realloc(st->data,sizeof(int) * st->capacity);
  }
  //入栈
  st->data[st->size++] = data;
}
//出栈
void stackpop(stack* st)
{
  //当前大学校减一
  if(st->size)
  --st->size;
}
//取栈顶元素
int stacktop(stack* st)
{
  return st->data[st->size-1];
}
//取当前栈的大小
size_t stacksize(stack* st)
{
  return st->size;
}
//判断栈是否为空
int stackempty(stack* st)
{
  if(st->size==0)
    return 1;//空
  return 0;//非空
}
//销毁栈
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
