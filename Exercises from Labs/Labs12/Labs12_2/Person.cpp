#include "Person.h"
#include<cstring>
#include<cstdio>

void Person::SetFullName(char * _name)
{
	delete fullName;
	int len = strlen(_name);
	fullName = new char[len + 1];
	strcpy(fullName, _name);
}

char * Person::GetFullName()
{
	return fullName;
}

void Person::SetEmail(char * _email)
{
	delete email;
	int len = strlen(_email);
	email = new char[len + 1];
	strcpy(email, _email);
}

char * Person::GetEmail()
{
	return email;
}

Person::Person()
{
	email = nullptr;
	fullName = nullptr;
	SetEmail("email@gmail.com");
	SetFullName("Name, Surname");
	next = nullptr;
}

Person::Person(char * _name, char * _email)
{
	email = nullptr;
	fullName = nullptr;
	SetFullName(_name);
	SetEmail(_email);
	next = nullptr;
}

Person::Person(Person & mk)
{
	email = nullptr;
	fullName = nullptr;
	SetFullName(mk.fullName);
	SetEmail(mk.email);
	next = nullptr;
}


Person::~Person()
{
	delete fullName;
	delete email;
	delete next;
}

void Person::Print()
{
	printf("Person: \n");
	printf("Full name; %s\nEmail: %s\n\n", fullName, email);
}

void Person::PrintList()
{
	Print();
	if (next != nullptr)
	{
		next->PrintList();
	}
}
