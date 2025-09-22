#include<iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}node;

node* top = NULL;
node* head = NULL;

void push(int x) {
	node* newnode = new node;
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (head == NULL) {
		head = newnode;
		top = newnode;
	}
	else {
		newnode->prev = top;
		top->next = newnode;
		top = newnode;
	}
}

void pop() {
	if (top == NULL) {
		cout << "Stack is empty!" << endl;
		return;
	}
	cout << top->data << endl;
	node* to_delete = top;
	top = top->prev;
	if (top != NULL) {
		top->next = NULL;
	}
	else {
		head = NULL;
	}

	delete to_delete;
}

void show_stack() {
	node* cur = head;
	while (cur != NULL) {
		cout << cur->data << endl;
		cur = cur->next;
	}
}

int main() {
	push(2);
	push(5);
	push(1);
	push(9);
	push(0);
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();

	cout << "---------------------------------------" << endl;


	show_stack();
	return 0;
}
