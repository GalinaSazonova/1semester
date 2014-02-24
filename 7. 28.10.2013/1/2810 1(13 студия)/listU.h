#pragma once

struct List;
struct ListElement;
typedef int ElementType;

List *createList(ListElement *test);

// Insert element in list by position
void insert(List *list, ElementType value, ListElement *position);
// Insert element into the head of list
void insertToHead(List *list, ElementType value);
// Removes element by position
void remove(List *list, ListElement *position);
// delete List
void deleteList(List *list);
// Print list 
void print(List *list);
// Returns the head of the List
ListElement *head(List *list);
// Returns position after head
ListElement *firstElement(List *list);
// Returns last element of the List
ListElement *end(List *list);
// Returns next element for shown
ListElement *next(List *list, ListElement *position);
// Returns value by position
ElementType valueOnPosition(List *list, ListElement *position);
// Returns length of list
int length(List *list);
// Returns middle of list
ListElement *middle(List *list);
