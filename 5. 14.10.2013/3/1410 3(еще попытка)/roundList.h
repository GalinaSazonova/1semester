#pragma once

struct ListElement;
struct List;

List *create();
// Добавляем в структуру заданное число элементов
void makeList(List *list, int number); 
// Находим начальную позицию победившего воина
int findWinPlace(List *list, int number, int m);  
// Вывод списка на экран
void printList(List *list, int number);  
// Удаление списка в данной задаче
void deleteListHere(List *list);
// Удаление списка
void deleteList(List *list);