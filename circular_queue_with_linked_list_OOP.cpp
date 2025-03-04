#include<iostream>
using namespace std;

class circle_Q {
private:
	typedef struct node {
		int data;
		struct node* next;
		struct node* prev;
	};

	node* head;
	node* tail;

public:
	circle_Q():head(NULL),tail(NULL){}

	void create_node(int x) {
		node* newnode = new node;
		newnode->data = x;
		newnode->next = NULL;
		newnode->prev = NULL;


		if (head == NULL) {
			head = tail = newnode;
		}
		else {
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
		tail->next = head;
		head->prev = tail;

	}

	void show_circular_queue() {
		if (head == NULL) return;

		node* cur = head;

		do {
			cout << cur->data << " ";
			cur = cur->next;

		} while (cur != head);
		cout << endl;
	}

	void show_reverse_circular_queue() {
		if (tail == NULL)return;

		node* cur = tail;
		do {
			cout << cur->data << " ";
			cur = cur->prev;

		} while (cur != tail);
		cout << endl;
	}
	~circle_Q() {
		if (head == NULL)return;

		node* cur = head;
		do {
			node* nextNode = cur->next;
			delete cur;
			cur = nextNode;
		} while (cur != head);

		head = tail = NULL;
	}
};


int main() {
	circle_Q Q;

	Q.create_node(4);
	Q.create_node(15);
	Q.create_node(5);
	Q.create_node(2);
	Q.create_node(34);
	Q.create_node(78);
	Q.create_node(90);
	Q.create_node(47);
	Q.create_node(987);


	Q.show_circular_queue();
	Q.show_reverse_circular_queue();

	return 0;
}
