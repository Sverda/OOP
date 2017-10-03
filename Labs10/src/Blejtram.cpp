#include<cstdio>
#include"Blejtram.h"
#include"Circle.h"
#include"Trapezoid.h"
#define ASIZE 20	/*maksymalna ilosc wpisow w pliku*/
#define CSIZE 100	/*rozmiar bufora*/

Blejtram::Blejtram()
{
	headC = NULL;
	headT = NULL;
	countC = 0;
	countT = 0;
}

Blejtram::~Blejtram()
{
	delete headC;
	delete headT;
}

Trapezoid* Blejtram::AddTrap(Trapezoid* t)
{
	Trapezoid* ptr = headT;
	// dodawanie klasy na koncu listy
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new Trapezoid(*t);
		ptr->next->next = NULL;
	}
	else
	{
		headT = new Trapezoid(*t);
		headT->next = NULL;
	}
	countT++;
	return ptr;
}

Circle* Blejtram::AddCircle(Circle* c)
{
	Circle* ptr = headC;
	// dodawanie klasy na koncu listy
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new Circle(*c);
		ptr->next->next = NULL;
	}
	else
	{
		headC = new Circle(*c);
		headC->next = NULL;
	}
	countT++;
	return ptr;
}


void Blejtram::Conversion(double n)
{
	// Trapezy
	Trapezoid* ptrT = headT;
	while (ptrT != NULL)
	{
		ptrT->Conversion(n);
		ptrT = ptrT->next;
	}
	// Kola
	Circle* ptrC = headC;
	while (ptrC != NULL)
	{
		ptrC->Conversion(n);
		ptrC = ptrC->next;
	}
}

void Blejtram::Print()
{
	// Trapezy
	printf("\nTrapezy: \n");
	Trapezoid* ptr = headT;
	while (ptr != NULL)
	{
		ptr->Print();
		ptr = ptr->next;
	}
	// Kola
	printf("\nKola: \n");
	Circle* ptrC = headC;
	while (ptrC != NULL)
	{
		ptrC->Print();
		ptrC = ptrC->next;
	}
}