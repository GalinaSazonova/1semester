
/* проверка 1
9869338391
3
проверка 2
238941098
0
проверка 3
1770269882
2*/
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

void findMax(int a[], int maxf, int arraySize, int maxfi) {
	maxf = a[0];
	for (int i = 1; i < arraySize; ++i) {
		if (a[i] > maxf) {
			maxf = a[i];
			maxfi = i;
		}
	}
}
int main()
{
	srand(time(0));
	int const size = 10;
	int mainArray[size] = {0};
	int max = 0;
	int maxi = 0;
	for (int i = 0; i < size; ++i) {
		mainArray[i] = rand() % 10;
		cout<< mainArray[i]<<" ";
	}
	printf("\n");
	int const helpArraySize = 10;
	int helpArray[helpArraySize] = {0};
	for (int i = 0; i < size; ++i) {
		++helpArray[mainArray[i]];
	}
	for (int i = 0; i < helpArraySize; ++i) {
		if (helpArray[i] > max) {
			max = helpArray[i];
			maxi = i;
		}
	}
	cout<< "Most popular element = ";
	cout<< maxi <<endl;
	return 0;
}