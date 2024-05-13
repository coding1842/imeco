/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include "binaryToAscii.h"

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/
char gInputFileName[BUFF_SIZE];
char gOutputFileName[BUFF_SIZE];

/*--<함수 프로토타입>-------------------------------------------- -----------------*/
void binaryToAscii();

/*------------------------------------------------ ---------------------------------
* 기능 : 메인
* 설명 : 바이너리 파일 문자열로 변환 후 새 파일에 저장하는 프로그램
* 입력 매개변수 : char gInputFileName
* 출력 매개변수: char OutputFileName
* 반환값 : SUCCESS - 0(FOK)
* FAIL - 0 없음(FERR)
*-------------------------------------- -------------------*/
int main()
{
	printf("읽어올 파일명을 입력하세요: ");
	scanf("%s", gInputFileName);

	printf("저장할 파일명을 입력하세요: ");
	scanf("%s", gOutputFileName);

	binaryToAscii();

	printf("이진 파일을 아스키 코드로 변환하여 %s 파일에 저장했습니다.\n", gOutputFileName);

	return 0;
}  /* 메인 끝 */
