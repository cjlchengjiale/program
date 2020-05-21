#include<iostream>
using namespace std;
int main()
{
	int i;
	int x=0;
	int k;
  cout<<"please input n:"<<endl;
	cin >> k;
	int a;
	int m=0;
	for(i=2;i<=k;i++)
	{
		m=0;
		for(a=2;a<i;a++)
		{
		if(i%a==0)
		{
		m++;
	}
	    }
	    	if(m==0)
	    	{
	    	if(x==10)
			{
	    	printf("\n");
			x=0;
			}
	printf("%6d",i);
	x++;
			}

	}

	return 0;
}
