#pragma once
#include <cstring>

class MyClass
{
private:
	char **email;
	int count;	// ilosc wpisow
public:
	MyClass* next;
public:
	MyClass(int x);
	MyClass(MyClass& mk);	// konstruktor kopiuj¹cy
	~MyClass();
	void setemail(char* adres, int idx) { strcpy(email[idx], adres); };
	char* getemail(int idx) { return email[idx]; };
	int GetCount();
};