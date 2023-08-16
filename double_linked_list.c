#define _CRT_SECURE_NO_WARNONGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* nextNode;
	struct Node* prevNode;
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
	head->prevNode = head;

	return 0;
}

void insertFirst(node* head, int newData) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->nextNode = head->nextNode;
	newNode->prevNode = head;

	head->nextNode = newNode;
	newNode->nextNode->prevNode = newNode;
}

void insertLast(node* head, int newData) {
	node* tailNode = head->prevNode;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->nextNode = head;
	newNode->prevNode = tailNode;

	tailNode->nextNode = newNode;
	head->prevNode = newNode;
}

void insertAt(node* head, int pos, int newData) {
	node* curNode = head;
	for (int i = 0; i < pos; i++) {
		curNode = curNode->nextNode;
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->prevNode = curNode;
	newNode->nextNode = curNode->nextNode;

	curNode->nextNode = newNode;
	curNode->nextNode->prevNode = newNode;
}

void deleteFirst(node* head) {
	node* deleteNode = head->nextNode;
	head->nextNode = deleteNode->nextNode;
	deleteNode->nextNode->prevNode = head;
	free(deleteNode);
}

void deleteLast(node* head) {
	node* deleteNode = head->prevNode;
	deleteNode->prevNode->nextNode = head;

	head->prevNode = deleteNode->prevNode;
	free(deleteNode);
}

void deleteAt(node* head, int pos) {
	node* curNode = head;
	node* deleteNode = curNode->nextNode;

	for (int i = 1; i < pos; i++) {
		curNode = curNode->nextNode;
		deleteNode = curNode->nextNode;
	}
	curNode->nextNode = deleteNode->nextNode;
	deleteNode->nextNode->prevNode = curNode;
	free(deleteNode);
}

void showList(node* head) {
	node* curNode = head->nextNode;
	while (curNode != head) {
		printf("%d ", curNode->data);
		curNode = curNode->nextNode;
	}
	printf("\n");
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
