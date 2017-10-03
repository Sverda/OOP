#include<cstdio>
#include"Trapezoid.h"
#include"Circle.h"
#include"Blejtram.h"
#define SIZE 3
#define N 1

int main()
{
	// Trapezy
	Trapezoid* t[SIZE];
	t[0] = new Trapezoid();
	t[1] = new Trapezoid(12, 12, 12, 12, 12, NULL);
	t[2] = new Trapezoid(*t[1]);

	// Kola
	Circle* c[SIZE];
	c[0] = new Circle();
	c[1] = new Circle(2, 2, 2, NULL);
	c[2] = new Circle(*c[1]);

	Blejtram* b = new Blejtram();
	for (int i = 0; i < SIZE; i++)
	{
		b->AddCircle(c[i]);
		b->AddTrap(t[i]);
	}
	b->Print();
	b->Conversion(N);
	b->Print();

	Trapezoid* nt = new Trapezoid(*c[1]);
	Circle* nc = new Circle(*t[1]);
	nt->Print();
	nc->Print();

	delete b;
}