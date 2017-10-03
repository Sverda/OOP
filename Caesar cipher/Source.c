#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define CSIZE 100
#define ALPHABET 26

struct Caesar
{
	char text[CSIZE];
	char encodeText[CSIZE];
	int key;
};

void printAlphabet(char tab[ALPHABET])
{
	for (int i = 0; i < ALPHABET; i++)
	{
		printf("%c\t", tab[i]);
		if ((i+1)%5 == 0)
		{
			putchar('\n');
		}
	}
	putchar('\n');
	putchar('\n');
}

void printCipher(char* tab[ALPHABET])
{
	for (int i = 0; i < ALPHABET; i++)
	{
		printf("%c\t", **(tab + i));
		if ((i + 1) % 5 == 0)
		{
			putchar('\n');
		}
	}
	putchar('\n');
	putchar('\n');
}

void printStruct(struct Caesar* csr)
{
	printf("Text to encode: %s\n", csr->text);
	printf("Text after encoding: %s\n", csr->encodeText);
	printf("Key: %d\n", csr->key);
}

void cipher(struct Caesar* csr)
{
	char alf[ALPHABET];	//alphabet with lower letters
	char* calf[ALPHABET];	//encoded alphabet with lower letters
	alf[0] = 'a';
	//filling alphabets
	for (int i = 1; i < ALPHABET; i++)
	{
		alf[i] = alf[i - 1] + 1;
	}
	//encoding alphabet
	for (int i = 0; i < ALPHABET; i++)
	{
		if (i < ALPHABET - (csr->key))
		{
			calf[i] = &alf[csr->key + i];
		}
		else
		{
			calf[i] = &alf[i - (ALPHABET - csr->key)];
		}
	}
	//encoding text
	int i;	//I need this to put '\0' at the end of file
	for (i = 0; i < CSIZE && csr->text[i] != '\0'; i++)
	{
		if (islower(csr->text[i]))
		{
			for (int j = 0; j < ALPHABET; j++)
			{
				if (alf[j] == csr->text[i])
				{
					csr->encodeText[i] = *calf[j];
					break;
				}
			}
		}
		else
		{
			char c = tolower(csr->text[i]);
			for (int j = 0; j < ALPHABET; j++)
			{
				if (alf[j] == c)
				{
					csr->encodeText[i] = toupper(*calf[j]);
					break;
				}
			}
		}
	}
	csr->encodeText[i] = '\0';
}

int main()
{
	struct Caesar csr;
	printf("Input text to encode: ");
	scanf_s("%s", csr.text, CSIZE);
	printf("Input key: ");
	scanf_s("%d", &csr.key);
	cipher(&csr);
	printStruct(&csr);
}