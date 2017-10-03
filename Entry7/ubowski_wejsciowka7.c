#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define FILENAME "file.txt"
#define FILENAME2 "sfile.txt"
#define CHARSIZE 50
#define BACKWARD 1
#define FOREWARD 0
#define MARK 4 /*below this mark students will be exiled*/

struct student {
	int ind;
	char name[30];
	float mark;
	struct student* next;
	struct student* prev;
};

void printlist(struct student** head, int howprint)
{
	struct student* ptr = *head;
	printf("\nPrinting list...\n");
	if (howprint == BACKWARD)
	{
		//print backward
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		while (ptr != NULL)
		{
			printf("%d %s %.1f\n", ptr->ind, ptr->name, ptr->mark);
			ptr = ptr->prev;
		}
	}
	else
	{
		//print foreward
		while (ptr != NULL)
		{
			printf("%d %s %.1f\n", ptr->ind, ptr->name, ptr->mark);
			ptr = ptr->next;
		}
	}
	putchar('\n');
}

void loaddata(struct student** head)
{
	FILE* file = NULL;
	char name[CHARSIZE];
	printf("Input file name:");
	scanf("%s", name);
	file = fopen(name, "r");
	if (errno == ENOENT)
	{
		perror("Can't open file");
		exit(0);
	}
	printf("Loading data...\n");
	struct student *news = NULL,
					*ptr = NULL;
	while (!feof(file))
	{
		news = malloc(sizeof(struct student));
		fscanf(file, "%d %s %f\n", &(news->ind), &(news->name), &(news->mark));
		printf("%d %s %.1f\n", news->ind, news->name, news->mark);
		if (*head == NULL)
		{
			*head = news;
			news->next = NULL;
			news->prev = NULL;
			continue;
		}
		//look for good spot
		ptr = *head;
		while (ptr != NULL)
		{
			if (ptr->ind > news->ind)
			{
				break;
			}
			ptr = ptr->next;
		}
		//place object in right place
		if (ptr == NULL)	//place object at the end
		{
			ptr = *head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = news;
			ptr->next->next = NULL;
			ptr->next->prev = ptr;
		}
		else if (ptr->prev == NULL)	//place object at the start
		{
			//connect new object to old
			news->next = *head;
			news->prev = NULL;
			//connect old object to new
			(*head)->prev = news;
			*head = news;
		}
		else
		{
			//connect new object to old
			news->next = ptr;
			news->prev = ptr->prev;
			//connect old object to new
			ptr->prev->next = news;
			ptr->prev = news;
		}

		news = NULL;
	}
	fclose(file);
}

void deallocatlist(struct student** head)
{
	struct student* ptr = *head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		free(ptr->prev);
	}
	free(ptr);
	*head = NULL;
}

void deletemorons(struct student **head, int mark)
{
	struct student *ptr = *head;
	struct student *dels = NULL;
	while (ptr != NULL)
	{
		if (ptr->mark < mark)
		{
			if (ptr->next == NULL)
			{
				ptr->prev->next = NULL;
			}
			else if (ptr->prev == NULL)
			{
				*head = ptr->next;
				ptr->next->prev = NULL;
			}
			else
			{
				ptr->next->prev = ptr->prev;
				ptr->prev->next = ptr->next;
			}
			dels = ptr;
			ptr = ptr->next;
			free(dels);
			dels = NULL;
		}
		else
		{
			ptr = ptr->next;
		}
	}
}

void savedata(struct student** head)
{
	FILE* file = NULL;
	char name[CHARSIZE];
	printf("Input file name:");
	scanf("%s", name);
	file = fopen(name, "w");
	if (errno == ENOENT)
	{
		perror("Can't save to file");
		exit(0);
	}
	printf("Saving data...\n");
	struct student* ptr = *head;
	while (ptr != NULL)
	{
		fprintf(file, "%d %s %.1f\n", ptr->ind, ptr->name, ptr->mark);
		ptr = ptr->next;
	}
	fclose(file);
	printf("Data saved. \n");
}

int main()
{
	struct student* head = NULL;
	loaddata(&head);
	printlist(&head, FOREWARD);
	deletemorons(&head, MARK);
	printlist(&head, FOREWARD);
	savedata(&head);
	deallocatlist(&head);
}