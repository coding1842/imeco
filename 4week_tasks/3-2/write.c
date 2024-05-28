/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include "write_read.h"

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : writing_process
* 설명 : 숫자 입력
* 입력 매개변수 : 
* 출력 매개변수:
* 반환값 :
*-------------------------------------- -------------------*/

void writing_process() 
{
    key_t key;
    int msgid;

    // 메시지 큐 키 생성
    key = ftok(".", 65);
    if (key == -1)
	{
        perror("ftok");
        exit(1);
    }

    // 메시지 큐 생성 및 에러 처리
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1)
	{
        perror("msgget");
        exit(1);
    }

    // 메시지 버퍼 초기화
    struct msg_buffer message;
    message.msg_type = 1;
	
	printf("-1 입력시 쓰기, 읽기 프로세스가  종료됩니다.\n");
    printf("%d개의 숫자를 입력하세요:\n", MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; ++i) 
	{
        scanf("%d", &message.data);

        // 메시지 큐에 메시지 보내기
        msgsnd(msgid, &message, sizeof(message), 0);

        // -1을 입력하면 프로세스 종료
        if (message.data == -1)
		{
            break;
        }
    }

    printf("쓰기 프로세스를 종료합니다...\n");
}

