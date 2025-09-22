/*2022 응컴 중간 1번*/
#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of integers >> ");
	scanf_s("%d", &n);

	int arr[100] = { 0 };
	printf("Enter integers >> ");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	int j = 0;
	int flag = 1;
	while (1) {
		if (arr[j] > arr[j + 1]) {
			flag = 0;
			int swap = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = swap;
		}
		if (j == n - 2 && flag)break;
		if (j == n - 2) {
			j = 0;
			flag = 1;
			continue;
		}
		j++;
	}

	printf("After sorting: ");
	for (int i=0; i < n; i++)printf("%d ", arr[i]);
	
	return 0;
}



/* 	   2016		임의 개수의 정수를 입력하여, 오름차순 및 내림차순으로 정렬하는 프로그램을 작성하라.*/
#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of integers >> ");
	scanf_s("%d", &n);

	printf("Enter integers >> ");
	int arr[100] = { 0 };
	for (int i = 0; i < n; i++)scanf_s("%d", &arr[i]);

	int i = 0;
	int flag = 1;
	while (1) {
		if (arr[i] > arr[i + 1]) {
			flag = 0;
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}

		if (flag && i == n - 2)break;

		if (i == n - 2) {
			i = 0;
			flag = 1;
			continue;
		}
		i++;
	}

	printf("Ascending: ");
	for (int j = 0; j < n; j++)printf("%d ", arr[j]);
	
	printf("\nDescending: ");
	for (int j = n - 1; j >= 0; j--)printf("%d ", arr[j]);

	return 0;
}
