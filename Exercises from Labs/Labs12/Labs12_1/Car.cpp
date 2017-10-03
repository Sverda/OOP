#include "Car.h"
#include<cstring>
#include<cstdio>

void Car::SetPrice(double _price)
{
	if (_price < 0)
	{
		price = 0;
	}
	else
	{
		price = _price;
	}
}

double Car::GetPrice()
{
	return price;
}

void Car::SetEngineType(char * _type)
{
	delete engineType;
	int len = strlen(_type);
	engineType = new char[len + 1];
	strcpy(engineType, _type);
}

char * Car::GetEngineType()
{
	return engineType;
}

Car::Car()
{
	engineType = nullptr;
	SetPrice(0);
	SetEngineType("Combustion");
	next = nullptr;
}

Car::Car(double _price, char * _engineType)
{
	engineType = nullptr;
	SetPrice(_price);
	SetEngineType(_engineType);
	next = nullptr;
}

Car::Car(Car & mk)
{
	engineType = nullptr;
	SetPrice(mk.price);
	SetEngineType(mk.engineType);
	next = nullptr;
}

Car::~Car()
{
	delete engineType;
	delete next;
	//printf("Deleting element. \n");
}

void Car::Print()
{
	printf("Car: \n");
	printf("Price: %lf\nEngine type: %s\n\n", price, engineType);
}

void Car::PrintList()
{
	Print();
	if (next != nullptr)
	{
		next->PrintList();
	}
}
