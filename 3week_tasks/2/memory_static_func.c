/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memory_static.h"

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : memory_static_func
* 설명 : 정적 메로리 할당 함수
* 입력 매개변수 : pspStudyArr
* 출력 매개변수:
* 반환값 : gspStudyName
*-------------------------------------- -------------------*/
char* memory_static_func(char* pspStudyArr)
{
	gspStudyName = (char*)alloca(strlen(pspStudyArr) + 1);
	strcpy(gspStudyName, pspStudyArr);

	printf("\nI study %s\n", gspStudyName);

	return gspStudyName;

} /* memory_static_func의 끝 */
