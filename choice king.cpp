#include<iostream>
#include <cstdlib>
using namespace std;
int main(void)
{
	int i, cnt, n , length;
	cin >> n;
	length = n;
	int *s = (int *)malloc(sizeof(int)*length);
	for(i = 0; i < length; i ++)
	{
		s[i] = i+1;
	}
	i = cnt = 0;
	while(1) {
		if(n == 1)
		{
			break;
		}
		if(s[i] != 0)
		{
			cnt ++;
		}
		if(cnt == 3)
		{
			s[i] = 0;
			cnt = 0;
			n --;
		}
		i = (i+1) % length;
	}
	for(int i = 0; i < length; i ++)
	{
		if(s[i] != 0)
		{
			cout << s[i];
			break;
		}
	}

	return 0;
}
