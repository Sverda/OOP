//#include<stdio.h>
//#include<stdlib.h>
//#include<malloc.h>
//#include<errno.h>
//#include<string.h>
//#define CSIZE 50
//#define FILENAME "file.txt" /*file does't exist*/
//#define NOFILENAME "correctfile.txt" /*file exists*/
//
//int main() 
//{
//	FILE* file;
//	/*printf("Input file name to load: ");
//	char name[CSIZE];
//	scanf("%s", name);*/
//	file = fopen(NOFILENAME, "r");
//	if (errno == ENOENT)
//	{
//		perror("Can't open file");
//	}
//	else
//	{
//		char *buffer = NULL;
//		fread(&buffer, sizeof(buffer), 1, file);
//		if (ferror(file))
//		{
//			perror("Can't load data from file correct.txt");
//		}
//		clearerr(file);
//		if (buffer != NULL)
//		{
//			printf("%s\n", buffer);
//		}
//	}
//}