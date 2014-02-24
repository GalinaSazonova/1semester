// выводятся дороги, принадлежащие только выбранному государству, общие дороги не в счет
#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int const maxArr = 10;
	List *roads = createList();
	FILE *file = fopen("Text.txt", "r");
	int n = 0;
	int m = 0;
	fscanf(file, "%d %d\n", &n, &m);
	int i = 0;
	int j = 0;
	int len = 0;
	for (int l = 0; l < m; l++)
	{
		fscanf(file, "%d %d %d\n", &i, &j, &len);
		insertToHead(roads, i, j, len, 0, 0);
	}
	int k = 0;
	fscanf(file, "%d\n", &k);
	int masOfCapCityNames[maxArr];
	for (int l = 0; l < k; l++)
	{
		masOfCapCityNames[l] = 0;
	}
	for (int l = 0; l < k; l++)
	{
		fscanf(file, "%d\n", &masOfCapCityNames[l]);
	}
	fclose(file);
	int forWhile = n - k;
	while (forWhile != 0)
	{
		for (int l = 0; l < k; l++)
		{
			findMin(roads, masOfCapCityNames[l]);
		}
		forWhile--;
	}
	for (int l = 0; l < k; l++)
	{
		cout << "Country #" << l << endl;
		cout << "Capital is " << masOfCapCityNames[l] << endl;
		printRight(roads, masOfCapCityNames[l]);
	}
	print(roads);
	deleteList(roads);
	return 0;
}