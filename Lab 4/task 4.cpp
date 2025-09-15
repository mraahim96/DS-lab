#include <iostream>
using namespace std;
class BubbleSort
{
private:
    int *arr;
    int size;
    int passes;

public:
    BubbleSort(int array[], int n)
    {
        size = n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = array[i];
        }
        passes = 0;
    }
    void sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            passes++;
            if (!swapped)
                break;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int getPasses()
    {
        return passes;
    }
    ~BubbleSort()
    {
        delete[] arr;
    }
};
int main()
{
    int arr[] = {10, 2, 0, 14, 43, 25, 18, 1, 5, 45};
    int n = 10;
    BubbleSort sorting(arr, n);
    cout << "Input list: ";
    sorting.display();
    sorting.sort();
    cout << "Sorted Element List: ";
    sorting.display();
    cout << "Number of passes taken: " << sorting.getPasses() << endl;
    return 0;
}