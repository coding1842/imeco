#ifndef GAME_H
#define GAME_H

#include <semaphore.h>

#define SHM_NAME "/game_shm"
#define SEM_NAME "/game_sem"

typedef struct
{
    int     iRound;
    int     player1Id;
    int     player2Id;
    char   player1[10];
    char   player2[10];
    char   cFinishYN;
} T_GAME;

void playGame(int playerId, T_GAME *game, sem_t *sem);

#endif /* GAME_H */

