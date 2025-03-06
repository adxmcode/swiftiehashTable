/*
Hash Function
Name: Adam Cabezas
Your team alias: NotSoHashable
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main() {
    int k;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now
    if (k <= 5) {
        k = 5;
    }

    if (k >= 100) {
        k = 100;
    }

    HashTable table(k);

    for (int i = 0; i < n; i++) {
        table.insert(texts[i]);
    }

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    table.printFirstFiveSlots();

    cout << "==== Printing the slot lengths ====" << endl;
    table.printSlotLengths();

    cout << "==== Printing the standard deviation ====" << endl;
    table.standardDeviation();
    return 0;
}
