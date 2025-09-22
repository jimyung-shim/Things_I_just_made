#include<stdio.h>
#include<string.h>
int main()
{
	while (1) {
		char string[20];
		scanf_s("%s", string, 20);
		if (strcmp(string, "quit") == 0)break;

		int len = strlen(string);

		if (string[0] == ')' || string[len - 1] == '(') {
			printf("Result >> Unmatched\n");
		}
		else {
			int left = 0, right = 0;
			for (int i = 0; i < len; i++) {
				if (string[i] == '(')left++;
				if (string[i] == ')')right++;
			}

			if (left == right)printf("Result >> Matched\n");
			else printf("Result >> Unmatched\n");
		}
	}
	return 0;
}
