#include <iostream>
using namespace std;

void combSort(int a[], int n) {
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

void PrintArray(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of cards: ";
    cin >> n;
    int cards[100];
    cout << "Enter card values: ";
    for (int i = 0; i < n; i++) cin >> cards[i];

    cout << "Original cards: ";
    PrintArray(cards, n);

    combSort(cards, n);

    cout << "Sorted cards: ";
    PrintArray(cards, n);

    return 0;
}
