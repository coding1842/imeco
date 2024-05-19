/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "memory_static.h"

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : memory_static_free
* 설명 : 정적 메모리 할당 free 함수
* 입력 매개변수 : gspStudyName
* 출력 매개변수:
* 반환값 :
*-------------------------------------- -------------------*/

char* memory_static_free(char** gspStudyName)
{
	printf("\n정적 메모리 free 전 주소: %p\n\n", *gspStudyName);

	printf("정적 메모리 free 중 %p\n\n", *gspStudyName);
	*gspStudyName = NULL;
	free(*gspStudyName);
	
	printf("정적 메모리 free 후 주소: %p\n\n", *gspStudyName);

	printf("alloca로할당한 정적메모리를 성공적으로 종료하였습니다.\n\n");

	return 0;

}/* memory_static_free의 종료 */
