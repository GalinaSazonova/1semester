#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

void insert(int a[], int first, int last)
{
	for (int i = first + 1; i < last; ++i)
	{
		for (int j = i; j > 0 && a[j - 1] > a[j]; --j)
		{
			int temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
		}
	}
}


void qSort(int a[], int left, int right)
{
    int i = left;
	int j = right;

	int neutral = 0;
	int temporary = 1;
	while (temporary)
	{
		if (a[left] > a[left + 1])
		{
			neutral = a[left];
			temporary = 0;
		}
		else if (a[left] < a[left + 1])
		{
			neutral = a[left + 1];
			temporary = 0;
		}
		else
			++left;
	}
 
    do 
	{
        while (a[i] < neutral) ++i;
        while (a[j] > neutral) --j;
 
        if(i <= j) 
		{
			int temp = 0;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
            ++i;
            --j;
        }
    } while (i <= j);
 
    if (i < right && (right - i) > 10)
        qSort(a, i, right);
	else if ((right - i) <= 10)
		insert(a, i, right + 1);
    if (left < j && (j - left) > 10)
        qSort(a, left,j);
	else if ((j - left) <= 10)
		insert(a, left, j + 1);
}


int main()
{
	srand(time(0));
	int const mas = 100;
	int mainArray[mas]= {0};
	for (int i = 0; i < mas; ++i) {
		mainArray[i] = rand() % 10;
		cout<< mainArray[i]<<" ";
	}
	printf("\n");
	qSort(mainArray, 0, mas-1);
	for(int i = 0; i < mas; i++)
	{
		cout<<mainArray[i];
	}        
	return 0;
}
