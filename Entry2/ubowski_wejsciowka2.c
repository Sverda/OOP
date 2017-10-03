#include<stdio.h>
#define SIZE 5

int main()
{
	printf("Program szyfruje tekst wprowadzony przez uzytkownika.");
	printf("\nAutor: Damian Ubowski \n\n");
	char a[SIZE][SIZE];	//litery alfabetu
	char* b[SIZE*SIZE];	//wskazniki do liter
	for (int i = 0; i < SIZE*SIZE; i++)
	{
		b[i] = NULL;
	}
	char c = 'a' - 1;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			c++;
			if (c == 'q' || c == 'v')
			{
				j--;
				continue;
			}
			a[j][i] = c;
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
		c = getchar();
		if (c == '\n')
		{
			break;
		}
		//szukanie odpowiedniej litery
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (c == a[i][j])
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
		for (int row = SIZE-1; row > 0; row--)
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