#include"MyClass.h"

MyClass::MyClass(int x)
{
	email = new char*[count = x];
	for (int i = 0; i < count; i++)
		email[i] = new char[100];
	next = NULL;
}

MyClass::MyClass(MyClass& mk)
{
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
	for (int i = 0; i < count; i++)
	{
		delete email[i];
	}
	delete email;
}

int MyClass::GetCount()
{
	return count;
}