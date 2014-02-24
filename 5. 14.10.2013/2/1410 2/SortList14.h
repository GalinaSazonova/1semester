#pragma once

struct SortListElement;
struct SortList;
typedef SortListElement *Position;

SortList *create();

// ������� �������� � ���������, ���� �������� ������ ��������
void insertGivenElementInSortList(SortList *sortlist, int value, int check);  

// �������� ��������,  ���� �������� ������ ��������
void deleteElementFromSortList(SortList *sortlist, int value, int check);  

// ���������� �������� ���������
void printSortList(SortList *sortlist);

// �������� ���������
void deleteSortList(SortList *sortlist);  

// ���������� ������ ������
int sizeOfList(SortList *sortlist);