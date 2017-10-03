#include<cstdio>
#include"Car.h"
#include"Truck.h"
#include"Passenger.h"
#define OBJECTS 5

int main()
{
	/*Truck A1, A2;
	A2 = A1 + A2;
	A2.Print();

	Passenger B1, B2;
	B2 = B1 + B2;
	B2.Print();*/

	Truck* sum = new Truck();
	Truck* head = new Truck();
	Truck* ptr = head;
	for (int i = 1; i < OBJECTS; i++)
	{
		ptr->next = new Truck();
		ptr = ptr->next;
	}
	// Sumowanie
	ptr = head;
	while (ptr != nullptr)
	{
		*sum = *sum + *ptr;
		ptr = ptr->next;
	}
	sum->Print();
	delete sum;
	delete head;
}