#include <iostream>
using namespace std;

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int BinarySearch(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] == x)
            return m;
        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "How many numbers? ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    BubbleSort(arr, n);
    cout << "Numbers after sorting: ";
    PrintArray(arr, n);

    int val;
    cout << "Which number do you want to search? ";
    cin >> val;

    int pos = BinarySearch(arr, n, val);
    if (pos == -1)
        cout << val << " is not present in the list." << endl;
    else
        cout << val << " is present at position " << pos << " (0-based index)." << endl;

    return 0;
}
