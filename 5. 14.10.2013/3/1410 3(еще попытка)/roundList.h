#pragma once

struct ListElement;
struct List;

List *create();
// ��������� � ��������� �������� ����� ���������
void makeList(List *list, int number); 
// ������� ��������� ������� ����������� �����
int findWinPlace(List *list, int number, int m);  
// ����� ������ �� �����
void printList(List *list, int number);  
// �������� ������ � ������ ������
void deleteListHere(List *list);
// �������� ������
void deleteList(List *list);