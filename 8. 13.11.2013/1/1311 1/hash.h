#pragma once;
#include <string>;

typedef std::string TypeOfWord;

struct HashTable;
// Создание хэш-таблицы
HashTable *createHashTable();
// Удаление хэш-таблицы
void deleteHashTable(HashTable *table);
// Вставка элемента в таблицу
void insertHashTable(HashTable *table, TypeOfWord word);
// Удаление элемента из таблицы
void removeHashElement(HashTable *table, TypeOfWord word);
// Проверка на принадлежность
bool existHashElement(HashTable *table, TypeOfWord word);
// Печать таблицы
void printHashTable(HashTable *table, int maxSizeOfWord);