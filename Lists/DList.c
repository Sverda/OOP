#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#define NUMOFELEMS 10

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

void populatelist(struct Node** nhead, struct Node** nptr, int numofelem)
{
	struct Node* head = *nhead;
	struct Node* ptr = *nptr;
	srand(time(NULL));
	for (int i = 0; i < numofelem; i++)
	{
		if (head == NULL)
		{
			head = malloc(sizeof(struct Node));
			ptr = head;
			ptr->data = rand() % 100;
			ptr->prev = NULL;
			ptr->next = NULL;
		}
		else
		{
			ptr->next = malloc(sizeof(struct Node));
			ptr->next->data = rand() % 100;
			ptr->next->prev = ptr;
			ptr = ptr->next;
			ptr->next = NULL;
		}
	}
	*nhead = head;
	*nptr = ptr;
}

void printforward(struct Node** head)
{
	struct Node* ptr = *head;
	while (ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	putchar('\n');
}

void printbackward(struct Node** tail)
{
	struct Node* ptr = *tail;
	while (ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->prev;
	}
	putchar('\n');
}

void insert(struct Node** head, int after, int value)
{
	struct Node* ptr = *head;
	for (int i = 0; i < after; i++)
	{
		ptr = ptr->next;
	}
	struct Node* newnode = malloc(sizeof(struct Node));
	newnode->data = value;
	newnode->next = ptr->next;
	newnode->prev = ptr;
	ptr->next->prev = newnode;
	ptr->next = newnode;
}

int main()
{
	struct Node* head = NULL;
	struct Node* tail = NULL;
	populatelist(&head, &tail, NUMOFELEMS);
	printforward(&head);
	printbackward(&tail);
	insert(&head, 1, 13);
	printforward(&head);
}