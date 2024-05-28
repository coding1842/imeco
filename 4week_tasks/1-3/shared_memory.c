/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : 메인
* 설명 : System V 사용하여, shared memory 만들기
* 입력 매개변수 : int argc, char** argv, const char* path, const char* id
* 출력 매개변수: 
* 반환값 : SUCCESS - 0(FOK)
* FAIL - 0 없음(FERR)
*-------------------------------------- -------------------*/

key_t generate_key(const char* path, const char* id) 
{
	return ftok(path, id[0]);
}

int main(int argc, char** argv) 
{
	if (argc == 3) 
	{
		const char* path = argv[1];
		const char* id = argv[2];

		key_t key = generate_key(path, id);
		printf("key: 0x%X\n", (unsigned int)key);

		int shmid = shmget(key, 1024, IPC_CREAT | IPC_EXCL | 0666);
		if (shmid == -1) {
			perror("shmget");
			return 1;
		}

		printf("id: %d, key: 0x%X\n", shmid, (unsigned int)key);

	}

	return 0;
} /* 메인 끝 */

