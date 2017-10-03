#include<cstdio>
#include"Car.h"
#include"Truck.h"
#include"Passenger.h"
#define OBJECTS 5

int main()
{
	// Car's list
	Car* chead = new Car();
	Car* cptr = chead;
	for (int i = 0; i < OBJECTS - 1; i++)
	{
		cptr->next = new Car();
		cptr = cptr->next;
	}
	//chead->PrintList();
	// Checking new operator
	Car* newCar = new Car();
	cptr = chead;
	while (cptr != nullptr)
	{
		*newCar += *cptr;
		cptr = cptr->next;
	}
	newCar->Print();
	delete newCar;
	delete chead;
}