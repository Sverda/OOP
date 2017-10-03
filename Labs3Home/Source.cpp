/*Zadanie 1.1*/
#include<stdio.h>
#include<math.h>
#define SIZE 3

struct triangle
{
	char build;
	double area;
};

void printTab(double t[])
{
	printf("Podane dane: \n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("Bok %lf\n", t[i]);
	}
}

struct triangle checkTriangle(double t[])
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("Podaj %d bok: ", i + 1);
		while (scanf_s("%lf", &t[i]) != 1 || getchar() != '\n' || t[i] < 0)
		{
			printf("Bledne dane, podaj je ponownie. \n");
			while (getchar() != '\n')
				;
			printf("Podaj %d bok: ", i + 1);
		}
	}
	struct triangle tr;
	if ((t[0] + t[1]) > t[2])
	{
		tr.build = 't';
		double p = (t[0] + t[1] + t[2]) / 2;
		tr.area = sqrt(p*(p - t[0])*(p - t[1])*(p - t[2]));
	}
	else
	{
		tr.build = 'n';
	}
	return tr;
}

int main()
{
	printf("Program sprawdza, czy z podanych bokow mozna zbudowac trojkat\ni oblicz jego pole. \n");
	printf("Autor: Damian Ubowski\n\n");
	double side[SIZE];
	struct triangle tr = checkTriangle(side);
	printTab(side);
	if (tr.build == 't')
	{
		printf("Z podanych bokow da sie zbudowac trojkata. \n");
		printf("Pole trojkata wynosi: %lf\n", tr.area);
	}
	else
	{
		printf("Z podanych bokow nie da sie zbudowac trojkata. \n");
	}
}