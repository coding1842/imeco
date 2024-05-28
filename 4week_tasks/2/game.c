/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include "game.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : playGame
* 설명 : 가위바위보 게임
* 입력 매개변수 : int playerId, T_GAME* game, sem_t* sem
* 출력 매개변수:
* 반환값 :
*-------------------------------------- -------------------*/

void playGame(int playerId, T_GAME *game, sem_t *sem)
{
	sem_wait(sem); // 세마포어 잠금

	// 플레이어의 차례를 확인하여 처리
	if (playerId == 1)
	{
		printf("플레이어 %d, 선택하세요 (가위/바위/보): ", playerId);
		fgets(game->player1, sizeof(game->player1), stdin);
		game->player1[strlen(game->player1) - 1] = '\0'; // 개행 문자 제거
		game->player1Id = 2; // 플레이어 1의 차례 종료, 플레이어 2의 차례로 변경
	} else 
	{
		printf("플레이어 %d, 선택하세요 (가위/바위/보): ", playerId);
		fgets(game->player2, sizeof(game->player2), stdin);
		game->player2[strlen(game->player2) - 1] = '\0'; // 개행 문자 제거
		game->player2Id = 1; // 플레이어 2의 차례 종료, 플레이어 1의 차례로 변경
	}

	// 두 플레이어가 모두 선택할 때까지 대기
	while (game->player1Id != playerId && game->player2Id != playerId)
	{
		sem_post(sem); // 세마포어 잠금 해제
		sem_wait(sem); // 세마포어 잠금
	}

	// 선택된 값에 따라 승부 결정
	if (strcmp(game->player1, game->player2) == 0) 
	{
		printf("플레이어 1: %s\n", game->player1);
		printf("플레이어 2: %s\n", game->player2);
		printf("비겼습니다.\n");
	} else if ((strcmp(game->player1, "가위") == 0 && strcmp(game->player2, "보") == 0) ||
			   (strcmp(game->player1, "바위") == 0 && strcmp(game->player2, "가위") == 0) ||
			   (strcmp(game->player1, "보") == 0 && strcmp(game->player2, "바위") == 0))
	{
		printf("플레이어 1: %s\n", game->player1);
		printf("플레이어 2: %s\n", game->player2);
		printf("플레이어 1이 이겼습니다.\n");
	} else 
	{
		printf("플레이어 1: %s\n", game->player1);
		printf("플레이어 2: %s\n", game->player2);
		printf("플레이어 2가 이겼습니다.\n");
	}

	game->cFinishYN = 'Y'; // 게임 종료 표시

	sem_post(sem); // 세마포어 잠금 해제
} /* playGame */

