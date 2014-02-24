#include "need.h"
#include <fstream>


NumberType searchByName (List *list, NameType pearson)
{
	for (Position i = 0; i < 100; i++)
	{
		if (strcmp(pearson, getName(list, i)) == 0)
		{
			return getNumber(list,i);
		}
	}
	return 0;
}

NameType searchByNumber (List *list, NumberType number)
{
	for (Position i = 0; i < 100; i++)
	{
		if (number == getNumber(list, i))
		{
			return getName(list,i);
		}
	}
	return NULL;
}