////Program uses several function in chain
//#include<stdio.h>
//#define NFUN 2 /*number of functions*/
//typedef void(*nfun)(int);	//pointer to function
//typedef nfun tabfun[NFUN];	//array of functions
//void fun4(int);
//
//void fun0(int i, tabfun* tab)
//{
//	printf("Fun0 %d\n", i);
//	for (int i = 0; i < NFUN; i++)
//	{
//		(*tab)[i](i + 1);
//		(*tab)[i] = fun4;
//	}
//	putchar('\n');
//}
//
//void fun1(int i, tabfun* tab)
//{
//	printf("Fun1 %d\n", i);
//	for (int i = 0; i < NFUN; i++)
//	{
//		(*tab)[i](i + 1);
//	}
//	putchar('\n');
//}
//
//void fun2(int i)
//{
//	printf("Fun2 %d\n", i);
//}
//
//void fun3(int i)
//{
//	printf("Fun3 %d\n", i);
//}
//
//void fun4(int i)
//{
//	printf("Fun4 %d\n", i);
//}
//
//int main()
//{
//	tabfun tab = { fun0, fun1 };
//	tabfun tab2 = { fun2, fun3 };
//	for (int i = 0; i < NFUN; i++)
//	{
//		tab[i](i+1, tab2);
//	}
//}