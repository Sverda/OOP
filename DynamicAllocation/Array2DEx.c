//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#define ROWS 5
//#define COLS 5
//#define SIZE 80
//
////tab allocation
//void talloc(int** str, int rows, int cols)
//{
//	if (str == NULL)
//	{
//		printf("Can't allocate memory. \n");
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		str[i] = calloc(cols, sizeof(int));
//		if (str[i] == NULL)
//		{
//			printf("Can't allocate memory. \n");
//		}
//	}
//	printf("Allocated new 2D array. \n");
//}
//
////tab deallocation
//void tdealloc(int** str, int rows, int cols)
//{
//	//deallocation
//	for (int i = 0; i < rows; i++)
//	{
//		free(str[i]);
//	}
//	free(str);
//	printf("Deallocation is over. \n");
//}
//
////printing 2D array
//void parray(int** str, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			printf("%d\t", str[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
//FILE* getfile()
//{
//	FILE* file;
//	char fname[SIZE];
//	printf("Input file to load: ");
//	scanf("%s", fname);
//	if ((file = fopen(fname, "r")) == NULL)
//	{
//		printf("Can't open file. \n");
//	}
//	printf("File has been loaded. \n");
//	return file;
//}
//
////read values from file
//void freadval(int** t, int rows, int cols, FILE* file)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			fscanf(file, "%d", &t[i][j]);
//			fgetc(file);
//		}
//	}
//}
//
////Program read number from file.txt and put them into allocated memory
//int main()
//{
//	int** tab = calloc(ROWS, sizeof(int*));
//	talloc(tab, ROWS, COLS);
//	FILE* file = getfile();
//	freadval(tab, ROWS, COLS, file);
//	fclose(file);
//	parray(tab, ROWS, COLS);
//	tdealloc(tab, ROWS, COLS);
//}