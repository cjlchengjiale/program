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
}books[100]={{101,"白夜行","东野圭吾","长江出版社",20,20},
{102,"千夜","东野圭吾","长江出版社",20,20},
{103,"解忧杂货店","东野圭吾","长江出版社",20,20},
{104,"三国志","陈寿","文化出版社",20,20},
{105,"红楼梦","曹雪芹","文化出版社",20,20},
{106,"西游记","吴承恩","文化出版社",20,20},
{107,"水浒传","施耐庵","文化出版社",20,20},
{108,"平凡的世界","路遥","文化出版社",20,20},
{109,"活着","余华","文化出版社",20,20},
{110,"灿烂千阳","卡勒德·胡赛尼","国际出版社",20,20},
{111,"追风筝的人","卡勒德·胡赛尼","国际出版社",18,20,{21,7},{5,10}},
{112,"围城","钱钟书","文化出版社",20,20},
{113,"我们仨","杨绛","文化出版社",20,20},
{114,"风流去","鲍鹏山","文化出版社",19,20,{19},{11}},
{115,"看见","柴静","中央出版社",20,20}};

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
menu:page_title("操作选单");
	 printf("用数字键选择操作\n\n");
	 printf("\t\t1 注册新书\t\t2 显示图书\n");
     printf("\t\t3 查询图书信息\t\t4 修改图书信息\n");
	 printf("\t\t5 删除图书\t\t6 借阅图书\n");
	 printf("\t\t7 归还图书\t\t8 退出系统\n");
     printf("请按数字键:\n");
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
	 fp=fopen("图书信息","wb");
	 if(fp==NULL)
		 return -1;
	 fwrite((char*)books,sizeof(struct book),100,fp);
	 fclose(fp);
	 goto menu;
}
void page_title(char *menu_item)
{
	printf("\t\t**********欢迎使用陕西科技大学图书管理系统**********\n\n-%s-\n\n",menu_item);
}
void return_confirm()
{
	printf("\n按任意键返回……\n");
	getch();
}


void book_add()            //添加图书
{
	int i;
	page_title("注册新书");
	for(i=0;i<100;i++)
		if(books[i].id==0)
			break;
	printf("序号:");
	scanf("%d",&books[i].id);
	printf("书名:");
	scanf("%s",&books[i].name);
	printf("作者:");
	scanf("%s",&books[i].author);
	printf("出版社:");
	scanf("%s",&books[i].publish);
	printf("数量:");
	scanf("%d",&books[i].total);
    books[i].store=books[i].total;
    return_confirm;
}
int book_show()                      //图书展示
{
	int i,flag=0;
	page_title("显示图书");
	for(i=0;i<100;i++)
	{
		if(strlen(books[i].name)!=0)
		{
			printf("序号:%d\t",books[i].id);
			printf("书名:%s\t",books[i].name);
			printf("作者:%s\t",books[i].author);
			printf("出版社:%s\t",books[i].publish);
			printf("存数:%d\t",books[i].store);
			printf("总数:%d\n",books[i].total);
			flag=1;
		}
	}
	if(flag==0)
		printf("\n没有找到相关记录.\n");
	return i;
}
int book_search()                     //查询图书
{
	int n,i,flag=0;
	page_title("查询图书信息");
	char nam[30];
	printf("输入书名:");
	scanf("%s",nam);
	for(i=0;i<100;i++)
	{
		if(strcmp(books[i].name,nam)==0)
		{
			printf("序号:%d\t",books[i].id);
			printf("书名:%s\t",books[i].name);
			printf("作者:%s\t",books[i].author);
			printf("出版社:%s\t",books[i].publish);
			printf("存数:%d\t",books[i].store);
			printf("总数:%d\n",books[i].total);
			n=i;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\n没有找到相关记录.\n");
		return -1;
	}
	return n;
}
int book_edit()         //修改图书信息
{
	int i,id_change;
	page_title("修改图书信息");
	printf("输入要修改的图书编号:");
	scanf("%d",&id_change);
	for(i=0;i<100;i++)
	{
		if(books[i].id==id_change)
		{
			printf("修改书名:");
			scanf("%s",&books[i].name);
			printf("修改作者:");
			scanf("%s",&books[i].author);
			printf("修改出版社名:");
			scanf("%s",&books[i].publish);
			printf("修改总数:");
			scanf("%d",&books[i].total);
			printf("修改图书信息成功.\n");
			books[i].store=books[i].total;
			return i;
		}
	}
	printf("\n没有找到相关记录.\n");
	return -1;
}
int book_del()                   //删除图书
{
	int i,num,j;
	page_title("删除图书");
	printf("输入所要删除的图书编号:");
	scanf("%d",&num);
	for(i=0;i<100;i++)
	{
		if(books[i].id==num)
			for(j=i;j<100;j++)
			{
				books[j].id=books[j+1].id;
				strcpy(books[j].name,books[j+1].name);
				strcpy(books[j].publish,books[j+1].publish);
				printf("该书已删除.\n");
				return i;
			}
	}
	printf("没有找到相关记录\n");
	return -1;
}
void book_out()         //借阅图书
{
	int n,s,i,d;
	system("cls");
	page_title("借阅图书");
	n=book_search();
	if(n!=-1 && books[n].store>0)
	{
		printf("输入借书证序号:");
		scanf("%d",&s);
		printf("输入可借天数:");
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
		printf("此书已全部借出.\n");
	else
		;
	return_confirm();
}
void book_in()         //归还图书
{
	int n,s,i;
	system("cls");
	page_title("归还图书");
	n=book_search();
	if(n!=-1 && books[n].store<books[n].total)
	{
		printf("借阅者图书证列表:\n");
		for(i=0;i<10;i++)
			if(books[n].usr[i]!=0)
				printf("[%d]--%d天\n",books[n].usr[i],books[n].days[i]);
		printf("输入借书证号:");
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
		printf("全部归还.\n");
	else if(n!=-1 && books[n].store<books[n].total)
		printf("归还成功，感谢使用.\n");
	else
		;
	return_confirm();
}
