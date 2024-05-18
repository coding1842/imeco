/*--<헤더 파일>-------------------------------------------- -----------------------*/
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*--<상수 정의>-------------------------------------------- -----------------*/


/*--<변수>------------------------------- -----------------------*/


/*--<함수 프로토타입>-------------------------------------------- -----------------*/


/*------------------------------------------------ ---------------------------------
* 기능 : createNode, addNode, printfNode
* 설명 : 노드 생성, 노드 연결, 현재 노드 보기
* 입력 매개변수 : struct Node** head, struct Node* head, int piValue
* 출력 매개변수:
* 반환값 : newNode
*-------------------------------------- -------------------*/

struct Node* createNode(int piValue)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("새로운 노드가 없습니다.\n");
		exit(1);
	}
	newNode -> data = piValue;
	newNode -> next = NULL;
	return newNode;
}

void addNode(struct Node** head, int piValue)
{
	struct Node* newNode = createNode(piValue);
	newNode -> next = *head;
	*head = newNode;
}

void printfNode(struct Node* head)
{
	printf("현재 노드 보기: ");
	while (head != NULL)
	{
		printf("%d -> ", head -> data);
		head = head -> next;
	}
	printf("NULL\n\n");
} /* createNode, addNode, printfNode 끝 */
