/* L,R,U,D로만 구성된 임의 길이의 스트링을 입력으로 받아, [0,0]좌표로부터 시작하여 최종 좌표([x,y])를 출력하는 프로그램을 작성하라.
현재 위치에서 L은 왼쪽으로, R은 오른쪽으로, U는 위로, D는 아래로 1씩 이됭한다. EXIT가 입력되면 종료하라.*/
#include<stdio.h>
#include<string.h>
int main()
{
	while (1) {
		printf("Enter a string >> ");
		char string[100];
		scanf_s("%s", string, 100);

		if (strcmp(string, "EXIT") == 0)break;

		int x = 0, y = 0;
		for (int i = 0; i < 100; i++) {
			if (string[i] == 'L')x--;
			else if (string[i] == 'R')x++;
			else if (string[i] == 'U')y++;
			else if (string[i] == 'D')y--;
		}
		printf("[%d,%d]\n", x, y);
	}
	return 0;
}
