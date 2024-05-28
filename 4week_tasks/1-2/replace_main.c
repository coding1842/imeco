/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : 메인
* 설명 : ftok함수를 대체할 수 있는 함수 만들기
* 입력 매개변수 : int argc, char** argv, const char* path, const char* id
* 출력 매개변수: 
* 반환값 : SUCCESS - 0(FOK)
* FAIL - 0 없음(FERR)
*-------------------------------------- -------------------*/

key_t replace_ftok_key(const char* path, const char* id)
{
	uint64_t hash = 0;
	for (size_t i = 0; path[i]; i++)
	{
		hash = (hash << 8) + path[i];
	}
	for (size_t i = 0; id[i]; i++)
	{
		hash = (hash << 8) + id[i];
	}

	return (key_t)hash;
}

int main(int argc, char** argv)
{
	if (argc == 3)
	{
		const char* path = argv[1];
		const char* id = argv[2];

		key_t key = replace_ftok_key(path, id);
		printf("replace_ftok_ key: 0x%X\n", (unsigned int)key);
	}

	return 0;
} /* 메인 끝 */
