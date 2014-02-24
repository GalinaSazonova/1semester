#include "listArray.h"

struct ListArray
{
	TypeOfValue *array;
	int last;
	int sizeOfArray;
};

ListArray *createList(int test)
{
	ListArray *list = new ListArray;
	list->array = new TypeOfValue[100];
	list->sizeOfArray = 100;
	list->last = -1;
	return list;
}

int head(ListArray *list)
{
	return 0;
}

int firstElement(ListArray *list)
{
	return 0;
}

int end(ListArray *list)
{
	return list->last + 1;
}

int next(ListArray *list, int position)
{
	return position + 1;
}

void insert(ListArray *list, TypeOfValue element, int position)
{
	if (list->last < list->sizeOfArray - 1)
	{
		for (int temp = end(list); temp != position; temp--)
		{
			list->array[temp] = list->array[temp + 1];
		}
		list->array[position] = element;
		list->last++;
	}
	else
	{
		TypeOfValue *newArray = new TypeOfValue[list->sizeOfArray * 2];
		for (int temp = 0; temp != end(list); temp++)
		{
			newArray[temp] = list->array[temp];
		}
		TypeOfValue *ptr = list->array;
		list->array = newArray;
		list->sizeOfArray = list->sizeOfArray * 2;
		for (int temp = end(list); temp != position; temp--)
		{
			list->array[temp] = list->array[temp + 1];
		}
		list->array[position] = element;
		list->last++;
		delete ptr;
	}
}


void remove(ListArray *list, int position)
{
	for (int temp = position; temp != end(list); temp++)
	{
		list->array[temp] = list->array[temp + 1];
	}
	list->last--;
}

int middle(ListArray *list)
{
	return list->last / 2;
}

int length(ListArray *list)
{
	return list->last + 1;
}

int returnPosition(ListArray *list, TypeOfValue value)
{
	for (int temp = 0; temp != end(list); temp++)
	{
		if (list->array[temp] == value)
		{
			return temp;
		}
	}
	return NULL;
}

TypeOfValue valueOnPosition(ListArray *list, int position)
{
	return list->array[position];
}

void print(ListArray *list)
{
	for (int temp = 0; temp != end(list); temp++)
	{
		cout << list->array[temp] << " ";
	}
	cout <<  endl;
}

void deleteList(ListArray *list)
{
	delete list->array;
	delete list;
}

