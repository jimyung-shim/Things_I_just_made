#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}node;

node* tail = NULL;
node* head = NULL;

void createNode(int x) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (head == NULL) {
		head = newnode;
		tail = newnode;
	}
	else {
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}

}

void show_list() {
	node* cur = head;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

void show_list_reverse() {
	node* cur = tail;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->prev;
	}
}


int main() {
	createNode(8);
	createNode(1);
	createNode(6);
	createNode(7);
	createNode(3);
	createNode(5);
	show_list_reverse();
	//show_list();
	printf("\n%d\n%d", head->data,tail->data);

	return 0;
}
