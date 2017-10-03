//#include<stdio.h>
//#include<stdlib.h>
//#define SIZE 100
//#define STRING "Appended text "
//#define FILE1 "Text3.txt"
//#define FILE2 "Text4.txt"
//
//void readAndPrintFile(FILE* file)
//{
//	char str[SIZE];
//	while (fscanf(file, "%s", str) == 1)
//	{
//		printf("%s", str);
//	}
//}
//
///*appending text with a and a+ mod and try to read these files*/
//int main()
//{
//	FILE* fp[2];
//	
//	//create files
//	if ((fp[0] = fopen(FILE1, "w")) == NULL)
//	{
//		printf("Can't open file %s \n", FILE1);
//		exit(0);
//	}
//	if ((fp[1] = fopen(FILE2, "w")) == NULL)
//	{
//		printf("Can't open file %s \n", FILE2);
//		exit(0);
//	}
//	fprintf(fp[0], "%s", STRING);
//	fprintf(fp[1], "%s", STRING);
//	if (fclose(fp[0]) == EOF || fclose(fp[1]) == EOF)
//	{
//		printf("One or more file is still open.\n");
//	}
//
//	//append to files
//	if ((fp[0] = fopen(FILE1, "a")) == NULL)
//	{
//		printf("Can't open file %s \n", FILE1);
//		exit(0);
//	}
//	if ((fp[1] = fopen(FILE2, "a+")) == NULL)
//	{
//		printf("Can't open file %s \n", FILE2);
//		exit(0);
//	}
//	fprintf(fp[0], "%s", STRING);
//	fprintf(fp[1], "%s", STRING);
//	if (fclose(fp[0]) == EOF || fclose(fp[1]) == EOF)
//	{
//		printf("One or more file is still open.\n");
//	}
//
//	//read files
//	if ((fp[0] = fopen(FILE1, "r")) == NULL)
//	{
//		printf("Can't open file %s \n", FILE1);
//		exit(0);
//	}
//	if ((fp[1] = fopen(FILE2, "r")) == NULL)
//	{
//		printf("Can't open file %s \n", FILE2);
//		exit(0);
//	}
//	readAndPrintFile(fp[0]);
//	putchar('\n');
//	putchar('\n');
//	readAndPrintFile(fp[1]);
//	putchar('\n');
//	if (fclose(fp[0]) == EOF || fclose(fp[1]) == EOF)
//	{
//		printf("One or more file is still open.\n");
//	}
//}