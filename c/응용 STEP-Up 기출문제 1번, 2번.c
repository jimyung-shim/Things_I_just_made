#include<stdio.h>		// 응용 STEP-Up 기출문제 1번
int main()
{
	int n;
	scanf_s("%d", &n);

	int count = 0;

	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0)printf("%d ", i);
		else count++;
	}
	printf("\n%d", count);

	return 0;
}


#include<stdio.h>		// 응용 STEP-Up 기출문제 2번
int max(int x[],int Num) {
	int M = 0;
	for (int i = 0; i < Num; i++) {
		if (x[i] > M)M = x[i];
	}
	return M;
}
int min(int y[],int num) {
	int m = 1000;
	for (int i = 0; i < num; i++) {
		if (y[i] < m)m = y[i];
	}
	return m;
}
int main()
{
	int arr[5];

	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &arr[i]);
	}


	printf("%d %d", max(arr, 5), min(arr, 5));

	return 0;
}
