#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10000];
int number=0;
bool fact(int n)
{
	int sum=0,k=0;
	memset(a,sizeof(a),0);
	for(int i=1;i!=n;i++)
	{
		if(n%i==0)
		{
			a[k++]=i;
			sum+=i;
		}
	}
	if(n==sum)
	{
		cout << n << " = " << a[0];
		number++;
		for(int h=0;h<k;h++)
		{
			if(a[h+1]!=0&&a[h]<a[h+1])
			{
				cout << " + " << a[h+1];
			}
			else
			{
				cout << endl;
				break;
			}
		}
	}
}
int main()
{
	int m,n,g;
  cout<<"please input start place:";
  cin >> m;
  cout<<"please input end place:";
  cin >> n;
	for(;m<=n;m++)
	{
		fact(m);
	}
	if(number==0) cout << "None";
	return 0;
}
