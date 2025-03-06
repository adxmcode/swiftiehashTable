#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "hash.h"

using namespace std;

HashTable::HashTable(int size) {
	tableSize = size;
	table = new Node* [tableSize];

	for (int i = 0; i < tableSize; i++) {
		table[i] = nullptr;
	}
}

HashTable::~HashTable() {
	for (int i = 0; i < tableSize; i++) {
		Node* current = table[i];
		while (current != nullptr) {
			Node* deletingNode = current;
			current = current->next;
			delete deletingNode;
		}
		table[i] = nullptr;
	}
	delete[] table;
}

/*Functions below*/
int HashTable::hash_function(const string& word) {
	unsigned long hashValue = 5312;
	for (char c : word) {
		hashValue = ((hashValue << 5) + hashValue) + c;
	}
	return hashValue % tableSize;
}

void HashTable::insert(const string& word) {
	int index = hash_function(word);

	Node* newNode = new Node(word);
	newNode->next = table[index];
	table[index] = newNode;
}

void HashTable::printFirstFiveSlots() {
	for (int i = 0; i < 5; i++) {
		cout << "Slot " << i << ": ";
		Node* current = table[i];

	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
		}
	  cout << endl;
  }
}


void HashTable::printSlotLengths() {
	for (int i = 0; i < tableSize; i++) {
		int length = 0;
		Node* current = table[i];
		while (current != nullptr) {
			length++;
			current = current->next;
		}
		cout << "Slot " << i << ": " << length << endl;
	}
}

void HashTable::standardDeviation() {
	int sum = 0;
	int count = 0;
	float mean = 0.0;
	float variance = 0.0;

	for (int i = 0; i < tableSize; i++) {
		int length = 0;
		Node* current = table[i];
		while (current != nullptr) {
			length++;
			current = current->next;
		}
		sum += length;
		if (length > 0) {
			count++;
		}
	}

	if (count == 0) {
		cout << "0.0" << endl;
	}

	mean = static_cast<float>(sum) / count;

	for (int i = 0; i < tableSize; i++) {
		int length = 0;
		Node* current = table[i];
		while (current != nullptr) {
			length++;
			current = current->next;
		}
		if (length > 0) {
			variance += (length - mean) * (length - mean);
		}
	}

	float stdDev = sqrt(variance / count);
	cout << fixed << setprecision(4) << stdDev << endl;
}