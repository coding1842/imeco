/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : score_grade
* 설명 : 문자열 출력
* 입력 매개변수 : psGrade - 문자열, piScore - 상수열
* 출력 매개변수:
* 반환값 :
*-------------------------------------- -------------------*/

void score_grade(int piScore, char* psGrade)
{
    if (piScore > 100)
    {
        printf("최대점수는 100점입니다. 다시 입력해주세요");
        exit(0);
    }
    else if (piScore <= 100 && piScore >= 90)
    {
        *psGrade = 'A';
    }
    else if (piScore <= 89 && piScore >= 80)
    {
        *psGrade = 'B';
    }
    else if (piScore <= 79 && piScore >= 70)
    {
        *psGrade = 'C';
    }
    else if (piScore <= 69 && piScore >= 60)
    {
        *psGrade = 'D';
    }
    else if (piScore <= 59 && piScore >= 0)
    {
        *psGrade = 'F';
    }
    else if (piScore < 0)
    {
        printf("최소점수는 0점입니다. 다시 입력해주세요");
        exit(0);
    }
}  /* score_grade의 끝 */

