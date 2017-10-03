#pragma once
#include "Car.h"
class Truck :
	public Car
{
protected:
	double capacity;	// maximum load
	int wheels;	// count of wheels
protected:
	// Setters and getters
	void SetCapacity(double _capacity);
	double GetCapacity();
	void SetWheels(int _wheels);
	int GetWheels();
public:
	Truck();
	Truck(Truck &mk);
	Truck(double _capacity, int _wheels, double _price, char* _engineType);
	~Truck();
	void Print();
};

