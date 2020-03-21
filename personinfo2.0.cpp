#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 100
typedef struct PersonInfo{
  char name[100];
  char sex[10];
  char age[10];
  char phone[100];
  char address[100];
} PersonInfo;
typedef struct addressbook{
  PersonInfo* persons;
  int size;//体现有效元素
  int max;
} addressbook;
//此处参数设为指针类型
//1.结构体作为函数参数的时候，需要进行开背参数而结构体占据内存可能比较大，参数写成指针类型能降低拷贝开销
//2.初始化函数内部需要修稿结构体变量的内容，我们需要在函数内部修改同时影响到外部
void Init(addressbook* addr)//初始化
{
  addr->size = 0;
  addr->max = 2;
  addr->persons=(PersonInfo*)malloc(addr->max * sizeof(PersonInfo));
  for(int i=0;i<addr->max;i++){
    strcpy(addr->persons[i].name,"");
    strcpy(addr->persons[i].sex,"");
    strcpy(addr->persons[i].age,"");
    strcpy(addr->persons[i].phone,"");
    strcpy(addr->persons[i].address,"");
  }
}
void SearchSame(addressbook* addr)
{
  int a=0,b=0;
  for(int i =0;i<addr->size;i++){
    PersonInfo* info = &addr->persons[i];
    for(int j=i+1;j<addr->size;j++){
      PersonInfo* info1 = &addr->persons[j];
      if((strcmp(info->name,info1->name))==0||(strcmp(info->phone,info1->phone))==0){
        printf("[%d] 姓名:%s 性别:%s 年龄:%s 电话:%s 住址:%s\n",j,info1->name,info1->sex,info1->age,info1->phone,info1->address);
        a=1;
        b=1;
      }
    }
    if(a==1){
      printf("上述联系人中存在姓名重复或电话与下重复:\n");
      printf("[%d] 姓名:%s 性别:%s 年龄:%s 电话:%s 住址:%s\n",i,info->name,info->sex,info->age,info->phone,info->address);
      printf("\n");
    }
    a=0;
  }
  if(b==0){
    printf("无重复联系人\n");
  }
}
int menu()
{
  printf("=====================\n");
  printf("1. 新增联系人\n");
  printf("2. 删除联系人\n");
  printf("3. 查找联系人\n");
  printf("4. 修改联系人\n");
  printf("5. 打印全部联系人\n");
  printf("6. 清空全部联系人\n");
  printf("7. 排序全部联系人\n");
  printf("8. 查重\n");
  printf("0. 退出\n");
  printf("=====================\n");
  int choice =0;
  scanf("%d",&choice);
  return choice;
}
void Addperson(addressbook* addr_book)
{
  addr_book->max+=20;
  PersonInfo* newaddr = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->max);
  memcpy(newaddr,addr_book->persons,addr_book->size*(sizeof(PersonInfo)));
  free(addr_book->persons);
  addr_book->persons=newaddr;
}
void AddPersonInfo(addressbook* addr_book)
{
  printf("新增联系人\n");
  if(addr_book->size>=addr_book->max){
  Addperson(addr_book);
  }
  PersonInfo* info =&addr_book->persons[addr_book->size];
  printf("请输入联系人姓名:");
  scanf("%s",info->name);
  printf("请输入联系人性别(man/woman):");
  scanf("%s",info->sex);
  printf("请输入联系人年龄:");
  scanf("%s",info->age);
  printf("请输入联系人电话:");
  scanf("%s",info->phone);
  printf("请输入联系人住址:");
  scanf("%s",info->address);
  addr_book->size++;
  printf("新增联系人成功\n");
}
void DelPersonInfor(addressbook* addr_book)
{
  printf("删除联系人\n");
  printf("请选择删除方式:\n");
  printf("1.序号删除 2.姓名删除");
  int choice = 0;
  scanf("%d",&choice);
  if(choice==1){
    if(addr_book->size<=0){
      printf("通讯录为空！删除失败");
      return ;
    }
    int id = 0;
    printf("输入所要删除的序号：");
    if(id<0||id>addr_book->size){
      printf("输入的id非法，删除失败");
      return ;
    }
    scanf("%d",&id);
    PersonInfo* last_info = &addr_book->persons[addr_book->size-1];
    PersonInfo* to_delete = &addr_book->persons[id];
    *to_delete=*last_info;
    addr_book->size--;
  }
  if(choice==2){
    int i =0;
    char Name[1024];
    printf("请输入所需要删除的联系人的姓名：");
    scanf("%s",Name);
    while(1){
      PersonInfo* info=&addr_book->persons[i];
      if(i==addr_book->size){
        printf("查无此人\n");
        break;
      }
      if(strcmp(info->name,Name)==0){
        printf("找到了\n");
        PersonInfo* nlast_info = &addr_book->persons[addr_book->size-1];
        PersonInfo* nto_delete = &addr_book->persons[i];
        *nto_delete=*nlast_info;
        addr_book->size--;
        printf("删除成功\n");
        break;
      }
      i++;
    }
  }
}
void FindPersonInfo(addressbook* addr_book)
{
  printf("查找指定联系人\n");
  printf("请输入要超找的联系人姓名:");
  char name[100]={0};
  scanf("%s",name);
  for(int i=0;i<addr_book->size;i++){
    PersonInfo* info = &addr_book->persons[i];
    if(strcmp(name,info->name)==0){
      printf("[%d] 姓名:%s 性别:%s 年龄:%s 电话:%s 住址:%s\n",i,info->name,info->sex,info->age,info->phone,info->address);
    }
  }
}
void ModifyPersonInfo(addressbook* addr_book)
{
  //修改指定序号的联系人的姓名或者电话
    if(addr_book->size<=0){
      printf("通讯录为空！修改失败\n");
      return;
    }
    int id=0;
    printf("请输入需要修改的联系人的序号:");
    scanf("%d",&id);
    if(id<0||id>=addr_book->size){
      printf("输入的序号非法！修改失败\n");
      return;
    }
    PersonInfo* info = &addr_book->persons[id];
    printf("请输入修改后的姓名(*表示不变)：");
    char name[1024]={0};
    scanf("%s",name);
    if(strcmp(name,"*")!=0){
      strcpy(info->name,name);
    }
    printf("请输入修改后的性别(*表示不变)：");
    char sex[50]={0};
    scanf("%s",sex);
    if(strcmp(sex,"*")!=0){
      strcpy(info->sex,sex);
    }
    printf("请输入修改后年龄(*表示不变)：");
    char age[10] = {0};
    scanf("%s",age);
    if(strcmp(age,"*")!=0){
      strcpy(info->age,age);
    }
    printf("请输入修改后的电话(*表示不变)：");
    char phone[1024]={0};
    scanf("%s",phone);
    if(strcmp(phone,"*")!=0){
      strcpy(info->phone,phone);
    }
    printf("请输入修改后的住址(*表示不变)：");
    char address[1024]={0};
    scanf("%s",address);
    if(strcmp(address,"*")!=0){
      strcpy(info->address,address);
    }
    printf("修改成功\n");
}
void PrintAllPersonInfo(addressbook* addr_book)
{
  int num=3;
  re:
  printf("此操作需要输入密码:");
  char sec[20]={0};
  scanf("%s",sec);
  if(strcmp(sec,"abcdef123")==0){
    for(int i = 0;i<addr_book->size;i++){
      PersonInfo* info = &addr_book->persons[i];
      printf("[%d] 姓名:%s 性别:%s 年龄:%s 电话:%s 住址:%s\n",i,info->name,info->sex,info->age,info->phone,info->address);
    }
    printf("当前共打印%d条通讯录\n",addr_book->size);
    num=3;
  }
  else if(num==0){
    printf("抱歉操作锁死!\n");
  }
  else{
    printf("密码错误,你还有%d次机会\n",num--);
    goto re;
  }
}
void ClearPerson(addressbook* addr_book)
{
  printf("删除全部记录!\n");
  printf("您真的要删除吗?Y/N\n");
  char choice[1024]={0};
  scanf("%s",choice);
  if(strcmp(choice,"Y")==0||strcmp(choice,"y")==0){
    addr_book->size=0;
    printf("删除成功!\n");
  }
  else{
    printf("删除指令已取消\n");
  }
}
void SequencePerson(addressbook* addr_book)
{
  for(int i =0;i<addr_book->size;i++){
    for(int j=i;j<addr_book->size;j++){
      if(strcmp(addr_book->persons[i].name,addr_book->persons[j].name)>0){
        PersonInfo* info1 = &addr_book->persons[i];
        PersonInfo* info2 = &addr_book->persons[j];
        PersonInfo* info3 = &addr_book->persons[addr_book->size];
        *info3 = *info1;
        *info1 = *info2;
        *info2 = *info3;
      }
    }
  }
  printf("所有联系人排序成功!\n");
}
int main()
{
  //此处可能存在风险，有超出栈空间的风险
  addressbook address_book;
  char number[50]={0};
  int a=3;
  Init(&address_book);
  typedef void(*Func)(addressbook*);
  Func func_table[]={
    NULL,
    AddPersonInfo,
    DelPersonInfor,
    FindPersonInfo,
    ModifyPersonInfo,
    PrintAllPersonInfo,
    ClearPerson,
    SequencePerson,
    SearchSame,
  };
    //通过这个循环和用户交互
      printf("欢迎使用通讯录系统,如果你想要操作请输入密码\n");
      start:
      printf("密码：");
      scanf("%s",number);
      if(strcmp(number,"123456abc")==0){
        while(1){
          int choice = menu();
          if(choice<0||choice>=sizeof(func_table)/sizeof(func_table[0])){
            printf("您的输入有误");
            continue;
          }
          if(choice==0){
            printf("goodbye");
            break;
          }
          func_table[choice](&address_book);
        }
      }
      else if(a==0){
        printf("你不配使用该系统!!!\n");
      }
      else{
        printf("密码错误，你还有%d次机会\n",a--);
        goto start;
      }
  return 0;
}
