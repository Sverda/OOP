#pragma once
#include<cstdio>

class Trapezoid
{
	friend class Circle;
private:
	double x;	// wspolrzedne przeciecia dluzszej podstawy z wysokoscia
	double y;
	double p1;	// dluzsza podstawa
	double p2;	// krotsza podstawa
	double h;	// wysokosc
public:
	Trapezoid* next;

	Trapezoid();
	Trapezoid(double, double, double, double, double, Trapezoid*);
	Trapezoid(Trapezoid& mk);
	Trapezoid(Circle& mk);
	~Trapezoid();
	void Initial(double, double, double, double, double);
	void Print();
	void Conversion(double n);
};