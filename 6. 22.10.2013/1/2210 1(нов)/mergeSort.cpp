#include "mergeSort.h"

List *mergeSortForList(List *list, bool check)
{
	if (numberOfElements(list) == 1)
	{
		return list;
	}
	ListElement * test = NULL;
	List *leftHalf = createList();
	List *rightHalf = createList();
	ListElement *positionLeft = head(leftHalf);
	ListElement *positionRight = head(rightHalf);
	for (ListElement *temp = firstElement(list); temp != next(list, middle(list)); temp = next(list, temp))
	{
		insert(leftHalf, valueOfPhoneOnPosition(list, temp), nameByPos(list, temp), positionLeft);
		positionLeft = next(leftHalf, positionLeft);
	}
	for (ListElement *temp = next(list, middle(list)); temp != end(list); temp = next(list, temp))
	{
		insert(rightHalf, valueOfPhoneOnPosition(list, temp), nameByPos(list, temp), positionRight);
		positionRight = next(rightHalf, positionRight);
	}
	leftHalf = mergeSortForList(leftHalf, check);
	rightHalf = mergeSortForList(rightHalf, check);
	List *result = createList();
	ListElement *positionResult = head(result);
	positionLeft = head(leftHalf);
	positionRight = head(rightHalf);
	while (numberOfElements(leftHalf) && numberOfElements(rightHalf) != 0)
	{
		if (((valueOfPhoneOnPosition(leftHalf, firstElement(leftHalf)) <= valueOfPhoneOnPosition(rightHalf, firstElement(rightHalf))) && check) || (!check && (strcmp(nameByPos(list, firstElement(leftHalf)), nameByPos(list, firstElement(rightHalf))) <= 0)))
		{
			insert(result, valueOfPhoneOnPosition(leftHalf, firstElement(leftHalf)), nameByPos(list, firstElement(leftHalf)), positionResult);
			remove(leftHalf, positionLeft);
			positionResult = next(result, positionResult);
		}
		else
		{
			insert(result, valueOfPhoneOnPosition(rightHalf, firstElement(rightHalf)), nameByPos(list, firstElement(rightHalf)), positionResult);
			remove(rightHalf, positionRight);
			positionResult = next(result, positionResult);
		}
	}
	while (numberOfElements(leftHalf) != 0)
	{
		insert(result, valueOfPhoneOnPosition(leftHalf, firstElement(leftHalf)), nameByPos(list, firstElement(leftHalf)), positionResult);
		remove(leftHalf, positionLeft);
		positionResult = next(result, positionResult);
	}
	while (numberOfElements(rightHalf) != 0)
	{
		insert(result, valueOfPhoneOnPosition(rightHalf, firstElement(rightHalf)), nameByPos(list, firstElement(rightHalf)), positionResult);
		remove(rightHalf, positionRight);
		positionResult = next(result, positionResult);
	}
	deleteList(leftHalf);
	deleteList(rightHalf);
	deleteList(list);
	return result;
}