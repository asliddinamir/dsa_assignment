#include <iostream>

using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int min_idx = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first unsorted element
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

// Utility function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Given array is: ";
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    cout << "Sorted array is: ";
    printArray(arr, n);
    
    return 0;
}
