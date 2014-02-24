#include "list.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

struct ListElement
{
	int phone;
	char name[maxNameLength];
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *createList()
{
	List *result = new List;
	ListElement *element = new ListElement;
	result->head = element;
	element->next = nullptr;
	return result;
};

void insertToHead(List *list, char name[], int number)
{
	ListElement *element = new ListElement;
	element->next = list->head;
	list->head = element;
	list->head->phone = number;
	strcpy_s(list->head->name, name);
}

void printList(List *list)
{
	ListElement *tmp = list->head->next;
	while (tmp != nullptr)
	{
		printf("%s  %d\n", tmp->name, tmp->phone);
		tmp = tmp->next;
	}
	printf("\n");
}

void deleteList(List *list)
{
	ListElement *tmp = list->head;
	ListElement *delValue = tmp;
	while (tmp)
	{
		delValue = tmp;
		tmp = tmp->next;
		delete(delValue);
	}
	delete list;
}

int numberOfElements(List *list)
{
	ListElement *i = list->head->next;
	int count = 0;
	while (i != NULL)
	{
		++count;
		i = i->next;
	}
	return count;
}

void insert(List *list, int value, char name[], ListElement *position)
{
		ListElement *newElement = new ListElement;
		newElement->phone = value;
		strcpy_s(newElement->name, name);
		newElement->next = position->next;
		position->next = newElement;
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

int valueOfPhoneOnPosition(List *list, ListElement *position)
{
	return position->phone;
}

char *nameByPos(List *list, ListElement *position)
{
	return position->name;
}

ListElement *firstElement(List *list)
{
	return list->head->next;
}

ListElement *middle(List *list)
{
	int middleCount = numberOfElements(list) / 2 - 1;
	ListElement *temp = firstElement(list);
	while (middleCount > 0)
	{
		middleCount--;
		temp = temp->next;
	}
	return temp;
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

ListElement *previous(List *list, ListElement *position)
{
	ListElement *temp = head(list);
	while (next(list, temp) != position)
	{
		temp = temp->next;
	}
	return temp;
}


