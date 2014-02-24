/*  тесты, цифры записаны в порядке ввода:
12
5
16
10
запрос на вывод списка:
5,10,12,16
запрос на удаление элемента 12, и вывод списка: 5,10,16
запос на удаление элемента 5, и вывод списка: 10,16
*/


#include "SortList14.h"
#include <stdio.h>
#include <iostream>

using namespace std;

enum UserCommand
{
	exitEnum,
	add,
	deleteEl,
	print,
};

int main()
{
	SortList *sortlist = create();
	UserCommand dialogNumber = exitEnum;
	cout << "Enter number 0..3 to start a program" << endl;
	scanf("%d", &dialogNumber);
	while (dialogNumber != exitEnum)
	{
		if (dialogNumber == add) 
		{
			int value = 0;
			cout << "Enter value, you want to insert" << endl;
			cin >> value;
			insertGivenElementInSortList(sortlist, value, sizeOfList(sortlist));
		}

		if (dialogNumber == deleteEl) 
		{
			int value = 0;
			cout << "Enter value, you want to delete" << endl;
			cin >> value;
			deleteElementFromSortList(sortlist, value, sizeOfList(sortlist));
		}

		if (dialogNumber == print) 
		{
			cout << "sortList: " << endl;
			printSortList(sortlist);
			cout << endl;
		}
		cout << "enter next command" << endl;
		scanf("%d", &dialogNumber);
	}
	deleteSortList(sortlist);
	return 0;
}