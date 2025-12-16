#include <iostream>
using namespace std;

#define SIZE 10   // hash table size

int hashTable[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert using linear probing
void insert(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            cout << "Duplicate SKU: " << key << endl;
            return;
        }
        index = (index + 1) % SIZE;   // linear probing
    }

    hashTable[index] = key;
}

// Search SKU
void search(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            cout << "SKU " << key << " found at index " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }

    cout << "SKU " << key << " not found\n";
}

int main() {
    int n, sku;

    init();

    cout << "Enter number of products: ";
    cin >> n;

    cout << "Enter SKUs:\n";
    for (int i = 0; i < n; i++) {
        cin >> sku;
        insert(sku);
    }

    cout << "Search SKU: ";
    cin >> sku;
    search(sku);

    return 0;
}
