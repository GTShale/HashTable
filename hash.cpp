#include "hash.h"
#include <iostream>
#include <cmath>

using namespace std;

Node::Node(string w) : word(w), next(nullptr) {}

Hash::Hash(int b) : BUCKET(b), total(0) {
	table = new Node*[BUCKET]();
    }

Hash::~Hash() {
    for (int i = 0; i < BUCKET; i++) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

int Hash::hashFunction(string word) {
    int hash = 0;
    for (char c : word) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return (hash % BUCKET + BUCKET) % BUCKET; //make the return non-negative
}

void Hash::insertItem(string word) {
    int index = hashFunction(word);
    Node* newNode = new Node(word);
    newNode->next = table[index];
    table[index] = newNode;
    total++;
}

void Hash::deleteItem(string word) { //just in case
    int index = hashFunction(word);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current) {
        if (current->word == word) {
            if (prev) {
                prev->next = current->next;
            } else {
                table[index] = current->next;
            }
            delete current;
            total--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void Hash::displayHash() {
    for (int i = 0; i < 5 && i < BUCKET; i++) {
        cout << "Slot " << i << ": ";

        Node* current = table[i];
        int count = 0;

        while (current && count < 5) {
            cout << current->word;
            current = current->next;
            count++;

            if (current && count < 5) {
                cout << " ";
            }
        }

        cout << endl;
    }
}

void Hash::displayLength() {

    for (int i = 0; i < BUCKET; i++) {
        int count = 0;
        Node* current = table[i];
        while (current) {
            count++;
            current = current->next;
        }
        cout << "Slot " << i << ": " << count << endl;
    }
}

void Hash::displayPSD() { //PSD (population standard debiation)
    if (BUCKET == 0 || total == 0) {
    cout << "0" << endl;
        return;
    }

    double mean = static_cast<double>(total) / BUCKET;
    double varianceSum = 0.0;

    for (int i = 0; i < BUCKET; ++i) {
        int count = 0;
        Node* current = table[i];
        while (current) {
            count++;
            current = current->next;
        }
        double diff = count - mean;
        varianceSum += diff * diff;
    }

    double variance = varianceSum / BUCKET;
    double psd = sqrt(variance);

    cout << psd << endl;
}
