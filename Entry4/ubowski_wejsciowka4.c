/*Damian Ubowski*/
#include<stdio.h>
#define STRSIZE 50
#define PAIRSIZE 5
#define FILE1 "text.txt"

struct para
{
	char surname[STRSIZE];
	int grade;
};

int wiersz(FILE* f, struct para *p)
{
	int i = 0;
	int index;
	int value = fscanf(f, "%d %s %d\n", &index, &(p->surname), &(p->grade)) == 3;
	return !value;
}

int main()
{
	struct para pair[PAIRSIZE];
	FILE* rfile;	//r(ead)file
	char rfname[STRSIZE];	//r(ead)f(ile)name
	FILE* wfile;	//w(rite)file
	char wfname[STRSIZE];	//w(rite)f(ile)name

	//read name of the file
	printf("Podaj nazwe pliku do otczytu: ");
	scanf_s("%s", rfname, STRSIZE);
	printf("Podaj nazwe pliku do zapisu: ");
	scanf_s("%s", wfname, STRSIZE);
	//opening file
	if ((rfile = fopen(rfname, "r")) == NULL)
	{
		printf("Nie mozna otworzyc pliku %s. \n", rfname);
	}
	if ((wfile = fopen(wfname, "w")) == NULL)
	{
		printf("Nie mozna otworzyc pliku %s. \n", wfname);
	}
	//data processing
	int index = 0;
	while (feof(rfile) == 0 && wiersz(rfile, &(pair[index])) == 0 && index < PAIRSIZE)
	{
		fprintf(wfile, "%s %d\n", pair[index].surname, pair[index].grade);
		index++;
	}
	//closing file
	if (fclose(rfile))
	{
		printf("Plik nie zostal zamkniety %s. \n", rfname);
	}
	if (fclose(wfile))
	{
		printf("Plik nie zostal zamkniety %s. \n", wfname);
	}
	//printing array
	for (int i = 0; i < index; i++)
	{
		printf("Nazwisko: %s, Ocena: %d\n", pair[i].surname, pair[i].grade);
	}
	printf("\nKoniec programu. \n\n");
}