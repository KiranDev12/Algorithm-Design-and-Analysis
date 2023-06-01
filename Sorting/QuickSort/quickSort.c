#include <stdio.h>

int comparisonCount = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high+1;

    while (i <= j) {
        do{
            i++;
            comparisonCount++;
        }
        while (arr[i] < pivot && i <= high);/* {
            i++;
            comparisonCount++;  // Increment comparison count
        }*/

        do{
            j--;
            comparisonCount++;
        }
        while (arr[j] > pivot && j >= low + 1);/* {
            j--;
            comparisonCount++;  // Increment comparison count
        }*/

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8,7,6,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    comparisonCount = 0;  // Reset comparison count
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    printf("Comparison count: %d\n", comparisonCount);

    return 0;
}