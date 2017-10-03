#include"Circle.h"
#include"Trapezoid.h"

Circle::Circle()
{
	x = 0;
	y = 0;
	r = 1;
	next = NULL;
}

Circle::Circle(double tx, double ty, double tr, Circle* tnext)
{
	Initial(tx, ty, tr);
	next = tnext;
}

Circle::Circle(Circle& mk)
{
	x = mk.x;
	y = mk.y;
	r = mk.r;
	next = mk.next;
}

Circle::Circle(Trapezoid& mk)
{
	x = mk.x;
	y = mk.y;
	r = 1;
	next = NULL;
}

Circle::~Circle()
{
	delete next;
}

void Circle::Initial(double tx, double ty, double tr)
{
	// wsp. srodka
	x = tx;
	y = ty;
	// promien
	if (r <= 0)
	{
		r = 1;
	}
	else
	{
		r = tr;
	}
}

void Circle::Print()
{
	printf("\nWsp. srodka: (%lf, %lf)\n", x, y);
	printf("Promien: %lf\n", r);
	double p = PI*r*r;
	printf("Pole: %lf\n", p);
}

void Circle::Conversion(double n)
{
	double d = n - x;
	if (d > 0)
	{
		x += 2 * d;
	}
	else
	{
		x -= 2 * d;
	}
}

void Circle::Translate(double vx, double vy)
{
	x += vx;
	y += vy;
}

void Circle::Symmetry(double mx, double my)
{
	double dx = mx - x;
	double dy = my - y;
	x = dx + mx;
	y = dy + my;
}