#pragma once
#include"MyClass.h"

class Lecturer
{
private:
	int classCount;	// ilosc klas
public:
	MyClass* head;
public:
	Lecturer();
	Lecturer(char* fname);
	Lecturer(Lecturer& cpy);
	~Lecturer();
	void AddClass(char* fname);
	void PrintClasses();
	MyClass* SearchClasses(int);
};