#pragma once
#include "list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

// Sorting list
// if check = false - sort by name
// if check = true - sort by number
List *mergeSortForList(List *list, bool check);
