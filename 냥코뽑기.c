#include<stdio.h>

int main() {

	char string[9][100] = { "고양이","탱크","배틀","징글","황소","새","물고기","도마뱀","거신" };

	for (int i = 0; i < 9; i++) {
		int n = rand() % 9;
		printf("%s\n", string[n]);

	}

	return 0;
}
