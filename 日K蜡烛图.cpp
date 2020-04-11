#include<iostream>
using namespace std;
int main()
{
	double open,high,low,close;
	cin>>open>>high>>low>>close;
	if(open>close)
	{
		cout << "BW-Solid";
		if(low<open&&low<close)
		{
			if(high>open&&high>close)
			{
				cout << " with Lower Shadow and Upper Shadow";
				exit(0);
			}
			else
			{
				printf(" with Lower Shadow");
				exit(0);
			}
		}
		if(high>open&&high>close)
		{
			printf(" with Upper Shadow");
			exit(0);
		}
	}
	else
	{
		if(open==close)
		{
			printf("R-Cross");
			if(low<open&&low<close)
			{
				if(high>open&&high>close)
				{
					cout << " and Upper Shadow";
					exit(0);
				}
				else
				{
					printf(" with Lower Shadow");
					exit(0);
				}
			}
			if(high>open&&high>close)
			{
				printf(" with Upper Shadow");
				exit(0);
			}
		}
		else
		{
			cout << "R-Hollow";
			if(low<open&&low<close)
			{
				if(high>open&&high>close)
				{
					cout << " and Upper Shadow";
					exit(0);
				}
				else
				{
					printf(" with Lower Shadow");
					exit(0);
				}
			}
			if(high>open&&high>close)
			{
				printf(" with Upper Shadow");
				exit(0);
			}
		}
	}
	return 0;
 }
