#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int a[10]= {0};
	int nul = 0;
	int const mas = 10;

	for (int i = 0; i < mas; ++i) {
		a[i] = rand() % 10;
		printf("%d ,", a[i]);
	}

	for (int i = 0; i < mas; ++i) {
		if (a[i] == 0) {
			++nul;
		}
	}

	printf("the number of zero elements in the array = %d\n", nul);
	return 0;
}
