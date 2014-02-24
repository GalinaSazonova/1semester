#pragma once

struct ListElement;
struct List;

List *create();
// Insert element to head
void insertToHead(List *list, int beg, char let, int end);
// delete list
void deleteList(List *list);
// changes state, if needs
int move(List *list, int state, char c);