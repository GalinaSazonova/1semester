#pragma once
#include "book.h"
// Поиск телефона по имени
NumberType searchByName (List *list, NameType pearson);
// Поиск имени по номеру телефона
NameType searchByNumber (List *list, NumberType number);