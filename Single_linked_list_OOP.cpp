#include<iostream>

using namespace std;

class linked_list {
private:
	class node {
	public:
		int data;
		node* next;

		node(int x) {
			data = x;
			next = NULL;
		}
	};
	node* head;
	node* tail;

public:
	linked_list() : head(NULL), tail(NULL) {
		cout << "Linked list" << endl;
	}

	void createNode(int x) {
		node* Node = new node(x);

		if (head == NULL) {
			head = tail = Node;
		}
		else {
			tail->next = Node;
			tail = Node;
		}
	}

	void show_list() {
		node* cur = head;
		while (cur!=NULL) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	~linked_list() {
		node* cur = head;

		while (cur != NULL) {
			node* pre = cur;
			cur = cur->next;
			delete pre;
		}
		cout << "Linked list is done!" << endl;
	}
};

int main()
{
	linked_list LL;

	LL.createNode(34);
	LL.createNode(15);
	LL.createNode(6);
	LL.createNode(26);
	LL.createNode(75);
	LL.createNode(4);

	LL.show_list();

	return 0;

}
