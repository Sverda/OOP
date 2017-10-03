#pragma once
#include<cstdio>
#include<cmath>
#include"FigGeo.h"
#include"Trapezoid.h"
#define PI (3.141592653589793)

class Circle : public FigGeo
{
	friend class Trapezoid;
private:
	double r;
	void addField();
	void subField();
public:
	Circle* next;
	static double allFields;

	Circle() :FigGeo(), r(1), next(NULL){ addField(); }
	Circle(double tx, double ty, double tr, Circle* tnext); 
	Circle(Circle& mk) :FigGeo(mk.x, mk.y), r(mk.r), next(mk.next){ addField(); }
	//Circle(Trapezoid& mk) : FigGeo(mk.x, mk.y), r(1), next(NULL){}
	~Circle();
	void Print();
	void Conversion(double);
	void Translate(double, double);
	void Symmetry(double, double);
};