#define _CRT_SECURE_NO_WARNONGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* nextNode;
	struct Node* prevNode;
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
	head = insertAt(head, 2, 50);
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
	if (head == NULL) {
		newNode->nextNode = newNode;
		newNode->prevNode = newNode;
	}
	else {
		newNode->nextNode = head;
		newNode->prevNode = head->prevNode;
		head->prevNode->nextNode = newNode;
		head->prevNode = newNode;
	}
	return newNode;
}

node* insertLast(node* head, int newData) {
	node* tailNode = head->prevNode;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->nextNode = head;
	newNode->prevNode = tailNode;

	tailNode->nextNode = newNode;
	head->prevNode = newNode;

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
		newNode->prevNode = head->prevNode;

		head->prevNode->nextNode = newNode;
		head->prevNode = newNode;

		return newNode;
	}
	else {
		newNode->prevNode = curNode;
		newNode->nextNode = curNode->nextNode;

		curNode->nextNode->prevNode = newNode;
		curNode->nextNode = newNode;

		return head;
	}
}

node* deleteFirst(node* head) {
	node* deleteNode = head;
	head->prevNode->nextNode = deleteNode->nextNode;
	head->nextNode->prevNode = head->prevNode;
	head = deleteNode->nextNode;
	free(deleteNode);

	return head;
	// return deleteNode->nextNode; ?
}

node* deleteLast(node* head) {
	node* deleteNode = head->prevNode;
	deleteNode->prevNode->nextNode = head;
	head->prevNode = deleteNode->prevNode;
	free(deleteNode);

	return head;
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
		head->nextNode->prevNode = head->prevNode;
		head->prevNode->nextNode = head->nextNode;
		head = head->nextNode;
		free(deleteNode);

		return head;
	}
	else {
		curNode->nextNode = deleteNode->nextNode;
		deleteNode->nextNode->prevNode = curNode;
		free(deleteNode);

		return head;
	}
}

void showList(node* head) {
	printf("%d ", head->data);
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
	int length = 1;
	if (head == NULL) {
		length = 0;
	}
	node* curNode = head;
	while (curNode->nextNode != head) {
		curNode = curNode->nextNode;
		length++;
	}

	return length;
}

node* reverseList(node* head) {
	if (head == NULL || head->nextNode == head) {
		return head;  
	}

	node* curNode = head;
	node* prevNode = NULL;
	node* nextNode = NULL;

	do {
		nextNode = curNode->nextNode;  
		curNode->nextNode = prevNode;  
		curNode->prevNode = nextNode;  
		prevNode = curNode; 
		curNode = nextNode;  
	} while (curNode != head);

	head = prevNode;  

	return head;
}
