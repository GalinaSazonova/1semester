#include <stdio.h>

int main()
{ 
	int const arraySize = 28;
	int a[arraySize] = {0};
	for (int i = 0; i <= 9; ++i) {
		for (int j = 0; j <= 9; ++j) {
			for (int k = 0; k <= 9; ++k) {
				++a[i + j + k];
			}
		}
	}
	int result = 0;
	for (int i = 0; i < arraySize; ++i) {
		result += a[i] * a[i];
	}
	printf("number of lucky tickets = %d\n", result);
	return 0;
}