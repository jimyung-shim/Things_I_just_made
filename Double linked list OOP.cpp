#include<iostream>

using namespace std;

class double_linked_list {
private:
	typedef struct node {
		int data;
		struct node* next;
		struct node* prev;
	}node;

	node* head = NULL;
	node* tail = NULL;
public:
	double_linked_list() : head(NULL),tail(NULL){}

	void create_node(int x) {
		node* newNode = new node;
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;

		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void show_list() {
		node* cur = head;
		while (cur != NULL) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}

	void show_list_reverse() {
		node* cur = tail;
		while (cur != NULL) {
			cout << cur->data << " ";
			cur = cur->prev;
		}
		cout << endl;
	}

};

int main()
{
	double_linked_list DLL;

	DLL.create_node(34);
	DLL.create_node(313);
	DLL.create_node(4);
	DLL.create_node(25);
	DLL.create_node(73);
	DLL.create_node(54);
	DLL.create_node(90);
	DLL.create_node(85);


	DLL.show_list();
	DLL.show_list_reverse();

	return 0;
}
