/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "binaryToAscii.h"

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
 * 기능 : binaryToAscii
 * 설명 : 바이너리 파일 아스키코드로 변환
 * 입력 매개변수 : char gInputFileName
 * 출력 매개변수: char gOutputFileName
 * 반환값 : 
 *-------------------------------------- -------------------*/
void binaryToAscii()
{
	FILE *inputFile = fopen(gInputFileName, "r");
	FILE *outputFile = fopen(gOutputFileName, "w");

	char binary[9];

	while (fscanf(inputFile, "%8s", binary) == 1)
	{
		int ascii = strtol(binary, NULL, 2);
		fprintf(outputFile, "%c", ascii);
	}
	fclose(inputFile);
	fclose(outputFile);
} /* binaryToAscii의 끝 */
