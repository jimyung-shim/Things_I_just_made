#include<stdio.h>		// 응용 STEP-Up 기출문제 4번
int main()
{
	int n;
	scanf_s("%d", &n);

	int sum = 0;

	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	printf("%d", sum);

	return 0;
}

#include<stdio.h>		// 응용 STEP-Up 기출문제 6번
int main()
{
	int n;
	scanf_s("%d", &n);

	if (n % 2 == 0) {		// 짝수
		for (int i = 1; i <= n; i++) {
			printf("%d ", 2 * i);
		}
	}

	if (n % 2 != 0) {		// 홀수
		for (int i = 1; i <= n; i++) {
			printf("%d ", 2 * i - 1);
		}
	}
	return 0;
}

#include<stdio.h>		// 응용 STEP-Up 기출문제 7번
int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int x, y;

	scanf_s("%d %d", &x, &y);

	swap(&x, &y);

	printf("%d %d", x, y);

	return 0;
}
