#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
bool compare(int a,int b)
{
	return a>b;
}
int main()
{
	long long m,k,sum=0,n=0,num=0,i=0,a[maxn];
  cout<<"please input size and max num you want add"<<endl;
	cin >> m >> k;
	memset(a,sizeof(a),0);
	for(int j=2;j<=m;j++)
	{
		n=0;
		for(int k=2;k<j;k++)
		{
			if(j%k==0)
			{
				n++;
				if(n==1) continue;
			}
		}
		if(n==0)
		{
			a[i++]=j;
		}
	}
	sort(a,a+m,compare);
	for(int i=0;i<k;i++)
	{
		sum+=a[i];
		if(a[i]!=0)
		{
			cout << a[i];
			if(a[i+1]!=0&&i!=k-1) cout << "+";
		}
		if(a[i]==0||i==k-1)
		{
			cout << "=" << sum;
			break;
		}
	}
	return 0;
}
