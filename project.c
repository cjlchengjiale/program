#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct book
{
	int id;
	char name[31];
	char author[27];
	char publish[31];
	int store;
	int total;
	int usr[10];
	int days[10];
}books[100]={{101,"��ҹ��","��Ұ����","����������",20,20},
{102,"ǧҹ","��Ұ����","����������",20,20},
{103,"�����ӻ���","��Ұ����","����������",20,20},
{104,"����־","����","�Ļ�������",20,20},
{105,"��¥��","��ѩ��","�Ļ�������",20,20},
{106,"���μ�","��ж�","�Ļ�������",20,20},
{107,"ˮ䰴�","ʩ����","�Ļ�������",20,20},
{108,"ƽ��������","·ң","�Ļ�������",20,20},
{109,"����","�໪","�Ļ�������",20,20},
{110,"����ǧ��","���յ¡�������","���ʳ�����",20,20},
{111,"׷���ݵ���","���յ¡�������","���ʳ�����",18,20,{21,7},{5,10}},
{112,"Χ��","Ǯ����","�Ļ�������",20,20},
{113,"������","���","�Ļ�������",20,20},
{114,"����ȥ","����ɽ","�Ļ�������",19,20,{19},{11}},
{115,"����","��","���������",20,20}};

main()
{
	void page_title(char *menu_item);
	void return_confirm();
	void book_add();
	int book_show();
	int book_search();
	int book_edit();
	int book_del();
	void book_out();
	void book_in();
menu:page_title("����ѡ��");
	 printf("�����ּ�ѡ�����\n\n");
	 printf("\t\t1 ע������\t\t2 ��ʾͼ��\n");
     printf("\t\t3 ��ѯͼ����Ϣ\t\t4 �޸�ͼ����Ϣ\n");
	 printf("\t\t5 ɾ��ͼ��\t\t6 ����ͼ��\n");
	 printf("\t\t7 �黹ͼ��\t\t8 �˳�ϵͳ\n");
     printf("�밴���ּ�:\n");
	 switch(getch())
	 {
	 case '1':book_add();break;
	 case '2':book_show();break;
	 case '3':book_search();break;
	 case '4':book_edit();break;
     case '5':book_del();break;
	 case '6':book_out();break;
     case '7':book_in();break;
	 case '8':exit(0);
	 }
	 FILE *fp;
	 fp=fopen("ͼ����Ϣ","wb");
	 if(fp==NULL)
		 return -1;
	 fwrite((char*)books,sizeof(struct book),100,fp);
	 fclose(fp);
	 goto menu;
}
void page_title(char *menu_item)
{
	printf("\t\t**********��ӭʹ�������Ƽ���ѧͼ�����ϵͳ**********\n\n-%s-\n\n",menu_item);
}
void return_confirm()
{
	printf("\n����������ء���\n");
	getch();
}


void book_add()            //���ͼ��
{
	int i;
	page_title("ע������");
	for(i=0;i<100;i++)
		if(books[i].id==0)
			break;
	printf("���:");
	scanf("%d",&books[i].id);
	printf("����:");
	scanf("%s",&books[i].name);
	printf("����:");
	scanf("%s",&books[i].author);
	printf("������:");
	scanf("%s",&books[i].publish);
	printf("����:");
	scanf("%d",&books[i].total);
    books[i].store=books[i].total;
    return_confirm;
}
int book_show()                      //ͼ��չʾ
{
	int i,flag=0;
	page_title("��ʾͼ��");
	for(i=0;i<100;i++)
	{
		if(strlen(books[i].name)!=0)
		{
			printf("���:%d\t",books[i].id);
			printf("����:%s\t",books[i].name);
			printf("����:%s\t",books[i].author);
			printf("������:%s\t",books[i].publish);
			printf("����:%d\t",books[i].store);
			printf("����:%d\n",books[i].total);
			flag=1;
		}
	}
	if(flag==0)
		printf("\nû���ҵ���ؼ�¼.\n");
	return i;
}
int book_search()                     //��ѯͼ��
{
	int n,i,flag=0;
	page_title("��ѯͼ����Ϣ");
	char nam[30];
	printf("��������:");
	scanf("%s",nam);
	for(i=0;i<100;i++)
	{
		if(strcmp(books[i].name,nam)==0)
		{
			printf("���:%d\t",books[i].id);
			printf("����:%s\t",books[i].name);
			printf("����:%s\t",books[i].author);
			printf("������:%s\t",books[i].publish);
			printf("����:%d\t",books[i].store);
			printf("����:%d\n",books[i].total);
			n=i;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nû���ҵ���ؼ�¼.\n");
		return -1;
	}
	return n;
}
int book_edit()         //�޸�ͼ����Ϣ
{
	int i,id_change;
	page_title("�޸�ͼ����Ϣ");
	printf("����Ҫ�޸ĵ�ͼ����:");
	scanf("%d",&id_change);
	for(i=0;i<100;i++)
	{
		if(books[i].id==id_change)
		{
			printf("�޸�����:");
			scanf("%s",&books[i].name);
			printf("�޸�����:");
			scanf("%s",&books[i].author);
			printf("�޸ĳ�������:");
			scanf("%s",&books[i].publish);
			printf("�޸�����:");
			scanf("%d",&books[i].total);
			printf("�޸�ͼ����Ϣ�ɹ�.\n");
			books[i].store=books[i].total;
			return i;
		}
	}
	printf("\nû���ҵ���ؼ�¼.\n");
	return -1;
}
int book_del()                   //ɾ��ͼ��
{
	int i,num,j;
	page_title("ɾ��ͼ��");
	printf("������Ҫɾ����ͼ����:");
	scanf("%d",&num);
	for(i=0;i<100;i++)
	{
		if(books[i].id==num)
			for(j=i;j<100;j++)
			{
				books[j].id=books[j+1].id;
				strcpy(books[j].name,books[j+1].name);
				strcpy(books[j].publish,books[j+1].publish);
				printf("������ɾ��.\n");
				return i;
			}
	}
	printf("û���ҵ���ؼ�¼\n");
	return -1;
}
void book_out()         //����ͼ��
{
	int n,s,i,d;
	system("cls");
	page_title("����ͼ��");
	n=book_search();
	if(n!=-1 && books[n].store>0)
	{
		printf("�������֤���:");
		scanf("%d",&s);
		printf("����ɽ�����:");
		scanf("%d",&d);
		for(i=0;i<10;i++)
			if(books[n].usr[i]==0)
			{
				books[n].usr[i]=s;
				books[n].days[i]=d;
				break;
			}
			books[n].store--;
	}
	else if(n!=-1 && books[n].store==0)
		printf("������ȫ�����.\n");
	else
		;
	return_confirm();
}
void book_in()         //�黹ͼ��
{
	int n,s,i;
	system("cls");
	page_title("�黹ͼ��");
	n=book_search();
	if(n!=-1 && books[n].store<books[n].total)
	{
		printf("������ͼ��֤�б�:\n");
		for(i=0;i<10;i++)
			if(books[n].usr[i]!=0)
				printf("[%d]--%d��\n",books[n].usr[i],books[n].days[i]);
		printf("�������֤��:");
		scanf("%d",&s);
		for(i=0;i<10;i++)
		{
			if(books[n].usr[i]==s)
			{
				books[n].usr[i]=0;
				books[n].days[i]=0;
				break;
			}
		}
		books[n].store++;
	}
	if(n!=-1 && books[n].store==books[n].total)
		printf("ȫ���黹.\n");
	else if(n!=-1 && books[n].store<books[n].total)
		printf("�黹�ɹ�����лʹ��.\n");
	else
		;
	return_confirm();
}
