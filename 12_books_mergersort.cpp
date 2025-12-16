#include <iostream>
using namespace std;

// Merge two parts
void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1;
    int temp[20];
    int k = l;

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (int x = l; x <= r; x++)
        a[x] = temp[x];
}

// Merge sort function
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int books[] = {45, 12, 78, 34, 23};
    int n = 5;

    cout << "Book IDs before sorting:\n";
    for (int i = 0; i < n; i++)
        cout << books[i] << " ";

    mergeSort(books, 0, n - 1);

    cout << "\n\nBook IDs after sorting:\n";
    for (int i = 0; i < n; i++)
        cout << books[i] << " ";

    return 0;
}
