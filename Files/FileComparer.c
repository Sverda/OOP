//#include<stdio.h>
//#include<ctype.h>
//#define CSIZE 200
//#define FILE1 "C:\Users\Damian\Dropbox\Studies\Object-oriented programming\PO_Labs\Files\Text1.txt"
//#define FILE2 "C:\Users\Damian\Dropbox\Studies\Object-oriented programming\PO_Labs\Files\Text2.txt"
//#define FILE3 "Text1.txt"
//#define FILE4 "Text2.txt"
//
//struct Strings
//{
//	char text1[CSIZE];
//	char text2[CSIZE];
//};
//
//int stringSize(char c[CSIZE])
//{
//	int size = 0;
//	while (c[size] != '\0' && size < CSIZE && (c[size] > 0 && c[size] < 255))
//	{
//		size++;
//	}
//	return size;
//}
//
//struct Strings compare(FILE* file1, FILE* file2)
//{
//	struct Strings str;
//	str.text1[0] = '\0';
//	str.text2[0] = '\0';
//	int ctextsize[2];
//	while ((fgets(str.text1, CSIZE - 1, file1) != NULL) && (fgets(str.text2, CSIZE - 1, file2) != NULL))
//	{
//		ctextsize[0] = stringSize(str.text1);
//		ctextsize[1] = stringSize(str.text2);
//		str.text1[ctextsize[0]] = '\0';
//		str.text2[ctextsize[1]] = '\0';
//		if (ctextsize[0] != ctextsize[1])
//		{
//			break;
//		}
//		for (int i = 0; i < CSIZE; i++)
//		{
//			if (str.text1[i] != str.text2[i])
//			{
//				return str;
//			}
//		}
//	}
//	return str;
//}
//
//FILE* getFileByUser()
//{
//	char filePath[CSIZE];
//	printf("Input file path: ");
//	scanf_s("%s", filePath, CSIZE);
//	return fopen(filePath, "r");
//}
//
///*comparing two files and write the first diffrent line */
//int main(int argc, char* argv[])
//{
//	FILE* fp1;
//	FILE* fp2;
//
//	if (argc == 1)
//	{
//		fp1 = getFileByUser();
//		fp2 = getFileByUser();
//	}
//	else
//	{
//		fp1 = fopen(FILE3, "r");
//		fp2 = fopen(FILE4, "r");
//	}
//	if (fp1 == NULL || fp2 == NULL)
//	{
//		printf("Plikow nie otwarto. \nKoniec programu. \n");
//		exit(0);
//	}
//	struct Strings str = compare(fp1, fp2);
//	printf("Different line: %s\n", str.text1);
//	printf("Different line: %s\n\n", str.text2);
//	fclose(fp1);
//	fclose(fp2);
//
//	printf("Koniec programu. \n");
//}