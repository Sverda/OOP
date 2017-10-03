#pragma once
#include "Car.h"
class Truck :
	public Car
{
protected:
	double capacity;
	int wheels;
protected:
public:
	Truck();
	Truck(Truck &mk);
	Truck(double _capacity, int _wheels, double _price, char * _engineType);
	~Truck();
	void Print();
	//Setters and getters
	void SetCapacity(double _capacity);
	double GetCapacity();
	void SetWheels(int _wheels);
	int GetWheels();
};

