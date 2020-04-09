#include<iostream>
using namespace std;
int* deletesamenum(int *num,int length)
{
  if(num==NULL){
    return NULL;
  }
  int i = 0;
  int j = 1;
  int find = 0;
  while(j<length){
    num[find++] = num[i];
    if(num[i]!=num[j]){
      ++i;
      ++j;
    }
    else{
      while(j<length&&num[i]==num[j]){
        ++j;
      }
      i=j;
      ++j;
    }
  }
  if(i<length){
    num[find++] = num[i];
  }
  return num;
}
int main()
{
  int number[10] = {1,1,2,3,3,4,5,6,6,6};
  int* a = deletesamenum(number,10);
  for(int i = 0;i<6;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
