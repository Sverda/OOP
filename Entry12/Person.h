#pragma once
class Person
{
protected:
	char* fullName;
	char* email;
public:
	Person* next;
public:
	Person();
	Person(char* _name, char* _email);
	Person(Person &mk);
	~Person();
	// Setters and getters
	void SetFullName(char* _name);
	char* GetFullName();
	void SetEmail(char* _email);
	char* GetEmail();
	// Other methods
	void Print();
	void PrintList();
};

