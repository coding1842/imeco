/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordCount.h"

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : 메인
* 설명 : 텍스트파일을 읽어 특정 단어가 몇 개 나오는지 출력하는 프로그램
* 입력 매개변수 : int argc, char *argv
* 출력 매개변수: 
* 반환값 : SUCCESS - 0(FOK)
* FAIL - 0 없음(FERR)
*-------------------------------------- -------------------*/
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
} /* 메인 끝*/
