#include <iostream>
#include <string>
using namespace std;

#define MAX 10

// Stack implementation
class Stack {
    string arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(string page) {
        if (top < MAX - 1)
            arr[++top] = page;
    }

    string pop() {
        if (top >= 0)
            return arr[top--];
        return "";
    }

    bool empty() {
        return top == -1;
    }
};

int main() {
    Stack backStack, forwardStack;
    string currentPage = "Home";

    cout << "Current Page: " << currentPage << endl;

    // Visit pages
    backStack.push(currentPage);
    currentPage = "Google";

    backStack.push(currentPage);
    currentPage = "YouTube";

    cout << "Current Page: " << currentPage << endl;

    // Back operation
    if (!backStack.empty()) {
        forwardStack.push(currentPage);
        currentPage = backStack.pop();
    }
    cout << "After Back: " << currentPage << endl;

    // Forward operation
    if (!forwardStack.empty()) {
        backStack.push(currentPage);
        currentPage = forwardStack.pop();
    }
    cout << "After Forward: " << currentPage << endl;

    return 0;
}
