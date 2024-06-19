#include <iostream>

using namespace std;

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Temporary arrays to hold the data
    int *L = new int[n1];
    int *R = new int[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    // Initial indexes for the left (i), right (j), and merged (k) subarrays
    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy any remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy any remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    // Free the memory allocated for temporary arrays
    delete[] L;
    delete[] R;
}

// Recursive function to implement Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Find the mid point

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is: ";
    printArray(arr, arr_size);
    // Perform Merge Sort
    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is: ";

    printArray(arr, arr_size);

    return 0;
}
