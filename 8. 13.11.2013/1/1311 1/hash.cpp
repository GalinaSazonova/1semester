#include "List.h"
#include "hash.h"
#include <string>
#include <math.h>

const int sizeOfHashTable = 101;

struct HashTable
{
	List *buckets[sizeOfHashTable];
};

HashTable *createHashTable()
{
	HashTable *hashTable = new HashTable;
	for (int i = 0; i != sizeOfHashTable; i++)
	{
		hashTable->buckets[i] = createList();
	}
	return hashTable;
}

int hashFunction(TypeOfWord element)
{
	unsigned long int result = 0;
	int check = 0;
	for (int i = 0; i != element.size(); i++)
	{
		check++;
		result += element[i];
		if (check == 4)
		{
			result *= 73837;
			check = 0;
		}
	}
	return result %= sizeOfHashTable;
}

void insertHashTable(HashTable *table, TypeOfWord word)
{
	insert(table->buckets[hashFunction(word)], word);
}

void removeHashElement(HashTable *table, TypeOfWord word)
{
	remove(table->buckets[hashFunction(word)], returnPos(table->buckets[hashFunction(word)], word));
}

bool existHashElement(HashTable *table, TypeOfWord word)
{
	return existInList(table->buckets[hashFunction(word)], word);
}

void printHashTable(HashTable *table, int maxSizeOfWord)
{
	for (int i = 0; i != sizeOfHashTable; i++)
	{
		printList(table->buckets[i], maxSizeOfWord);
	}
}

void deleteHashTable(HashTable *table)
{
	for (int i = 0; i != sizeOfHashTable; i++)
	{
		deleteList(table->buckets[i]);
	}
	delete table;
}
