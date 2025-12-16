#include <iostream>
using namespace std;

#define MAX 50

class Stack {
    char s[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        s[++top] = c;
    }

    char pop() {
        return s[top--];
    }

    bool empty() {
        return top == -1;
    }
};

bool isBalanced(string expr) {
    Stack st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // Closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty())
                return false;

            char top = st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }

    return st.empty();
}

int main() {
    string expr = "{(a+b)*[c-d]}";

    if (isBalanced(expr))
        cout << "Expression is VALID\n";
    else
        cout << "Expression is INVALID\n";

    return 0;
}
