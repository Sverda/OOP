//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#include<time.h>
//int LEN = 10;
//
//struct element
//{
//	int val;
//	struct element* next;
//};
//
////EDIT: Sorting by changing pointers, not values
//void sort(struct element* head)
//{
//	struct element* i = head;
//	while (i != NULL)
//	{
//		struct element* j = i->next;
//		while (j != NULL)
//		{
//			if (i->val < j->val)
//			{
//				int p = i->val;
//				i->val = j->val;
//				j->val = p;
//			}
//			j = j->next;
//		}
//		i = i->next;
//	}
//	printf("Elements were sorted. \n");
//}
//
//void additem(struct element** mptr, int value)
//{
//	struct element* newel = malloc(sizeof(struct element));
//	newel->val = value;
//	newel->next = NULL;
//
//	(**mptr).next = newel;
//	*mptr = newel;
//	printf("Item added. \n");
//}
//
//void printlist(struct element* head)
//{
//	if (head == NULL)
//	{
//		return;
//	}
//	printf("List's elements: \n");
//	struct element* ptr = head;
//	int i = 1;
//	while (ptr != NULL)
//	{
//		printf("%d\t", ptr->val);
//		ptr = ptr->next;
//		if (i % 5 == 0)
//		{
//			putchar('\n');
//		}
//	}
//	putchar('\n');
//}
//
//void createlist(struct element** head, struct element** ptr)
//{
//	//Create list
//	for (int i = 0; i < LEN; i++)
//	{
//		struct element* newel = malloc(sizeof(struct element));
//		if (*head == NULL)
//		{
//			*head = newel;
//			*ptr = newel;
//		}
//		else
//		{
//			(**ptr).next = newel;
//			*ptr = (**ptr).next;
//		}
//		(**ptr).val = rand() % 100;
//		(**ptr).next = NULL;
//	}
//	printf("List was created. \n");
//}
//
//void dealloclist(struct element* head)
//{
//	struct element* ptr = head;
//	if (head == NULL)
//	{
//		return;
//	}
//	for (int i = 0; i < LEN; i++)
//	{
//		while (ptr != NULL)
//		{
//			ptr = ptr->next;
//		}
//		free(ptr);
//	}
//	printf("List was destroyed. \n");
//}
//
//int main()
//{
//	srand(time(NULL));
//	struct element* head = NULL;
//	struct element* ptr = NULL;
//	createlist(&head, &ptr);
//	printlist(head);
//	additem(&ptr, rand() % 1000 + 500);
//	printlist(head);
//	sort(head);
//	printlist(head);
//	dealloclist(head);
//}