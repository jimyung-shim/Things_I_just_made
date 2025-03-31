#include<stdio.h>                      // 알고리즘 1
int main()
{
	int n;
	scanf_s("%d", &n);
	int operationcount = 0; // 연산횟수 0으로 초기화
	for (int i = 2; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)count++;  // 약수의 갯수 세기
			operationcount++; // 연산횟수 증가;
		}
		if (count == 2)printf("%d ", i); // 약수의 갯수가 2개인 경우 즉, 소수일때 출력
	}
	printf("\nOperation count : %d", operationcount);
	return 0;
}

#include<stdio.h>                       // 알고리즘 2
int main()
{
	int n;
	scanf_s("%d", &n);
	int operationcount = 0; // 연산횟수 0으로 초기화
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= i - 1; j++) {
			operationcount++;  // 연산횟수 증가
			if (i % j == 0)break;
			// 1과 자신을 제외한 모든 숫자로 나눠지지 않을 때. 즉, 소수일 때 출력
			if (j == i - 1)printf("%d ", i); 
		}
	}
	printf("\nOperation count : %d", operationcount);
	return 0;
}

#include<stdio.h>                       // 3번 알고리즘
int main()
{
	int n;
	scanf_s("%d", &n);
	
	int operationcount = 0; // 연산횟수 0으로 초기화

	if (n >= 2) {
		printf("2 "); // 2도 소수이기에 출력
	}

	for (int i = 3; i <= n; i += 2) {
		int isp = 1; // 소수 판별
		for (int j = 3; j  <= i - 1; j += 2) {
			operationcount++;  // 연산횟수 증가
			if (i % j == 0) {
				isp = 0; // 소수가 아님
				break;
			}
		}
		if (isp) {
			printf("%d ", i); // 소수일 경우 출력
		}
	}
	printf("\nOperation count : %d", operationcount);
	return 0;
}

#include<stdio.h>                       // 4번 알고리즘
#include<math.h> // c언어로 루트를 구현하기 위해 포함
int main()
{
	int n;
	scanf_s("%d", &n);
	
	int operationcount = 0; // 연산횟수 0으로 초기화

	if (n >= 2) {
		printf("2 "); // 2도 소수이므로 출력
	}

	for (int i = 3; i <= n; i += 2) {
		int isp = 1; // 소수 판별
		for (int j = 3; j <= sqrt(i); j += 2) { // sqrt함수를 통해 루트 구현
			operationcount++;  // 연산횟수 증가
			if (i % j == 0) {
				isp = 0; // 소수가 아님
				break;
			}
		}
		if (isp) {
			printf("%d ", i); // 소수일 경우 출력
		}
	}
	printf("\nOperation count : %d", operationcount);
	return 0;
}

#include <stdio.h>                      // 5번 알고리즘
#include <math.h>

#define MAX 1000  // 필요한 범위의 최대값

int isp[MAX];  // 소수 여부를 저장하는 배열  // isp: is prime

void sieve_of_eratosthenes(int n) {
	for (int i = 2; i <= n; i++) {
		isp[i] = 1;  // 모든 수를 소수로 정의
	}
	isp[0] = isp[1] = 0;  // 0과 1은 소수가 아님

	for (int i = 2; i * i <= n; i++) {
		if (isp[i]) {
			for (int j = i * i; j <= n; j += i) {
				isp[j] = 0;  // i의 배수는 소수가 아님
			}
		}
	}
}

int main() {
	int n, i, j;
	int countoperation = 0; // 연산 횟수 초기화
	scanf_s("%d", &n);

	if (n >= 2) {
		printf("%d ", 2);  // 2도 소수이므로 출력
	}

	sieve_of_eratosthenes(n);

	for (i = 3; i <= n; i += 2) {
		int flag = 1;  // 소수일 경우로 초기화


		for (j = 3; j <= sqrt(i); j += 2) {
			if (isp[j]) {
				countoperation++;  //연산횟수 증가

				if (i % j == 0) {
					flag = 0;  // 소수가 아닐 경우 flag는 0으로 정의
					break;
				}
			}
		}
		if (flag) printf("%d ", i);  //flag 가 0이 아닐 경우 출력
	}

	printf("\nOperation count : %d", countoperation); // 총 연산 횟수 출력
	return 0;
}
