#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct StackType {
	node* dataNode;
} stack;

typedef struct Node {
	int data;
	struct Node* nextNode;
	struct Node* prevNode;
} node;

stack* createStack(node* head);
int isEmpty(stack* s, node* head);
void push(node* head, int newData);
void pop(stack* s, node* head);

int main() {
	node* head = (node*)malloc(sizeof(node));
	stack* s = createStack(head);

	push(s, head, 1);
	push(s, head, 2);
	push(s, head, 3);

	pop(s, head);
	pop(s, head);
	
	free(s);
	return 0;
}

stack* createStack(node* head) {
	stack* s = (stack*)malloc(sizeof(stack));
	s->dataNode = head;
	s->dataNode->nextNode = head;
	s->dataNode->prevNode = head;

	return s;
}

int isEmpty(stack* s, node* head) {
	return s->dataNode->nextNode == head ? 1 : 0;
}

void push(stack* s, node* head, int newData) {
	node* tailNode = head->prevNode;
	node* newNode = (node*)malloc(sizeof(node));
	s->dataNode->nextNode = newNode;
	newNode->data = newData;
	newNode->nextNode = head;
	newNode->prevNode = tailNode;

	tailNode->nextNode = newNode;
	head->prevNode = newNode;
}

void pop(stack* s, node* head) {
	if (isEmpty(s, head) == 1) {
		return;
	}
	else {
		node* deleteNode = head->prevNode;
		deleteNode->prevNode->nextNode = head;

		s->dataNode->prevNode = deleteNode->prevNode;
		free(deleteNode);
	}
}
