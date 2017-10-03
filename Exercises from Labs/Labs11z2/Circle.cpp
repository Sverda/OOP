#include"Circle.h"

double Circle::allFields = 0;

Circle::Circle(double tx, double ty, double tr, Circle* tnext) :FigGeo(tx, ty), next(tnext)
{
	if (r <= 0)
	{
		r = 1;
	}
	else
	{
		r = tr;
	}
	addField();
}

Circle::~Circle()
{
	printf("Destruktor klasy kolo obiektu: %lf\n", x);
	subField();
	delete next;
}

void Circle::addField()
{
	double field = r*r*PI;
	allFields += field;
}

void Circle::subField()
{
	double field = r*r*PI;
	allFields -= field;
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