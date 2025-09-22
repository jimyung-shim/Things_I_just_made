// 2023 응컴 기말 1번

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	while (1) {
		printf("Enter an integer>> ");
		char integer[10000];
		scanf("%s", integer);

		if (integer[0] == '0')return 0;

		int n1 = integer[0] - '0', n2 = integer[1] - '0', judge = integer[2] - '0';

		if (judge >= 5 && judge <= 9) {
			n2++;
			if (n2 >= 10) {
				n2 = 0;
				n1++;
			}
		}

		int length = strlen(integer) - 1;;
		if (n1 >= 10) {
			length++;
			n1 = n1 / 10;
		}

		printf("%d.%d*10^%d\n\n", n1, n2, length);
	}
	return 0;
}

// 연결리스트 삽입 정렬

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* tail;

int main()
{
	while (1) {
		tail = NULL;
		int arr[999];
		int i = 0;
		printf("Enter integers>> ");

		for (;;) {
			scanf("%d", &arr[i]);
			if (arr[i] < 0)break;
			i++;
		}

		if (i == 0 && arr[0] < 0)return 0;

		for (int j = 0; arr[j] > 0; j++) {
			if (tail == NULL || tail->data >= arr[j]) {
				node* newnode = (node*)malloc(sizeof(node));
				newnode->data = arr[j];
				newnode->next = tail;
				tail = newnode;
			}

			else {
				node* cur = tail;
				node* pre = NULL;
				while (cur != NULL && cur->data < arr[j]) {
					pre = cur;
					cur = cur->next;
				}

				node* newnode = (node*)malloc(sizeof(node));
				newnode->data = arr[j];
				newnode->next = cur;
				if (pre != NULL)pre->next = newnode;
			}

			node* cur = tail;
			while (cur != NULL) {
				printf("%d ", cur->data);
				cur = cur->next;
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

// 삽입정렬

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("Enter integers>> ");
	int arr[999], count = 0;
	while (1) {
		scanf("%d", &arr[count]);
		if (arr[count] < 0)break;
		count++;
	}

	for (int i = 1; i < count; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
		for (int a = 0; a < count; a++)printf("%d ", arr[a]);
		printf("\n");
	}
	return 0;
}

// 퀵소트

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void quickSort(int arr[], int left, int right, int size) {
    if (left >= right) return;

    int pivot = arr[left], l = left + 1, r = right;

    while (l <= r) {
        if (arr[l] <= pivot) l++;
        else if (arr[r] >= pivot) r--;
        else {
            int temp = arr[l];
            arr[l++] = arr[r];
            arr[r--] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[r];
    arr[r] = temp;

    printf("(%d,%d): ", left, right);
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, left, r - 1, size);
    quickSort(arr, r + 1, right, size);
}

int main() {
    while (1) {
        int n;
        printf("Enter the number of integers>> ");
        scanf("%d", &n);
        if (n == 0)return 0;

        int arr[999];
        printf("Enter %d integers>> ", n);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        quickSort(arr, 0, n - 1, n);

        printf("After sorting: ");
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n\n");
    }
    return 0;
}
