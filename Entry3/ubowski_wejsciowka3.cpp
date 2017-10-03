//#include<stdio.h>
//#include<string.h>
//#define CSIZE 25 /*rozmiar napisu w strukturze*/
//#define TSIZE 2 /*rozmiar tablicy*/
//
//struct text_t
//{
//	char text[CSIZE];
//	int tsize;
//};
//
//unsigned textSize(char text[])
//{
//	unsigned size = 0;
//	while (text[size] != '\0')
//	{
//		size++;
//	}
//	return size;
//}
//
//unsigned cutText(struct text_t t[])
//{
//	unsigned cuts = 0;
//	for (int i = 0; i < TSIZE; i++)
//	{
//		if (textSize(t[i].text) > t[i].tsize)
//		{
//			t[i].text[t[i].tsize] = '\0';
//			cuts++;
//		}
//	}
//	return cuts;
//}
//
//int main()
//{
//	printf("Program przycina wedlug wytycznych zadania. \n");
//	printf("Autor: Damian Ubowski \n\n");
//	struct text_t t[TSIZE];
//	for (int i = 0; i < TSIZE; i++)
//	{
//		printf("Podaj %d napis: ", i + 1);
//		while (scanf_s("%s", t[i].text, sizeof(t[i])) != 1 || getchar() != '\n')
//		{
//			printf("Bledne dane, prosze poprawic. ");
//			while (getchar() != '\n')
//				;
//			printf("Podaj %d napis: ", i + 1);
//		}
//		printf("Podaj %d dlugosc napisu: ", i + 1);
//		while (scanf_s("%d", &t[i].tsize) != 1 || getchar() != '\n' || t[i].tsize < 0)
//		{
//			printf("Bledne dane, prosze poprawic. ");
//			while (getchar() != '\n')
//				;
//			printf("Podaj %d dlugosc napisu: ", i + 1);
//		}
//	}
//	int results = cutText(t);
//	for (int i = 0; i < TSIZE; i++)
//	{
//		printf("%d\t%s\n", t[i].tsize, t[i].text);
//	}
//	printf("Liczba przyciec: %d\n\n", results);
//	printf("Koniec programu. \n");
//}