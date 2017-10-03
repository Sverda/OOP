#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define SIZE 100
#define FILENAME "file.txt"
#define SROWS 10 /*First value of rows in array*/

FILE* getfile()
{
	FILE* file;
	/*char name[SIZE];
	printf("Input file name: ");
	scanf("%s", name);*/
	file = fopen(FILENAME, "r");
	printf("File open complete. \n");
	return file;
}

void deallocate(char** t, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		free(t[i]);
	}
	free(t);
	printf("Deallocation is over. \n");
}

void getstrings(FILE* file, char** texts, int* rows)
{
	char str[SIZE];
	int i = 0;
	while (!feof(file))
	{
		fscanf(file, "%s", str);
		int cols = strlen(str);
		//Allocate more memory if needed
		if (i >= rows)
		{
			*rows *= SROWS;
			texts = realloc(texts, *rows * sizeof(char*));
			if (texts == NULL)
			{
				printf("Can't reallocate the memory. 'n");
				deallocate(texts, rows);
				exit(0);
			}
		}
		//Allocate memory for columns and copy string
		texts[i] = malloc((cols + 1) * sizeof(char));
		if (texts[i] == NULL)
		{
			printf("Can't allocate memory for columns. \n");
			deallocate(texts, rows);
			exit(0);
		}
		strcpy(texts[i], str);
		i++;
	}
	*rows = i;
}

void printarray(char** t, int rows)
{
	printf("Printing array: \n");
	for (int i = 0; i < rows; i++)
	{
		printf("%s\n", t[i]);
	}
	putchar('\n');
}

void sort(char** t, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = i + 1; j < rows; j++)
		{
			if (strlen(t[i]) > strlen(t[j]))
			{
				char* s = t[i];
				t[i] = t[j];
				t[j] = s;
			}
		}
	}
}

int main()
{
	FILE* file = getfile();
	int rows = SROWS;
	char** texts = malloc(rows * sizeof(char*));
	if (texts == NULL)
	{
		printf("Can't allocate the memory. \n");
		exit(0);
	}
	getstrings(file, texts, &rows);
	printarray(texts, rows);
	sort(texts, rows);
	printarray(texts, rows);
	deallocate(texts, rows);
	fclose(file);
}