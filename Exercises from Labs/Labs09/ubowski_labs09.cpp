#include<stdio.h>
#include<math.h>
#define PI (3.141592653589793)
#define SIZE 2

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

class Circle
{
private:
	double x, y, r;
public:
	void Initial(double, double, double);
	void Print();
	void Conversion(double);
	void Translate(double, double);
	void Symmetry(double, double);
};

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

int main()
{
	double x, y, r;
	double n1;
	double p1;	// dluzsza podstawa
	double p2;	// krotsza podstawa
	double h;	// wysokosc
	char s;	//wybor figury
	int n;	//os
	Trapezoid t[SIZE];
	Circle c[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		t[i].Initial(1, 1, 1, 1, 1);
		c[i].Initial(1, 1, 1);
	}
	printf("Ktora figure chcesz zmodyfikowac?\n");
	printf("\t1 - Kolo\n");
	printf("\t2 - Trapez\n");
	printf("Wybor: ");
	s = getchar();
	printf("Wybierz nr figury z zakresu [0, %d]: ", SIZE - 1);
	scanf("%d", &n);
	switch (s)
	{
	case '1':
		printf("Sposob modyfikacji: \n");
		printf("\t1 - inicjalizacja\n");
		printf("\t2 - symetria osiowa\n");
		printf("\t3 - translacja\n");
		printf("\t4 - symetria punktowa\n");
		printf("Wybor: ");
		getchar();
		s = getchar();
		switch (s)
		{
		case '1':
			printf("Podaj x, y, r: ");
			scanf("%lf %lf %lf", &x, &y, &r);
			c[n].Initial(x, y, r);
			c[n].Print();
			break;
		case '2':
			printf("Podaj os: ");
			scanf("%lf", &n1);
			c[n].Conversion(n1);
			c[n].Print();
			break;
		case '3':
			printf("Vektor translacji: ");
			scanf("%lf %lf", &x, &y);
			c[n].Translate(x, y);
			c[n].Print();
			break;
		case '4':
			printf("Punkt symetrii: ");
			scanf("%lf %lf", &x, &y);
			c[n].Symmetry(x, y);
			c[n].Print();
			break;
		}
		break;
	case '2':
		//scanf("%d", &n);
		printf("Sposob modyfikacji: \n");
		printf("\t1 - inicjalizacja\n");
		printf("\t2 - symetria osiowa\n");
		printf("Wybor: ");
		//getchar();
		s = getchar();
		scanf("%c", &s);
		switch (s)
		{
		case '1':
			printf("Podaj wspolrzedne przeciecia dluzszej podstawy z wysokoscia: ");
			scanf("%lf %lf", &x, &y);
			printf("Podaj dluzsza podstawe: ");
			scanf("%lf", &p1);
			printf("Podaj krotsza podstawe: ");
			scanf("%lf", &p2);
			printf("Podaj wysokosc: ");
			scanf("%lf", &h);
			t[n].Initial(x, y, p1, p2, h);
			t[n].Print();
			break;
		case '2':
			printf("Podaj os: ");
			scanf("%lf", &n1);
			t[n].Conversion(n1);
			t[n].Print();
			break;
		}
		break;
	}
	printf("Koniec programu\n\n");
}