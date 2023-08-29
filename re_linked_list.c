#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct node* nextNode;
} node;

node* insertFirst(node* head, int newData);
node* insertLast(node* head, int newData);
node* insertAt(node* head, int pos, int newData);
node* deleteFirst(node* head);
node* deleteLast(node* head);
node* deleteAt(node* head, int pos);
void showList(node* head);
void deleteList(node* head);
int getListLength(node* head);
node* reverseList(node* head);

int main() {
	node* head = NULL;

	head = insertFirst(head, 10);
	head = insertFirst(head, 20);
	head = insertFirst(head, 30);
	head = insertLast(head, 40);
	head = insertAt(head, 1, 50);
	head = insertAt(head, 0, 0);
	head = insertAt(head, 6, 60);
	head = deleteFirst(head);
	head = deleteLast(head); 
	head = deleteAt(head, 1);
	printf("linked list length: %d\n", getListLength(head));
	showList(head);
	head = reverseList(head);
	showList(head);
	deleteList(head);

	return 0;
}

node* insertFirst(node* head, int newData) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->nextNode = head;

	return newNode;
} 

void showList(node* head) {
	node* curNode = head;
	while (curNode != NULL) {
		printf("%d ", curNode->data);
		curNode = curNode->nextNode;
	}
	printf("\n");
}

node* insertLast(node* head, int newData) {
	node* curNode = head;
	while (curNode->nextNode != NULL) {
		curNode = curNode->nextNode;
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	curNode->nextNode = newNode;
	newNode->nextNode = NULL;

	return head;
}

node* insertAt(node* head, int pos, int newData) {
	node* curNode = head;
	for (int i = 1; i < pos; i++) {
		curNode = curNode->nextNode;
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;

	if (pos == 0) {
		newNode->nextNode = head;

		return newNode;
	}
	else {
		newNode->nextNode = curNode->nextNode;
		curNode->nextNode = newNode;

		return head;
	}
}

node* deleteFirst(node* head) {
	node* deleteNode = head;
	head = deleteNode->nextNode;
	free(deleteNode);
	
	return head;
}

node* deleteLast(node* head) {
	if (head == NULL) {     
		return NULL;
	}
	else if (head->nextNode == NULL) {    
		return NULL;
	}
	else {     
		node* curNode = head;
		node* deleteNode = curNode->nextNode;

		while (deleteNode->nextNode != NULL) {
			curNode = curNode->nextNode;
			deleteNode = curNode->nextNode;
		}
		curNode->nextNode = NULL;
		free(deleteNode);

		return head;
	}
}

node* deleteAt(node* head, int pos) {
	node* curNode = head;
	node* deleteNode = curNode->nextNode;

	for (int i = 1; i < pos; i++) {
		curNode = curNode->nextNode;
		deleteNode = curNode->nextNode;
	}

	if (pos == 0) {
		deleteNode = head;
		head = head->nextNode;
		free(deleteNode);

		return head;
	}
	else {
		curNode->nextNode = deleteNode->nextNode;
		free(deleteNode);

		return head;
	}
}

void deleteList(node* head) {
	node* curNode = head;

	while (curNode != NULL) {
		node* nextNode = curNode->nextNode;
		free(curNode);
		curNode = nextNode;
	}
}

int getListLength(node* head) {
	int length = 1;
	if (head == NULL) {
		length = 0;
	}
	node* curNode = head;
	while (curNode->nextNode != NULL) {
		curNode = curNode->nextNode;
		length++;
	}
	return length;
}

node* reverseList(node* head) {
	node* curNode = head;
	node* prevNode = NULL;
	node* nextNode = NULL;

	while (curNode != NULL) {
		nextNode = curNode->nextNode;
		curNode->nextNode = prevNode;
		prevNode = curNode;
		curNode = nextNode;
	}
	head = prevNode;
	return head;
}
