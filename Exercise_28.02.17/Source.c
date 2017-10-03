#include<stdio.h>
#define SIZE 5

int main()
{
	printf("Program szyfruje tekst wprowadzony przez uzytkownika.");
	printf("\nAutor: Damian Ubowski \n\n");
	char a[SIZE][SIZE];	//litery alfabetu
	char* b[SIZE*SIZE];	//wskazniki do liter
	char** c[SIZE*SIZE];
	for (int i = 0; i < SIZE*SIZE; i++)
	{
		b[i] = NULL;
	}
	char c_pom = 'a' - 1;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			c_pom++;
			if (c_pom == 'q' || c_pom == 'v')
			{
				j--;
				continue;
			}
			a[j][i] = c_pom;
		}
	}
	a[SIZE - 1][SIZE - 1] = ' ';
	//printf("Alfabet przed szyfrowaniem: \n");
	//for (int i = 0; i < SIZE; i++)
	//{
	//	for (int j = 0; j < SIZE; j++)
	//	{
	//		printf("%c\t", a[i][j]);
	//	}
	//	putchar('\n');
	//}

	//wczytywanie danych
	printf("Podaj napis do zaszyfrowanie: ");
	int textsize = 0;	//kontroluje wielkosc tekstu
	int z = 0;	//indeks dla tablicy b
	while (textsize < 25)
	{
		c_pom = getchar();
		if (c_pom == '\n')
		{
			break;
		}
		//szukanie odpowiedniej litery
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (c_pom == a[i][j])
				{
					b[z] = &a[i][j];
					z++;
				}
			}
		}
		textsize++;
		if (textsize >= 25)
		{
			printf("Tekst jest za dlugi, zostanie przyciety.\n");
		}
	}

	printf("Podales tekst: ");
	for (int i = 0; i < textsize; i++)
	{
		printf("%c", *b[i]);
	}
	putchar('\n');

	//szyfrowanie, przenoszenie rzedow tak jak w podanym przykladzie ze strony
	for (int col = 0; col < SIZE; col++)
	{
		int m = a[SIZE - 1][col];
		for (int row = SIZE - 1; row > 0; row--)
		{
			a[row][col] = a[row - 1][col];
		}
		a[0][col] = m;
	}
	//printf("Alfabet po szyfrowaniu: \n");
	//for (int i = 0; i < SIZE; i++)
	//{
	//	for (int j = 0; j < SIZE; j++)
	//	{
	//		printf("%c\t", a[i][j]);
	//	}
	//	putchar('\n');
	//}

	printf("Zaszyfrowany tekst: ");
	for (int i = 0; i < textsize; i++)
	{
		printf("%c", *b[i]);
	}
	putchar('\n');

	//przywracanie poczatkowego stanu tablicy
	for (int col = 0; col < SIZE; col++)
	{
		int m = a[0][col];
		for (int row = 0; row < SIZE; row++)
		{
			a[row][col] = a[row + 1][col];
		}
		a[SIZE - 1][col] = m;
	}

	printf("Odszyfrowany tekst: ");
	for (int i = 0; i < textsize; i++)
	{
		printf("%c", *b[i]);
	}
	putchar('\n');

	//zapelnianie tablicy C
	c_pom = 0;
	for (int i = 0; i < textsize; i++)
	{
		int m = *b[i];
		if (m != 'a' && m != 'e' && m != 'i' && m != 'o' && m != 'u' && m != 'y')
		{
			c[c_pom] = &b[i];
			c_pom++;
		}
	}
	for (int i = 0; i < textsize; i++)
	{
		int m = *b[i];
		if (m == 'a' || m == 'e' || m == 'i' || m == 'o' || m == 'u' || m == 'y')
		{
			c[c_pom] = &b[i];
			c_pom++;
		}
	}
	printf("Tekst ze zmieniona kolejnosci liter: ");
	for (int i = 0; i < textsize; i++)
	{
		printf("%c", **c[i]);
	}
	putchar('\n');

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// TESTY:
//----------------------------------------------------------------------------
//     Dane wejscia			|	Dane wyjscia				|
//----------------------------------------------------------------------------
//      preaching			|	updebghmf					|
//      highlighting		|	ghfgkhfgshmf				|
//      ethic				|	dsghb						|
//      censor				|	bdmrnp						|
//      ingredient and grid	|	hmfpdchdmszemczfphc			|
//      Censor2				|	(Program przestal dzialac)	|
//----------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////