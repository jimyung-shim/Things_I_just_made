#include<stdio.h>
int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++)arr[i] = 1;

	scanf_s("%d %d", &arr[3], &arr[4]);

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}

	printf("%d", sum);

	return 0;
}
