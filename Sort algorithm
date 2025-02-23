#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void selction_sort(int arr[],int n){
	int key;
	for (key = 0; key < n; key++) {
		int index = key;
		for (int j = key; j < n; j++) {
			if (arr[j] < arr[index]) {
				index = j;
			}
		}

		int temp = arr[key];
		arr[key] = arr[index];
		arr[index] = temp;
	}

}

void bubble_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped)break;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	for (int a = 0; a < n; a++)printf("%d ", arr[a]);
	printf("\n");


	bubble_sort(arr, n);

	for (int a = 0; a < n; a++)printf("%d ", arr[a]);



	return 0;
}

