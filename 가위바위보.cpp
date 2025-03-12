#include<iostream>
using namespace std;

class rsp {
private:
	int randomNum;
	string x;

public:
	rsp() : randomNum(rand() % 3) {
		cout << "Rock, Scissors, Paper!: ";
	}

	void atk() {
		cin >> x;
	}

	int quit() {
		if (x == "quit")return 1;
		return 0;
	}

	void rock_scissors_paper() {
		string computer;
		if (this->randomNum == 0) {
			computer = "rock";
			cout << computer << endl;
			if (x == "Rock" || x == "rock") {
				cout << "Draw!" << endl;
			}
			if (x == "scissors" || x == "Scissors") {
				cout << "You loser!! haha!!" << endl;
			}
			if (x == "Paper" || x == "paper") {
				cout << "You win...." << endl;
			}
		}
		if (this->randomNum == 1) {
			computer = "scissors";
			cout << computer << endl;
			if (x == "Rock" || x == "rock") {
				cout << "You win...." << endl;
			}
			if (x == "scissors" || x == "Scissors") {
				cout << "Draw!" << endl;
			}
			if (x == "Paper" || x == "paper") {
				cout << "You loser!! haha!!" << endl;
			}
		}
		if (this->randomNum == 2) {
			computer = "paper";
			cout << computer << endl;
			if (x == "Rock" || x == "rock") {
				cout << "You loser!! haha!!" << endl;
			}
			if (x == "scissors" || x == "Scissors") {
				cout << "You win...." << endl;
			}
			if (x == "Paper" || x == "paper") {
				cout << "Draw!" << endl;
			}
		}
	}
	~rsp() {
		randomNum = 0;
	}
};

int main()
{
	while (1) {
		rsp rsp1;

		rsp1.atk();

		if (rsp1.quit())return 0;

		rsp1.rock_scissors_paper();
	}
	return 0;
}
