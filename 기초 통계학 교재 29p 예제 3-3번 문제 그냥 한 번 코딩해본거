#include<stdio.h>   //기초 통계학 교재 29p 예제 3-3번 문제 그냥 한 번 코딩해본거
#include<math.h>
int main()
{
	int arr[6];
	for (int i = 0; i < 6; i++) {
		scanf_s("%d", &arr[i]);
	}
	
	int san = 0;

	for (int i = 0; i < 6; i++) {
		san += arr[i];
	}
	san = san / 6;

	float bun = 0;

	for (int i = 0; i < 6; i++) {
		bun += arr[i] * arr[i];
	}
	bun = (bun - 6 * san * san) / 5;

	float pyo = sqrt(bun);

	printf("분산: %.1f, 표준편차: %.2f\n", bun, pyo);

	return 0;
}
