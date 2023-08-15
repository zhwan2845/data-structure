#define _CRT_SECURE_NO_WARNONGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* nextNode;  
} node;

void insertFirst(node* head, int newData);
void insertLast(node* head, int newData);
void insertAt(node* head, int pos, int newData);
void deleteFirst(node* head);
void deleteLast(node* head);
void deleteAt(node* head, int pos);
void showList(node* head);
void deleteList(node* head);
int getListLength(node* head);

int main() {
	node* head = (node*)malloc(sizeof(node));
	head->nextNode = head;

	insertFirst(head, 10);
	insertFirst(head, 20);
	insertFirst(head, 30);
	insertLast(head, 40);
	insertAt(head, 2, 50);
	deleteFirst(head);
	deleteLast(head);
	deleteAt(head, 1);
	printf("linked list length: %d\n", getListLength(head));

	showList(head);
	deleteList(head);

	return 0;
}

void insertFirst(node* head, int newData) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->nextNode = head->nextNode;

	head->nextNode = newNode;
}

void showList(node* head) {
	node* curNode = head->nextNode;
	while (curNode != head) {
		printf("%d ", curNode->data);
		curNode = curNode->nextNode;
	}
	printf("\n");
}

void insertLast(node* head, int newData) {
	node* curNode = head;
	while (curNode->nextNode != head) {
		curNode = curNode->nextNode;
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	curNode->nextNode = newNode;
	newNode->nextNode = head;
}

void insertAt(node* head, int pos, int newData) {
	node* curNode = head;
	for (int i = 1; i < pos; i++) {
		curNode = curNode->nextNode;
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->nextNode = curNode->nextNode;
	curNode->nextNode = newNode;
}

void deleteFirst(node* head) {
	node* deleteNode = head->nextNode;
	head->nextNode = deleteNode->nextNode;
	free(deleteNode);
}

void deleteLast(node* head) {
	node* curNode = head;
	node* deleteNode = curNode->nextNode;
	while (deleteNode->nextNode != head) {
		curNode = curNode->nextNode;
		deleteNode = curNode->nextNode;
	}
	free(deleteNode);
	curNode->nextNode = head;
}

void deleteAt(node* head, int pos) {
	node* curNode = head;
	node* deleteNode = curNode->nextNode;

	for (int i = 1; i < pos; i++) {
		curNode = curNode->nextNode;
		deleteNode = curNode->nextNode;
	}
	curNode->nextNode = deleteNode->nextNode;
	free(deleteNode);
}

void deleteList(node* head) {
	node* curNode = head;

	while (curNode != head) {
		node* nextNode = curNode->nextNode;
		free(curNode);
		curNode = nextNode;
	}
}

int getListLength(node* head) {
	int length = 0;
	node* curNode = head;
	while (curNode->nextNode != head) {
		curNode = curNode->nextNode;
		length++;
	}

	return length;
}
