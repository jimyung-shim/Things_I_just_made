#include<stdio.h>			// 기초 스텝업 10번 문제
int exchange(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int arr[5] = { 15,29,3,46,22 };

	int max = 0, min = 1000;
	int max_num = 0, min_num = 0;


	for (int i = 0; i < 5; i++) {
		if (arr[i] > max) {
			max = arr[i];
			max_num = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			min_num = i;
		}
	}

	exchange(&arr[max_num], &arr[min_num]);

	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
