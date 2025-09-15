#include <iostream>
using namespace std;

class ShippingSorter
{
private:
    int *crates;
    int size;

public:
    ShippingSorter(int arr[], int n)
    {
        crates = new int[n];
        size = n;
        for (int i = 0; i < n; i++)
        {
            crates[i] = arr[i];
        }
    }
    void insertionSort()
    {
        for (int i = 1; i < size; i++)
        {
            int key = crates[i];
            int j = i - 1;
            while (j >= 0 && crates[j] > key)
            {
                crates[j + 1] = crates[j];
                j--;
            }
            crates[j + 1] = key;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << crates[i] << " ";
        }
        cout << endl;
    }
    ~ShippingSorter()
    {
        delete[] crates;
    }
};
int main()
{
    int n;
    cout << "Enter the number of crates: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the shipment times for crates: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ShippingSorter sorter(arr, n);

    sorter.insertionSort();
    
    cout << "Sorted crates in shipment order: ";
    sorter.display();
    delete[] arr;
    return 0;
}