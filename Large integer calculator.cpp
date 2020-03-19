typedef int status;
typedef char Elem;
#define OK 0
#define ERROR -1
#define MAXN 25000

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
using namespace std;

typedef struct StackNode{
  Elem data;
  struct StackNode *next;
}StackNode,*LinkStack;

typedef struct Node{
  char sign1='+';//��һ���������ķ���
  char ctr1[MAXN]={'\0'};//��һ���������ַ���(����)
  int itr1[MAXN]={0};//��һ���������ַ���ת��Ϊ������(����)
  int Lenctr1;//��һ���������ĳ���

  char sign2='+';//�ڶ����������ķ���
  char ctr2[MAXN]={'\0'};//�ڶ����������ַ���(����)
  int itr2[MAXN]={0};//�ڶ����������ַ���ת��Ϊ������(����)
  int Lenctr2;//�ڶ����������ĳ���

  char signresult='+';//�������������ķ���
  char cresult[MAXN]={'\0'};//���������õ��Ĵ������ṹ�ַ���(����)
  int iresult[MAXN]={0};//�����������(����)
  int Lencresult;//�������
}Node;

void InitNode(Node &K){//����ʼ��
  K.sign1='+';
  K.ctr1[MAXN]={'\0'};
  memset(K.itr1,0,sizeof(K.itr1));
  K.Lenctr1=0;

  K.sign2='+';
  K.ctr2[MAXN]={'\0'};
  memset(K.itr2,0,sizeof(K.itr2));
  K.Lenctr2=0;

  K.signresult='+';
  K.cresult[MAXN]={'\0'};
  memset(K.iresult,0,sizeof(K.iresult));
  K.Lencresult=0;
}

void page__title(char * menu_item){
  printf("\n\t* * * * * * * * * ���������� * * * * * * * * * *");
  printf("\n\n\t * *          -������-%s-������-          * *\n\n",menu_item);
  printf("\t* * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
  printf("* *�����������������ݣ�\n\n");
}
void page_title(){
  printf("\n\t* * * * * * * * * * ���������� * * * * * * * * * *\n\n");
  cout << "\t   1.����-�ӷ�-����           2.����-����-����" << endl << endl;
  cout << "\t   3.����-�˷�-����           4.����-����-����" << endl << endl;
  cout << "\t   5.�������ʽ����           6.����-����ת��-" << endl << endl;
  cout << "\t   7.����-�׳�-����           8.����-����-����" << endl;
  printf("\n\n\t* * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
  cout << "* *������������е�������ţ�";
}

status InitStack(LinkStack &S){//��ջ�ĳ�ʼ��
  S=NULL;
  return OK;
}

status Push(LinkStack &S,Elem  e){//��ջ����ջ
  LinkStack p=(LinkStack)malloc(sizeof(StackNode));
  p->data=e;
  p->next=S;
  S=p;
  return OK;
}

status Pop(LinkStack &S,Elem &e){//��ջ�ĳ�ջ
  LinkStack p;
  if(S==NULL) return ERROR;
  e=S->data;
  p=S;
  S=S->next;
  delete p;
  return OK;
}

char GetTop(LinkStack S){//ȡջ��Ԫ��
  if(S!=NULL) return S->data;
}

status StackEmpty(LinkStack S)
{
  if(S==NULL) return 1;
  else return 0;
}

void DestroyStack(LinkStack &S){//������ջ
    LinkStack p=S->next,q=S;
    while(p!=NULL){
        free(q);
        q=p;
        p=p->next;
    }
    free(p);
}

void TraverStack(LinkStack S){//��ջ�ĵݹ������ʾ
  if(S){
    cout << S->data;
    TraverStack(S->next);
  }
}

int In(char ch){//�ж�ch�Ƿ�Ϊ��������ǵĻ�����1���Ƿ���0
  switch(ch){
    case '-':return 1;
    case '+':return 1;
    case '*':return 1;
    case '/':return 1;
    case '(':return 1;
    case ')':return 1;
    case '#':return 1;
    default:return 0;
  }
}

char Precede(char ch1,char ch2){//���ȼ��Ƚ�
  int a1=ch1-'#',a2=ch2-'#';
  char sign[13][13]={
    {'=',' ',' ',' ',' ','<','<','<','<',' ','<',' ','<'},
    {},
    {},
    {},
    {},
    {' ',' ',' ',' ',' ','<','=','<','<',' ','<',' ','<'},
    {'>',' ',' ',' ',' ',' ','>','>','>',' ','>',' ','>'},
    {'>',' ',' ',' ',' ','<','>','>','>',' ','>',' ','>'},
    {'>',' ',' ',' ',' ','<','>','<','>',' ','>',' ','<'},
    {},
    {'>',' ',' ',' ',' ','<','>','<','>',' ','>',' ','<'},
    {},
    {'>',' ',' ',' ',' ','<','>','>','>',' ','>',' ','>'},
  };
  return sign[a1][a2];
}

void Addition(Node &K,int s){//�ӷ�����
  if(K.Lenctr1<K.Lenctr2){
    swap(K.sign1,K.sign2);
    swap(K.ctr1,K.ctr2);
    swap(K.Lenctr1,K.Lenctr2);
  }
  else{
    if(strcmp(K.ctr1,K.ctr2)<0&&K.Lenctr1==K.Lenctr2){
      swap(K.sign1,K.sign2);
      swap(K.ctr1,K.ctr2);
    }
  }
  for(int i=K.Lenctr1-1,j=0;i>=0;i--,j++){//��ctr1�ַ�������ת��Ϊ��������
    K.itr1[j]=K.ctr1[i]-'0';
  }
  for(int i=K.Lenctr2-1,j=0;i>=0;i--,j++){//��ctr2�ַ�������ת��Ϊ��������
    K.itr2[j]=K.ctr2[i]-'0';
  }
	K.Lencresult=K.Lenctr1;
	for(int i=0;i<K.Lencresult;i++){
		K.iresult[i]=K.itr1[i]+K.itr2[i];//���мӷ�����
	}
  for(int i=0;i<K.Lencresult;i++){//�ж��Ƿ��λ
    if(K.iresult[i]>=10){
      K.iresult[i]%=10;
      K.iresult[i+1]++;
    }
  }
  int k=0;//�ж�K.iresult���һ������Ԫ�ز�Ϊ0���±�
  for(int i=0;i<=K.Lencresult;i++){
		if(K.iresult[i]!=0) k=i;
	}
  for(int i=k,j=0;i>=0;i--){//����������ת��Ϊ�ַ�������
    K.cresult[j++]=K.iresult[i]+'0';
  }
  K.Lencresult=k+1;
  K.signresult=K.sign1;
  if(s==0){
    cout << endl << "*�����Ľ��Ϊ��" << endl << endl;
    cout << K.signresult;
    for(int i=0;i<=k;i++){//������
      cout << K.cresult[i];
    }
    cout << endl << endl;
  }
}

void Subtraction(Node &K,int s){//��������
  if(K.Lenctr1<K.Lenctr2){
    swap(K.sign1,K.sign2);
    swap(K.ctr1,K.ctr2);
    swap(K.Lenctr1,K.Lenctr2);
    if(K.sign1=='-') K.sign1='+';
    else K.sign1='-';
  }
  else{
    if(strcmp(K.ctr1,K.ctr2)<0&&K.Lenctr1==K.Lenctr2){
      swap(K.sign1,K.sign2);
      swap(K.ctr1,K.ctr2);
    }
  }
  for(int i=K.Lenctr1-1,j=0;i>=0;i--,j++){//��ctr1�ַ�������ת��Ϊ��������
    K.itr1[j]=K.ctr1[i]-'0';
  }
  for(int i=K.Lenctr2-1,j=0;i>=0;i--,j++){//��ctr2�ַ�������ת��Ϊ��������
    K.itr2[j]=K.ctr2[i]-'0';
  }
  K.Lencresult=K.Lenctr1;
  for(int i=0;i<K.Lencresult;i++){
		K.iresult[i]=K.itr1[i]-K.itr2[i];//���м�������
	}
  for(int i=0;i<K.Lencresult;i++){//�ж��Ƿ���λ
    if(K.iresult[i]<0){
      K.iresult[i]+=10;
      K.iresult[i+1]--;
    }
  }
  int k=0;//�ж�K.iresult���һ������Ԫ�ز�Ϊ0���±�
  for(int i=0;i<=K.Lencresult;i++){
		if(K.iresult[i]!=0) k=i;
	}
  for(int i=k,j=0;i>=0;i--){//����������ת��Ϊ�ַ�������
    K.cresult[j++]=K.iresult[i]+'0';
  }
  K.Lencresult=k+1;
  if(k!=0){
    if(K.Lenctr1>=K.Lenctr2){
      K.signresult=K.sign1;
    }
    else{
      K.signresult=K.sign2;
    }
  }
  else{
    K.signresult='+';
  }
  if(s==0){
    cout << endl << "*�����Ľ��Ϊ��" << endl << endl;
    cout << K.signresult;
    for(int i=0;i<=k;i++){//������
      cout << K.cresult[i];
    }
    cout << endl << endl;
  }
}

void Multiple(Node &K,int s){//�����˷�
  if(K.Lenctr1<K.Lenctr2){
    swap(K.sign1,K.sign2);
    swap(K.ctr1,K.ctr2);
    swap(K.Lenctr1,K.Lenctr2);
  }
  else{
    if(strcmp(K.ctr1,K.ctr2)<0&&K.Lenctr1==K.Lenctr2){
      swap(K.sign1,K.sign2);
      swap(K.ctr1,K.ctr2);
    }
  }
  for(int i=K.Lenctr1-1,j=0;i>=0;i--,j++){//��ctr1�ַ�������ת��Ϊ��������
    K.itr1[j]=K.ctr1[i]-'0';
  }
  for(int i=K.Lenctr2-1,j=0;i>=0;i--,j++){//��ctr2�ַ�������ת��Ϊ��������
    K.itr2[j]=K.ctr2[i]-'0';
  }
  K.Lencresult=K.Lenctr1*K.Lenctr1;
  for(int i=0;i<K.Lenctr1;i++){
    for(int j=0;j<K.Lenctr2;j++){
      K.iresult[i+j]+=K.itr1[i]*K.itr2[j];
    }
  }
  for(int i=0;i<=K.Lencresult;i++){//�ж��Ƿ��λ
    if(K.iresult[i]>=10){//�ж�����Ԫ���Ƿ����10
      K.iresult[i+1]+=K.iresult[i]/10;//�������10�������10��λ
      K.iresult[i]%=10;
    }
  }
  int k=0;//�жϽ�����������һ����Ϊ0������Ԫ�ص��±�
  for(int i=0;i<=K.Lencresult;i++){
    if(K.iresult[i]!=0) k=i;
  }
  for(int i=k,j=0;i>=0;i--){//����������ת��Ϊ�ַ�������
    K.cresult[j++]=K.iresult[i]+'0';
  }
  K.Lencresult=k+1;
  switch(K.sign1){//�ж���������������
    case '-':
      if(K.sign2=='-') K.signresult='+';
      else K.signresult='-';
      break;
    case '+':
      if(K.sign2=='-') K.signresult=K.sign2;
      else K.signresult=K.sign1;
      break;
    default:
      if(K.sign2=='-') K.signresult=K.sign2;
      else K.signresult='+';
  }
  if(s==0){
    cout << endl << "*�����Ľ��Ϊ��" << endl << endl;
    cout << K.signresult;
    for(int i=0;i<=k;i++){//������
      cout << K.cresult[i];
    }
    cout << endl << endl;
  }
}

void Division(Node &K,int s){
  if(K.Lenctr1<K.Lenctr2){
    swap(K.sign1,K.sign2);
    swap(K.ctr1,K.ctr2);
    swap(K.Lenctr1,K.Lenctr2);
  }
  else{
    if(strcmp(K.ctr1,K.ctr2)<0&&K.Lenctr1==K.Lenctr2){
      swap(K.sign1,K.sign2);
      swap(K.ctr1,K.ctr2);
    }
  }
  for(int i=K.Lenctr1-1,j=0;i>=0;i--,j++){//��ctr1�ַ�������ת��Ϊ��������
    K.itr1[j]=K.ctr1[i]-'0';
  }
  for(int i=K.Lenctr2-1,j=0;i>=0;i--,j++){//��ctr2�ַ�������ת��Ϊ��������
    K.itr2[j]=K.ctr2[i]-'0';
  }
}

void Into(){//ʮ����ת��Ϊ�����ƣ��ַ����������ݽ�Ϊ����
  char str[MAXN];
  al:cin >> str;
  if(In(str[0])){//��ʽ������������
    cout << "\n***��ʽ�������������룡����" << endl << endl;
    Sleep(1500);
    system("cls");
    page__title("����ת��");
    goto al;
  }
  int len=strlen(str);//����str�ַ�������
  char binary[10][6]={"00000","10000","01000","11000","00100","10100","01100","11100","00010","10010"};//�����Ʊ�
  char result2[MAXN]={'0'};//�����ַ�����result2����ʼ��Ϊ'0'
  char result1[MAXN]={'0'};//�����ַ�����result1����ʼ��Ϊ'0'
  strcpy(result2,binary[(str[0]-'0')]);//�������Ʊ�������Ӧ�ַ�������result2
  for(int i=0;i<len-1;i++){
    strcpy(result1,result2);//ʹresult1��result2�ַ�����ͬ
    //�𣺸�result���������00
    for(int k=strlen(result2);k>=0;k--){
      result2[k+2]=result2[k];
    }
    result2[0]='0';
    result2[1]='0';
    //ֹ
    for(int j=0;j<strlen(result1);j++){//��ͬ�ַ�����λ���
      result2[j]=((result2[j]-'0')+(result1[j]-'0'))+'0';
    }
    for(int j=0;j<strlen(result2);j++){//�ж��ַ������Ƿ��д���2���ַ����֣����У������ǰλ��'0',ǰһλ��'1'
      if(result2[j]>='2'){
        if(result2[j]=='2') result2[j]='0';
        else result2[j]='1';
        if(result2[j+1]==NULL) result2[j+1]='0';
        result2[j+1]=((result2[j+1]-'0')+1)+'0';
      }
    }
    //�𣺸�result���������0
    for(int k=strlen(result2);k>=0;k--){
      result2[k+1]=result2[k];
    }
    result2[0]='0';
    //ֹ
    for(int j=0;j<5;j++){//����һλ���ֵĶ���������
      result2[j]=((result2[j]-'0')+(binary[(str[i+1]-'0')][j]-'0'))+'0';
    }
    for(int j=0;j<strlen(result2);j++){//�ж��ַ������Ƿ��д���2���ַ����֣����У������ǰλ��'0',ǰһλ��'1'
      if(result2[j]>='2'){
        if(result2[j]=='2') result2[j]='0';
        else result2[j]='1';
        if(result2[j+1]==NULL) result2[j+1]='0';
        result2[j+1]=((result2[j+1]-'0')+1)+'0';
      }
    }
  }
  int num=0;//��¼�ַ��������һλ��Ϊ'0'���±�
  for(int i=0;i<strlen(result2);i++){//�ж��ַ��������һλ��Ϊ'0'���±�
    if(result2[i]=='1') num=i;
  }
  cout << endl << "*�����Ľ��Ϊ��" << endl << endl;
  for(int i=num;i>=0;i--){//�ַ����������
    cout << result2[i];
  }
  cout << endl << endl;
}

void Operate(char sign,Node &K,int s){//����ȱ�ټӼ��������ж�
  switch(sign){
    case '+':s=1;//Subtraction(K,s);
      switch(K.sign1){
        case '-':
          if(K.sign2=='-') Addition(K,s);
          else Subtraction(K,s);
          break;
        case '+':
          if(K.sign2=='-') Subtraction(K,s);
          else Addition(K,s);
          break;
        default:
          if(K.sign2=='-') Subtraction(K,s);
          else Addition(K,s);
      }
      break;
    case '-':s=1;//Addition(K,s);
      switch(K.sign1){
        case '-':
          if(K.sign2=='-') Subtraction(K,s);
          else Addition(K,s);
          break;
        case '+':
          if(K.sign2=='-') Addition(K,s);
          else Subtraction(K,s);
          break;
        default:
         if(K.sign2=='-') Addition(K,s);
         else Subtraction(K,s);
      }
      break;
    case '*':s=1;Multiple(K,s);break;
    case '/':s=1;Division(K,s);break;
  }
}


void EvalauteExpression(Node &K,int s){
  char ch,ch1,a,b,x,theta;
  LinkStack OPTR,OPND;//OPTR�Ĵ�����ջ;OPND�Ĵ��������������
  InitStack(OPTR);//��ʼ��ջ
  InitStack(OPND);//��ʼ��ջ
  cin >> ch;
  Push(OPTR,ch);//#��ջ
  cin >> ch;
  if(ch=='-'){
    Push(OPND,ch);
    cin >> ch;
  }
  int count=0;//��¼ÿ�����ݵ�����λ��
  while(ch!='#'||GetTop(OPTR)!='#'){
    if(!In(ch)){//�������������0�ǵû�����1
      Push(OPND,ch);//������ջ��OPND��
      cin >> ch;//��һ���ַ�����
      ch1=ch;
      count++;//���Ϊ���֣���icount+1
    }
    else{
      if(count!=0) Push(OPND,(count+'0'));//�������λ����Ϊ0������ջ��OPND��
      count=0;//��ջ���ʼ��
      switch(Precede(GetTop(OPTR),ch)){
        case '<':{
          Push(OPTR,ch);//�����ֻ�Ϊ�������ջ��OPTR��
          cin >> ch;
          if(ch1=='-'&&ch1==ch||In(ch1)==1&&ch=='-'){
            if(ch1=='-'&&ch1==ch){
              Push(OPND,ch1);
            }
            else{
              Push(OPND,ch);
            }
            cin >> ch;
          }
          ch1=ch;
          break;}
        case '>':{//������ȼ�Ϊ >������ȡ����Ԫ�ؽ��м��㣬�ٽ������Ľ���ٴ���ջ��OPND��
          Pop(OPTR,theta);//�����Ҫ���к�������������
          Pop(OPND,a);//����Ԫ�س�ջ
          K.Lenctr1=a-'0';
          for(int i=K.Lenctr1-1;i>=0;i--){//�����ݴ���K.itr1
            Pop(OPND,K.ctr1[i]);
          }
          if(GetTop(OPND)=='-') Pop(OPND,K.sign1);
          Pop(OPND,b);//����Ԫ�س�ջ
          K.Lenctr2=b-'0';
          for(int i=K.Lenctr2-1;i>=0;i--){//�����ݴ���K.itr2
            Pop(OPND,K.ctr2[i]);
          }
          if(GetTop(OPND)=='-') Pop(OPND,K.sign2);//ȡ������λ
          swap(K.sign1,K.sign2);
          swap(K.ctr1,K.ctr2);
          swap(K.Lenctr1,K.Lenctr2);
          Operate(theta,K,s);//�жϺ������㣬�����ú�������ʵ��
          int number=0;//�жϽ�ջλ��
          if(K.signresult=='-') Push(OPND,K.signresult);//ȡ������λ
          for(int i=0;i<K.Lencresult;i++){//�����Ľ����ջ
            Push(OPND,K.cresult[i]);
            number++;
          }
          //cout << number << endl;
          Push(OPND,(number+'0'));
          number=0;
          InitNode(K);
          break;}
        case '=':{
          Pop(OPTR,x);//�����ֻ�Ϊ�������ջ��OPTR��
          cin >> ch;
          if(ch1=='-'&&ch1==ch||In(ch1)==1&&ch=='-'){
            if(ch1=='-'&&ch1==ch){
              Push(OPND,ch1);
            }
            else{
              Push(OPND,ch);
            }
            cin >> ch;
          }
          ch1=ch;
          break;}
      }
    }
  }
  char ch2,result[MAXN];
  char num;
  Pop(OPND,num);
  int clen=(num-'0');
  for(int i=clen-1;i>=0;i--){
    Pop(OPND,result[i]);
  }
  if(GetTop(OPND)=='-') Pop(OPND,ch2);
  cout << endl << "*�����Ľ��Ϊ��" << endl << endl;
  if(ch2=='-') cout << ch2;
  cout << result << endl << endl;
  /*cout <<"\nջ"<< endl;
  TraverStack(OPND);
  cout << endl;*/
}

void Factorial(){//��׳�
	long long a[250000];//����ÿһλ���õ�����
	int temp,digit,n,i,j=0;//tempÿ�εĵ���   digitÿ�ε�����λ��
	scanf("%d",&n);
	a[0]=1;//��1��ʼ��
	digit=1;//λ���ӵ�һλ��ʼ
	for(i=2;i<=n;i++)
	{
		int num=0;
		for(j=0;j<digit;j++)
		{
			temp=a[j]*i+num;//��һ������ÿһλ�����ֱ����i��
			a[j]=temp%10;//��һ������ÿһλ������������д���
			num=temp/10;
		}
		while(num)//�ж��˳�ѭ����num��ֵ�Ƿ�Ϊ0
		{
			a[digit]=num%10;//��������
			num=num/10;
			digit++;
		}
	}
	for(i=digit-1;i>=0;i--)//�������ÿһλ
		printf("%d",a[i]);
	printf("\n");
}

void Charscanf(Node &K){//��������
  char str1[MAXN],str2[MAXN];
  scanf("%s %s",str1,str2);//����һ�����ݸ���str1,���ڶ������ݸ���str2
  int Lenstr1=strlen(str1),Lenstr2=strlen(str2);
  if(str1[0]!='-'&&str1[0]!='+'){
    strcpy(K.ctr1,str1);
  }
  else{
    K.sign1=str1[0];
		for(int i=1,j=0;i<Lenstr1;i++){
			K.ctr1[j++]=str1[i];
		}
  }
  if(str2[0]!='-'&&str2[0]!='+'){
    strcpy(K.ctr2,str2);
  }
  else{
    K.sign2=str2[0];
		for(int i=1,j=0;i<Lenstr2;i++){
			K.ctr2[j++]=str2[i];
		}
  }
  K.Lenctr1=strlen(K.ctr1),K.Lenctr2=strlen(K.ctr2);
}

int main(){
  Node K;//����һ�����
  int s=0;//�ж��������Ƿ�����������sΪ0���������Ϊ��0ֵ�����������
  al:char ch;
  page_title();
  cin >> ch;
  switch(ch){//ѡ������㷨
    case '1':system("cls");page__title("�ӷ�");InitNode(K);Charscanf(K);
      switch(K.sign1){
        case '-':
          if(K.sign2=='-') Addition(K,s);
          else Subtraction(K,s);
          break;
        case '+':
          if(K.sign2=='-') Subtraction(K,s);
          else Addition(K,s);
          break;
        default:
          if(K.sign2=='-') Subtraction(K,s);
          else Addition(K,s);
      }
      break;
    case '2':system("cls");page__title("����");InitNode(K);Charscanf(K);
      switch(K.sign1){
        case '-':
          if(K.sign2=='-') Subtraction(K,s);
          else Addition(K,s);
          break;
        case '+':
          if(K.sign2=='-') Addition(K,s);
          else Subtraction(K,s);
          break;
        default:
        if(K.sign2=='-') Addition(K,s);
        else Subtraction(K,s);
      }
      break;
    case '3':system("cls");page__title("�˷�");InitNode(K);Charscanf(K);Multiple(K,s);break;
    case '4':system("cls");page__title("����");InitNode(K);Charscanf(K);break;
    case '5':system("cls");page__title("���ʽ��ֵ");cout << "���Դ˸�ʽ���룺#...���ʽ...#" << endl << endl;InitNode(K);EvalauteExpression(K,s);break;
    case '6':system("cls");page__title("����ת��");InitNode(K);Into();break;
    case '7':system("cls");page__title("�׳�");cout << "�ɼ������ݷ�Χ(1~50000)" << endl << endl;Factorial();break;
    case '8':system("cls");page__title("����");InitNode(K);break;
    default:
      cout << "\n***��ʽ�������������룡����\n" << endl;
      Sleep(1500);
      system("cls");
      goto al;
  }
  return 0;
}
