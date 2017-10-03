#include"Trapezoid.h"
#include"Circle.h"

Trapezoid::Trapezoid()
{
	x = 0;
	y = 0;
	p1 = 1;
	p2 = 1;
	h = 1;
	next = NULL;
}

Trapezoid::Trapezoid(double tx, double ty, double tp1, double tp2, double th, Trapezoid* tnext)
{
	Initial(tx, ty, tp1, tp2, th);
	next = tnext;
}

Trapezoid::Trapezoid(Trapezoid& mk)
{
	x = mk.x;
	y = mk.y;
	p1 = mk.p1;
	p2 = mk.p2;
	h = mk.h;
	next = mk.next;
}

Trapezoid::Trapezoid(Circle& mk)
{
	x = mk.x;
	y = mk.y;
	p1 = 1;
	p2 = 1;
	h = 1;
	next = NULL;
}

Trapezoid::~Trapezoid()
{
	delete next;
}

void Trapezoid::Initial(double tx, double ty, double tp1, double tp2, double th)
{
	// wsp. przeciecia dluzszej podstawy z wysokoscia
	x = tx;
	y = ty;
	// I podstawa
	if (tp1 <= 0)
	{
		p1 = 1;
	}
	else
	{
		p1 = tp1;
	}
	// II podstawa
	if (tp2 <= 0)
	{
		p2 = 1;
	}
	else
	{
		p2 = tp2;
	}
	// wysokosc
	if (h <= 0)
	{
		h = 1;
	}
	else
	{
		h = th;
	}
}

void Trapezoid::Print()
{
	printf("\nDlugosc dluzszej podstawy: %lf\n", p1);
	printf("Dlugosc krotszej podstawy: %lf\n", p2);
	printf("Dlugosc wysokosci: %lf\n", h);
	printf("Wspolrzedne przeciecia dluzszej podstawy z wysokoscia: (%lf, %lf)\n", x, y);
	double nx, ny;
	// lewy dolny wierzcholek
	nx = (p1 - p2) / 2.0 - x;
	ny = y;
	printf("Lewy dolny wierzcholek: (%lf, %lf)\n", nx, ny);
	// prawy dolny wierz.
	nx += p1;
	printf("Prawy dolny wierzcholek: (%lf, %lf)\n", nx, ny);
	// lewy gorny wierz.
	nx = x;
	ny = y + h;
	printf("Lewy gorny wierzcholek: (%lf, %lf)\n", nx, ny);
	// prawy gorny wierz.
	nx += p2;
	printf("Prawy gorny wierzcholek: (%lf, %lf)\n\n", nx, ny);
}


void Trapezoid::Conversion(double n)
{
	double d = n - x;	// odleglosc pomiedzy punktem i prosta
	if (d >= 0)
	{
		x = x + 2 * d - p2;
	}
	else
	{
		d *= -1.0;
		x = x - 2 * d - p2;
	}
}