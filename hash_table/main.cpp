#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv) {

	hashTable hashObj;
	string name = "";

	hashObj.AddItem("Paul", "Locha");
	hashObj.AddItem("Kim", "Iced Mocha");
	hashObj.AddItem("Emma", "Strawberry Smoothy");
	hashObj.AddItem("Annie", "Hot Chocolate");
	hashObj.AddItem("Sarah", "Passion Tea");
	hashObj.AddItem("Pepper", "Caramel Mocha");

	hashObj.PrintTable();

	while (name != "exit") {
		cout << "Remove ";
		cin >> name;
		if (name != "exit") {
			hashObj.RemoveItem(name);
		}
	}

	hashObj.PrintTable();
	return 0;
}