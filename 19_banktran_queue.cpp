#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    string trans[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    // Add transaction
    void enqueue(string t) {
        if (rear == MAX - 1) {
            cout << "Transaction queue full\n";
            return;
        }
        trans[++rear] = t;
    }

    // Process transaction
    void dequeue() {
        if (front > rear) {
            cout << "No transactions to process\n";
            return;
        }
        cout << "Processing: " << trans[front++] << endl;
    }
};

int main() {
    Queue bank;

    // Add transactions
    bank.enqueue("Deposit 500");
    bank.enqueue("Withdraw 200");
    bank.enqueue("Deposit 1000");
    bank.enqueue("Withdraw 300");

    cout << "Bank Transaction Processing:\n";

    // Process transactions
    bank.dequeue();
    bank.dequeue();
    bank.dequeue();
    bank.dequeue();

    return 0;
}
