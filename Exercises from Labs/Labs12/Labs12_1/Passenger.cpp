#include "Passenger.h"
#include<cstdio>



void Passenger::SetBoot(double _boot)
{
	if (_boot <= 0)
	{
		boot = 10;
		return;
	}
	boot = _boot;
}

double Passenger::GetBoot()
{
	return boot;
}

void Passenger::SetDoors(int _doors)
{
	if (_doors <= 0)
	{
		doors = 4;
		return;
	}
	doors = _doors;
}

int Passenger::GetDoors()
{
	return doors;
}

void Passenger::SetFigure(char _figure)
{
	if (_figure != 'S' || _figure != 'H' || _figure != 'K' || _figure != 'V')
	{
		figure = 'S';
	}
	figure = _figure;
}

char Passenger::GetFigure()
{
	return figure;
}

Passenger::Passenger() :Car()
{
	boot = 10;
	doors = 4;
	figure = 'S';
}

Passenger::Passenger(Passenger & mk) :Car(mk)
{
	boot = mk.boot;
	doors = mk.doors;
	figure = mk.figure;
}

Passenger::Passenger(double _boot, int _doors, char _figure, double _price, char * _engineType) :Car(_price, _engineType)
{
	SetBoot(_boot);
	SetDoors(_doors);
	SetFigure(_figure);
}


Passenger::~Passenger()
{

}

void Passenger::Print()
{
	printf("Klasa samochodu osobowego:\n");
	printf("Poj. bagaznika: %lf\nIlosc drzwi: %d\nTyp sylwetki: %c\n", boot, doors, figure);
	Car::Print();
}
