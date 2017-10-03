#include "Truck.h"
#include<cstdio>



void Truck::SetCapacity(double _capacity)
{
	if (_capacity <= 0)
	{
		capacity = 100;
		return;
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
		wheels = 10;
		return;
	}
	wheels = _wheels;
}

int Truck::GetWheels()
{
	return wheels;
}

Truck::Truck():Car()
{
	capacity = 100;
	wheels = 10;
}

Truck::Truck(Truck & mk) :Car(mk)
{
	wheels = mk.wheels;
	capacity = mk.capacity;
}

Truck::Truck(double _capacity, int _wheels, double _price, char * _engineType) :Car(_price, _engineType)
{
	SetCapacity(_capacity);
	SetWheels(_wheels);
}

Truck::~Truck()
{

}

void Truck::Print()
{
	printf("Klasa samochodu ciezarowego: \n");
	printf("Maksymalny ladunek: %lf\nLiczba kol: %d\n", capacity, wheels);
	Car::Print();
}
