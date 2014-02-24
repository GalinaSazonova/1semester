/* с ListArray  все работает 
10
15,29,27,5,86,73,49,46,75,57

5,15,27,29,46,49,57,73,75,86

а вот с listU не совсем
постоянно выводится начение -842150451
список сортируется, но откуда это странное значение?!
например, 5
-842150451,28,32,10,1,11
-842150451,1,10,11,28,32 (да, еще это число не 5-м добавилось, а как +число идет)

*/
#include <stdio.h>
#include <iostream>
#include "merge.h"
#include <time.h>

using namespace std;

int main()
{
	srand(time(0));
	int numberOfElements = 0;
	cout << "Please, enter number of elements" << endl;
	cin >> numberOfElements;
	PositionChosen test = NULL;
	ListChosen *list = createList(test);
	createSomeList(list, numberOfElements);
	print(list);
	list = mergeSort(list);
	print(list);
	deleteList(list);
	return 0;
}

