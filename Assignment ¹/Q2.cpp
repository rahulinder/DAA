#include <iostream>
#include <vector>

using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main function that sorts arr[left...right] using merge()
void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return; // Base case

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Helper function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // Task 1: Sort arr
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr) / sizeof(arr[0]);

    cout << "Original arr: ";
    printArray(arr, n1);

    mergeSort(arr, 0, n1 - 1);

    cout << "Sorted arr:   ";
    printArray(arr, n1);

    cout << "\n---\n\n";

    // Task 2: Sort arr2
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Original arr2: ";
    printArray(arr2, n2);

    mergeSort(arr2, 0, n2 - 1);

    cout << "Sorted arr2:   ";
    printArray(arr2, n2);

    return 0;
}