#include<cstdio>
#include"Car.h"
#include"Truck.h"
#include"Passenger.h"
#define OBJECTS 5

template<class T1> T1 Merge(T1* head)
{
	T1 sum;
	T1* ptr = head;
	while (ptr != nullptr)
	{
		sum += *ptr;
		ptr = ptr->next;
	}
	return sum;
}

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
	cptr = nullptr;
	Merge<Car>(chead).Print();
	delete chead;

	// Truck's list
	Truck* head = new Truck();
	Truck* ptr = head;
	for (int i = 1; i < OBJECTS; i++)
	{
		ptr->next = new Truck();
		ptr = ptr->next;
	}
	ptr = nullptr;
	Merge<Truck>(head).Print();
	delete head;
}