#include<iostream>
#include<cstring>
using namespace std;
class Student
{
public: //���еĳ�Ա������ɼ�
	//��Ա����
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
private:  //˽�еĳ�Ա�����ⲻ�ɼ�
	//��Ա������ ����
	int _number;
	int _id;
protected:  // �����ĳ�Ա�����ⲻ�ɼ�
	char name[10];
	char gender[10];
	char major[10];
};
void SetStudent()
{
	Student st;//����һ�������
	//strcpy(st.name, "123");//Ϊst�е�name��ֵ
	st.setId(20);//��Ÿ�ֵ

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
