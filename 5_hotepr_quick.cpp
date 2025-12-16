#include <iostream>
using namespace std;

// Partition function
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Display prices
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int prices[] = {3500, 1200, 2800, 4500, 2000};
    int n = 5;

    cout << "Room Prices Before Sorting:\n";
    display(prices, n);

    quickSort(prices, 0, n - 1);

    cout << "\nRoom Prices After Quick Sort:\n";
    display(prices, n);

    return 0;
}
