#include <iostream>
using namespace std;

struct Patient {
    int id;
    Patient* left;
    Patient* right;
};

// Create new patient node
Patient* createPatient(int id) {
    Patient* p = new Patient();
    p->id = id;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Insert patient in BST
Patient* insert(Patient* root, int id) {
    if (root == NULL)
        return createPatient(id);

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}

// Search patient by ID
void search(Patient* root, int id) {
    if (root == NULL) {
        cout << "Patient not found\n";
        return;
    }

    if (id == root->id)
        cout << "Patient found with ID: " << id << endl;
    else if (id < root->id)
        search(root->left, id);
    else
        search(root->right, id);
}

// Find minimum value node
Patient* findMin(Patient* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete patient from BST
Patient* deletePatient(Patient* root, int id) {
    if (root == NULL)
        return root;

    if (id < root->id)
        root->left = deletePatient(root->left, id);
    else if (id > root->id)
        root->right = deletePatient(root->right, id);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Patient* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Patient* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Patient* temp = findMin(root->right);
        root->id = temp->id;
        root->right = deletePatient(root->right, temp->id);
    }
    return root;
}

int main() {
    Patient* root = NULL;
    int choice, id;

    do {
        cout << "\n1. Insert Patient";
        cout << "\n2. Search Patient";
        cout << "\n3. Delete Patient";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient ID: ";
            cin >> id;
            root = insert(root, id);
            break;

        case 2:
            cout << "Enter patient ID to search: ";
            cin >> id;
            search(root, id);
            break;

        case 3:
            cout << "Enter patient ID to delete: ";
            cin >> id;
            root = deletePatient(root, id);
            break;
        }
    } while (choice != 4);

    return 0;
}
