#pragma once

int const maxNameLength = 50;

struct ListElement;
struct List;
List *createList();

void printList(List *list);

void deleteList(List *list);
// Returns length of list
int numberOfElements(List *list);
// Insert element to  head
void insertToHead(List *list, char name[], int number);
// Insert element by pos
void insert(List *list, int value, char name[], ListElement *position);
// Returns the head of the List
ListElement *head(List *list);
// Returns position after head
ListElement *firstElement(List *list);
// Returns last element of the List
ListElement *end(List *list);
// Returns next element for shown
ListElement *next(List *list, ListElement *position);
// Returns value of phone number by position
int valueOfPhoneOnPosition(List *list, ListElement *position);
// Returns name by position
char *nameByPos(List *list, ListElement *position);
// Returns middle of list
ListElement *middle(List *list);
// Removes element by position
void remove(List *list, ListElement *position);
// Returns previos position
ListElement *previous(List *list, ListElement *position);