/*		Damian Ubowski		*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define SIZE 30
#define ROWS 20
#define COLS 10
#define FILENAME "file.txt"

//dealokacja tablicy
void tdealloc(char** str, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		free(str[i]);
	}
	free(str);
	printf("Dealokacja zakonczona powodzeniem. \n");
}

//wczytywanie pliku
FILE* getfile()
{
	FILE* file;
	char fname[SIZE];
	printf("Input file to load: ");
	scanf("%s", fname);
	if ((file = fopen(fname, "r")) == NULL)
	{
		printf("Can't open file. \n");
	}
	printf("Plik zostal wczytany. \n");
	return file;
}

unsigned countcols(char* tab)
{
	int cols = 0;
	while (tab[cols] != '\0')
	{
		cols++;
	}
	cols++;	//doliczanie znaku konca tekstu
	return cols;
}

char** getbin(FILE* file, int* rows)
{
	char t[ROWS][COLS];
	int i = 0;
	//wczytywanie danych do tablicy t z pliku
	while (!feof(file))
	{
		fscanf(file, "%s", t[i]);
		//sprawdzanie poprawnosci danych
		int flag = 0;
		for (int j = 0; j < COLS && t[i][j] != '\0'; j++)
		{
			if (t[i][j] != '1' && j == 0)
			{
				flag = 1;
			}
			if (t[i][j] != '1' && t[i][j] != '0')
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			i++;
		}
		else
		{
			for (int j = 0; j < COLS; j++)
			{
				t[i][j] = ' ';
			}
		}
		fgetc(file);
	}
	//alokowanie tablicy dynamicznej z dopasowanymi rozmiarami
	char** st = NULL;
	*rows = 0;
	while (t[*rows][0] == '1')
	{
		(*rows)++;
	}
	st = malloc(*rows * sizeof(char*));
	for (i = 0; i < *rows; i++)
	{
		//liczenie potrzebnych komorek pamieci
		int cols = countcols(t[i]);
		st[i] = malloc(cols * sizeof(char));
		strcpy(st[i], t[i]);
	}
	return st;
}

//wypisywanie tablicy 2D
void parray(char** str, int rows)
{
	printf("\nWartosci w tablicy: \n");
	for (int i = 0; i < rows; i++)
	{
		int cols = countcols(str[i]) - 1;
		for (int j = 0; j < cols; j++)
		{
			printf("%c\t", str[i][j]);
		}
		putchar('\n\n');
	}
}

//zamiana postaci binarnej na dziesietna
int bin2int(char* str)
{
	int cols = countcols(str);
	int value = 0;
	for (int i = 0; i < cols - 1; i++)
	{
		int num = str[i] - '0';
		value += num*(int)pow(2.0, (double)(cols - 2 - i));
	}
	return value;
}

//sortowanie przez wybor
void sort(char** t, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = i + 1; j < rows; j++)
		{
			if (bin2int(t[i]) > bin2int(t[j]))
			{
				char* p = t[i];
				t[i] = t[j];
				t[j] = p;
			}
		}
	}
}

int main()
{
	FILE* file = getfile();
	int rows;
	char** tab = getbin(file, &rows);
	//parray(tab, rows);
	for (int i = 0; i < rows; i++)
	{
		printf("Binarna liczba %s = %d\n", tab[i], bin2int(tab[i]));
	}
	putchar('\n');
	sort(tab, rows);
	for (int i = 0; i < rows; i++)
	{
		printf("Binarna liczba %s = %d\n", tab[i], bin2int(tab[i]));
	}
	putchar('\n');
	fclose(file);
	tdealloc(tab, rows);
}