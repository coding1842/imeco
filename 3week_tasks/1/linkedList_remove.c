/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : removeNode, freeNode
* 설명 : 노드 삭제 연결, 노드 종료
* 입력 매개변수 : struct Node** head, struct Node* head, int piValue
* 출력 매개변수:
* 반환값 :
*-------------------------------------- -------------------*/

void removeNode(struct Node** head, int piValue)
{
	struct Node* curr = *head;
	struct Node* prev = NULL;

	if (curr != NULL && curr -> data == piValue )
	{
		*head = curr -> next;
		free(curr);

		return;
	}

	while (curr != NULL && curr -> data != piValue)
	{
		prev = curr;
		curr = curr -> next;
	}

	if (curr == NULL)
	{
		printf("지울려는 노드 %d이 존재하지 않습니다.\n", piValue);
		return;
	}

	prev -> next = curr -> next;
	free(curr);
}

void freeNode(struct Node* head)
{
	struct Node* temp;
	while(head != NULL)
	{
		temp = head;
		head = head -> next;
		free(temp);
	}
} /* removeNode, freeNode 끝 */
