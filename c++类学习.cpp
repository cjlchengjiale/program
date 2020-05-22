#include<iostream>
#include<cstring>
using namespace std;
class Student
{
public: //公有的成员在类外可见
	//成员函数
	void display()
	{}

	void setId(int id)
	{
		_id = id;
	}

	void setNumber(int number)
	{
		_number = number;
	}
private:  //私有的成员在类外不可见
	//成员变量， 属性
	int _number;
	int _id;
protected:  // 保护的成员在类外不可见
	char name[10];
	char gender[10];
	char major[10];
};
void SetStudent()
{
	Student st;//声明一个类变量
	//strcpy(st.name, "123");//为st中的name赋值
	st.setId(20);//序号赋值

	Student st2;
	st2.display();
	//st2._id = 10;
}
int main()
{
  //test10();
  SetStudent()
  return 0;
}
