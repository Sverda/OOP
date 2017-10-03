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
	next = nullptr;
}

Truck::Truck(Truck & mk) :Car(mk)
{
	wheels = mk.wheels;
	capacity = mk.capacity;
	next = nullptr;
}

Truck::Truck(double _capacity, int _wheels, double _price, char * _engineType) :Car(_price, _engineType)
{
	SetCapacity(_capacity);
	SetWheels(_wheels);
	next = nullptr;
}

Truck::~Truck()
{
	//printf("Destruktor pochodny. \n");
	//delete next;
}

void Truck::Print()
{
	printf("Klasa samochodu ciezarowego: \n");
	printf("Maksymalny ladunek: %lf\nLiczba kol: %d\n", capacity, wheels);
	Car::Print();
}

const Truck& Truck::operator+=(const Truck& mk)
{
	price += mk.price;
	SetEngineType(mk.engineType);
	capacity += mk.capacity;
	wheels = mk.wheels;
	return *this;
}

const Truck& Truck::operator=(const Truck& mk)
{
	price = mk.price;
	SetEngineType(mk.engineType);
	capacity = mk.capacity;
	wheels = mk.wheels;
	return *this;
}

const Truck operator+(const Truck& a, const Truck& b)
{
	return Truck(a.capacity + b.capacity, a.wheels + b.wheels, a.price + b.price, a.engineType);
}