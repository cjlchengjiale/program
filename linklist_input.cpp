#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct STU
{
  int data;
  struct STU *next;
} list,*linklist;
void creatlink(linklist &l)
{
  l=(linklist)malloc(sizeof(list));
  if(l==NULL)
  {
    cout<<"falised";
  }
  else
  {
    l->next=NULL;
  }
}
void scanflist(linklist l,int a)//β�巨
{
  linklist p,q;
  int i=0;
  p=l;
  for(i;i<a;i++)
  {
    q=(linklist)malloc(sizeof(list));
    cin>>q->data;
    p->next=q;
    p=q;
  }
  p->next=NULL;
}
void scanflist1(linklist l,int a)//ͷ�巨
{
  linklist p,q;
  int i=0;
  p=l;
  for(i;i<a;i++)
  {
    q=(linklist)malloc(sizeof(list));
    cin>>q->data;
    q->next=p->next;
    p->next=q;
  }
}
int inlist(linklist &l,int i,int j,int k)//�������
{
  if(i>k+2)
  {
    cout<<"falised";
  }
  linklist p,q;
  int num=0;
  p=l;
  if(p==NULL)
  {
    printf("falised");
  }
  else
  {
    while(p&&(num<i-1))
    {
      p=p->next;
      ++num;
    }
    if(!p||num>i-1)
    {
      return 0;
    }
    q=new STU;
    q->data=j;
    q->next=p->next;
    p->next=q;
  }
    return 1;
}
void printflist(linklist l)//������ӡ
{
  linklist q;
  q=l->next;
  while(q)
  {
    cout<<q->data<<" ";
    q=q->next;
  }

}
bool ListDelete(linklist &l,int i,int t)//�ڵ�ɾ��
{
  if(i<=0||i>t+1)
  {
    cout<<"falised";
  }
  linklist p,q;
  p=l;
  int number=0;
  if(p==NULL||i<0)
  {
    cout<<"falised";
  }
  else
  {
    while(p->next&&(number<i-1))
    {
      p=p->next;
      ++number;
    }
    if(!(p->next)||(number>i-1))
    {
      return 0;
    }
    q=p->next;
    p->next=q->next;
    delete q;
  }
  return 1;
}
void DestroyList(linklist l)
{
  linklist p,q;
  p=l;
  while(p)
  {
    q=p->next;
    p->next=q->next;
    free(q);
  }
}
int main()
{
  linklist l;
  creatlink(l);
  int chose;
  menu:cout<<"��ѡ��˳�����л��ǵ�������:"<<endl<<"˳������������1\t"<<"��������������2"<<endl;
  scanf("%d",&chose);
  if(chose!=1&&chose!=2)
  {
    cout<<"������������������";
    goto menu;
  }
  if(chose==1)
  {
  cout<<"��ѡ����˳������"<<endl;
  int a;
  cout<<"������Ҫ�������ݵĸ���:";
  cin>>a;
  scanflist(l,a);
  cout<<"��˳������Ľ��Ϊ:";
  printflist(l);
  cout<<endl;
  int b;
  cout<<"������Ҫ���ĸ��ڵ��������:";
  cin>>b;
  int e;
  cout<<"������Ҫ��"<<b<<"�����������:";
  cin>>e;
  inlist(l,b,e,a);
  if(b>0&&b<=a+1)
  {
      printflist(l);
      cout<<endl;
  }
  int d;
  cout<<"������Ҫɾ���ĸ��ڵ�:";
  cin>>d;
  ListDelete(l,d,a);
  if(d>0&&d<=a+1)
  {
    printflist(l);
    cout<<endl;
  }
  DestroyList(l);
 }
 if(chose==2)
 {
 cout<<"��ѡ���˵�������"<<endl;
 int a;
 cout<<"������Ҫ�������ݵĸ���:";
 cin>>a;
 scanflist1(l,a);
 printflist(l);
 cout<<endl;
 int b;
 cout<<"������Ҫ���ĸ��ڵ��������:";
 cin>>b;
 int e;
 cout<<"������Ҫ��"<<b<<"�����������:";
 cin>>e;
 inlist(l,b,e,a);
 if(b>0&&b<=a+1)
 {
     printflist(l);
     cout<<endl;
 }
 int d;
 cout<<"������Ҫɾ���ĸ��ڵ�:";
 cin>>d;
 ListDelete(l,d,a);
 if(d>0&&d<=a+1)
 {
   printflist(l);
   cout<<endl;
 }
 DestroyList(l);
}
  return 0;
}
