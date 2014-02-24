#include "SortList14.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct SortListElement
{
	int value;
	SortListElement *next;
};

struct SortList
{
	SortListElement *head;
	int size;
};

SortList *create()
{
	SortList *newSortList = new SortList;
	newSortList->head = nullptr;
	newSortList->size = 0;
	return newSortList;
};

void remove(SortList *sortlist, Position position)
{
	if (position->next == NULL) 
	{
		cout << "Error" << endl;
		return;
	}
	Position temp = position->next;
	position->next = temp->next;
	sortlist->size--;
	delete temp;
}

void insertToHead(SortList *sortlist, int value)
{
	SortListElement *newElement = new SortListElement;
	newElement->value = value;
	newElement->next = sortlist->head;
	sortlist->head = newElement;
	sortlist->size++;
}

void insertElement(SortList *sortlist, int value, Position position)
{
	SortListElement *newElement = new SortListElement;
	newElement->value = value;
	newElement->next = position->next;
	position->next = newElement;
	sortlist->size++;
}

void insertGivenElementInSortList(SortList *sortlist, int value, int check) 
{
	if (check == 0) 
	{
		insertToHead(sortlist, value);
	}
	else
	{
		Position positionTemp = sortlist->head;
		Position positionToInsert = sortlist->head;
		while (positionTemp != NULL)
		{
			if (value <= positionTemp->value) 
			{
				positionToInsert = positionTemp;
				break;
			}
			else
			{
				positionToInsert = positionTemp;
			}
			positionTemp = positionTemp->next;
		}
		if (value >= positionToInsert->value)
		{
			if (positionToInsert == sortlist->head)
			{
				insertToHead(sortlist, value);
				int temp = sortlist->head->next->value;
				sortlist->head->next->value = sortlist->head->value;
				sortlist->head->value = temp;
			}
			else
			{
				insertElement(sortlist, value, positionToInsert);
			}
		}
		else
		{
			if (positionToInsert == sortlist->head)
			{
				insertToHead(sortlist, value);
			}
			else
			{
				insertElement(sortlist, value, positionToInsert);
				int temp = positionToInsert->next->value;
				positionToInsert->next->value = positionToInsert->value;
				positionToInsert->value = temp;
			}
		}
	}
}

void removeHead(SortList *sortlist)
{
	Position temp = sortlist->head;
	sortlist->head = temp->next;
	delete temp;
	sortlist->size--;
}

void deleteElementFromSortList(SortList *sortlist, int value, int check)
{
	Position positionTemp = sortlist->head;
	Position positionToDelete = sortlist->head;
	while (positionTemp != NULL)
	{
		if (value == positionTemp->value) 
		{
			positionToDelete = positionTemp;
		}
		positionTemp = positionTemp->next;
	}

	positionTemp = sortlist->head;
	while (positionTemp != NULL)
	{
		if (positionTemp->next == positionToDelete)
		{
			positionToDelete = positionTemp;
			break;
		}
		positionTemp = positionTemp->next;
	}

	if (positionToDelete != NULL && positionToDelete != sortlist->head)
	{
		remove(sortlist, positionToDelete);
	}
	else
	{
		if (positionToDelete == sortlist->head)
		{
			removeHead(sortlist);
		}
		else
		{
			cout << "This element is not exist, or was removed earlier" << endl;
		}
	}
}

void printSortList(SortList *sortlist)
{
	Position positionTemp = sortlist->head;
	while (positionTemp != NULL)
	{
		cout << positionTemp->value << ", ";
		positionTemp = positionTemp->next;
	}
}

void deleteSortList(SortList *sortlist)
{
	SortListElement *tmp = sortlist->head;
	SortListElement *delValue = tmp;
	while (tmp)
	{
		delValue = tmp;
		tmp = tmp->next;
		delete delValue;
	}
	delete sortlist;
}

int sizeOfList(SortList *sortlist)
{
	return sortlist->size;
}