#include <cstdio>
#include"Lecturer.h"
#define FILE0 "Emails0.txt"
#define FILE1 "Emails1.txt"
#define FILE2 "Emails2.txt"
using namespace std;

int main() 
{
	printf("Wykladowca 1:\n");
	Lecturer* l0 = new Lecturer(FILE0);
	l0->AddClass(FILE0);
	l0->PrintClasses();

	printf("Wykladowca 2:\n");
	Lecturer* l1 = new Lecturer(*l0);
	l1->AddClass(FILE1);
	l1->PrintClasses();

	printf("Wykladowca 3:\n");
	Lecturer* l2 = new Lecturer();
	l2->AddClass(FILE2);
	l2->AddClass(FILE1);
	l2->AddClass(FILE0);
	l2->PrintClasses();

	delete l0;
	delete l1;
	delete l2;
}

// Konstruktor zostal wywolany dla kazdej klasy Lecturer i MyClass, czyli:
// - lecturer 0 posiada 2 klasy
// - lecturer 1 posiada 3 klasy
// - lecturer 2 posidad 3 klasy
// Laczna ilosc konstruktorow to 3+2+3+3=11, ilosc destruktorow jest taka sama. 