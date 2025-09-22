/* 두 정수를 입력하여, 2부터 작은 수까지의 모든 소수를 구하고, 그 소수를 이용한 소인수분해 방법을 써서 최대공약수(GCD)와
최소공배수(LCM)을 구하는 프로그램을 작성하라. 입출력 양식은 아래로 같이 하고, 두 정수가 모두 0이면 프로그램을 종료하라.
(맨 마지막 괄호의 세수는 최대공약수와 처음 입력한 수를 최대공약수로 나눈 수들이다)*/
#include<stdio.h>
#define MAX 100
int stack[MAX] = { 0 };
int top = -1;
int push(int a) {
	if (top == MAX - 1)return 0;
	else {
		top++;
		stack[top] = a;
		return 1;
	}
}

int factorization(int b, int c) {
	int div1 = b, div2 = c;
	while (div1 % 2 == 0 && div2 % 2 == 0) {	// 두 수가 2로 나눠질 경우 스텍에 2푸시
		push(2);
		div1 /= 2;
		div2 /= 2;
	}

	int div3 = b, div4 = c;
	for (int i = 3; i <= c; i += 2) {
		while (div3 % i == 0 && div4 % i == 0) {	// 두 수가 3 이상의 소수로 나눠질 때 스텍에 푸시
			int count = 0;
			for (int j = 1; j <= i; j++) {
				if (i % j == 0)count++;
			}
			if (count == 2) {
				push(i);
				div3 /= i;
				div4 /= i;
			}
		}
	}
}

int gcd() {
	int GCD = 1;
	for (int i = 0; i < MAX; i++) {
		if (stack[i])GCD *= stack[i];
	}
	return GCD;
}
int main()
{
	while (1) {
		printf("Enter two integers >> ");
		int n1, n2;
		scanf_s("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0)break;

		printf("Prime numbers: ");
		for (int i = 2; i <= n2; i++) {
			int count = 0;
			for (int j = 1; j <= i; j++) {
				if (i % j == 0)count++;
			}
			if (count == 2)printf("%d ", i);
		}
		printf("\n");

		factorization(n1, n2);

		printf("(1, %d, %d) ", n1, n2);
		int num = 1;
		for (int i = 0; i < MAX; i++) {
			if (stack[i]) {
				num *= stack[i];
				printf("(%d, %d, %d) ", num, n1 / num, n2 / num);
			}
		}
		printf("\n");

		printf("GCD=%d,  LCM=%d\n", gcd(), n1 * n2 / gcd());
		
		for (int i = 0; i < MAX; i++)stack[i] = 0;
		top = -1;
	}
	return 0;
}

//**************************************************************************************  수정 버전 **********************************************************************************************************
#include<stdio.h>
#define MAX 1000
int stack[MAX] = { 0 };
int top = -1;

void push(int x) {
	if (top < MAX - 1) {
		top++;
		stack[top] = x;
	}
}

void factorization(int a, int b) {
	while (a % 2 == 0 && b % 2 == 0) {
		a /= 2;
		b /= 2;
		push(2);
	}
	for (int i = 3; i <= b; i++) {
		int count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)count++;
		}

		if (count == 2) {
			while (a % i == 0 && b % i == 0) {
				a /= i;
				b /= i;
				push(i);
			}
		}
	}
}

int main()
{
	while (1) {
		printf("Enter two integers >> ");
		int n1, n2;
		scanf_s("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0)break;
		factorization(n1, n2);

		printf("Prime numbers: ");
		for (int i = 2; i <= n2; i++) {
			int count = 0;
			for (int j = 1; j <= i; j++) {
				if (i % j == 0)count++;
			}
			if (count == 2)printf("%d ", i);
		}

		printf("\n(1,%d,%d) ", n1, n2);
		int a = 0;
		int gcd = 1;
		while (stack[a]) {
			gcd *= stack[a];
			printf("(%d,%d,%d) ", gcd, n1 / gcd, n2 / gcd);
			a++;
		}
		printf("\nGCD=%d, LCM=%d\n", gcd, n1 * n2 / gcd);

		for (int b = 0; b < MAX; b++) {
			stack[b] = 0;
		} top = -1;

	}
	return 0;
}
