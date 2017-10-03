#pragma once
#include<cstdio>
#include<cmath>
#define PI (3.141592653589793)

class Circle
{
	friend class Trapezoid;
private:
	double x, y, r;
public:
	Circle* next;

	Circle();
	Circle(double, double, double, Circle*);
	Circle(Circle& mk);
	Circle(Trapezoid& mk);
	~Circle();
	void Initial(double, double, double);
	void Print();
	void Conversion(double);
	void Translate(double, double);
	void Symmetry(double, double);
};