#include"MyClass.h"

MyClass::MyClass(int x)
{
	manageStaticID();
	email = new char*[count = x];
	for (int i = 0; i < count; i++)
		email[i] = new char[100];
	next = NULL;
}

MyClass::MyClass(MyClass& mk)
{
	manageStaticID();
	email = new char*[mk.count];
	count = mk.count;
	for (int i = 0; i < count; i++) {
		email[i] = new char[100];
		strcpy(email[i], mk.email[i]);
	}
	next = NULL;;
};

MyClass::~MyClass()
{
	manageStaticID();
	for (int i = 0; i < count; i++)
	{
		delete email[i];
	}
	delete email;
	delete next;
}

void MyClass::Print()
{
	printf("Identyfikator: %d\n", ID);
	for (int i = 0; i < count; i++)
	{
		printf("%s %d\n", GetEmail(i));
	}
	putchar('\n');
}

void MyClass::manageStaticID()
{
	static int globalID = 0;
	ID = globalID++;
}

int MyClass::GetCount()
{
	return count;
}

int MyClass::GetID()
{
	return ID;
}

MyClass* MyClass::Search(int id) 
{
	if (id == ID)
	{
		return this;
	}
	else
	{
		if (next != NULL)
		{
			return next->Search(id);
		}
		else
		{
			return NULL;
		}
	}
}