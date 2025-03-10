Arsen Talgat 

main.cpp: 
In main tokenizers starts with reading the file. First input is the number of Buckets, 'k'. 
Then it reads and stores the lines into the array 'texts'(Maximum 500 words, can be changed if needed), after reading all lines tokenizers stops.
Hash Table 'h' is being declared with the number of buckets.
 In the for loop, insertItem is called to insert all words from 'texts' array into Hash Table 'h'. 
At the end, we display the first 5 slots, length of first 5 slots and standard deviation.

hash.cpp:
The constructor initializes with words 'w' from the input and pointer 'next' that is by default nullptr.
The constructor Hash initializes BUCKET with the number of given buckets as an input 'b'. Total is the number of items in the Hash Table that will be useful for PSD calculation. Table is a dynamic array of pointers to Node.
Destructor clears memory used my Hash Table and deletes all arrays of pointers to Node.
Hash Function - uses every character of the word to calculate the key. "<< 5" is used as a better replacement of "* 33", and return hash multiple bucket additions to make the return value non negative.
Insert Item - makes an index for every word, and stores it in the Hash Tabl, be creating a new Node with data(word) and pointer.
Delete Item - could be used to delete Item and fix the affected pointers. 
Display hash - prints first 5 slots of the Hash Table.
Display length - prints the length of the first 5 slots.
Display PSD(Population Standard Deviation) - calculates the standard deviation adjusted prints it.

Hash.h:
Default Node constructor takes string input as a word and stores it as data. Also creates a pointer.
All the elements that were used in hash.cpp are in class hash.