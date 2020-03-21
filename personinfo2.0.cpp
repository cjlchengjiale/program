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
  int size;//������ЧԪ��
  int max;
} addressbook;
//�˴�������Ϊָ������
//1.�ṹ����Ϊ����������ʱ����Ҫ���п����������ṹ��ռ���ڴ���ܱȽϴ󣬲���д��ָ�������ܽ��Ϳ�������
//2.��ʼ�������ڲ���Ҫ�޸�ṹ����������ݣ�������Ҫ�ں����ڲ��޸�ͬʱӰ�쵽�ⲿ
void Init(addressbook* addr)//��ʼ��
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
        printf("[%d] ����:%s �Ա�:%s ����:%s �绰:%s סַ:%s\n",j,info1->name,info1->sex,info1->age,info1->phone,info1->address);
        a=1;
        b=1;
      }
    }
    if(a==1){
      printf("������ϵ���д��������ظ���绰�����ظ�:\n");
      printf("[%d] ����:%s �Ա�:%s ����:%s �绰:%s סַ:%s\n",i,info->name,info->sex,info->age,info->phone,info->address);
      printf("\n");
    }
    a=0;
  }
  if(b==0){
    printf("���ظ���ϵ��\n");
  }
}
int menu()
{
  printf("=====================\n");
  printf("1. ������ϵ��\n");
  printf("2. ɾ����ϵ��\n");
  printf("3. ������ϵ��\n");
  printf("4. �޸���ϵ��\n");
  printf("5. ��ӡȫ����ϵ��\n");
  printf("6. ���ȫ����ϵ��\n");
  printf("7. ����ȫ����ϵ��\n");
  printf("8. ����\n");
  printf("0. �˳�\n");
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
  printf("������ϵ��\n");
  if(addr_book->size>=addr_book->max){
  Addperson(addr_book);
  }
  PersonInfo* info =&addr_book->persons[addr_book->size];
  printf("��������ϵ������:");
  scanf("%s",info->name);
  printf("��������ϵ���Ա�(man/woman):");
  scanf("%s",info->sex);
  printf("��������ϵ������:");
  scanf("%s",info->age);
  printf("��������ϵ�˵绰:");
  scanf("%s",info->phone);
  printf("��������ϵ��סַ:");
  scanf("%s",info->address);
  addr_book->size++;
  printf("������ϵ�˳ɹ�\n");
}
void DelPersonInfor(addressbook* addr_book)
{
  printf("ɾ����ϵ��\n");
  printf("��ѡ��ɾ����ʽ:\n");
  printf("1.���ɾ�� 2.����ɾ��");
  int choice = 0;
  scanf("%d",&choice);
  if(choice==1){
    if(addr_book->size<=0){
      printf("ͨѶ¼Ϊ�գ�ɾ��ʧ��");
      return ;
    }
    int id = 0;
    printf("������Ҫɾ������ţ�");
    if(id<0||id>addr_book->size){
      printf("�����id�Ƿ���ɾ��ʧ��");
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
    printf("����������Ҫɾ������ϵ�˵�������");
    scanf("%s",Name);
    while(1){
      PersonInfo* info=&addr_book->persons[i];
      if(i==addr_book->size){
        printf("���޴���\n");
        break;
      }
      if(strcmp(info->name,Name)==0){
        printf("�ҵ���\n");
        PersonInfo* nlast_info = &addr_book->persons[addr_book->size-1];
        PersonInfo* nto_delete = &addr_book->persons[i];
        *nto_delete=*nlast_info;
        addr_book->size--;
        printf("ɾ���ɹ�\n");
        break;
      }
      i++;
    }
  }
}
void FindPersonInfo(addressbook* addr_book)
{
  printf("����ָ����ϵ��\n");
  printf("������Ҫ���ҵ���ϵ������:");
  char name[100]={0};
  scanf("%s",name);
  for(int i=0;i<addr_book->size;i++){
    PersonInfo* info = &addr_book->persons[i];
    if(strcmp(name,info->name)==0){
      printf("[%d] ����:%s �Ա�:%s ����:%s �绰:%s סַ:%s\n",i,info->name,info->sex,info->age,info->phone,info->address);
    }
  }
}
void ModifyPersonInfo(addressbook* addr_book)
{
  //�޸�ָ����ŵ���ϵ�˵��������ߵ绰
    if(addr_book->size<=0){
      printf("ͨѶ¼Ϊ�գ��޸�ʧ��\n");
      return;
    }
    int id=0;
    printf("��������Ҫ�޸ĵ���ϵ�˵����:");
    scanf("%d",&id);
    if(id<0||id>=addr_book->size){
      printf("�������ŷǷ����޸�ʧ��\n");
      return;
    }
    PersonInfo* info = &addr_book->persons[id];
    printf("�������޸ĺ������(*��ʾ����)��");
    char name[1024]={0};
    scanf("%s",name);
    if(strcmp(name,"*")!=0){
      strcpy(info->name,name);
    }
    printf("�������޸ĺ���Ա�(*��ʾ����)��");
    char sex[50]={0};
    scanf("%s",sex);
    if(strcmp(sex,"*")!=0){
      strcpy(info->sex,sex);
    }
    printf("�������޸ĺ�����(*��ʾ����)��");
    char age[10] = {0};
    scanf("%s",age);
    if(strcmp(age,"*")!=0){
      strcpy(info->age,age);
    }
    printf("�������޸ĺ�ĵ绰(*��ʾ����)��");
    char phone[1024]={0};
    scanf("%s",phone);
    if(strcmp(phone,"*")!=0){
      strcpy(info->phone,phone);
    }
    printf("�������޸ĺ��סַ(*��ʾ����)��");
    char address[1024]={0};
    scanf("%s",address);
    if(strcmp(address,"*")!=0){
      strcpy(info->address,address);
    }
    printf("�޸ĳɹ�\n");
}
void PrintAllPersonInfo(addressbook* addr_book)
{
  int num=3;
  re:
  printf("�˲�����Ҫ��������:");
  char sec[20]={0};
  scanf("%s",sec);
  if(strcmp(sec,"abcdef123")==0){
    for(int i = 0;i<addr_book->size;i++){
      PersonInfo* info = &addr_book->persons[i];
      printf("[%d] ����:%s �Ա�:%s ����:%s �绰:%s סַ:%s\n",i,info->name,info->sex,info->age,info->phone,info->address);
    }
    printf("��ǰ����ӡ%d��ͨѶ¼\n",addr_book->size);
    num=3;
  }
  else if(num==0){
    printf("��Ǹ��������!\n");
  }
  else{
    printf("�������,�㻹��%d�λ���\n",num--);
    goto re;
  }
}
void ClearPerson(addressbook* addr_book)
{
  printf("ɾ��ȫ����¼!\n");
  printf("�����Ҫɾ����?Y/N\n");
  char choice[1024]={0};
  scanf("%s",choice);
  if(strcmp(choice,"Y")==0||strcmp(choice,"y")==0){
    addr_book->size=0;
    printf("ɾ���ɹ�!\n");
  }
  else{
    printf("ɾ��ָ����ȡ��\n");
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
  printf("������ϵ������ɹ�!\n");
}
int main()
{
  //�˴����ܴ��ڷ��գ��г���ջ�ռ�ķ���
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
    //ͨ�����ѭ�����û�����
      printf("��ӭʹ��ͨѶ¼ϵͳ,�������Ҫ��������������\n");
      start:
      printf("���룺");
      scanf("%s",number);
      if(strcmp(number,"123456abc")==0){
        while(1){
          int choice = menu();
          if(choice<0||choice>=sizeof(func_table)/sizeof(func_table[0])){
            printf("������������");
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
        printf("�㲻��ʹ�ø�ϵͳ!!!\n");
      }
      else{
        printf("��������㻹��%d�λ���\n",a--);
        goto start;
      }
  return 0;
}
