#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x,t,m,n,i,j,k,l,v=1;
	char ch;
	cin>>x>>ch;
	for(i=1;;i++)
	{
		t=(2*pow(i,2))-1;
		if(t>x)
		{
			break;
		}
	}
	m=i-1;
	n=2*m-1;//行数
	l=((n-1)/2)+1;
	k=2*(pow(l,2))-1;
	//cout<<k;//
	j=x-k;//剩下的个数
	int a,b,c;
	for(a=0;a<=((n-1)/2)-1;a++)
	{
		for(b=1;b<=a;b++)
		{
			printf(" ");
		}
		for(c=1;c<=n-2*a;c++)
		{
			printf("%c",ch);
		}
		if(a==((n+1)/2)) break;
		else printf("\n");
	}
	for(a=1;a<=((n+1)/2);a++)
	{
		for(b=1;b<=((n+1)/2)-a;b++)
		{
			printf(" ");
		}
		for(c=1;c<=2*a-1;c++)
		{
			printf("%c",ch);
		}
		if(a==((n+1)/2)) break;
		else printf("\n");
	}
    cout << endl;
	cout << j;
	return 0;
}
