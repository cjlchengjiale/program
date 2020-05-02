#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[10000];
	int k=0,t=0,len=0,number=0;
	int b[10000];
  cout<<"请输入单词 空格划分 . 表示结束"<<endl;
	for(int i=0;i<10000;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='.')
		{
			for(int j=i;;j--)
			{
				if(a[j-1]==' ')
          number++;
				else break;
			}
			break;
		}
	}
	if(a[0]=='.') exit(0);
	len=strlen(a)-1-number;
	memset(b,sizeof(b),0);
	for(int j=0;j<len;j++)
	{
		if(a[j]!=' ')
		{
        	b[t]=++k;
		}
		if(a[j]==' '&&a[j+1]!=' ')
		{
			t++;
			k=0;
		}
	}
  cout<<"每个单词长度为"<<endl;
	for(int i=0;i<=t;i++)
	{
		if(b[i]==0) i++;
		if(i==t||b[i+1]==0) cout << b[i];
		else cout << b[i] << " ";
	}
	return 0;
}
