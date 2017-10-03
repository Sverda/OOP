#include<cstdio>
#include"Person.h"
#include"OpticalInstrument.h"
#include"Car.h"
#include"Engine.h"
#define OBJECTS 5

int main() 
{
	// Person's list
	Person* phead = new Person();
	Person* pptr = phead;
	for (int i = 0; i < OBJECTS-1; i++)
	{
		pptr->next = new Person();
		pptr = pptr->next;
	}
	phead->PrintList();
	delete phead;

	// OpticalInstruments's list
	OpticalInstrument* ohead = new OpticalInstrument();
	OpticalInstrument* optr = ohead;
	for (int i = 0; i < OBJECTS - 1; i++)
	{
		optr->next = new OpticalInstrument();
		optr = optr->next;
	}
	ohead->PrintList();
	delete ohead;

	// Car's list
	Car* chead = new Car();
	Car* cptr = chead;
	for (int i = 0; i < OBJECTS - 1; i++)
	{
		cptr->next = new Car();
		cptr = cptr->next;
	}
	chead->PrintList();
	delete chead;

	// Engine's List
	Engine* ehead = new Engine();
	Engine* eptr = ehead;
	for (int i = 0; i < OBJECTS - 1; i++)
	{
		eptr->next = new Engine();
		eptr = eptr->next;
	}
	ehead->PrintList();
	delete ehead;
}