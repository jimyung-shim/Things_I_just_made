// C
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 1000
int stack[MAX];
int top = -1;

void push(int x) {
	if (top < MAX - 1) {
		top++;
		stack[top] = x;
	}
}

void calculate(char x) {
	if (top >= 1) {
		if (x == '+') {
			stack[top - 1] = stack[top - 1] + stack[top];
		}
		if (x == '-') {
			stack[top - 1] = stack[top - 1] - stack[top];
		}
		if (x == '*') {
			stack[top - 1] = stack[top - 1] * stack[top];
		}
		if (x == '/') {
			stack[top - 1] = stack[top - 1] / stack[top];
		}
		top--;
	}
}

int main() {
	char express[100];
	gets(express);

	int len = strlen(express);

	for (int i = 0; i < len; i++) {
		if (express[i] != ' ') {
			if (isdigit(express[i])&&isdigit(express[i+1])&&!isdigit(express[i+2])) {
				int value = (express[i] - '0') * 10 + express[i+1] - '0';
				push(value);
				i++;
			} else if (isdigit(express[i])&&!isdigit(express[i+1])) {
				int value = express[i] - '0';
				push(value);
			}
			else {
				calculate(express[i]);
			}
		}
	}

	printf("%d", stack[0]);


	return 0;
}

//C++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

#define MAX 1000
int stack[MAX];
int top = -1;
int num = 0, operator_num = 0;


void push(int x) {
	if (top < MAX - 1) {
		top++;
		stack[top] = x;
		num++;
	}
}

void calculation(char x) {
	if(top>=1) {
		if (x == '+') {
			stack[top - 1] = stack[top - 1] + stack[top];
		}
		if (x == '-') {
			stack[top - 1] = stack[top - 1] - stack[top];
		}
		if (x == '*') {
			stack[top - 1] = stack[top - 1] * stack[top];
		}
		if (x == '/') {
			stack[top - 1] = stack[top - 1] / stack[top];
		}
		top--;
	}
}

int main()
{
	string expression;
	getline(cin, expression);

	if (expression == "0")return 0;

	int len = expression.length();

	for (int i = 0; i < len; i++) {
		if (expression[i] != ' ') {
			if (isdigit(expression[i]) && isdigit(expression[i + 1]) && !isdigit(expression[i + 2])) {
				int value = (expression[i] - '0') * 10 + expression[i + 1] - '0';
				push(value);
				i++;
			}
			else if (isdigit(expression[i]) && !isdigit(expression[i + 1])) {
				int value = expression[i] - '0';
				push(value);
			}
			else {
				calculation(expression[i]);
				operator_num++;
			}
		}
	}
	if (num == operator_num+1) {
		cout << stack[0] << endl;
	}
	else {
		cout << "Invalid expression" << endl;
	}

	return 0;
}
