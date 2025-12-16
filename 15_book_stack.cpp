#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    string books[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push book into bin
    void push(string book) {
        if (top == MAX - 1) {
            cout << "Return bin is full\n";
            return;
        }
        books[++top] = book;
        cout << book << " returned\n";
    }

    // Pop book for processing
    void pop() {
        if (top == -1) {
            cout << "No books to process\n";
            return;
        }
        cout << "Processing book: " << books[top--] << endl;
    }
};

int main() {
    Stack bin;

    bin.push("DS Book");
    bin.push("OS Book");
    bin.push("DBMS Book");

    bin.pop();
    bin.pop();
    bin.pop();

    return 0;
}

