/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "binaryToAscii.h"

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
 * 기능 : 메인
 * 설명 : 성적입력하면 학점알려주는 프로그램
 * 입력 매개변수 : int liScore, char lsGrade
 * 출력 매개변수: int piScore, char lsGrade
 * 반환값 : SUCCESS - 0(FOK)
 * FAIL - 0 없음(FERR)
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
