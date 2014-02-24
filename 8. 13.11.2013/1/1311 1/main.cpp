/*
	��� ����� ������������� ����� ����� ��������� �� ��������
*/
#include "hash.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string nameOfFile;
	cout << "����������, ������� ��� �����" << endl;
	cin >> nameOfFile;
	ifstream text(nameOfFile);
	if (text)
	{
		HashTable *hashTable = createHashTable();
		int maxSizeOfWord = 0;
		while (!text.eof())
		{
			string word = "";
			text >> word;
			if (word.size() > maxSizeOfWord)
			{
				maxSizeOfWord = word.size();
			}
				insertHashTable(hashTable, word);
		}
		printHashTable(hashTable, maxSizeOfWord + 1);
		deleteHashTable(hashTable);
	}
	else
	{
		cout << "������ ����� �� ����������" << endl;
	}
	return 0;
}