#include <iostream>
#include <cmath>
using namespace std;

void combSort(int a[], int n)
{
    int gap = n;
    const float shrink = 1.3;
    bool swapped = true;
    while (gap > 1 || swapped)
    {
        gap = int(floor(gap / shrink));
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (int i = 0; i + gap < n; i++)
        {
            if (a[i] > a[i + gap])
            {
                int t = a[i];
                a[i] = a[i + gap];
                a[i + gap] = t;
                swapped = true;
            }
        }
    }
}

int InterpolationSearch(int a[], int n, int val)
{
    int low = 0, high = n - 1;
    while (low <= high && val >= a[low] && val <= a[high])
    {
        if (a[high] == a[low])
            break;
        int pos = low + ((val - a[low]) * (high - low)) / (a[high] - a[low]);
        if (a[pos] == val)
            return pos;
        if (a[pos] < val)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    combSort(a, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    int value;
    cout << "Enter value to search: ";
    cin >> value;
    int idx = InterpolationSearch(a, n, value);
    if (idx != -1)
        cout << "Value found at index " << idx << endl;
    else
        cout << "Value not found" << endl;

    delete[] a;
    return 0;
}
