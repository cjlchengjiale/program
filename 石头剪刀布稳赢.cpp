#include<stdio.h>
#include<string.h>
int main()
{
	int a,b=0;
  printf("����ƽ�ּ������\n");
	scanf("%d",&a);
	char ch[200000][10];
	int i;
	int h=0;
  printf("�������� JianDao  ChuiZi  Bu  ������End��ʾ����\n");
	for(i=0;;i++)
	{
		scanf("%s",ch[i]);
		b++;
		if(strcmp(ch[i],"End")==0) break;
	}
	b=b-1;
	for(int k=0;k<b;k++)
	{
		if(h==a)
		{
			if(strcmp(ch[k],"ChuiZi")==0)
		{
		    printf("ChuiZi\n");
		    h=0;
		}
		if(strcmp(ch[k],"Bu")==0)
		{
		    printf("Bu\n");
		    h=0;
		}
		if(strcmp(ch[k],"JianDao")==0)
		{
		    printf("JianDao\n");
		    h=0;
		}
	}
	else{
		if(strcmp(ch[k],"ChuiZi")==0)
		{
		    printf("Bu\n");
		    h++;
		}
		if(strcmp(ch[k],"Bu")==0)
		{
		    printf("JianDao\n");
		    h++;
		}
		if(strcmp(ch[k],"JianDao")==0)
		{
		    printf("ChuiZi\n");
		    h++;
		}
	}
	}
	return 0;
}
