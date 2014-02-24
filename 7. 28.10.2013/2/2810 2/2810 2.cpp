#define _CRT_SECURE_NO_WARNINGS
#include "binaryTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;

enum UserCommand
{
	exitEnum,
	add,
	deleteEl,
	checkIfHere,
	printIncrease,
	printDecrease,
};

int main()
{
	BinaryTree *tree = createTree();
	UserCommand dialogNumber;
	cout << "Please enter a command\n 0-exit\n 1-add value\n 2-delete value\n 3-findout if element is in the tree\n 4-print tree (increase)\n 5-print tree (decrese)\n" << endl;
	scanf("%d", &dialogNumber);
	while (dialogNumber != exitEnum)
	{
		if (dialogNumber == add) 
		{
			int value = 0;
			cout << "Enter value, you want to insert" << endl;
			cin >> value;
			tree = addValue(tree, value);
		}

		if (dialogNumber == deleteEl) 
		{
			int value = 0;
			cout << "Enter value, you want to delete" << endl;
			cin >> value;
			tree = removeValue(tree, value);
		}

		if (dialogNumber == checkIfHere) 
		{
			int value = 0;
			cout << "Enter element you want to find" << endl;
			cin >> value;
			//bool check = exist(tree, value);
			if (exist(tree, value))
			{
				cout << "is in the tree" << endl;
			}
			else
			{
				cout << "is not in the tree" << endl;
			}
		}

		if (dialogNumber == printIncrease)
		{
			cout << "Tree (increase): \n";
			fprintIncrease(tree);
			cout << "\n";
		}

		if (dialogNumber == printDecrease)
		{
			cout << "Tree (decrease): \n";
			fprintDecrease(tree);
			cout << "\n";
		}
		cout << "Please, enter next command" << endl;
		scanf("%d", &dialogNumber);
	}
	deleteTree(tree);
	return 0;
}