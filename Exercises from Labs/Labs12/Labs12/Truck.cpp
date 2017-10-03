#include "Truck.h"
#include<cstdio>


Truck::Truck():Car()
{
	capacity = 10;
	wheels = 10;
}

Truck::Truck(Truck &mk):Car(mk)
{
	capacity = mk.capacity;
	wheels = mk.wheels;
}

Truck::Truck(double _capacity, int _wheels, double _price, char * _engineType):Car(_price, _engineType)
{
	SetCapacity(_capacity);
	SetWheels(_wheels);
}

Truck::~Truck()
{

}


void Truck::SetCapacity(double _capacity)
{
	if (_capacity <= 0)
	{
		capacity = 0;
	}
	capacity = _capacity;
}

double Truck::GetCapacity()
{
	return capacity;
}

void Truck::SetWheels(int _wheels)
{
	if (_wheels <= 0)
	{
		wheels = 0;
	}
	wheels = _wheels;
}

int Truck::GetWheels()
{
	return wheels;
}


void Truck::Print()
{
	printf("Klasa samochodu ciezarowego: \n");
	printf("Maksymalny ladunek: %lf\nLiczba kol: %d\n", capacity, wheels);
	Car::Print();
}