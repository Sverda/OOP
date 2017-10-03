#pragma once
#include<cstdio>
#include"FigGeo.h"
#include"Circle.h"

class Trapezoid: public FigGeo
{
	friend class Circle;
private:
	//double x;	// wspolrzedne przeciecia dluzszej podstawy z wysokoscia
	//double y;
	double p1;	// dluzsza podstawa
	double p2;	// krotsza podstawa
	double h;	// wysokosc
public:
	Trapezoid* next;

	Trapezoid() :FigGeo(), p1(1), p2(1), h(1), next(NULL){}
	Trapezoid(double, double, double, double, double, Trapezoid*);
	Trapezoid(Trapezoid& mk) :FigGeo(mk), p1(mk.p1), p2(mk.p2), h(mk.h), next(mk.next){}
	//Trapezoid(Circle& mk) :FigGeo(mk.x, mk.y), p1(1), p2(1), h(1), next(NULL){}
	~Trapezoid();
	void Print();
	void Conversion(double n);
};