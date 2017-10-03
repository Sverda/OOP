////Testing new way to pass static array to function with ability to change 'true' values
////Both approaches are correct
//#include<stdio.h>
//
//void changeTab(int(*t)[3])
//{
//	(*t)[0] = 1;
//	(*t)[1] = 2;
//	(*t)[2] = 3;
//}
//
//void changeTab2(int *t)
//{
//	t[0] = 2;
//	t[1] = 3;
//	t[2] = 4;
//}
//
//int main()
//{
//	int t[3];
//	t[0] = 0;
//	t[1] = 1;
//	t[2] = 2;
//	printf("First element: %d\n", t[0]);
//	printf("Second element: %d\n", t[1]);
//	printf("Third element: %d\n\n", t[2]);
//	changeTab(t);
//	printf("First element: %d\n", t[0]);
//	printf("Second element: %d\n", t[1]);
//	printf("Third element: %d\n\n", t[2]);
//	changeTab2(t);
//	printf("First element: %d\n", t[0]);
//	printf("Second element: %d\n", t[1]);
//	printf("Third element: %d\n\n", t[2]);
//}