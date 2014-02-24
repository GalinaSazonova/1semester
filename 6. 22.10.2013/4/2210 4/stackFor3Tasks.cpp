#include "stackFor3Tasks.h"
#include <iostream>
#include <stdio.h>

using namespace std;

struct StackElement
{
	char value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};

Stack *create()
{
	Stack *result = new Stack;
	result->head = NULL;
	return result;
}


bool empty(Stack *stack)
{
	return stack->head != NULL;
}

void push(Stack *stack, char element)
{
	StackElement *newElem = new StackElement;
	newElem->value = element;
	newElem->next = stack->head;
	stack->head = newElem;
}

void pop(Stack *stack)
{
	Position temp = stack->head;
	stack->head = stack->head->next;
	delete temp;
}

char top(Stack *stack)
{
	return stack->head->value;
}

void deleteStack(Stack *stack)
{
	StackElement *temp = stack->head;
	while (temp != nullptr)
	{
		StackElement *toDelete = temp;
		temp = temp->next;
		delete toDelete;
	}
	delete stack;
}





				

