#include <iostream>
using namespace std;

// Insertion Sort
void insertionSort(int a[], int n, int &comp) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            comp++;
            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
            } else
                break;
        }
        a[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(int a[], int n, int &comp) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(int a[], int n, int &comp) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

// Display array
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int prices[] = {3500, 1200, 2800, 4500, 2000};
    int n = 5;

    int a1[5], a2[5], a3[5];
    for (int i = 0; i < n; i++)
        a1[i] = a2[i] = a3[i] = prices[i];

    int c1 = 0, c2 = 0, c3 = 0;

    insertionSort(a1, n, c1);
    bubbleSort(a2, n, c2);
    selectionSort(a3, n, c3);

    cout << "Insertion Sort: ";
    display(a1, n);
    cout << "Comparisons: " << c1 << endl;

    cout << "\nBubble Sort: ";
    display(a2, n);
    cout << "Comparisons: " << c2 << endl;

    cout << "\nSelection Sort: ";
    display(a3, n);
    cout << "Comparisons: " << c3 << endl;

    return 0;
}
