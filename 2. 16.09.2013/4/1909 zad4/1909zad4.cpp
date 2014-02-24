#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* проверка прошла  вроде удачно, ниже значения:

1 тест 
4,4,8,5,8,0,6,3,2,2
0,3,2,2,8,4,6,4,8,5

2 тест
9,8,9,7,3,3,4,9,6,9
8,7,3,3,4,6,4,9,9,9*/

int main()
{
	srand(time(0));
	int const mas = 10;
	int a[mas]= {0};	
	for (int i = 0; i < mas; ++i) {
		a[i] = rand() % 100;
		printf("%d ,", a[i]);
	}
	int first = a[0];
	int left = 1;
	int toСhange = 0;
	do { 
		if (a[left] < first) {
			int temp = a[toСhange];
			a[toСhange] = a[left];
			a[left] = temp;
			++toСhange;
		}
		++left;
		} while (left < mas);
	printf("\n");
	for (int i = 0; i < mas; ++i) {
		printf("%d ,", a[i]);
	}
	return 0;
}
