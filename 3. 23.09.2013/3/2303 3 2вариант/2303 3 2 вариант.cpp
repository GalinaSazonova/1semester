#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

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
 
	if (i < right)
	{
		qSort(a, i, right);
	}
	if (j > left)
	{
		qSort(a, left, j);
	}
}

int main()
{
	srand(time(0));
	int const size = 10;
	int mainArray[size] = {0};
	for (int i = 0; i < size; ++i) {
		mainArray[i] = rand() % 10;
		cout<< mainArray[i]<<" ";
	}
	printf("\n");
	qSort(mainArray, 0, size - 1);
	int helpArray[2] = {0};
	int check = 0;
	while (true)
	{
		int count = 0;
		int test = mainArray[check];
		while (mainArray[check] == test)
		{
			++count;
			++check;
		}
		if (count >= helpArray[0])
		{
			helpArray[0] = count;
			helpArray[1] = mainArray[check - 1];
		}
		if (check == size)
		{
			break;
		}
	}
	cout << "Most popular element = ";
	cout << helpArray[1] << endl;
	return 0;
}