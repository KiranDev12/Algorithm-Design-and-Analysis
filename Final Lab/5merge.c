#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left[], int right[], int leftSize, int rightSize, int* count) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftSize && j < rightSize) {
        (*count)++;
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size,int* count) {
    if (size < 2)
        return;

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    mergeSort(left, mid,count);
    mergeSort(right, size - mid,count);

    // Merge the sorted subarrays
    merge(arr, left, right, mid, size - mid,count);
}

void mergeProcessed(int arr[], int left[], int right[], int leftSize, int rightSize) {
    int i,j;
    for(i=0;i<leftSize;i++){
        arr[i]=left[i];
    }
    for(i=leftSize,j=0;i<leftSize+rightSize;i++,j++){
        arr[i]=right[j];
    }
}
void generateWorstCase(int arr[],int n) {
    int i, j;
    int mid = n/2;
    int temp[n];
    for (i = 0, j = 0; i < mid; i++, j += 2)
        temp[i] = arr[j];
    for (i = mid, j = 1; i < n; i++, j += 2)
        temp[i] = arr[j];
    for (i = 0; i < n; i++)
        arr[i] = temp[i];
}
void generate(int arr[], int size) {
    if (size < 2)
        return;
    generateWorstCase(arr,size);
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];
    generate(left, mid);
    generate(right, size - mid);
    mergeProcessed(arr, left, right, mid, size - mid);
}
int main() {
    int i, j, result1, result2, result3;
    j = 8;
    FILE *ptr = fopen("Plot.txt", "w");
    if (ptr == NULL)
    {
        printf("Error file not generated\n");
        exit(0);
    }
    while (j <= 32762)
    {
        int arr[j];

        // BEST CASE
        int count = 0;
        for (i = 0; i < j; i++)
            arr[i] = i;
        mergeSort(arr, j, &count);
        result1 = count;
        

        // WORST CASE
        count = 0;
        generate(arr,j);
        mergeSort(arr, j, &count);
        result3 = count;
        
        
        // AVERAGE CASE
        count = 0;
        for (i = 0; i < j; i++)
            arr[i] = rand()%j;
        mergeSort(arr, j, &count);
        result2 = count;


        fprintf(ptr, "%d\t\t%d\t%d\t%d\n", j, result1, result2, result3);
        j *= 2;
    }
    fclose(ptr);
    return 0;
}
