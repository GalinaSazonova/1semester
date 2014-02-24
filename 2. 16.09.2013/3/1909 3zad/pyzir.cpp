#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int const mas = 10;
	int a[mas]= {0};
	for (int i = 0; i < mas; ++i) {
		a[i] = rand() % 10;
		printf("%d ,", a[i]);
	}
	printf("\n");
	for (int i = 0; i < mas; ++i) {
		for (int j = 0; j < mas - 1; ++j) {


			if (a[j + 1] > a[j]) {
				int x = a[j + 1];
				a[j + 1] = a[j];
				a[j] = x;
			}
		}
	}
	for (int i = 0; i < mas; ++i) {
		printf("%d ,", a[i]);
	}
	return 0;
}
