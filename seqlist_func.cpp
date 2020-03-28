#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef int SLDateType;
typedef struct seqlist{
  int* array;
  int size;
  int capacity;
} SeqList;
void SeqListInit(SeqList* ps)
{
  if(ps==NULL){
    return ;
  }
  ps->size = 0;
  ps->capacity = 20;
  ps->array = (int *)malloc(sizeof(int)*ps->capacity);
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
  ps->array[ps->size++] = x;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
  if(ps->size<ps->capacity){
    size_t num = ps->size;
    while(num>0){
    ps->array[num] = ps->array[num-1];
    --num;
    }
    ps->array[0] = x;
    ++ps->size;
  }
  else{
    return ;
  }
}
void SeqListPopFront(SeqList* ps)
{
  size_t start = 0;
  while(start<ps->size-1){
    ps->array[start] =ps->array[++start];
  }
  ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
  if(ps->size){
    ps->size--;
  }
}
void SeqListPrint(SeqList* ps)
{
  size_t end = 0;
  while(end<ps->size){
    printf("%d ",ps->array[end++]);
  }
}
int SeqListFind(SeqList* ps, SLDateType x)
{
  size_t num = 0;
  while(num<ps->size){
    if(ps->array[num]==x){
      return num;
    }
    ++num;
  }
  return 0;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
  if(pos<ps->size){
      size_t end = ps->size;
      while(end>pos){
        ps->array[end] = ps->array[--end];
      }
      ps->array[pos] = x;
      ps->size++;
  }
  else{
    return ;
  }
}
void SeqListErase(SeqList* ps, size_t pos)
{
  if(pos<ps->size){
    size_t end = pos;
    while(end<ps->size){
      ps->array[end] = ps->array[end++];
    }
    ps->size--;
  }
}
