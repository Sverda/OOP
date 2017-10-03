#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define CSIZE 50
#define FILENAME "file.txt"

struct student {
	int i_num;
	char name[CSIZE];
	float mark;
	struct student *next;
};

void savedata(struct student** head, int row)
{
	FILE* file;
	printf("Input file name to save: ");
	char name[CSIZE];
	scanf("%s", name);
	if ((file = fopen(name, "w")) == NULL)
	{
		printf("Can't load file. \n");
		exit(0);
	}
	struct student* ptr = *head;
	for (int i = 0; i < row; i++)
	{
		fprintf(file, "%d %s %f\n", ptr->i_num, ptr->name, ptr->mark);
		ptr = ptr->next;
	}
	fclose(file);
}

void loaddata(struct student** head, struct student** ptr, int* row)
{
	FILE* file;
	printf("Input file name to load: ");
	char name[CSIZE];
	scanf("%s", name);
	if ((file = fopen(name, "r")) == NULL)
	{
		printf("Can't load file. \n");
		exit(0);
	}
	while (!feof(file))
	{
		if (*head == NULL)
		{
			*head = malloc(sizeof(struct student));
			if (*head == NULL)
			{
				printf("Can't allocate memory. \n");
				exit(0);
			}
			*ptr = *head;
		}
		else
		{
			(**ptr).next = malloc(sizeof(struct student));
			if ((**ptr).next == NULL)
			{
				printf("Can't allocate memory. \n");
				exit(0);
			}
			*ptr = (**ptr).next;
		}
		fscanf(file, "%d %s %f\n", &(**ptr).i_num, &(**ptr).name, &(**ptr).mark);
		printf("Student %d: %d, %s, %.1f\n", *row + 1, (*ptr)->i_num, (*ptr)->name, (*ptr)->mark);
		(**ptr).next = NULL;
		(*row)++;
	}
	putchar('\n');
	fclose(file);
}

void dealloclist(struct student** head, int row)
{
	for (int i = 0; i < row; i++)
	{
		struct student* ptr = *head;
		for (int j = i; j < row - 1; j++)
		{
			ptr = ptr->next;
		}
		free(ptr);
		ptr->next = NULL;
	}
	(*head) = NULL;
}

void printlist(struct student** head, int row)
{
	struct student* ptr = *head;
	for (int i = 0; i < row; i++)
	{
		printf("Student %d: %d, %s, %.1f\n", i + 1, ptr->i_num, ptr->name, ptr->mark);
		ptr = ptr->next;
	}
	putchar('\n');
}

void reverselist(struct student** head, int row)
{
	struct student* newhead = NULL;
	struct student* newptr = NULL;
	for (int i = 0; i < row; i++)
	{
		//ptr points to last element
		struct student* last = *head;
		for (int j = i; j < row - 1; j++)
		{
			last = last->next;
		}
		if (i==0)
		{
			newptr = newhead = last;
			newptr->next = NULL;
		}
		else
		{
			newptr->next = last;
			newptr = newptr->next;
		}
	}
	newptr->next = NULL;
	*head = newhead;
}

int main()
{
	int row = 0;
	struct student* head = NULL;
	struct student* ptr = NULL;
	loaddata(&head, &ptr, &row);
	reverselist(&head, row);
	printlist(&head, row);
	savedata(&head, row);
	dealloclist(&head, row);
}