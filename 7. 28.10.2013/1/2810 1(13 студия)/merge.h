#pragma once
#include "listArray.h"
#include "listU.h"
#include <stdio.h>
#include <iostream>

using namespace std;

//typedef ListArray ListChosen;
//typedef int PositionChosen;

typedef List ListChosen;
typedef ListElement *PositionChosen;

// Creates List with chosen type
void createSomeList(ListChosen *list, int numberOfElements);
// Sorting list
ListChosen *mergeSort(ListChosen *list);