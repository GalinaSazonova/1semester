#pragma once

struct List;
struct ListElement;

List *createList();

// Insert element into the head of list
void insertToHead(List *list, int cityOut, int cityIn, int lengh, int cap1, int cap2);
// Removes element by position
void remove(List *list, ListElement *position);
// delete List
void deleteList(List *list);
// Print list 
void print(List *list);
// finds the best city to join country
void findMin(List *list, int mainCity);
// print cities, in a way 6(9), where 6 is a city out, 9 is city in, both are in given country
void printRight(List *list, int mainCity);
