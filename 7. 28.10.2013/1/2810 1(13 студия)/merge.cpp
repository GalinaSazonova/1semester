#include "merge.h"

void createSomeList(ListChosen *list, int numberOfElements)
{
	PositionChosen temp = head(list);
	for (int i = numberOfElements; i > 0; i--)
	{
		insert(list, rand() % 100, temp);
		temp = next(list, temp);
	}
}

ListChosen *mergeSort(ListChosen *list)
{
	if (length(list) == 1)
	{
		return list;
	}
	PositionChosen test = NULL;
	ListChosen *leftHalf = createList(test);
	ListChosen *rightHalf = createList(test);
	PositionChosen positionLeft = head(leftHalf);
	PositionChosen positionRight = head(rightHalf);
	for (PositionChosen temp = head(list); temp != next(list, middle(list)); temp = next(list, temp))
	{
		insert(leftHalf, valueOnPosition(list, temp), positionLeft);
		positionLeft = next(leftHalf, positionLeft);
	}
	for (PositionChosen temp = next(list, middle(list)); temp != end(list); temp = next(list, temp))
	{
		insert(rightHalf, valueOnPosition(list, temp), positionRight);
		positionRight = next(rightHalf, positionRight);
	}
	leftHalf = mergeSort(leftHalf);
	rightHalf = mergeSort(rightHalf);
	ListChosen *result = createList(test);
	PositionChosen positionResult = head(result);
	positionLeft = head(leftHalf);
	positionRight = head(rightHalf);
	while (length(leftHalf) && length(rightHalf) != 0)
	{
		if (valueOnPosition(leftHalf, head(leftHalf)) <= valueOnPosition(rightHalf, head(rightHalf)))
		{
			insert(result, valueOnPosition(leftHalf, head(leftHalf)), positionResult);
			remove(leftHalf, positionLeft);
			positionResult = next(result, positionResult);
		}
		else
		{
			insert(result, valueOnPosition(rightHalf, head(rightHalf)), positionResult);
			remove(rightHalf, positionRight);
			positionResult = next(result, positionResult);
		}
	}
	while (length(leftHalf) != 0)
	{
		insert(result, valueOnPosition(leftHalf, head(leftHalf)), positionResult);
		remove(leftHalf, positionLeft);
		positionResult = next(result, positionResult);
	}
	while (length(rightHalf) != 0)
	{
		insert(result, valueOnPosition(rightHalf, head(rightHalf)), positionResult);
		remove(rightHalf, positionRight);
		positionResult = next(result, positionResult);
	}
	deleteList(leftHalf);
	deleteList(rightHalf);
	deleteList(list);
	return result;
}