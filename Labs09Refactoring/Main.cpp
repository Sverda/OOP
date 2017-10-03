#include<cstdio>
#include"Trapezoid.h"
#include"Circle.h"
#define SIZE 2

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
		printf("Sposob modyfikacji: \n");
		printf("\t1 - inicjalizacja\n");
		printf("\t2 - symetria osiowa\n");
		printf("Wybor: ");
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