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
* 기능 : reading_process
* 설명 :  숫자 정렬해주기
* 입력 매개변수 : 
* 출력 매개변수:
* 반환값 :
*-------------------------------------- -------------------*/

int sorted_nums[MAX_SIZE];
int sorted_count = 0;

void reading_process()
{
    key_t key;
    int msgid;

    // 메시지 큐 키 생성
    key = ftok(".", 65);
    if (key == -1)
	{
        printf("키 생성 실패");
        exit(1);
    }

    // 메시지 큐 생성 및 에러 처리
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) 
	{
		printf("메시지 큐 생성 실패");
        exit(1);
    }

    // 메시지 버퍼 선언
    struct msg_buffer message;

    printf("읽기 프로세스는 입력을 대기 중입니다...\n");

    while (1) 
	{
        // 메시지 큐에서 메시지 수신
        msgrcv(msgid, &message, sizeof(message), 1, 0);

        // 수신된 데이터가 종료 메시지인지 확인
        if (message.data == -1) 
		{
            break; // 종료 메시지면 반복 종료
        }

        // 수신된 데이터를 정렬된 숫자 배열에 저장
        sorted_nums[sorted_count++] = message.data;

        // 새로운 데이터가 수신될 때마다 배열을 정렬
        for (int i = 0; i < sorted_count - 1; ++i) 
		{
            for (int j = 0; j < sorted_count - i - 1; ++j) 
			{
                if (sorted_nums[j] > sorted_nums[j + 1]) 
				{
                    // 숫자 교환
                    int temp = sorted_nums[j];
                    sorted_nums[j] = sorted_nums[j + 1];
                    sorted_nums[j + 1] = temp;
                }
            }
        }

        // 수신된 데이터를 출력
        printf("수신된 데이터: %d\n", message.data);

        // 정렬된 데이터 출력
        printf("정렬된 숫자: ");
        for (int i = 0; i < sorted_count; ++i)
		{
            printf("%d ", sorted_nums[i]);
        }
        printf("\n");
    }

    printf("읽기 프로세스를 종료합니다...\n");
}/* reading_process 끝 */

