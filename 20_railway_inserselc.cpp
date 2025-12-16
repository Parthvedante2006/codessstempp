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
            } else {
                break;
            }
        }
        a[j + 1] = key;
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
    // Arrival times in minutes
    int times[] = {630, 555, 765, 530, 670}; // 10:30, 9:15, 12:45, 8:50, 11:10
    int n = 5;

    int arr1[5], arr2[5];
    for (int i = 0; i < n; i++)
        arr1[i] = arr2[i] = times[i];

    int comp1 = 0, comp2 = 0;

    insertionSort(arr1, n, comp1);
    selectionSort(arr2, n, comp2);

    cout << "Insertion Sort Result: ";
    display(arr1, n);
    cout << "Comparisons: " << comp1 << endl;

    cout << "\nSelection Sort Result: ";
    display(arr2, n);
    cout << "Comparisons: " << comp2 << endl;

    return 0;
}
