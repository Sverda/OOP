//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#define LEN 5
//
//struct list
//{
//	int value;
//	struct list* next;
//};
//
//int main()
//{
//	srand(time(NULL));
//	//Create list
//	struct list* head = NULL;
//	struct list* ptr = NULL;
//	for (int i = 0; i < LEN; i++)
//	{
//		struct list* nel = malloc(sizeof(struct list));
//		if (head == NULL)
//		{
//			head = nel;
//			ptr = nel;
//		}
//		else
//		{
//			ptr->next = nel;
//			ptr = ptr->next;
//		}
//		ptr->value = rand() % 10;
//		ptr->next = NULL;
//	}
//	//Printing list
//	for (struct list* i = 0; i != NULL; i = i->next)
//	{
//		printf("%d\t", i->value);
//	}
//	//Deallocation
//	for (int i = 0; i < LEN; i++)
//	{
//		ptr = head;
//		for (int j = i+1; j < LEN; j++)
//		{
//			ptr = ptr->next;
//		}
//		free(ptr);
//	}
//}