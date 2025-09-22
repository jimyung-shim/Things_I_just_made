#include<stdio.h>		// GCD1 알고리즘
#define MAX 1000
int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);		// 두 수 a, b 입력
	int max = 0;
	int ad[MAX], bd[MAX];

	for (int i = 0; i < MAX; i++) {		//a,b 의 약수 배열ad[], bd[] 전부 0으로 초기화
		ad[i] = 0;
		bd[i] = 0;
	}

	int acount = 0, bcount = 0;
	for (int i = 1; i <= a; i++) {		// a의 약수를 찾아내서 배열 ad[]에 집어넣기
		if (a % i == 0) {
			ad[acount] = i;
			acount++;
		}
	}

	for (int i = 1; i <= b; i++) {		// b의 약수를 찾아내서 배열 bd[]에 집어넣기
		if (b % i == 0) {
			bd[bcount] = i;
			bcount++;
		}
	}

	int pd[MAX];
	int pcount = 0;
	for (int i = 0; i < MAX; i++)pd[i] = 0;		// 공약수 배열 pd[] 전부 0으로 초기화

	for (int i = 0; i < a; i++) {		// a, b의 공약수를 구해서 배열pd[]에 집어넣기
		for (int j = 0; j <= b; j++) {
			if (ad[i] == bd[j]) {
				pd[pcount] = bd[j];
				pcount++;
			}
		}
	}
	int x = 0;
	for (int i = 0; i < MAX; i++) {		// 변수 x를 이용하여 최대공약수 구하기
		if (pd[i])x++;
	}
	printf("최대공약수: %d", pd[x - 1]);		// 최대공약수 출력
	
	return 0;
}

#include <stdio.h>			// GCD2  알고리즘
int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);		// a, b 입력 받기

	int factors1[100] = { 0 }, factors2[100] = { 0 };  
	int count1 = 0, count2 = 0;

	for (int i = 2; i * i <= a; i++) {		// a 소인수분해
		while (a % i == 0) {
			factors1[count1++] = i;
			a /= i;
		}
	}
	if (a > 1) {
		factors1[count1++] = a;
	}

	for (int i = 2; i * i <= b; i++) {		// b 소인수분해
		while (b % i == 0) {
			factors2[count2++] = i;
			b /= i;
		}
	}
	if (b > 1)factors2[count2++] = b;
	
	int gcd = 1;
	for (int i = 0; i < count1; i++) {		// 최대공약수 계산
		for (int j = 0; j < count2; j++) {
			if (factors1[i] == factors2[j]) {
				gcd *= factors1[i];
				factors2[j] = -1; // 중복 방지
				break;
			}
		}
	}

	printf("최대공약수: %d\n", gcd);
	return 0;
}

#include<stdio.h>		// GCD3 알고리즘
int Euclid_algorithm(int x, int y) {
	/* 유클리드 함수 구현 : mod 연산을 반복하여 나머지가 0이 됐을 때,
	마지막 계산에서 나누는 수로 사용된 수가 최대공약수가 된다.*/
	int mod = 1;	
	for (;;) {
		mod = x % y;
		if (mod == 0) {	// mod가 나머지일 때 0이 됐으므로 y가 최대공약수
			return y;
		}
		x = y % mod;
		if (x == 0) {	// x가 나머지일 때 0이 됐으므로 mod가 최대공약수
			return mod;
		}
		y = mod % x;
		if (y == 0) {	// y가 나머지일 때 0이 됐으므로 x가 최대공약수
			return x;
		}
	}
}
int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);		// 두 수 a, b 입력

	printf("최대공약수: %d", Euclid_algorithm(a, b));		// 최대공약수 출력

	return 0;
}
