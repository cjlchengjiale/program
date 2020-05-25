#include<iostream>
using namespace std;
class A1
{
public:
	A1(int a = 1,double b = 0.1)
	{
		_a = a;
		_b = b;
	}
	void display()
	{
		cout<<_a<<" "<<_b<<endl;
	}
	bool operator>(const A1& a)
	{
		return _a>a._a&&_b>a._b;
	}
private:
	int _a;
	double _b;
};
class Date
{
public:
	Date(int year = 2000,int month = 1,int day = 1)
	{
			if(year>0&&(month<13&&month>0)&&(day>0&&day<=getdays(year,month)))
			{
				_year = year;
				_month = month;
				_day = day;
			}
			else
			{
				cout<<"set day error "<<endl;
				cout<<"reset 2000-1-1"<<endl;
				_year = 2000;
				_month = 1;
				_day = 1;
			}
	}
	Date(const Date& d)
	{
		_day = d._day;
		_month = d._month;
		_year = d._year;
	}
	int getdays(int year,int month)
	{
		static int num[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		int day = num[month];
		if (month == 2
			&& (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
			++day;
		return day;
	}
	void display()
	{
		cout<<getdays(_year,_month)<<endl;
		cout<<_year<<" "<<_month<<" "<<_day<<endl;
	}
	Date& operator+=(int day)
	{
		if(day<0)
			return (*this)-=(-day);
		_day+=day;
		while(_day>getdays(_year,_month))
		{
			_day-=getdays(_year,_month);
			++_month;
			if(_month==13)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}
	Date& operator-=(int day)
	{
		if(day<0)
			return *this+=(-day);
			_day-=day;
		while(_day<0)
		{
			_month--;
			if(_month==0)
			{
				_month = 12;
				_year--;
			}
			_day+=getdays(_year,_month);
		}
	}
	Date& operator++()
	{
		return (*this)+=1;
	}
	Date operator++(int)
	{
		Date ret = *this;
		(*this)+=1;
		return ret;
	}
	Date& operator--()
	{
		return (*this)-=1;
	}
	Date operator--(int)
	{
		Date ret = *this;
		*this-=1;
		return ret;
	}
	Date operator+(int day)
	{
		Date ret = *this;
		ret += day;
		return ret;
	}

	Date operator-(int day)
	{
		Date ret = *this;
		ret -= day;
		return ret;
	}
	bool operator==(const Date& d)
	{
		return _year==d._year&&_month==d._month&&_day==d._day;
	}
	bool operator>(const Date& d)
	{
		if(_year>d._year)
			return true;
		else if(_year==d._year)
		{
			if(_month>d._month)
				return true;
			else if(_month==d._month)
			{
				if(_day>d._day)
					return true;
				else
					return false;
			}
		}
		return false;
	}
	bool operator<(const Date& d)
	{
		return !((*this)>d);
	}
	int get_year_days(int year)
	{
		if(((year%4==0)&&(year%100!=0))||year%400==0)
			return 366;
		return 365;
	}
	int operator-(Date& d)
	{
		// if(*this<d)
		// {
		// 	Date* tmp = this;
		// 	*this = d;
		// 	d = *tmp;
		// }
		if(*this==d)
			return 0;
		int flag = 1;
		Date big(*this);
		Date small(d);
		if(big<small)
		{
			Date tmp(big);
			big = small;
			small = tmp;
			flag = -1;
		}
		int day = 0;
		int year1 = big._year;
		int year2 = small._year;
		if(big._year==small._year&&big._month==small._month)
		{
			return (big._day-small._day)*flag;
		}
		day+= getdays(small._year,small._month)-small._day+big._day;
		int month1 = big._month;
		int month2 = small._month;
		if(small._year==big._year)
		{
			while(month2!=month1-1)
			{
				cout<<"1"<<endl;
				month2++;
				day+=getdays(small._year,month2);
			}
			return day*flag;
		}
		if(year1-year2>1)
		{
			while((year2+1)!=year1)
			{
				++year2;
				day+=get_year_days(year2);
			}
		}
		while(big._year!=small._year&&month1!=1)
		{
			month1--;
			day+=getdays(big._year,month1);
		}
		while(big._year!=small._year&&month2!=12)
		{
			month2++;
			day+=getdays(small._year,month2);
		}
		return day*flag;
	}
private:
	int _day;
	int _month;
	int _year;
};
