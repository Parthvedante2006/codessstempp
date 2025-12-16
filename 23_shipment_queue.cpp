#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    string q[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    // Insert parcel
    void enqueue(string parcel) {
        if (rear == MAX - 1) {
            cout << "Queue is full\n";
            return;
        }
        q[++rear] = parcel;
        cout << parcel << " entered the system\n";
    }

    // Process parcel
    void dequeue() {
        if (front > rear) {
            cout << "No parcels to process\n";
            return;
        }
        cout << "Processing parcel: " << q[front++] << endl;
    }

    // Display queue
    void display() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Current Queue: ";
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue shipment;

    // Enter parcels
    shipment.enqueue("P100");
    shipment.enqueue("P102");
    shipment.enqueue("P105");
    shipment.enqueue("P110");

    cout << endl;
    shipment.display();

    cout << endl;
    shipment.dequeue();
    shipment.dequeue();

    cout << endl;
    shipment.display();

    return 0;
}
