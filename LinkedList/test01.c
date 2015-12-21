#include <stdio.h>
#include <stdlib.h>

typedef struct _Node Node;
typedef struct _Node{
	int data;
	Node* next;	
} Node;

void Traverse(Node* pHead)
{
	/*
	Node* curNode = pHead;

	while(curNode != NULL)
	{
		printf("%d ", curNode->data);
		curNode = curNode->next;
	}
	*/

	while(pHead != NULL)
	{
		printf("%d ", pHead->data);
		pHead = pHead->next;
	}
}


int main(void)
{
	Node* headNode = NULL;
	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;


	headNode = malloc( 1 * sizeof(Node) ); // <- (wik01) : only 1 object, "1*" doesn't need.
	node1 = malloc( 1 * sizeof(Node) );
	node2 = malloc( 1 * sizeof(Node) );
	node3 = malloc( 1 * sizeof(Node) );

	headNode->data = 1;
	node1->data = 2;
	node2->data = 3;
	node3->data = 4;

	headNode->next = node1;   //<- (wik02) : the "->" means value..not a address..
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;


	//process
	Traverse(headNode);  //<- (stk01) : why call by pointer variable doesn't change after call out.
	

	

	return 0;
}

