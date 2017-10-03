#include<stdio.h>
#define CSIZE 200
#define FILE1 "C:\Users\Damian\Dropbox\Studies\Object-oriented programming\PO_Labs\Files\Text1.txt"
#define FILE2 "C:\Users\Damian\Dropbox\Studies\Object-oriented programming\PO_Labs\Files\Text2.txt"

int main()
{
	FILE* stream;
	if ((stream = fopen("Text2.txt", "r")) == NULL)
	{
		printf("Pliku nie otwarto");
		return 0;
	}
	char s[CSIZE]; 
	while ((fgets(s, CSIZE - 1, stream) != NULL))
	{
		printf("%s", s);
	}
	fclose(stream);
}