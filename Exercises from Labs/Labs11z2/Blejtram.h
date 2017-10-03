#pragma once
#include<cstdio>
#include<cmath>
#include"Circle.h"
#include"Trapezoid.h"

class Blejtram
{
public:
	Trapezoid* headT;
	Circle* headC;


	Blejtram();
	~Blejtram();
	Trapezoid* AddTrap(Trapezoid*);
	Circle* AddCircle(Circle*);
	void Conversion(double);
	void Print();

private:
	int countT;
	int countC;
};