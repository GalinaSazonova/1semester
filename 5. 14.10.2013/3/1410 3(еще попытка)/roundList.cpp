#include "roundList.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};
struct List
{
	ListElement *head;
};

List *create()
{
	List *newList = new List;
	ListElement *element = new ListElement;
	newList->head = element;
	return newList;
}

void makeList(List *list, int number)
{
	ListElement *tempor = list->head;
	for (int i = 1; i <= number; ++i)
	{
		ListElement *addElement = new ListElement;
		addElement->value = i;
		tempor->next = addElement;
		tempor = addElement;
	}
	tempor->next = list->head->next;
}

int findWinPlace(List *list, int number, int step)
{
	int result = 0;
	ListElement *tempor = list->head;
	ListElement *beforeTempor = list->head;
	for (int i = 1; i < number; ++i)
	{
		for (int j = 1; j < step; ++j)
		{	
			beforeTempor = tempor;
			tempor = tempor->next;
		}
		ListElement *delValue = tempor->next;
		tempor->next = tempor->next->next;
		delete delValue;
	}
	if (step == 1)
	{
		result = list->head->next->value;
		delete list->head->next;
		list->head->next = nullptr;
	}
	else
	{
		result = tempor->value;
		delete tempor;
		beforeTempor->next = nullptr;
		list->head->next = nullptr;
	}
	return result;
}

void deleteListHere(List *list)
{
	delete list->head;
	delete list;
}

void printList(List *list, int number)
{
	ListElement *tempor = list->head->next;
	for (int i = 1; i <= number; ++i)
	{
		cout << tempor->value << "  ";
		tempor = tempor->next;
	}
	printf("\n");
}

void deleteList(List *list)
{
	ListElement *tmp = list->head;
	ListElement *delValue = tmp;
	while (tmp->next != list->head && list->head->next != nullptr)
	{
		delValue = tmp;
		tmp = tmp->next;
		delete delValue;
	}
	delete tmp;
	delete list;
}
