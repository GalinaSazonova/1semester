#pragma once

typedef int NumberType;
typedef char *NameType;
typedef int Position;

struct List;  
List *create();  
// �������, �������� ��� � ����� �������� � phonebook
void insert( List *list, NameType pearson, NumberType phoneNumber);  
// ���������� ����� �� �����
NumberType getNumber(List *list, Position i);
// ���������� ��� �� ������
NameType getName(List *list, Position i);  
// �������, ������� ��������� � ��������� ����� ������(�������, ���), ��������� �� �����
void insertToListFromFile( List *list, NameType pearson, NumberType phone); 
// ������� ���������
void deleteList(List *list);