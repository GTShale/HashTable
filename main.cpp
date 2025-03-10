#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"

using namespace std;

int main() {

	int k = 0;
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

    Hash h(k);

    for (int i = 0; i < n; i++) {
        h.insertItem(texts[i]);
    }

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    h.displayHash();

    cout << "==== Printing the slot lengths ====" << endl;
    h.displayLength();

    cout << "==== Printing the standard deviation ====" << endl;
    h.displayPSD();

    return 0;
}
