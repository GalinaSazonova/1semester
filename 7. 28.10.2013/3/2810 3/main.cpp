/*
Ура, теперь считает:)
(*(+83)(/52))
22

( * ( + 1 1 ) 2 )
4

(-(+ 5 5)(* 7 1))
3
*/
#include "BinaryTree.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string expression(string fileName)
{
	ifstream text(fileName);
	if (text)
	{
		string line = "";
		string temp = "";
		while (!text.eof())
		{
			text >> temp;
			line += temp;
		}
		return line;
	}
	else
	{
		return "Error";
	}
}

int main()
{
	string fileName = "";
	cout << "Enter the name of file" << endl;
	cin >> fileName;
	int firstReadingElement = 0;
	string testString = expression(fileName);
	if (testString == "Error")
	{
		cout << "File doesn't exist" << endl;
	}
	else
	{
		BinaryTree *tree = createTree();
		tree = createArithmTree(tree, expression(fileName), firstReadingElement);
		cout << "This is an expression, writed in file: ";
		printArithmTree(tree);
		cout << endl;
		bool test = 0;
		int result = countArithmTree(tree, test);
		if (!test)
		{
			cout << "This is the result of counting: " << result << endl;
		}
		else
		{
			cout << "Error" << endl;
		}
		deleteTree(tree);
	}
	return 0;
}