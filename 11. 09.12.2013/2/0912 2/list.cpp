#include "list.h"

struct ListElement
{
	int beginS;
	char letter;
	int endS;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List *create()
{
	List *result = new List;
	result->head = nullptr;
	return result;
}

void insertToHead(List *list, int beg, char let, int end)
{
	ListElement *newElement = new ListElement;
	newElement->beginS = beg;
	newElement->letter = let;
	newElement->endS = end;
	newElement->next = list->head;
	list->head = newElement;
}

void deleteList(List *list)
{
	ListElement *position = list->head;
	while (position != nullptr)
	{
		ListElement *temp = position;
		position = position->next;
		delete temp;
	}
	delete list;
}

int move(List *list, int state, char c)
{
	ListElement *temp = list->head;
	while (temp != nullptr)
	{
		if (state == temp->beginS && c == temp->letter)
		{

			state = temp->endS;
			return state;
		}
		else
		{
			if (temp->letter == 'A' && state == temp->beginS && c != '/' && c != '*')
			{
				state = temp->endS;
				return state;
			}
		}
		temp = temp->next;
	}
	return state;
}