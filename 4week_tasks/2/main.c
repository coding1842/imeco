/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : 메인
* 설명 : POSIX shared memory 사용해서 가위바위보 게임 만들기
* 입력 매개변수 :int argc, char* argv[], int playerId, T_GAME *game, sem_t *sem
* 출력 매개변수: 
* 반환값 : SUCCESS - 0(FOK)
* FAIL - 0 없음(FERR)
*-------------------------------------- -------------------*/

int main(int argc, char *argv[])
{
    sem_t *sem;
    T_GAME *game;
    int shm_fd;

    // 세마포어 생성
    sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED)
	{
        printf("세마포어를 열 수 없습니다.\n");
        return 1;
    }

    // 공유 메모리 영역 생성 또는 연결
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
	{
        printf("공유 메모리를 열 수 없습니다.\n");
        return 1;
    }

    ftruncate(shm_fd, sizeof(T_GAME));
    game = (T_GAME *) mmap(NULL, sizeof(T_GAME), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (game == MAP_FAILED)
	{
        printf("메모리 매핑에 실패했습니다.\n");
        return 1;
    }

    int playerId;
    if (argc != 2)
	{
        printf("사용법: ./a.out [플레이어 ID]\n");
        return 1;
    }
    playerId = atoi(argv[1]);

    playGame(playerId, game, sem);

    // 세마포어 및 공유 메모리 해제
    sem_close(sem);
    shm_unlink(SHM_NAME);

    return 0;
} /* 메인 끝 */

