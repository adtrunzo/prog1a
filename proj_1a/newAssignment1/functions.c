#include "functions.h"

void InsertAtTail(char* x, char* y, long z, char* a, int b){
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x, y, z, a, b);
	if(head == NULL){
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
}

void remove_node(struct Node* head, char *value){
	
	struct Node* temp;
	struct Node* temp2;	
//empty list	
	if(head==NULL){
		return;
	}
	//removing from front
	if(head->last == value){
		//last node left
		//if(head->next ==NULL && head->prev == NULL){
		head = head->next;
		free(head->prev);
		head->prev=NULL;
		//printf("the node needs to be removed");
	}
	//removing from middle
	while(head->next != NULL){
		if(head->last == value){
			temp = head->prev;
			temp->next = head->next;
			head->next->prev = temp;
			free(head);
		}else{
		head = head->next;
		}
	}
	//removing from end
	while(head->next != NULL){
		head = head->next;
	}
	if(head->last == value){
		head = head->prev;
		free(head->next);
		head->next=NULL;
	}
	/*
	temp= head->prev;
	temp->next = NULL;
	free(head);
	head=NULL;
	*/
	/*else{
		while(temp->next!=NULL){
			temp = temp->next;
			if(temp->last == value){
			temp = temp->prev;
			temp->next = temp->next->next;
			temp = temp->next;
			temp->prev = temp->prev->prev;
			temp = temp->prev;
			free(temp);
			}
		}
	}
*/
}



void Print(){
	struct Node* temp = head;
	printf("Forward: ");
//	if (temp->next == NULL && temp->prev == NULL){
//		printf("no nodes left");
//	}
	if(temp==NULL) return;
	while(temp != NULL){

		if(temp->last != NULL){
		printf("%s ", temp->last);
		printf("%s ", temp->first);
		printf("%ld ", temp->ID);
		printf("%s ", temp->year);
		printf("%d ", temp->grad);
		}
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint(){
	struct Node* temp = head;
	if(temp == NULL) return;
	while(temp->next != NULL){
		temp = temp->next;
	}
	printf("Reverse: ");
	while(temp != NULL){
		printf("%s ", temp->last);
		printf("%s ", temp->first);
		printf("%ld ", temp->ID);
		printf("%s ", temp->year);
		printf("%d ", temp->grad);
		temp = temp->prev;
	}
	printf("\n");
}

int main() {
	head = NULL;
	int b = 0;
	printf("Hello, welcome to the student list. What would you like to do?\n");	
	int a;
	int len;
	char * last;
	char * first;
	long ID;
	char * year;
	int GradYear;
	while(b == 0){
	printf("1: Add a Student\n");
	printf("2: Remove a Student\n");
	printf("3: Print the list Forwards\n");
	printf("4: Print the list Backwards\n");
	printf("5: Exit the program\n");
	scanf("%d", &a);
	if(a==1){
		//char last[40];
		//char first[40];
	       	//long ID;
	       	//char year[40];
	       	//int GradYear;
		printf("Provide Length of Student's Last Name\n");
		scanf("%d", &len);
		last=malloc(len);
		//scanf("%s", last);
		printf("Provide Student's Last Name\n");
		scanf("%s", last);
		printf("Provide Length of Student's First Name\n");
		scanf("%d", &len);
		first=malloc(len);
		printf("Provide Student's First Name\n");
		scanf("%s", first);
		printf("Provide Students ID\n");
		scanf("%ld", &ID);
		printf("Provide Student Class Year Length (i.e. freshman, sophmore, etc.)\n");
		scanf("%d", &len);
		year=malloc(len);
		printf("Provide Student Class Year (i.e. freshman, sophmore, etc.)\n");
		scanf("%s", year);
		printf("Provide Student Gradution Year\n");
		scanf("%d", &GradYear);
		InsertAtTail(last, first, ID, year, GradYear);	
	}
	if(a==2){
		printf("Provide Student's Last Name\n");
		scanf("%s", last);
		remove_node(head, last);
	}
	if(a==3){
		Print();
	}
	if(a==4){
		ReversePrint();
	}if(a==5){
		free(last);
		free(first);
		free(year);
		exit(0);
	}	
	}



	//InsertAtTail("Last", "first", 4443, "Freshman", 2020); Print(); ReversePrint();
	//InsertAtTail("Hetfield", "James", 1424, "Sophmore", 1981); Print(); ReversePrint();
	//InsertAtTail("Ulrich", "Lars", 2112, "Senior", 8573); Print(); ReversePrint();
	//InsertAtTail("Ulrich", "Lars", 2112, "Senior", 8573); Print(); ReversePrint();
	//InsertAtTail("World", "order", 31234, "Junior", 1121); Print(); ReversePrint();
	//printf("\n\nremove\n\n");
	//remove_node(head, "Last"); Print(); ReversePrint(); 
	//remove_node(head, "Ulrich"); Print(); ReversePrint();
	//remove_node(head, "World"); Print(); ReversePrint();
	//remove_node(head, "Hetfield"); Print(); ReversePrint();
}
