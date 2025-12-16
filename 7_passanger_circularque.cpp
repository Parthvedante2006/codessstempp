#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    string q[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Passenger enters queue
    void enqueue(string name) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue is full\n";
            return;
        }

        if (front == -1)  // first passenger
            front = 0;

        rear = (rear + 1) % MAX;
        q[rear] = name;
        cout << name << " entered the queue\n";
    }

    // Passenger boards bus
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << q[front] << " boarded the bus\n";

        if (front == rear) {  // last passenger
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Display queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Current Queue: ";
        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue bus;

    bus.enqueue("Passenger A");
    bus.enqueue("Passenger B");
    bus.enqueue("Passenger C");

    bus.display();

    bus.dequeue();
    bus.dequeue();

    bus.enqueue("Passenger D");
    bus.enqueue("Passenger E");

    bus.display();

    return 0;
}
