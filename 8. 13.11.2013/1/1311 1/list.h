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

// ������ �������� �������
void swap(int &value1, int &value2);

// ��������� ����� ������ ������
List *createList();
// �������� ������
void deleteList(List *list);

// ���������� ������ ������
Position head(List *list);
// ���������� ��������� ������� ������
Position last(List *list);
// ����������� �������, ��������� �� ������
Position next(List *list, Position position);
// ���������� ��������� �� ������ �������
Position previous(List *list, Position position);
// ���������� ������� �� ��������
Position returnPos(List* list, TypeOfWord word);
// ����� ������
void printList(List *list, int maxSizeOfWord);
// �������� �������� �� ��������� �������
void remove(List*list, Position position);
// ������� ��������� �� �������
void insert(List *list, TypeOfWord value);
// �������� �� ������� ����� � ������
bool existInList(List *list, std::string word);