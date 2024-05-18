#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
	int data, liValue;
	struct Node* next;
};

struct Node* createNode(int value);
void addNode(struct Node** head, int value);
void printfNode(struct Node* head);
void removeNode(struct Node** head, int value);
void freeNode(struct Node* head);

#endif
