#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
            break;
    }
    return;
}
int main()
{
    int Bottles;
    cout << "Enter no of bottles : ";
    cin >> Bottles;

    int Levels[Bottles];
    cout << "Enter levels of bottles " << endl;
    for (int i = 0; i < Bottles; i++)
    {
        cout << "Enter level of " << i + 1 << " bottle : ";
        cin >> Levels[i];
    }
    BubbleSort(Levels, Bottles);
    cout << "Sorted levels of bottles : ";
    for (int i = 0; i < Bottles; i++)
    {
        cout << "level of " << i + 1 << " bottle : " << Levels[i] << endl;
    }
    return 0;
}