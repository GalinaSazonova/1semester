#include <stdio.h>
#include <stdlib.h>

void per(int a[11], int l, int r) 
{
	int middle = (r - l) / 2;
	for (int i = 0; i <= middle; ++i) {
		int x = a[l + i];
		a[l + i] = a[r - i];
		a[r - i] = x;
	}
}

 int main()
 { 
	int m = 0;
	printf("Input m ");
	scanf("%d", &m);
	int mas[11];

	for (int i = 0; i < 11; ++i) {
		mas[i] = i + 1;
		printf("%d,  ", mas[i]);
	}
    printf("\n");
    per(mas, 0, m - 1);
	per(mas, m, 10);
	per(mas, 0, 10);

	for (int i = 0; i < 11; ++i) {
		printf("%d,  ", mas[i]);
	}
	return 0; 
 }
	 