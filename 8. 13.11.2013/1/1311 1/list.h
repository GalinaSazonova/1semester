#pragma once;
#include <stdio.h>
#include <iostream>

struct ElementOfList;
struct List;

struct TypeOfElement
{
	int countOfWord;
	std::string word;
};

typedef ElementOfList *Position;
typedef TypeOfElement *TypeOfValue;
typedef std::string TypeOfWord;

// Меняет элементы местами
void swap(int &value1, int &value2);

// Создается новый пустой список
List *createList();
// Удаление списка
void deleteList(List *list);

// Возвращает голову списка
Position head(List *list);
// Возвращает последний элемент списка
Position last(List *list);
// Возврращает элемент, следующее за данным
Position next(List *list, Position position);
// Возвращает следубщий за данным элемент
Position previous(List *list, Position position);
// Возвращает позицию по значению
Position returnPos(List* list, TypeOfWord word);
// Вывод списка
void printList(List *list, int maxSizeOfWord);
// Удаление элемента по введенной позиции
void remove(List*list, Position position);
// Вставка эелемента по позиции
void insert(List *list, TypeOfWord value);
// Проверка на наличие слова в списке
bool existInList(List *list, std::string word);