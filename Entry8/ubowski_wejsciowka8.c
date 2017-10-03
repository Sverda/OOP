//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#include<ctype.h>
//#include<stdlib.h>
//#include<time.h>
//#include<assert.h>
//#include<errno.h>
//#define CSIZE25 25
//#define CSIZE50 50
//#define CSIZE100 100
//#define CSIZE200 200
//#define LOGFILE "log.txt"
//
//void SaveLog(char* text)
//{
//	time_t ntime;
//	struct tm* sntime;
//	char* ttime;
//	FILE* file = NULL;
//
//	//formatowanie czasu
//	time(&ntime);
//	sntime = localtime(&ntime);
//	ttime = asctime(sntime);
//	//zapisywanie do pliku LOGFILE
//	file = fopen(LOGFILE, "a");
//	if (file == NULL)
//	{
//		perror("Can't open log.txt file");
//		return;
//	}
//	fseek(file, 0, SEEK_END);
//	fprintf(file, "%s %s\n", ttime, text);
//	if (ferror(file))
//	{
//		perror("log.txt errer");
//		clearerr(file);
//	}
//	fclose(file);
//}
//
//void GetUserData(char** name, unsigned* n)
//{
//	char text[CSIZE100];		//stores text for log.txt
//	char tmpname[CSIZE25];		//temporary array for name
//	printf("Podaj nazwe: ");
//	scanf("%s", tmpname);
//	*name = malloc(sizeof(char) * (strlen(tmpname) + 1));
//	strcpy(*name, tmpname);
//	//Log
//	/*sprintf(text, "Pobranie od uzytkownika jego nazwy: %s", *name);
//	SaveLog(text);*/
//
//	int result;
//	printf("Podaj ilosc prob: ");
//	result = scanf("%u", n);
//	getchar();
//	assert(result == 1 && *n > 0/* && floor((double)*n) == *n*/);
//	//Log
//	/*sprintf(text, "Pobranie od uzytkownika liczby naturalnej: %d", *n);
//	SaveLog(text);*/
//}
//
//int playRound()
//{
//	int point = 1;
//	char rchar;				//random char
//	char input;				//input from user
//	char text[CSIZE100];	//text to save in log
//
//	//losowanie znaku metoda silowa
//	srand(time(NULL));
//	do
//	{
//		rchar = rand() % 122;
//	} while (!isalnum(rchar));
//	printf("Nacisnij znak %c: ", rchar);
//	//Log
//	sprintf(text, "Wylosowano znak: %c", rchar);
//	SaveLog(text);
//
//	input = getc(stdin);
//	getchar();
//	if (input != rchar)
//	{
//		printf("Bledna odpowiedz. \n");
//		point = 0;
//		sprintf(text, "Uzytkownik podal bledny znak: %c", input);
//	}
//	else
//	{
//		sprintf(text, "Uzytkownik podal poprawny znak: %c", input);
//	}
//	SaveLog(text);
//	return point;
//}
//
//void StartTest(unsigned n, unsigned* pts, double* rtime)
//{
//	*pts = 0;				//ilosc punktow
//	time_t start, finish;	//czas poczatku, konca testu
//	time_t testTime;		//czas testu
//	struct tm* strresult;	//czas testu z aktualna data
//	char cresult[CSIZE50];	//sformatowana data, zawierajaca minuty i sekundy
//
//	time(&start);
//	for (unsigned i = 0; i < n; i++)
//	{
//		*pts += playRound();
//	}
//	time(&finish);
//	*rtime = difftime(finish, start);
//	testTime = (time_t)*rtime;
//	strresult = localtime(&testTime);
//	strftime(cresult, sizeof(cresult), "%M:%S", strresult);
//	printf("Czas testu: %s\nPoprawne odpowiedzi: %d\n", cresult, *pts);
//}
//
//char* pathToFolder(char pathToFile[])
//{
//	char* newpath = malloc(sizeof(char)*(strlen(pathToFile) + 1));
//	strcpy(newpath, pathToFile);
//	for (int i = strlen(newpath); i > 0; i--)
//	{
//		if (newpath[i] == '\\')
//		{
//			newpath[i] = '\0';
//			break;
//		}
//	}
//	return newpath;
//}
//
//int fileExist(char* name)
//{
//	FILE* file = fopen(name, "r");
//	if (file == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		fclose(file);
//		return 1;
//	}
//
//}
//
//void Save(char* name, unsigned pts, double rt, char* pathToFile)
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
//	fprintf(file, "Ilosc sekund: %lf, zdobyte punkty: %d\n", rt, pts);
//	if (ferror(file))
//	{
//		perror(strerror(NULL));
//		clearerr(file);
//		SaveLog("Problem z otwartym plikiem do zapisu wynikow usera. ");
//	}
//	fclose(file);
//	free(ename);
//}
//
//int main(int argc, char* argv[])
//{
//	char* name = NULL;			//nazwa uzytkownika
//	double timeResult = 0.0;	//czas trwania testu
//	unsigned points = 0;		//zdobyte punkty
//	unsigned trials = 0;		//wszystkich prob
//	char log[CSIZE100];
//
//	SaveLog("Rozpoczecie dzialania programu");
//	GetUserData(&name, &trials);
//	//Log
//	sprintf(log, "Podana nazwa: %s, liczba naturalna: %u", name, trials);
//	SaveLog(log);
//
//	StartTest(trials, &points, &timeResult);
//	//Log
//	sprintf(log, "Zdobytych punktow: %u, czas (w sekundach): %lf", points, timeResult);
//	SaveLog(log);
//
//	Save(name, points, timeResult, argv[0]);
//	//Log
//	sprintf(log, "Zapisano wyniki do %s.txt", name);
//	SaveLog(log);
//
//	free(name);
//	SaveLog("Zakonczenie dzialania programu\n");
//	printf("Koniec programu\n\n");
//}