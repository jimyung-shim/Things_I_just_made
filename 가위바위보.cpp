#include<iostream>
using namespace std;

class rsp {
private:
	int randomNum = rand() % 3;

public:
	void rock_scissors_paper(string x) {
		string what;
		if (this->randomNum == 0) {
			what = "rock";
			cout << what << endl;
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
			what = "scissors";
			cout << what << endl;
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
			what = "paper";
			cout << what << endl;
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
};

int main()
{
	while (1) {
		rsp rsp1;

		cout << "Rock, Scissors, Paper!: ";

		string what1;
		cin >> what1;
		if (what1 == "quit")return 0;

		rsp1.rock_scissors_paper(what1);
	}
	return 0;
}
