#pragma once
#include<cstdio>

class Trapezoid
{
private:
	double x;	// wspolrzedne przeciecia dluzszej podstawy z wysokoscia
	double y;
	double p1;	// dluzsza podstawa
	double p2;	// krotsza podstawa
	double h;	// wysokosc
public:
	void Initial(double, double, double, double, double);
	void Print();
	void Conversion(double n);
};