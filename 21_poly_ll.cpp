#include <iostream>
using namespace std;

// Node structure
struct Node {
    int coeff;
    int power;
    Node* next;
};

// Create node
Node* createNode(int c, int p) {
    Node* temp = new Node();
    temp->coeff = c;
    temp->power = p;
    temp->next = NULL;
    return temp;
}

// Insert term in sorted order
void insertTerm(Node*& head, int c, int p) {
    Node* newNode = createNode(c, p);

    if (head == NULL || head->power < p) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    while (curr && curr->power > p) {
        prev = curr;
        curr = curr->next;
    }

    if (curr && curr->power == p) {
        curr->coeff += c;   // Simplification
    } else {
        newNode->next = curr;
        prev->next = newNode;
    }
}

// Add two polynomials
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1) {
        insertTerm(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2) {
        insertTerm(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

// Display polynomial
void display(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->power;
        if (head->next)
            cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Polynomial 1: 3x^2 + 4x + 5
    insertTerm(poly1, 3, 2);
    insertTerm(poly1, 4, 1);
    insertTerm(poly1, 5, 0);

    // Polynomial 2: 2x^2 + 6
    insertTerm(poly2, 2, 2);
    insertTerm(poly2, 6, 0);

    cout << "Polynomial 1: ";
    display(poly1);

    cout << "Polynomial 2: ";
    display(poly2);

    Node* sum = addPoly(poly1, poly2);

    cout << "Sum: ";
    display(sum);

    return 0;
}
