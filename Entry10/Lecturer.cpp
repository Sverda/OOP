#include"Lecturer.h"
#include<cstdio>
#include<assert.h>
#define ASIZE 20	/*maksymalna ilosc wpisow w pliku*/
#define CSIZE 100	/*rozmiar bufora*/

Lecturer::Lecturer()
{
	classCount = 0;
	head = NULL;
}

Lecturer::Lecturer(char* fname)
{
	classCount = 0;
	head = NULL;
	AddClass(fname);
}

Lecturer::Lecturer(Lecturer& cpy)
{
	classCount = 0;
	MyClass* cptr = cpy.head;
	MyClass* ptr = head = new MyClass(*cptr);
	classCount++;
	while (cptr->next != NULL)
	{
		cptr = cptr->next;
		ptr->next = new MyClass(*cptr);
		ptr = ptr->next;
		classCount++;
	}
	ptr->next = NULL;
}

Lecturer::~Lecturer()
{
	// usuwanie listy
	MyClass* ptr = NULL;
	for (int i = 0; i < classCount; i++)
	{
		ptr = head;
		for (int j = i + 1; j < classCount; j++)
		{
			ptr = ptr->next;
		}
		delete ptr;
	}
}

void Lecturer::AddClass(char* fname)
{
	MyClass* ptr = head;	// wskaznik elementu listy
	FILE* file = NULL;
	char buffor[ASIZE][CSIZE];	// emaile odczytane z pliku
	int n = 0;	// licznik krotek w pliku
	// odczytywanie pliku
	file = fopen(fname, "r");
	//assert(file == NULL);
	while (!feof(file))
	{
		fscanf(file, "%s\n", buffor[n]);
		n++;
	}
	// dodawanie klasy na koncu listy
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new MyClass(n);
		for (int i = 0; i < n; i++)
		{
			ptr->next->setemail(buffor[i], i);
		}
		ptr->next->next = NULL;
	}
	else
	{
		head = new MyClass(n);
		for (int i = 0; i < n; i++)
		{
			head->setemail(buffor[i], i);
		}
		head->next = NULL;
	}
	fclose(file);
	classCount++;
}

void Lecturer::PrintClasses()
{
	MyClass* ptr = head;
	int count;
	if (ptr == NULL)
	{
		printf("Wykladowca nie ma zadnej klasy. \n");
		return;
	}
	while (ptr != NULL)
	{
		printf("Klasa: \n");
		count = ptr->GetCount();
		for (int i = 0; i < count; i++)
		{
			printf("%s\n", ptr->getemail(i));
		}
		putchar('\n');
		ptr = ptr->next;
	}
}