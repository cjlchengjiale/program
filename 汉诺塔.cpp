#include<stdio.h>
#include<math.h>
void hanio(int a,char x,char y,char z);
int main()
{
	int n;
	scanf("%d",&n);
	hanio(n,'1','2','3');
	int num;
	num=pow(2,n)-1;
	printf("%d",num);
	return 0;
 }
void hanio(int a,char x,char y,char z)
{
	if(a==1)
	{
		printf("%c->%c\n",x,z);
	}
	else
	{
		hanio(a-1,x,z,y);
		printf("%c->%c\n",x,z);
		hanio(a-1,y,x,z);
	}
}
