#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

#define BUF_SIZE 8

int main()
{
	fpFd = fopen("binary.txt", "r");
	char lcText[BUF_SIZE];

	printf("Translated Text: ");
	while (fread(lcText, sizeof(char), BUF_SIZE, fpFd) == BUF_SIZE)
	{
		char ascii = strtol(lcText, NULL, 2);
		printf("%c", ascii);
	}

	printf("\n");
	fclose(fpFd);
	return 0;
}
