#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "roundList.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter number of people ";
	int numb = 0;
	cin >> numb;
	cout << " Enter step ";
	int step = 0;
	cin >> step;
	List *list = create();
	makeList(list, numb);
	printList(list, numb);
	printf("\n");
	printf("Win Warrior Position: %d", findWinPlace(list, numb, step));
	deleteList(list);
	return 0;
}
