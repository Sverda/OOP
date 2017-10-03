#pragma once
#include "Car.h"
class Passenger :
	public Car
{
protected:
	double boot;
	int doors;	// count of doors
	char figure;	// H - hantchback, S - sedan, K - kombi, V - van
protected:
	// Setters and getters
	void SetBoot(double _boot);
	double GetBoot();
	void SetDoors(int _doors);
	int GetDoors();
	void SetFigure(char _figure);
	char GetFigure();
public:
	Passenger();
	Passenger(Passenger &mk);
	Passenger(double _boot, int _doors, char _figure, double _price, char* _engineType);
	~Passenger();
	void Print();
	const Passenger& operator+=(const Passenger& mk);
	const Passenger& operator=(const Passenger& mk);
	friend const Passenger operator+(const Passenger& mk, const Passenger& mk2);
};

