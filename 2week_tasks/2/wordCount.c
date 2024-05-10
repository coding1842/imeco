#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordCount.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s <filename> <word>\n", argv[0]);
		return 1;
	}

	fpFd = fopen(argv[1], "r");

	char *lcpWord = argv[2];
	size_t liWordCtn = strlen(lcpWord);

	int liCount = 0;
	char lcCheck[liWordCtn + 1];
	lcCheck[liWordCtn] = '\0';

	while (fread(lcCheck, sizeof(char), liWordCtn, fpFd) == liWordCtn)
	{
		if (strcmp(lcCheck, lcpWord) == 0)
		{
			liCount++;
		}
		fseek(fpFd, -liWordCtn + 1, SEEK_CUR);
	}
	
	printf("Number of '%s' in the file: %d\n", lcpWord, liCount);

	fclose(fpFd);
	return 0;
}
