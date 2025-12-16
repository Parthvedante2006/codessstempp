#include <iostream>
using namespace std;

#define SIZE 5

// Node for chaining
struct Node {
    int trackingNo;
    string parcelName;
    Node* next;
};

// Hash table array
Node* table[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert parcel
void insertParcel(int trackingNo, string name) {
    int index = hashFunction(trackingNo);

    Node* newNode = new Node();
    newNode->trackingNo = trackingNo;
    newNode->parcelName = name;
    newNode->next = table[index];

    table[index] = newNode;
}

// Search parcel
void searchParcel(int trackingNo) {
    int index = hashFunction(trackingNo);
    Node* temp = table[index];

    while (temp) {
        if (temp->trackingNo == trackingNo) {
            cout << "Parcel Found: " << temp->parcelName << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Parcel not found\n";
}

// Display hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        Node* temp = table[i];
        while (temp) {
            cout << "[" << temp->trackingNo << " - " 
                 << temp->parcelName << "] -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    // Initialize table
    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    insertParcel(101, "Electronics");
    insertParcel(106, "Books");
    insertParcel(111, "Clothes");
    insertParcel(102, "Medicines");

    cout << "\nParcel Table:\n";
    display();

    cout << "\nSearching Parcel 106:\n";
    searchParcel(106);

    return 0;
}
