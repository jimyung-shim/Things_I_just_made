#include<stdio.h>
#define MAX 100
int stack[MAX] = { 0 };
int top = -1;
int push(int x) {
	if (top == MAX - 1)return 0;
	else {
		top++;
		stack[top] = x;
		return 1;
	}
}

int main()
{
	int n;
	scanf_s("%d", &n);

	int div2 = n;
	while (div2 % 2 == 0) {			// 2로 나눠지면 스텍에 2 푸시
		push(2);
		div2 /= 2;
	}

	int div1 = n;
	for (int i = 3; i <= div1; i += 2) {		// 3이상의 홀수로 나눠지면 스텍에 푸시
		while (div1 % i == 0) {
			push(i);
			div1 /= i;
		}
	}

	for (int i = 0; i < MAX; i++) {
		if (stack[i]) {
			printf("%d ", stack[i]);
		}
	}
	return 0;
}
