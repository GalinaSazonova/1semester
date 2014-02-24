#include <stdio.h>
#include <iostream>
#include "qSort.h"
#include <fstream>

using namespace std;

struct Help
{
	int numberOfElement;
	int meanOfElement;
} ;

int main()
{
	ifstream in ("need.txt");
	int const size = 10;
	int mainArray[size] = {0};
	for (int i = 0; i < size; ++i) {
		in >> mainArray[i];
	}
	qSort(mainArray, 0, size - 1);
	Help tryToDo;
	tryToDo.numberOfElement = 0;
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
		if (count >= tryToDo.numberOfElement)
		{
			tryToDo.numberOfElement = count;
			tryToDo.meanOfElement = mainArray[check - 1];
		}
		if (check == size)
		{
			break;
		}
	}
	cout << "Most popular element = ";
	cout << tryToDo.meanOfElement << endl;
	return 0;
}