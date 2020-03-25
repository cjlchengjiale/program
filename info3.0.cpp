#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<assert.h>
#define MAX_SIZE 1000
typedef struct PersonInfo
{
	char name[200];
	int sex;
	int age;
	char phone[200];
	char homedress[200];

}PersonInfo;

typedef struct AddressBook
{
	// PersonInfo persons[MAX_SIZE];
	//���ö�̬���鿪���ڴ�ռ�
	PersonInfo* persons;
	int capacity;//������С
	 int size;
}AddressBook;

void ReallocPerson(AddressBook* addr_book)
{
//	//1.ֱ��ʹ��realloc
//	//addr_book->capacity += 20;
//	//addr_book->persons = (PersonInfo*)realloc(addr_book->persons, sizeof(PersonInfo) * addr_book->capacity);
//	//2.ͨ��malloc�ֶ�����
	addr_book->capacity += 20;
	PersonInfo* newperson = (PersonInfo*)malloc(sizeof(PersonInfo) * addr_book->capacity);
	//���ɵ��ڴ��ϵ����ݿ�������
	memcpy(newperson, addr_book->persons, addr_book->size*sizeof(PersonInfo));
	//�ͷžɵ��ڴ�
	free(addr_book->persons);
	//���ڴ���λ
	addr_book->persons= newperson;
}
void save(AddressBook* addr_book)
{
	FILE* fp = fopen("address", "w");
	if (fp == NULL)
	{
		perror("�ļ���ʧ��\n");
		return;
	}
	for (int i = 0; i < addr_book->size; i++)
	{
		fwrite(&addr_book->persons[i], sizeof(PersonInfo), 1, fp);
	}
	fclose(fp);
	printf("����ɹ�\n");
}
void load(AddressBook* addr_book)
{
	FILE* fp = fopen("address", "r");
	if (fp == NULL)
	{
		perror("�ļ���ʧ��\n");
		return;
	}
	//ѭ����ȡ�ļ��е����ݣ��������ݼ��ص��ṹ����
	PersonInfo tmp = { 0 };
	while (1)
	{
		int n=fread(&tmp, sizeof(PersonInfo), 1, fp);
		if (n < 1)
		{
			break;
		}
		if (addr_book->size >= addr_book->capacity)
		{
			ReallocPerson(addr_book);
		}
		addr_book->persons[addr_book->size] = tmp;
		addr_book->size++;
	}
	fclose(fp);

}
//��ʼ������
void Init(AddressBook* addr)
{
	addr->size = 0;
	//�޸Ķ�
	addr->capacity = 20;
	addr->persons = (PersonInfo*)malloc(addr->capacity * sizeof(PersonInfo));
	for (int i = 0; i < addr->capacity; i++)
	{
		strcpy(addr->persons[i].name, "");
		addr->persons[i].sex = 0;
		addr->persons[i].age = 0;
		strcpy(addr->persons[i].homedress, "");
		strcpy(addr->persons[i].phone, "");
	}
}

int Menu()
{
	printf("--==========================-\n");
	printf("||      ͨѶ¼����ϵͳ      ||\n");
	printf("-===========================-\n");
	printf("||       1.�����ϵ��       ||\n");
	printf("||       2.ɾ����ϵ��       ||\n");
	printf("||       3.�޸���ϵ��       ||\n");
	printf("||       4.������ϵ��       ||\n");
	printf("||       5.��ӡ������ϵ��   ||\n");
	printf("||       6.ɾ��������ϵ��   ||\n");
	printf("||       7.����������       ||  \n");
	printf("||       0.�˳�             || \n");
	printf("==============================\n");
	printf("��������Ҫ���еĲ������: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void AddPersonInfo(AddressBook* addr_book)
{
	//fp = fopen("address", "wb");
	printf("�����ϵ��:\n");
	if (addr_book->size >= MAX_SIZE)
	{
		printf("��ϵ���Ѿ�����! ���ʧ��!\n");
		return;
	}
	//�޸���,�ڴ治����������
	PersonInfo* info = &addr_book->persons[addr_book->size];
	if (addr_book->size >= addr_book->capacity)
	{
		ReallocPerson(addr_book);
	}
	//PersonInfo* info = &addr_book->persons[addr_book->size];
	printf("��������Ҫ�����ϵ�˵�����:\n");
	scanf("%s", info->name);
	printf("�������Ա�(��:1  Ů:2):\n");

	while(1)
	{
		int sexs = 0;

		scanf("%d", &sexs);
		if (sexs == 1 || sexs == 2)
		{
			addr_book->persons[addr_book->size].sex = sexs;
			break;
		}
		else
		{
			printf("����������������\n");
		}
	}
	printf("����������:\n");
	scanf("%d", &info->age);
	printf("������绰:\n");
	scanf("%s", info->phone);
	printf("�������ͥסַ:\n");
	scanf("%s", info->homedress);
	addr_book->size++;
	printf("��ӳɹ�!\n");
}
void DelPersonInfo(AddressBook* addr_book)
{
	PersonInfo* info = &addr_book->persons[addr_book->size];
	int input = 0;
	printf("��������Ҫɾ������ϵ����ţ�\n");
	scanf("%d", &input);
	if (input < 0 || input >= addr_book->size)
	{
		printf("��ŷǷ�����\n");
	}
	addr_book->persons[input] = addr_book->persons[addr_book->size - 1];
	addr_book->size--;
	printf("ɾ����ɣ���\n");
}
void ModifPersonInfo(AddressBook* addr_book)
{

	int id = 0;
	printf("��������Ҫ�޸ĵ���ϵ�˱�ţ�\n");
	scanf("%d", &id);
	PersonInfo* info = &addr_book->persons[id];
	if (id < 0 || id >= addr_book->size)
	{
		printf("��ŷǷ�����\n");
		return;
	}

		printf("�������޸ĺ����������* ��ʾ���޸ĵ�ǰ�\n");
		char name[100] = { 0 };
		scanf("%s", name);
		if (!strcmp("*", name) == 0)
		{
			strcpy(info->name, name);
		}
		printf("�������޸ĺ���Ա𣺣�* ��ʾ���޸ĵ�ǰ�\n");
		int sexs = 0;
		scanf("%d", &sexs);
		if(sexs!='*')
		{
			info->sex = sexs;
		}
		printf("�������޸ĺ�����䣺��* ��ʾ���޸ĵ�ǰ�\n");
		int age=0;
		scanf("%d", &age);
		if (age != '*')
		{
			info->age =age;
		}
		printf("�������޸ĺ�ĵ绰����* ��ʾ���޸ĵ�ǰ�\n");
		char phone[200] = { 0 };
		scanf("%s", phone);
		if (!strcmp("*", phone) == 0)
		{
			strcpy(info->phone, phone);
		}
		printf("�������޸ĺ�ļ�ͥסַ����* ��ʾ���޸ĵ�ǰ�\n");
		char homedress[200] = { 0 };
		scanf("%s", homedress);
		if (!strcmp("*", homedress) == 0)
		{
			strcpy(info->homedress, homedress);
		}


	printf("�޸����\n");
	return;

}
void FindPersonInfo(AddressBook* addr_book)
{
	char name[200] = { 0 };
	printf("������Ҫ���ҵ�������\n");
	scanf("%s", name);
	for (int i = 0; i <= addr_book->size - 1; i++)
	{
		PersonInfo* info = &addr_book->persons[i];
		if (strcmp(info->name,name)==0)
		{
			printf("[%d]  %s   %s  %d   %s    %s\n", i, info->name, (info->sex== 1) ? "��" : "Ů", info->age, info->phone, info->homedress);
		}

	}
	printf("������ϣ�\n");

}
void PrintPersonInfo(AddressBook* addr_book)
{
	assert(addr_book);

	if (addr_book->size== 0)
	{
		printf("��ǰû����ϵ��!\n");
	}
	for (int i = 0; i < addr_book->size; i++)
	{
		PersonInfo* info = &addr_book->persons[i];
		printf("[%d]  %s   %s  %d   %s    %s\n", i, info->name, (info->sex)== 1 ? "��":"Ů" , info->age, info->phone, info->homedress);
	}

}
void CleanPersonInfo(AddressBook* addr_book)
{
	char input[200] = { 0 };
	printf("����Ҫ��ʽ�����Ƿ�ȷ����Y/N����\n");
	scanf("%s", input);
	if ((strcmp(input,"Y")==0))
	{
		printf("ɾ���ɹ���\n");
		addr_book->size = 0;

		return;
	}
	else
	{
		printf("ȡ���ɹ���\n");
	}

}
void SortPersonInfo(AddressBook* addr_book)
{
	for (int i = addr_book->size-1; i >=0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (strcmp(addr_book->persons[j-1].name, addr_book->persons[j].name) > 0)
			{
		       PersonInfo t = addr_book->persons[j-1];
				addr_book->persons[j-1] = addr_book->persons[j];
				addr_book->persons[j] = t;
			}
			else
				continue;
		}
	}
	printf("����ɹ���\n");
	return;
}
int main()
{
	AddressBook address_book;
	Init(&address_book);
	load(&address_book);
	//ת�Ʊ�
	typedef void(*Func)(AddressBook*);
	Func func_table[] = {
		NULL,
		AddPersonInfo,
		DelPersonInfo,
		ModifPersonInfo,
		FindPersonInfo,
		PrintPersonInfo,
		CleanPersonInfo,
		SortPersonInfo,
	};
	while (1)
	{
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(func_table)/sizeof(func_table[0]))
		{
			printf(" ��������!\n");
			continue;
		}
		if (choice == 0)
		{
			save(&address_book);
			printf(" GoodBye!\n");
			break;
		}
		func_table[choice](&address_book);

	}
	system("pause");
	return 0;
}
