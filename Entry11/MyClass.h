#pragma once
#include <cstring>
#include<cstdio>

class MyClass
{
private:
	char **email;
	int count;	// ilosc wpisow
	int ID;
public:
	MyClass* next;
private:
	void manageStaticID();	//true - inkrementacja ID, false - dekrementacja
public:
	MyClass(int x);
	MyClass(MyClass& mk);	// konstruktor kopiuj¹cy
	~MyClass();
	void Print();
	void SetEmail(char* adres, int idx) { strcpy(email[idx], adres); };
	char* GetEmail(int idx) { return email[idx]; };
	int GetCount();
	int GetID();
	MyClass* Search(int);
};