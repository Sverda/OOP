//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#define ROWS 5
//#define COLS 5
//
//void parray(char** str, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			printf("%c\t", str[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
//int main()
//{
//	char** t = malloc(ROWS * sizeof(char*));
//	if (t == NULL)
//	{
//		printf("Can't allocate memory. \n");
//	}
//	for (int i = 0; i < ROWS; i++)
//	{
//		t[i] = calloc(COLS, sizeof(char));
//		if (t[i] == NULL)
//		{
//			printf("Can't allocate memory. \n");
//		}
//	}
//	char a = 'a';
//	for (int i = 0; i < ROWS; i++)
//	{
//		for (int j = 0; j < COLS; j++)
//		{
//			t[i][j] = a++;
//		}
//	}
//	parray(t, ROWS, COLS);
//	for (int i = 0; i < ROWS; i++)
//	{
//		free(t[i]);
//	}
//	free(t);
//}