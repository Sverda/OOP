#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define SIZE 27

int main()
{
	char* string = malloc(SIZE * sizeof(char));
	if (string == NULL)
	{
		printf("Can't allocate new variable. \n");
	}
	else
	{
		printf("Create new variable. \n");
	}
	string[0] = 'a';
	for (int i = 1; i < SIZE-1; i++)
	{
		string[i] = string[i - 1] + 1;
	}
	string[SIZE - 1] = '\0';
	printf("%s\n", string);
	free(string);
}