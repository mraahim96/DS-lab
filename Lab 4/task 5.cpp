#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int curr = arr[i + 1];
        int prev = i;
        while (prev >= 0)
        {
            if (arr[prev] > curr)
            {
                arr[prev + 1] = arr[prev];
                prev--;
            }
            else
            {
                break;
            }
        }
        arr[prev + 1] = curr;
    }
}
int main()
{
    int arr[] = {9, 5, 1, 4, 3, 14, 119};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    InsertionSort(arr, n);
    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}