#include "listU.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct ListElement
{
	ElementType value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *createList(ListElement *test)
{
	List *result = new List;
	result->head = nullptr;
	return result;
}

void insert(List *list, ElementType value, ListElement *position)
{
		ListElement *newElement = new ListElement;
		newElement->value = value;
		newElement->next = position->next;
		position->next = newElement;
}

void insertToHead(List *list, ElementType value)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	newElement->next = list->head;
	list->head = newElement;
}

void remove(List *list, ListElement *position)
{
	if (position->next == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	ListElement *temp = position->next;
	position->next = temp->next;
	delete temp;
}

void deleteList(List *list)
{
	ListElement *position = list->head;
	while (position != NULL)
	{
		ListElement *temp = position;
		position = position->next;
		delete temp;
	}
	delete list;
}

void print(List *list)
{
	ListElement *positionTemp = list->head;
	while (positionTemp != NULL)
	{
		cout << positionTemp->value << ", ";
		positionTemp = positionTemp->next;
	}
	cout << endl;
}

ListElement *head(List *list)
{
	return list->head;
}

ListElement *end(List *list)
{
	return nullptr;
}

ListElement *next(List *list, ListElement *position)
{
	return position->next;
}

ElementType valueOnPosition(List *list, ListElement *position)
{
	return position->value;
}

ListElement *firstElement(List *list)
{
	return list->head->next;
}

int length(List *list)
{
	if (head(list) == 0)
	{
		return 0;
	}
	int count = 0;
	ListElement *temp = head(list);
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

ListElement *middle(List *list)
{
	int middleCount = length(list) / 2 - 1;
	ListElement *temp = head(list);
	while (middleCount > 0)
	{
		middleCount--;
		temp = temp->next;
	}
	return temp;
}

