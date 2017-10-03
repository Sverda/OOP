#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<errno.h>
#define CSIZE25 25
#define CSIZE50 50
#define CSIZE100 100
#define CSIZE200 200
#define LOGFILE "log.txt"

void SaveLog(char* text)
{
	time_t ntime;
	struct tm* sntime;
	char* ttime;
	FILE* file = NULL;

	//formatowanie czasu
	time(&ntime);
	sntime = localtime(&ntime);
	ttime = asctime(sntime);
	//zapisywanie do pliku LOGFILE
	file = fopen(LOGFILE, "a");
	if (file == NULL)
	{
		perror("Can't open log.txt file");
		return;
	}
	fseek(file, 0, SEEK_END);
	fprintf(file, "%s %s\n", ttime, text);
	if (ferror(file))
	{
		perror("log.txt errer");
		clearerr(file);
	}
	fclose(file);
}

void GetUserData(char** name, unsigned* n)
{
	char tmpname[CSIZE25];		//temporary array for name
	printf("Podaj nazwe: ");
	scanf("%s", tmpname);
	*name = malloc(sizeof(char) * (strlen(tmpname) + 1));
	strcpy(*name, tmpname);

	int result;
	printf("Podaj liczbe: ");
	result = scanf("%u", n);
	getchar();
	//assert(result == 1 && *n > 0/* && floor((double)*n) == *n*/);
}

//void Save(char* name, unsigned pts, char* pathToFile)
//{
//	FILE* file = NULL;
//	//dodawanie rozszerzenia .txt
//	char* ename = malloc(strlen(name) + 5);	//+1 dla '\0', +4 dla ".txt"
//	strcpy(ename, name);
//	strcat(ename, ".txt");
//	if (!fileExist(ename))
//	{
//		char* path = pathToFolder(pathToFile);
//		char log[CSIZE200];
//		sprintf(log, "Plik dla podanego nicku nie istnieje. \nZostanie utworzony w: %s\n", path);
//		printf("%s", log);
//		SaveLog(log);
//		free(path);
//	}
//	//dopisywanie na koncu pliku
//	file = fopen(ename, "a");
//	if (file == NULL)
//	{
//		perror("Can't open file");
//		SaveLog("Problem z otwarciem pliku do zapisu wynikow usera. ");
//		return;
//	}
//	fseek(file, 0L, SEEK_END);
//	fprintf(file, "Zdobyte punkty: %d\n", pts);
//	if (ferror(file))
//	{
//		perror(strerror(NULL));
//		clearerr(file);
//		SaveLog("Problem z otwartym plikiem do zapisu wynikow usera. ");
//	}
//	fclose(file);
//	free(ename);
//}

void SaveState(char* name, char c1, char c2, char input, int point)
{
	char fname[CSIZE100];
	sprintf(fname, "gra-%s.txt", name);
	FILE* file = fopen(fname, "a+");
	if (file == NULL)
	{
		perror("Can't open log.txt file");
		return;
	}
	fprintf(file, "%c %c %c %d\n", c1, c2, input, point);
	fclose(file);
}

char randChar()
{
	char rchar;
	do
	{
		rchar = rand() % 122;
		if (!islower(rchar))
		{
			rchar = tolower(rchar);
		}
	} while (!isalpha(rchar));
	return rchar;
}

int playRound(char* name, double* t)
{
	int point = 1;
	char rchar;				//random char
	char rchar2;			//random char
	char input;				//input from user
	char text[CSIZE100];	//text to save in log
	time_t start, finish;

	//losowanie znaków metoda silowa
	rchar = randChar();
	rchar2 = randChar();
	//sprawdzanie kolejnosci
	if (rchar > rchar2)
	{
		char p = rchar;
		rchar = rchar2;
		rchar2 = p;
	}
	time(&start);
	printf("Nacisnij znak z przedzialu: (%c, %c) ", rchar, rchar2);
	//Log
	sprintf(text, "Wylosowano znak: %c i %c", rchar, rchar2);
	SaveLog(text);

	input = getc(stdin);
	getchar();
	time(&finish);
	if (input >= rchar && input <= rchar2)
	{
		sprintf(text, "Uzytkownik podal poprawny znak: %c", input);
	}
	else
	{
		printf("Bledna odpowiedz. \n");
		point = 0;
		sprintf(text, "Uzytkownik podal bledny znak: %c", input);
	}
	SaveState(name, rchar, rchar2, input, point);
	SaveLog(text);
	*t = difftime(finish, start);
	return point;
}

void StartTest(unsigned n, unsigned* pts, char* name, double* time)
{
	*pts = 0;				//ilosc punktow
	double t, all = 0.0;

	for (unsigned i = 0; i < n; i++)
	{
		*pts += playRound(name, &t);
		all += t;
	}
	*time = all / n;
	printf("Sredni czas %lf\n", *time);
	printf("Poprawne odpowiedzi: %d\n", *pts);
}

void again(char* name)
{
	char text[CSIZE100];
	char fname[CSIZE100];
	sprintf(fname, "gra-%s.txt", name);
	FILE* file = fopen(fname, "r");
	if (file == NULL)
	{
		perror("Can't open file");
		return;
	}
	char c1, c2, input;
	int score;
	while (!feof(file))
	{
		fscanf(file, "%c %c %c %d\n", &c1, &c2, &input, &score);
		if (score)
		{
			continue;
		}
		printf("Nacisnij znak z przedzialu: (%c, %c) ", c1, c2);

		getchar();
		input = getc(stdin);
		if (input >= c1 && input <= c2)
		{
			sprintf(text, "Uzytkownik podal poprawny znak: %c", input);
		}
		else
		{
			printf("Bledna odpowiedz. \n");
			sprintf(text, "Uzytkownik podal bledny znak: %c", input);
		}
		//printf("%s", text);
	}
	fclose(file);
}

int main(int argc, char* argv[])
{
	srand((int)time(NULL));
	char* name = NULL;			//nazwa uzytkownika
	unsigned num;
	unsigned points = 0;		//zdobyte punkty
	char log[CSIZE100];
	int next;
	double time;

	do
	{
		SaveLog("Rozpoczecie dzialania programu");
		GetUserData(&name, &num);
		//Log
		sprintf(log, "Podana nazwa: %s, liczba naturalna: %u", name, num);
		SaveLog(log);

		StartTest(num, &points, name, &time);
		sprintf(log, "Sredni czas: %lf", time);
		SaveLog(log);
		//Log
		sprintf(log, "Zdobytych punktow: %u", points);
		SaveLog(log);

		printf("Czy chcesz poprawic swoj wynik? 1 - Tak, 0 - nie\n");
		scanf("%d", &next);
		if (next)
		{
			again(name);
		}


		printf("Czy chcesz zagrac jeszcze raz od poczatku? 1 - Tak, 0 - nie\n");
		scanf("%d", &next);
	} while (next);

	free(name);
	SaveLog("Zakonczenie dzialania programu\n");
	printf("Koniec programu\n\n");
}