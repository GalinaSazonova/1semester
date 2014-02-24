#include "qSort.h"

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
