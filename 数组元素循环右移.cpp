#include<iostream>
using namespace std;
int main()
{
	int n,m;
  cout<<"输入数组大小n和右移个数m"<<endl;
	cin >> n >> m;
	if(n<=100&&n>=1)
	{
		int a[n];
    cout<<"输入数组元素"<<endl;
		for(int i=0;i<n;i++)
		{
			m=m%n;
			cin >> a[m++];
		}
		int t=1;
		for(int i=0;i<n;i++)
		{
			cout << a[i];
			if(t<n)
			{
				cout << " ";
				t++;
			}
		}
	}
}
