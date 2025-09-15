#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(int a[], int n, string msg)
{
    cout << msg;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void copyArr(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void bubble(int a[], int n)
{
    int c = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            c++;
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    cout << "Bubble sort comparisons: " << c << endl;
}

void insertion(int a[], int n)
{
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            c++;
            a[j + 1] = a[j];
            j--;
        }
        c++;
        a[j + 1] = key;
    }
    cout << "Insertion sort comparisons: " << c << endl;
}

void selection(int a[], int n)
{
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            c++;
            if (a[j] < a[m])
                m = j;
        }
        swap(a[i], a[m]);
    }
    cout << "Selection sort comparisons: " << c << endl;
}

void shell(int a[], int n)
{
    int c = 0;
    for (int g = n / 2; g > 0; g /= 2)
        for (int i = g; i < n; i++)
        {
            int temp = a[i], j = i;
            while (j >= g && a[j - g] > temp)
            {
                c++;
                a[j] = a[j - g];
                j -= g;
            }
            c++;
            a[j] = temp;
        }
    cout << "Shell sort comparisons: " << c << endl;
}

int main()
{
    srand(time(0));
    const int N = 20;
    int arr[N], temp[N];

    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;
    printArray(arr, N, "Original: ");

    copyArr(arr, temp, N);
    bubble(temp, N);
    printArray(temp, N, "Bubble sorted: ");
    copyArr(arr, temp, N);
    insertion(temp, N);
    printArray(temp, N, "Insertion sorted: ");
    copyArr(arr, temp, N);
    selection(temp, N);
    printArray(temp, N, "Selection sorted: ");
    copyArr(arr, temp, N);
    shell(temp, N);
    printArray(temp, N, "Shell sorted: ");

    return 0;
}
