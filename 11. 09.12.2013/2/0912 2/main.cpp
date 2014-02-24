#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	List *list = create();
	ifstream in("table.txt");
	int newState = 0;
	int tempState = 0;
	char tempC;
	while (!in.eof())
	{
		in >> tempState;
		in >> tempC;
		in >> newState;
		insertToHead(list, tempState, tempC, newState);
	}
	in.close();
	ifstream use("Text.txt");
	char strToKeep[256];
	char *tmp = new char[50];
	char *str = tmp;
	int state = 0;
	char c = 0;
	int i = 0;
	int check = 1;
	while (!use.eof())
	{
		use.getline(str, 40);
		check = 1;
		while (c != '\0' || check == 1)
		{
			check = 0;
			c = str[0];
			str++;
			state = move(list, state, c);
			if (state == 2 || state == 3)
			{
				strToKeep[i]= c;
				i++;
			}
			else
			{
				if (state == 0)
				{
					strToKeep[0] = '\0';
					i = 0;
				}
				else
				{
					if (state == 4)
					{
						strToKeep[i] = c;
						cout << "/";
						for (int j = 0; j < i + 1; j++)
						{
							cout << strToKeep[j];
						}
						cout << endl;
						strToKeep[0] = '\0';
						i = 0;
						state = 0;
					}
				}
			}
		}
	}
	delete[]tmp;
	deleteList(list);
	use.close();
	return 0;
}