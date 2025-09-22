#include<stdio.h>
int main(int argc, char* argv[])
{
	int arr[9];

	for (int i = 1; i < argc; i++) {
		arr[i - 1] = atoi(argv[i]);
	}

	printf("%s> sortInt ",argv[0]);
	for (int i = 0; i < 9; i++) {
		printf("%d ", arr[i]);
	}

	int i = 0;
	int flag = 1;
	while (1) {
		if (arr[i] > arr[i + 1]) {
			flag = 0;
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}

		if (i == 7 && flag)break;
		if (i == 7) {
			i = 0;
			flag = 1;
			continue;
		}
		i++;
	}
	printf("\nAfter sorting: ");
	for (int j = 0; j < 9; j++)printf("%d ", arr[j]);

	return 0;
}
