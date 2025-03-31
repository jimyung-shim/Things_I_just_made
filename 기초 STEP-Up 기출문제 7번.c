#include<stdio.h>
int add(int x,int y) {
	return x + y;
}

int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);

	add(a, b);

	printf("%d", add(a, b));
	return 0;
}
