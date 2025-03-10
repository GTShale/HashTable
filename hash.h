#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string w);
};

class Hash {
private:
    int total;
    int BUCKET;
    Node** table;

    int hashFunction(string word);

public:
    Hash(int b);
    ~Hash();

    void insertItem(string word);
    void deleteItem(string word);
    void displayHash();
    void displayLength();
    void displayPSD();
};

#endif
