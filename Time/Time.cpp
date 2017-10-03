#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

void checklooptime(int loopsize)
{
	printf("Rozpoczynanie petli...\n");
	time_t start, finish;
	time(&start);
	for (int i = 0; i < loopsize; i++);
	time(&finish);
	printf("Czas rozpoczecia: %s", asctime(localtime(&start)));
	printf("Czas zakonczenia: %s", asctime(localtime(&finish)));
	printf("Roznica pomiedzy startem, a koncem: %.2f\n", difftime(finish, start));
}

void checkclocks()
{
	clock_t clocks = clock();
	printf("Liczba tykniec od rozpoczecia procesu: %d\n", clocks);
	printf("Liczba sekund od rozpoczecia procesu: %d\n", clocks / CLOCKS_PER_SEC);
}

int main()
{
	checklooptime(1000000000);
}