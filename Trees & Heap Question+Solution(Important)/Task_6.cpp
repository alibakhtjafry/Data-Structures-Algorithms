#include <bits\stdc++.h>
using namespace std;
void maxHeapify(int arr[], int n, int i, int &count)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left - 1] > arr[largest - 1])
        largest = left;

    if (right <= n && arr[right - 1] > arr[largest - 1])
        largest = right;

    if (largest != i)
    {
        swap(arr[i - 1], arr[largest - 1]);
        count++;
        maxHeapify(arr, n, largest, count);
    }
}

void buildMaxHeap(int arr[], int n, int &count)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(arr, n, i, count);
    }
}

int main()
{
    int n;

    // Input number of elements
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int swapCount = 0; // Variable to count swaps
    buildMaxHeap(arr, n, swapCount);

    // Output the max heap
    cout << "Max Heap: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Number of swaps made: " << swapCount << endl;

    return 0;
}