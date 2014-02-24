#pragma once;
#include <string>;

typedef std::string TypeOfWord;

struct HashTable;
// �������� ���-�������
HashTable *createHashTable();
// �������� ���-�������
void deleteHashTable(HashTable *table);
// ������� �������� � �������
void insertHashTable(HashTable *table, TypeOfWord word);
// �������� �������� �� �������
void removeHashElement(HashTable *table, TypeOfWord word);
// �������� �� ��������������
bool existHashElement(HashTable *table, TypeOfWord word);
// ������ �������
void printHashTable(HashTable *table, int maxSizeOfWord);