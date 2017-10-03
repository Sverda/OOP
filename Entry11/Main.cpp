#include <cstdio>
#include"Lecturer.h"
#define FILE0 "Emails0.txt"
#define FILE1 "Emails1.txt"
#define FILE2 "Emails2.txt"
#define FILE3 "Emails3.txt"
#define FILE4 "Emails4.txt"
#define FILE5 "Emails5.txt"
using namespace std;

int main() 
{
	printf("Wykladowca:\n");
	Lecturer* l0 = new Lecturer(FILE0);
	l0->AddClass(FILE1);
	l0->AddClass(FILE2);
	l0->AddClass(FILE3);
	l0->AddClass(FILE4);
	l0->AddClass(FILE5);
	l0->PrintClasses();

	printf("Klase z ktorym ID szukasz?\n Odpowiedz: ");
	int id;
	scanf("%d", &id);
	MyClass* searchedClass = l0->SearchClasses(id);
	if (searchedClass == NULL)
	{
		printf("\nPodana klasa nie istnieje. \n");
	}
	else
	{
		printf("\nZnalezion klasa: \n");
		searchedClass->Print();
	}

	delete l0;
}

// Konstruktor zostal wywolany dla kazdej klasy Lecturer i MyClass, czyli:
// - lecturer 0 posiada 2 klasy
// - lecturer 1 posiada 3 klasy
// - lecturer 2 posidad 3 klasy
// Laczna ilosc konstruktorow to 3+2+3+3=11, ilosc destruktorow jest taka sama. 