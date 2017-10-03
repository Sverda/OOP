#include<cstdio>
#include"Person.h"
#include"OpticalInstrument.h"
#include"Car.h"
#include"Engine.h"
#include"Truck.h"
#include"Passenger.h"
#define OBJECTS 5

int main()
{
	Car* head = nullptr;
	Car* ptr = nullptr;
	Car* newelem = nullptr;

	int choose1;	// wybor typu samochodu
	char opt;	// przechowuje znak zamkniecia aplikacji
	double boot;
	int doors;
	char figure;
	double price;
	char engine[20];
	double capacity;
	int wheels;
	do
	{
		printf("Podaj rodzaj samochodu: \n 1 - osobowy\n 2 - ciezarowy\n 3 - ogolny\n");
		printf("Wybor: ");
		scanf("%d", &choose1);
		printf("\nWprowadz dane: \n");
		switch (choose1)
		{
		case 1:
			printf("Poj. bagaznika: ");
			scanf("%lf", &boot);
			printf("Ilosc drzwi: ");
			scanf("%d", &doors);
			while (getchar() != '\n');
			printf("Typ sylwetki: ");
			scanf("%c", &figure);
			printf("Cena: ");
			scanf("%lf", &price);
			printf("Typ silnika: ");
			scanf("%s", &engine);
			newelem = new Passenger(boot, doors, figure, price, engine);
			break;
		case 2:
			printf("Maksymalna pojemnosc: ");
			scanf("%lf", &capacity);
			printf("Ilosc drzwi: ");
			scanf("%d", &wheels);
			printf("Cena: ");
			scanf("%lf", &price);
			printf("Typ silnika: ");
			scanf("%s", &engine);
			newelem = new Truck(capacity, wheels, price, engine);
			break;
		case 3:
			printf("Cena: ");
			scanf("%lf", &price);
			printf("Typ silnika: ");
			scanf("%s", &engine);
			newelem = new Car(price, engine);
			break;
		default:
			printf("Brak opcji\n\n");
			break;
		}
		// dodawanie elementu na koncu listy
		if (head == nullptr)
		{
			head = newelem;
			ptr = head;
		}
		else
		{
			ptr->next = newelem;
			ptr = ptr->next;
		}
		// decyzja zamkniecia programu
		printf("Nacisnij 'e' aby wyjsc i wypisac liste lub 'k' aby kontynuowac: ");
		while (getchar() != '\n');
		opt = getchar();
		putchar('\n');
	} while (opt != 'e');

	if (head == nullptr)
	{
		return 0;
	}
	printf("Wypisz elementy ktorych cena jest wieksza niz: ");
	scanf("%lf", &price);
	head->PrintLargerThan(price);
	delete head;
}