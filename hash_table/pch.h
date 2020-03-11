#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


#ifndef PCH_H
#define PCH_H

class hashTable {

private:
	static const int tableSize = 4;
	struct item {
		string name;
		string drink;
		item* next;
	};
	item* HashTable[tableSize];

public:
	hashTable();
	int Hash(string key);
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void FindDrink(string name);
	void RemoveItem(string name);
};

#endif
