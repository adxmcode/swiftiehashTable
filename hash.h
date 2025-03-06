#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

class Node {
public:
	string data;
	Node* next;

	Node(const string& value) : data(value), next(nullptr) {}
};

class HashTable {
private:
	int tableSize;
	Node** table;

public:
	HashTable(int size);
	~HashTable();
	
	int hash_function(const string& word);
	void insert(const string& word);
	void printFirstFiveSlots();
	void printSlotLengths();
	void standardDeviation();
};

#endif