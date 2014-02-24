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

	int const range = 10;
	int b[range] = {0};
	for (int i = 0; i < range; ++i) {
			++b[a[i]];
	}
	int check = -1;
	for (int i = 0; i < range; ++i) {
		if (b[i] != 0) {
			do { 
				++check;
				--b[i];
				a[check] = i;
				printf("%d ,",i);				
			}
				while (b[i] != 0);
		}
	}
	printf("\n");
	/*for (int i = 0; i < mas; ++i) {
		printf("%d ,", a[i]);
	}
	printf("\n");*/
	return 0;
}
