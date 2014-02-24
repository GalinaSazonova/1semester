#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;


struct ListArray;

typedef int TypeOfValue;

// Create a new empty list.
ListArray *createList(int test);
// Delete list
void deleteList(ListArray *list);
// Returns the head of the List
int head(ListArray *list);
// Returns position after head
int firstElement(ListArray *list);
// Returns last element of the List
int end(ListArray *list);
// Returns position of next element
int next(ListArray *list, int position);
// Returns position of middle element.
int middle(ListArray *list);
// Return length of list.
int length(ListArray *list);
// Return position about input value.
int returnPosition(ListArray *list, TypeOfValue value);
// Return value about input position.
TypeOfValue valueOnPosition(ListArray *list, int position);
// Print list
void print(ListArray *list);
// Remove element by position.
void remove(ListArray *list, int position);
// Insert element by position.
void insert(ListArray *list, TypeOfValue value, int position);
