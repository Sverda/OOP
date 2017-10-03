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

struct movie {
	int ID;
	char title[40];
	int year;
	double price;
	struct movie *next;
	struct movie *prev;
}; 

void loaddata(struct movie** head)
{
	FILE* file = NULL;
	/*char name[CHARSIZE];
	printf("Input file name:");
	scanf("%s", name);*/
	file = fopen(FILENAME, "r");
	if (errno == ENOENT)
	{
		perror("Can't open file");
		exit(0);
	}
	printf("Loading data...\n");
	struct movie *news = NULL,
		*ptr = NULL;
	while (!feof(file))
	{
		news = malloc(sizeof(struct movie));
		fscanf(file, "%d %s %d %lf\n", &(news->ID), &(news->title), &(news->year), &(news->price));
		printf("%d %s %d %.1lf\n", news->ID, news->title, news->year, news->price);
		
		if (*head == NULL)
		{
			*head = news;
			ptr = *head;
			ptr->prev = NULL;
		}
		else
		{
			ptr->next = news;
			ptr->next->next = NULL;
			ptr->next->prev = ptr;
			ptr = ptr->next;
		}
	}
	fclose(file);
}

void printlist(struct movie** head, int howprint)
{
	struct movie* ptr = *head;
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
			printf("%d %s %d %.1lf\n", ptr->ID, ptr->title, ptr->year, ptr->price);
			ptr = ptr->prev;
		}
	}
	else
	{
		//print foreward
		while (ptr != NULL)
		{
			printf("%d %s %d %.1lf\n", ptr->ID, ptr->title, ptr->year, ptr->price);
			ptr = ptr->next;
		}
	}
	putchar('\n');
}

void savedata(struct movie** head, int howprint)
{
	FILE* file = NULL;
	/*char name[CHARSIZE];
	printf("Input file title:");
	scanf("%s", name);*/
	file = fopen(FILENAME2, "w");
	if (errno == ENOENT)
	{
		perror("Can't save to file");
		exit(0);
	}
	struct movie* ptr = *head;
	if (howprint == BACKWARD)
	{
		//print backward
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		while (ptr != NULL)
		{
			fprintf(file, "%d %s %d %.1lf\n", ptr->ID, ptr->title, ptr->year, ptr->price);
			ptr = ptr->prev;
		}
	}
	else
	{
		//print foreward
		while (ptr != NULL)
		{
			fprintf(file, "%d %s %d %.1lf\n", ptr->ID, ptr->title, ptr->year, ptr->price);
			ptr = ptr->next;
		}
	}
	fclose(file);
	printf("Data saved. \n");
}

void deallocatlist(struct movie** head)
{
	struct movie* ptr = *head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		free(ptr->prev);
	}
	free(ptr);
	*head = NULL;
}

struct movie* addnew()
{
	/*struct movie* news = malloc(sizeof(struct movie));
	printf("Podaj indeks: ");
	scanf("%d", &(news->ID));
	printf("Podaj tytul: ");
	scanf("%s", &(news->title));
	printf("Podaj rok: ");
	scanf("%d", &(news->year));
	printf("Podaj cene: ");
	scanf("%lf", &(news->price));*/
	struct movie* news = malloc(sizeof(struct movie));
	news->ID = 1004;
	strcpy(&(news->title), "Title4");
	news->year = 2004;
	news->price = 14.0;
	return news;
}

void replace(struct movie** head)
{
	printf("Podaj numer indeksu po ktorym zostanie dodany nowy film: ");
	int newid;
	scanf("%d", &newid);
	struct movie* news = addnew();
	struct movie* ptr = *head;
	while (ptr != NULL)
	{
		if (ptr->ID == newid)
		{
			break;
		}
		ptr = ptr->next;
	}
	if (ptr != NULL)
	{
		if (ptr->prev == NULL)	//place object at the start
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
	}
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = news;
		ptr->next->next = NULL;
		ptr->next->prev = ptr;
		//prinf("Nie ma filmu o podanym indeksie. \n");
	}
}

void delete(struct movie** head)
{
	printf("Na podstawie czego usuniety bedzie elem.?\n");
	printf("1 - ID\n2 - tytul\n3 - rok\n4 - cena\n");
	int menu;
	scanf("%d", &menu);
	struct movie* ptr = *head;
	switch (menu)
	{
	case 1:
		printf("Podaj ID: ");
		int id;
		scanf("%d", &id);
		while (ptr != NULL)
		{
			if (ptr->ID == id)
			{
				break;
			}
			ptr = ptr->next;
		}
		break;
	case 2:
		printf("Podaj tytul: ");
		char title[CHARSIZE];
		scanf("%s", title);
		while (ptr != NULL)
		{
			if (!strcmp(ptr->title, title))
			{
				break;
			}
			ptr = ptr->next;
		}
		break;
	case 3:
		printf("Podaj rok: ");
		int year;
		scanf("%d", &year);
		while (ptr != NULL)
		{
			if (ptr->year == year)
			{
				break;
			}
			ptr = ptr->next;
		}
		break;
	case 4:
		printf("Podaj cene: ");
		double price;
		scanf("%lf", &price);
		while (ptr != NULL)
		{
			if (ptr->price == price)
			{
				break;
			}
			ptr = ptr->next;
		}
		break;
	default:
		break;
	}
	if (ptr != NULL)
	{
		if (ptr->prev == NULL)
		{
			struct movie* del = ptr;
			*head = ptr->next;
			ptr->next->prev = NULL;
			free(del);
			del = NULL;
		}
		else if (ptr->next == NULL)
		{
			ptr->prev->next = NULL;
			free(ptr);
			ptr = NULL;
		}
		else
		{
			struct movie* del = ptr;
			del->next->prev = del->prev;
			del->prev->next = del->next;
			free(del);
			del = NULL;
		}
	}
}

int main()
{
	struct movie* head = NULL;
	loaddata(&head);
	//replace(&head);
	//printlist(&head, FOREWARD);
	delete(&head);
	printlist(&head, FOREWARD);
	savedata(&head, BACKWARD);
	deallocatlist(&head);
}