#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of " << i + 1 << ": ";
        cin >> arr[i];
    }
    int value;
    cout << "Enter value to find : ";
    cin >> value;
    int index = LinearSearch(arr, n, value);
    if (index)
    {
        cout << value << " found at index : " << index;
    }
    else
        cout << "Value not Found";
    return 0;
}