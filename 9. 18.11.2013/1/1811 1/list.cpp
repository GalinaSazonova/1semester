#include "list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct ListElement
{
	int cityOut;
	int cityIn;
	int lengh;
	int whichCap1;
	int whichCap2;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *createList()
{
	List *result = new List;
	result->head = nullptr;
	return result;
}

void insertToHead(List *list, int cityOut, int cityIn, int lengh, int cap1, int cap2)
{
	ListElement *newElement = new ListElement;
	newElement->cityOut = cityOut;
	newElement->cityIn = cityIn;
	newElement->lengh = lengh;
	newElement->whichCap1 = cap1;
	newElement->whichCap2 = cap2;
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
		cout << positionTemp->cityOut << " " << positionTemp->cityIn << " " << positionTemp->lengh << " " << positionTemp->whichCap1 << " " << positionTemp->whichCap2 << "; "; 
		positionTemp = positionTemp->next;
	}
	cout << endl;
}

void findAndChange(List *list, int mainCity, int city)
{
	ListElement *temp = list->head;
	while (temp != nullptr)
	{
		if (temp->cityIn == city && temp->whichCap2 == 0)
		{
			temp->whichCap2 = mainCity;
		}
		if (temp->cityOut == city && temp->whichCap1 == 0)
		{
			temp->whichCap1 = mainCity;
		}
		temp = temp->next;
	}
}

void findMin(List *list, int mainCity)
{
	int min = 100;
	int check = 0;
	ListElement *temp = list->head;
	ListElement *chosen = list->head;
	while (temp != nullptr)
	{
		if (temp->cityIn == mainCity)
		{
			temp->whichCap2 = mainCity;
		}
		if (temp->cityOut == mainCity)
		{
			temp->whichCap1 = mainCity;
		}
		if ((temp->lengh < min) && (temp->whichCap1 == mainCity || temp->whichCap2 == mainCity) && (temp->whichCap1 != temp->whichCap2) && (temp->whichCap1 == 0 || temp->whichCap2 == 0))
		{
			min = temp->lengh;
			chosen = temp;
			check++;
		}
		temp = temp->next;
	}
	if (check > 0)
	{
		if (chosen->whichCap1 == 0)
		{
			chosen->whichCap1 = mainCity;
		}
		if (chosen->whichCap2 == 0)
		{
			chosen->whichCap2 = mainCity;
		}
		findAndChange(list, mainCity, chosen->cityIn);
		findAndChange(list, mainCity, chosen->cityOut);
	}
}

void printRight(List *list, int mainCity)
{
	ListElement *positionTemp = list->head;
	while (positionTemp != NULL)
	{
		if ((positionTemp->whichCap1 == positionTemp->whichCap2) && (positionTemp->whichCap1 == mainCity))
		{
			cout << positionTemp->cityOut << "(" << positionTemp->cityIn << ")";
		}
		positionTemp = positionTemp->next;
	}
	cout << endl;
}