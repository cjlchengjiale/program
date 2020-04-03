#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m=2;
	int c=0;
	int j,number=0;
	int b[n+1];
	int i=2;
	for(j=2;j<=n;j++)
	{
		b[j]=pow(2,j)-1;
	}
	for(m;m<n+1;m++)
	{
		for(int k=2;k<b[m];k++)
		{
			if(b[m]%k==0)
			{
				number++;
				if(number==1) break;
			}

		}
		if(number==0)
		{
			printf("%d\n",b[m]);
            c++;
		}
		number=0;
	}
	if(c==0)
	{
		printf("None");
	}
	return 0;
}
