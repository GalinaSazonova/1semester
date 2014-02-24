#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void testForOwnership(int helpArray[], int left, int right, int value)
{
	if ((right - left) >= 0) 
	{
		if ((helpArray[(right + left) / 2] == value) )
		{
			cout << "True" << endl;
		}
		else
		{
			if (value < helpArray[(right + left) / 2])
			{
				testForOwnership(helpArray, left, (right + left) / 2 - 1, value);
			}
			else
			{
				testForOwnership(helpArray, (right + left) / 2 + 1, right, value);
			}
		}
	}
	else
	{
		cout << "False" << endl;
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
	int n = 0;
	cout << "Enter n" << endl;
	cin >> n;
	int k = 0;
	cout << "Enter k" << endl;
	cin >> k;
	int *mainArray = new int [n];
	for (int i = 0; i < n; i++)
	{
		mainArray[i] = rand() % 1000000001;
		cout << mainArray[i] << " ";
	}
	cout << endl;
	qSort(mainArray, 0, n - 1);
	for (int i = 0; i < k; i++)
	{
		int k = rand() % 1000000001;
		cout << k << " ";
		testForOwnership(mainArray, 0, n-1, k);
	}
	delete[] mainArray;
	return 0;
}
