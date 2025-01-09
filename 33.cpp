#include<iostream>
#include<string>

using namespace std;

class Army {
	typedef struct Soldier {
		string name;
		int age=NULL;
		int num;
		string rank;
		Soldier* next=NULL;
	}Soldier;

	Soldier* head=NULL;
	int k = 1;

public:
	void hire() {
		Soldier* newsoldier = new Soldier;
		cout << "\n**Hire new soldier!!**" << endl;
		
		cout << "Name? : ";
		cin >> newsoldier->name;

		cout << "Age? : ";
		cin >> newsoldier->age;

		cout << "Rank? : ";
		cin >> newsoldier->rank;

		newsoldier->num = k;
		k++;
		if (head == NULL) {
			head = newsoldier;
		}
		
		else {
			Soldier* cur = head;
			while (cur->next != NULL) {
				cur = cur->next;
			}

			cur->next = newsoldier;
		}
		cout << endl;
	}

	void showList() {
		Soldier* cur = head;
		cout << "\n**Soldiers list**" << endl;

		while (cur != NULL) {
			cout << "N." << cur->num << endl;
			cout <<"Name: " << cur->name << endl;
			cout <<"Age: " << cur->age << endl;
			cout <<"Rank: " << cur->rank << endl;
			cout << endl;
			cur = cur->next;
		}
	}

	void getout() {
		cout << "\n**Remove soldier**" << endl;
		cout << "Who?(Insert the soldier number) : ";
		int n;
		cin >> n;

		Soldier* cur = head;
		Soldier* prev = NULL;
		while (cur->num != n) {
			prev = cur;
			cur = cur->next;
		}

		if (prev==NULL)head = cur->next;
		else prev->next = cur->next;

		delete cur;
	}
};

int main()
{
	Army Ar;

	while (1) {


		cout << "Command: ";
		string comm;
		cin >> comm;

		if (comm == "quit")return 0;

		if (comm == "hire" || 
			comm == "Hire") {
			Ar.hire();
		}

		if (comm == "sort"||
			comm == "showlist") {
			Ar.showList();
		}

		if (comm == "delete"||
			comm == "getout") {
			Ar.getout();
		}
	}
	return 0;
}
