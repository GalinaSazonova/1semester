#pragma once

struct SortListElement;
struct SortList;
typedef SortListElement *Position;

SortList *create();

// вставка элемента в структуру, если известно только значение
void insertGivenElementInSortList(SortList *sortlist, int value, int check);  

// удаление элемента,  если известно только значение
void deleteElementFromSortList(SortList *sortlist, int value, int check);  

// распечатка значений структуры
void printSortList(SortList *sortlist);

// удаление структуры
void deleteSortList(SortList *sortlist);  

// Возвращает размер списка
int sizeOfList(SortList *sortlist);