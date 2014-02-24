#include <stdio.h>
#include <iostream>

int main()
{
	int balance = 0;
	bool check = 0;
	char line[255] = {0};
	printf("Input line ");
	scanf_s("%s", line, 255);

	for (int i = 0; line[i] != 0; ++i) {
		if (line[i] == '(') {
			++balance;
		}
		if (line[i] == ')') {
			--balance;
		}
		if (balance < 0) {
			check = 1;
			break;
		}
	}
	if (check == 1) {
		printf("No balance");
	} 
	else { 
		printf("Everything is alright:)");
	}
	printf("%d, %d", check, balance);
	return 0;
}
