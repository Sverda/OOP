#pragma once
#include<cstdio>
#include<cmath>
#define PI (3.141592653589793)

class Circle
{
private:
	double x, y, r;
public:
	void Initial(double, double, double);
	void Print();
	void Conversion(double);
	void Translate(double, double);
	void Symmetry(double, double);
};