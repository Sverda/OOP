#include<stdio.h>

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
	printf("Dlugosc dluzszej podstawy: %lf\n", p1);
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

int main() 
{
	Trapezoid t;
	double x;	// wspolrzedne przeciecia dluzszej podstawy z wysokoscia
	double y;
	double p1;	// dluzsza podstawa
	double p2;	// krotsza podstawa
	double h;	// wysokosc
	printf("Podaj wspolrzedne przeciecia dluzszej podstawy z wysokoscia: ");
	scanf("%lf %lf", &x, &y);
	printf("Podaj dluzsza podstawe: ");
	scanf("%lf", &p1);
	printf("Podaj krotsza podstawe: ");
	scanf("%lf", &p2);
	printf("Podaj wysokosc: ");
	scanf("%lf", &h);
	t.Initial(x, y, p1, p2, h);
	t.Print();
	double n;	// prosta
	printf("Podaj wartosc prostej: ");
	scanf("%lf", &n);
	t.Conversion(n);
	t.Print();
	t.Conversion(n);
	t.Print();
}