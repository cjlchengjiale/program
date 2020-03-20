#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct Node{
  int data;
  char number[10000];
  char number1[10000];
  struct Node *next;
}list,*linklist;
typedef struct big{
  char number[10000];
  char number1[10000];
} bignum;
void printlink(linklist &L);
void creatlink(linklist &L)//链表初始化
{
  L=(linklist)malloc(sizeof(list));
  if(L==NULL) cout<<"failed";
  else L->next=NULL;
}
void headcinlink(linklist &L,int n)//头插输入
{
  linklist p;
  for(int i=0;i<n;i++){
    p=(linklist)malloc(sizeof(list));
    cin>>p->data;
    p->next=L->next;
    L->next=p;
  }
}
void backcinlink(linklist &L,int n)//尾插输入
{
  linklist p,q;
  p=L;
  for(int i=0;i<n;i++){
    q=(linklist)malloc(sizeof(list));
    cin>>q->data;
    p->next=q;
    p=q;
  }
  p->next=NULL;
}
void headbignumber(linklist &L,char num[],int length)//头插字符转换整型
{
  linklist p;
  for(int i=0;i<length;i++){
    p=(linklist)malloc(sizeof(list));
    p->data=num[i]-'0';
    p->next=L->next;
    L->next=p;
  }
}
int connectlink(linklist &M,linklist &L,linklist &T)//连接链表并且返回连接后的长度
{
  linklist p,q,r;
  int num=0;
  p=L;
  q=T->next;
  for(int i=0;;i++){
    if(p->next==NULL){
      p->next=q;
      break;
    }
    p=p->next;
  }
  M->next=L->next;
  r=M->next;
  while(r!=NULL){
    r=r->next;
    num++;
  }
  return num;
}
void cutlink(linklist &L,linklist &T,linklist &R,int a,int n)//将链表从固定点a点剪断
{
  if(L==NULL||a>n+2||a<0) cout<<"failed";
  else {
    linklist p,q;
    int num=0;
    p=L;
    while(p&&num<a-1){
      p=p->next;
      ++num;
    }
    q=T;
    q->next=p->next;
    p->next=NULL;
    R->next=L->next;
  }
}
void changenum(linklist &L,linklist &T,int *long1,int *long2)//长度与链表的交换长的给前面短的给后面
{
  if(*long1<*long2){
    int temp=*long1;
    *long1=*long2;
    *long2=temp;
  }
  linklist N,p,q,r,j,l,m,n,u,v,w;
  N=(linklist)malloc(sizeof(list));
  N->next=NULL;
  r=N;
  p=T->next;
  while(p!=NULL){
    j=(linklist)malloc(sizeof(list));
    j->data=p->data;
    p=p->next;
    r->next=j;
    r=j;
  }
  r->next=NULL;
  T->next=NULL;
  l=L->next;
  m=T;
  while(l!=NULL){
    n=(linklist)malloc(sizeof(list));
    n->data=l->data;
    l=l->next;
    m->next=n;
    m=n;
  }
  m->next=NULL;
  L->next=NULL;
  u=L;
  v=N->next;
  while(v!=NULL){
    w=(linklist)malloc(sizeof(list));
    w->data=v->data;
    v=v->next;
    u->next=w;
    u=w;
  }
  u->next=NULL;
}
void bigsul(linklist &N,linklist &L,linklist &T,int long1,int long2)//大整数减法
{
  linklist p,q,r,s,t;
  q=L->next;
  r=T->next;
  t=T->next;
  int num=0;
  int i,k,e;
  while(r&&num<long2-1){
    r=r->next;
    ++num;
  }
  for(int a=num;a<long1-1;a++){
    s=(linklist)malloc(sizeof(list));
    s->data=0;
    s->next=r->next;
    r->next=s;
  }
  for(i=long1-1;i>=0;--i){
    if(q->data<t->data){
      p=(linklist)malloc(sizeof(list));
      p->data=q->data+10-t->data;
      q->next->data--;
      q=q->next;
      t=t->next;
      p->next=N->next;
      N->next=p;
    }
    else{
      p=(linklist)malloc(sizeof(list));
      p->data=q->data-t->data;
      q=q->next;
      t=t->next;
      p->next=N->next;
      N->next=p;
    }
  }
}
void bigadd(linklist &N,linklist &L,linklist &T,int long1,int long2)//大整数加法
{
  linklist q,r,t;
  q=L->next;
  r=T->next;
  int temp=0;
  int i,k,e;
  for(i=long1-1,k=long2-1;i>=0;--i,--k){
    if(k>=0){
      if(i!=0){
        t=(linklist)malloc(sizeof(list));
        e=q->data+r->data+temp;
        t->data=e%10;
        temp=e/10;
        t->next=N->next;
        N->next=t;
        q=q->next;
        r=r->next;
      }
      if(i==0){
        t=(linklist)malloc(sizeof(list));
        t->data=temp+q->data+r->data;
        t->next=N->next;
        N->next=t;
        break;
      }
    }
    else{
      if(i==0){
        t=(linklist)malloc(sizeof(list));
        t->data=q->data+temp;
        t->next=N->next;
        N->next=t;
        break;
      }
      t=(linklist)malloc(sizeof(list));
      e=q->data+temp;
      t->data=e%10;
      t->next=N->next;
      N->next=t;
      temp=e/10;
      q=q->next;
    }
  }
}
void into()
{
  char number[10000];
  cin>>number;
  int strleng=strlen(number);
  char number1[10][6]={"00000","10000","01000","11000","00100","10100","01100","11100","00010","10010"};
  char str2[10000]={'0'};
  char str1[10000]={'0'};
  strcpy(str2,number1[number[0]-'0']);
  for(int i=0;i<strleng-1;i++){
    strcpy(str1,str2);
    for(int p=strlen(str2);p>=0;p--){
      str2[p+2]=str2[p];
    }
    str2[0]='0';
    str2[1]='0';
    for(int k=0;k<strlen(str1);k++){
      str2[k]=(str1[k]-'0')+(str2[k]-'0')+'0';
    }
    for(int k=0;k<strlen(str2);k++){
      if(str2[k]>='2'){
        if((str2[k]-'0')==2) str2[k]='0';
        else str2[k]='1';
        if(str2[k+1]==NULL) str2[k+1]='0';
        str2[k+1]=((str2[k+1]-'0')+1)+'0';
      }
    }
    for(int j=strlen(str2);j>=0;j--){
      str2[j+1]=str2[j];
    }
    str2[0]='0';
    for(int k=0;k<5;k++){
      str2[k]=((str2[k]-'0')+(number1[(number[i+1]-'0')][k]-'0'))+'0';
    }
    for(int k=0;k<strlen(str2);k++){
      if(str2[k]>='2'){
        if((str2[k]-'0')==2) str2[k]='0';
        else str2[k]='1';
        if(str2[k+1]==NULL) str2[k+1]='0';
        str2[k+1]=((str2[k+1]-'0')+1)+'0';
      }
    }
  }
  int sum=0;
  for(int k=0;k<strlen(str2);k++){
    if(str2[k]=='1') sum=k;
  }
  for(int i=sum;i>=0;i--){
    cout<<str2[i];
  }
  cout<<endl;
}
void printlink(linklist &L)//链表输出
{
  linklist p;
  p=L->next;
  while(p!=NULL){
    cout<<p->data<<" ";
    p=p->next;
  }
}
void printlink1(linklist &L)//大整数加法链表输出
{
  linklist p;
  p=L->next;
  while(p!=NULL){
    cout<<p->data;
    p=p->next;
  }
}
void deletelik(linklist &L,int a,int n)//链表删除a结点
{
  linklist p,q;
  int num=0;
  p=L;
  if(L==NULL||a>(n+2)||a<0) cout<<"failed";
  else{
    while(p&&num<a-1){
      p=p->next;
      ++num;
    }
    q=p->next;
    p->next=q->next;
    delete(q);
  }
}
void addlink(linklist &L,int e,int a,int n)//链表在a点插入e数据
{
  if(a>n+2||a<0||L==NULL) cout<<"failed";
  else{
    linklist p,q;
    int num=0;
    p=L;
    while(p&&num<a-1){
      p=p->next;
      ++num;
    }
    q=new Node;
    q->data=e;
    q->next=p->next;
    p->next=q;
  }
}
void destroylink(linklist &L)//链表销毁
{
  linklist p,q;
  p=L;
  while(p){
    q=p->next;
    p->next=q->next;
    free(q);
  }
}
int main()
{/*
  bignum bignumber;
  cin>>bignumber.number>>bignumber.number1;
  int sizenumber=strlen(bignumber.number);
  int sizenumber1=strlen(bignumber.number1);
  linklist h,w,s,r;
  creatlink(h);
  creatlink(w);
  headbignumber(h,bignumber.number,sizenumber);
  headbignumber(w,bignumber.number1,sizenumber1);
  if(sizenumber<sizenumber1)   changenum(h,w,&sizenumber,&sizenumber1);
  creatlink(s);
  creatlink(r);
  bigadd(r,h,w,sizenumber,sizenumber1);
  printlink1(r);
  cout<<endl;
  bigsul(s,h,w,sizenumber,sizenumber1);
  printlink1(s);
  cout<<endl;*/
  linklist l,p,m,y,z;
  int a,b,c,d,e;
  cout<<"尾插输入个数"<<endl;
  cin>>a;
  creatlink(l);
  creatlink(p);
  creatlink(m);
  creatlink(y);
  creatlink(z);
  cout<<"输入数据"<<endl;
  backcinlink(l,a);
  printlink(l);
  cout<<endl<<"头插个数"<<endl;
  cin>>b;
  cout<<"输入数据"<<endl;
  headcinlink(p,b);
  printlink(p);
  cout<<endl;
  int q=connectlink(m,l,p);
  cout<<q<<endl;
  cout<<"连接后的链表数据"<<endl;
  printlink(m);
  cout<<endl<<"输入删除的结点"<<endl;;
  cin>>c;
  deletelik(m,c,q);
  cout<<"删除后节点后的链表"<<endl;
  printlink(m);
  cout<<endl;
  cout<<"输入要加入结点的数据和位置"<<endl;
  cin>>e>>d;
  addlink(m,e,d,--q);
  cout<<"连接后的链表"<<endl;
  printlink(m);
  cout<<endl;
  int o;
  cout<<"输入分离的链表结点"<<endl;
  cin>>o;
  cutlink(m,y,z,o,++q);
  cout<<"分开后的链表"<<endl;
  printlink(y);
  cout<<endl;
  printlink(z);
  cout<<endl;//*/
  //into();
  return 0;
}
