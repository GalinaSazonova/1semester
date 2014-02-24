#define _CRT_SECURE_NO_WARNINGS
#include "book.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

struct List 
{
	NumberType numbers[100];
	NameType nameInPhonebook[100];
	Position last;
};

List *create()
{
	List *result = new List;
	result->last = -1;
	for (int i = 0; i < 100; i++) 
	{
		result->nameInPhonebook[i] = new char[255];
	}
	return result;
}

void insertToListFromFile(List *list, NameType pearson, NumberType phone)
{
	++list->last;
	list->numbers[list->last] = phone;
	strcpy(list->nameInPhonebook[list->last], pearson);		
}

void insert(List *list, NameType pearson, NumberType phone)
{
	++list->last;
	if (list->last <= 100) 
	{
		list->numbers[list->last] = phone;
		strcpy(list->nameInPhonebook[list->last], pearson);
		FILE *file = fopen("phonebook.txt", "a");
		fprintf(file, "%s %d \n", list->nameInPhonebook[list->last], list->numbers[list->last]);
		fclose(file);
	} else {
		printf("ERROR: NOT ENOGTH PLACE IN PHONEBOOK");
	}
}

NumberType getNumber(List *list, Position i)
{
	return list->numbers[i];
}

NameType getName(List *list, Position i)
{
	return list->nameInPhonebook[i];
}

void deleteList(List *list)
{
	for (int i = 0; i < 100; i++)
	{
		delete list->nameInPhonebook[i];
		delete list->numbers;
	}
	delete list;
}