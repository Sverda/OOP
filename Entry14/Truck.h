#pragma once
#include "Car.h"
class Truck :
	public Car
{
protected:
	double capacity;	// maximum load
	int wheels;	// count of wheels
public:
	// Setters and getters
	void SetCapacity(double _capacity);
	double GetCapacity();
	void SetWheels(int _wheels);
	int GetWheels();
	Truck* next;
public:
	Truck();
	Truck(Truck &mk);
	Truck(double _capacity, int _wheels, double _price, char* _engineType);
	~Truck();
	void Print();
	const Truck& operator+=(const Truck& mk);
	const Truck& operator=(const Truck& mk);
	friend const Truck operator+(const Truck& mk, const Truck& mk2);
};

