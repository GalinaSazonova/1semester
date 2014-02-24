#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include "mergeSort.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
	FILE *file = fopen("Text.txt", "r");
	List *list = createList();
	int phone = 0;
	char name[maxNameLength];
	for (int i = 0; i < maxNameLength; ++i)
		name[i] = '0';
	if (file != NULL)
	{
		ListElement *temp = head(list);
		while (!feof(file))
		{
			fscanf(file, "%s %d\n", &name, &phone);
			insert(list, phone, name, temp);
			temp = next(list, temp);
		}
		fclose(file);
	}
	printList(list);
	cout << endl;
	bool kindOfSort = false;
	cout << "Enter which kind of sort do you want: 0-by name; 1-by number" << endl;
	cin >> kindOfSort;
	list = mergeSortForList(list, kindOfSort);
	printList(list);
	deleteList(list);
	return 0;
}