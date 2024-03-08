#include<stdio.h>
#include<stdlib.h>

struct Node {
	char* last;
	char* first;
	long ID;
	char* year;
	int grad;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(char* x, char* y, long z, char* a, int b){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->last = x;
	newNode->first = y;
	newNode->ID = z;
	newNode->year = a;
	newNode->grad = b;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertAtTail(char*, char *, long, char*, int);

void remove_node(struct Node*, char*);

void Print();

void ReversePrint();
