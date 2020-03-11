#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


hashTable::hashTable() {
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}


void hashTable::AddItem(string name, string drink) {

	int index = Hash(name);

	if (HashTable[index]->name == "empty") {
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {
		item* ptr = HashTable[index];

		item* newItem = new item;
		newItem->name = name;
		newItem->drink = drink;
		newItem->next = NULL;

		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newItem;
	}
}


int hashTable::NumberOfItemsInIndex(int index) {
	int count = 0;
	if (HashTable[index]->name == "empty") {
		return count;
	}
	else {
		count++;
		item* ptr = HashTable[index];
		while (ptr->next != NULL) {
			ptr = ptr->next;
			count++;
		}
		return count;
	}
}


void hashTable::PrintTable() {
	int number;
	for (int i = 0; i < tableSize; i++) {
		number = NumberOfItemsInIndex(i);
		cout << "----------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
	}
}


int hashTable::Hash(string key) {

	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++) {
		hash = (hash + (int)key[i]) * 17;
	}

	index = hash % tableSize;
	return index;

}


void hashTable::FindDrink(string name) {

	int index = Hash(name);
	bool foundName = false;
	string drink;
	item* ptr = HashTable[index];
	while (ptr != NULL) {
		if (ptr->name == name) {
			foundName = true;
			drink = ptr->drink;
		}
		ptr = ptr->next;
	}

	if (foundName == true) {
		cout << "Favorite drink = " << drink << endl;
	}
	else {
		cout << name << "'s information is not found\n";
	}

}


void hashTable::RemoveItem(string name) {

	int index = Hash(name);
	item* delPtr;
	item* p1;
	item* p2;

	// Case 0: bucket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty") {
		cout << name << " is not found in the hash table\n";
	}

	// Case 1: only 1 item is contained in the bucket, and it is the matching one
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL) {
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
		cout << name << " is removed from the hash table\n";
	}

	// Case 2: matching item is the first item in the bucket and there are following
	else if (HashTable[index]->name == name) {
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;
		cout << name << " is removed from the hash table\n";
	}

	// Case 3: bucket contains items but the first one is not the matching one
	else {
		p1 = HashTable[index]->next;
		p2 = HashTable[index];
		while (p1 != NULL && p1->name != name) {
			p2 = p1;
			p1 = p1->next;
		}
		if (p1 == NULL) {
			cout << name << " is not found in the hash table\n";
		}
		else {
			delPtr = p1;
			p1 = p1->next;
			p2->next = p1;
			delete delPtr;
			cout << name << " is removed from the hash table\n";
		}
	}
}