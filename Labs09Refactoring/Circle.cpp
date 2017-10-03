#include"Circle.h"

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
	printf("Wsp. srodka: (%lf, %lf)\n", x, y);
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