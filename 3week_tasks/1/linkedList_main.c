/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : 메인
* 설명 : 노드 생성 연결 삭제 프로그램
* 입력 매개변수 : struct Node* head, struct Node** head, char lsCommand, int liValue
* 출력 매개변수: struct Node* head, struct Node** head, int piValue
* 반환값 : SUCCESS - 0(FOK)
* FAIL - 0 없음(FERR)
*-------------------------------------- -------------------*/

int main()
{
	struct Node* head = NULL;
	char lsCommand[5];
	int liValue;

	while (1)
	{
		printf("커맨드 사용법 : 추가(노드를 추가한다), 삭제(노드를 삭제한다), 노드보기(현재 노드를 보여준다), 종료(노드들을 메모리 종료후 프로그램을 종료한다)\n");
		printf("커맨드 입력 : ");
		scanf("%s", lsCommand);

		if (strcmp(lsCommand, "추가") == 0)
		{
			printf("새로운 노드를 위해 숫자를 입력해주세요. : ");
			scanf("%d", &liValue);
		
			addNode(&head, liValue);
			printfNode(head);
		}

		if (strcmp(lsCommand, "삭제") == 0)
		{
			printf("제거할 노드를 위해 숫자를 입력해주세요. : ");
			scanf("%d", &liValue);

			removeNode(&head, liValue);

			printfNode(head);

			continue;
		}
		
		if (strcmp(lsCommand, "노드보기") == 0)
		{
			printfNode(head);
		}

		if (strcmp(lsCommand, "종료") == 0)
		{
			freeNode(head);
			exit(0);
		}
	}

	return 0;
} /* 메인 끝 */
