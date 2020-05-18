#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
  cout<<"ÇëÊäÈënµÄ·¶Î§"<<endl;
  cout<<"n = ";
	cin>>n;
	double a[n];
	double b[n];
	int i=0;
	int t;
	double sum[n];
	double sum1=0.000;
	for(i;i<=n;i++)
	{
		a[i]=i+1;
		b[i]=2*(i+1)-1;
		if(i==(n-1))
		break;
	}
	for(int k=0;k<n;k++)
	{
		t=pow(-1,k);
		sum[k]=(a[k]/b[k])*t;
		sum1+=sum[k];
	}
	printf("%.3lf",sum1);
	return 0;
}
