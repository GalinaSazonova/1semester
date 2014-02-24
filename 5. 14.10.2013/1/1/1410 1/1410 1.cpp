/*все работало с теми именами, что в файле, когда просила номер по имени выводило верно, и наоборот, когда по номер имя тоже верно*/
#define _CRT_SECURE_NO_WARNINGS
#include "book.h"
#include "need.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	List *list = create();
	char fileName[100];
	cout << "Enter the name of file" << endl;
	cin >> fileName;
	if (fileName != NULL)
	{
		FILE *file = fopen(fileName, "r");
		int phone = 0;
		char name[100];
		for (int i = 0; i < 100; i++)
			name[i] = '0';
		while (!feof(file))
		{
			fscanf(file, "%s %d\n", &name, &phone);
			insertToListFromFile(list, name, phone);
		}
		fclose(file);
	}
	int dialogNumber = -1;
	cout << "Enter number 0..3 to use a phonebook" << endl;
	cin >> dialogNumber;
	while (dialogNumber != 0)
	{
		if (dialogNumber == 1)
		{
			NameType pearson = new char[100];
			NumberType hisNumber = 0;
			cout << "Enter name of a new pearson " << endl;
			cin >> pearson;
			cout << "Enter number of a new pearson " << endl;
			cin >> hisNumber;
			insert(list, pearson, hisNumber);
			delete []pearson;
		}

		if (dialogNumber == 2) 
		{
			NameType needName = new char[100];
			cout << " Enter name of a pearson, you need " << endl;
			cin >> needName;
			NumberType need = 0;
			need = searchByName(list, needName);
			if (need == 0) 
			{
				cout << " There is no such a name, sorry" << endl;
			} 
			else 
			{
				cout << "number : " << need << " " << endl;
			}
			delete []needName;
		}

		if (dialogNumber == 3)
		{
			NumberType needNumber;
			cout << " Enter number of a pearson, you need" << endl;
			cin >> needNumber;
			NameType need = searchByNumber(list, needNumber);
			if (need == NULL) 
			{
				cout << " There is no such a name, sorry" << endl;
			} 
			else 
			{
				cout << "name : " << need << " " << endl;
			}
		}
		cout << "Enter next command" << endl;
		cin >> dialogNumber;
	}
	deleteList(list);
	return 0;
}