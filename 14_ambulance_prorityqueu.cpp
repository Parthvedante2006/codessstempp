#include <iostream>
using namespace std;

#define MAX 10

// Structure for emergency case
struct Case {
    string name;
    int priority;
};

// Priority Queue
class PriorityQueue {
    Case pq[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Add a case
    void insert(string name, int priority) {
        pq[size].name = name;
        pq[size].priority = priority;
        size++;
    }

    // Remove highest priority case
    void dispatch() {
        if (size == 0) {
            cout << "No emergency cases\n";
            return;
        }

        int maxIndex = 0;

        // Find highest priority
        for (int i = 1; i < size; i++) {
            if (pq[i].priority > pq[maxIndex].priority)
                maxIndex = i;
        }

        cout << "Ambulance dispatched to: "
             << pq[maxIndex].name
             << " (Priority " << pq[maxIndex].priority << ")\n";

        // Shift elements
        for (int i = maxIndex; i < size - 1; i++)
            pq[i] = pq[i + 1];

        size--;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert("Accident Case", 5);
    pq.insert("Heart Attack", 10);
    pq.insert("Fracture", 3);

    pq.dispatch();
    pq.dispatch();
    pq.dispatch();

    return 0;
}
