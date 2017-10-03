///*Zadanie 1.2*/
//#include<stdio.h>
//#define SIZE 6
//
//struct point
//{
//	char build;
//	int x;
//	int y;
//};
//
//struct point checkWeight(double t[])
//{
//	//wprowadzanie danych
//	for (int i = 0; i < SIZE; i=i+2)
//	{
//		printf("Podaj x %d punktu: ", i + 1);
//		while (scanf_s("lf", &t[i]) != 1 || getchar() != '\n')
//		{
//			printf("Bledne dane, popraw je. \n");
//			while (getchar() != '\n')
//				;
//			printf("Podaj x %d punktu: ", i + 1);
//		}
//		printf("Podaj y %d punktu: ", i + 1);
//		while (scanf_s("lf", &t[i+1]) != 1 || getchar() != '\n')
//		{
//			printf("Bledne dane, popraw je. \n");
//			while (getchar() != '\n')
//				;
//			printf("Podaj y %d punktu: ", i + 1);
//		}
//	}
//	struct point po;
//
//}
//
//int main()
//{
//	printf("Autor: Damian Ubowski");
//	double points[SIZE];
//	struct point p = checkWeight(points);
//}