#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int num)
{
    int count = 0;
    if (low > high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            count += 1;
            return count;
        }
        if (arr[mid] > num)
        {
            count = count + binarySearch(arr, low, mid - 1, num);
        }
        else
        {
            count = count + binarySearch(arr, mid + 1, high, num);
        }
    }
    return count;
}

int main()
{
    int size = 10;
    FILE *f = fopen("Count.txt", "w");
    while (size != 110)
    {
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = i;
        }
        int best = binarySearch(arr, 0, size - 1, arr[(size - 1) / 2]);
        int worst = binarySearch(arr, 0, size - 1, arr[0]);
        int avg = binarySearch(arr, 0, size - 1, arr[rand() % size]);
        fprintf(f, "%d\t%d\t%d\t%d\n", size, best, avg, worst);
        size += 10;
    }
    return 0;
}