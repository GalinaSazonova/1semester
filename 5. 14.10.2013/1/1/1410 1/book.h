#pragma once

typedef int NumberType;
typedef char *NameType;
typedef int Position;

struct List;  
List *create();  
// функция, вносящая имя и номер телефона в phonebook
void insert( List *list, NameType pearson, NumberType phoneNumber);  
// возвращает номер по имени
NumberType getNumber(List *list, Position i);
// возвращает имя по номеру
NameType getName(List *list, Position i);  
// функция, которая добавляет в структуру новую запись(телефон, имя), считанную из файла
void insertToListFromFile( List *list, NameType pearson, NumberType phone); 
// удаляет структуру
void deleteList(List *list);