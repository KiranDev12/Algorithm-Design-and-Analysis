// #TODO : Bubble sort algorithm display and how to reduce worst case time complexity
/*
Run a nested for loop with two variables i and j
If arr[j] is greater than arr[j+1] -> swap these adjacent elements
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Bubble_sort(int arr[], int n);

void main()
{

    int size = 10;
    FILE * fp = fopen("output.txt", "w");
    while (size != 110)
    {
        int count, arr[size], i;

        srand(time(NULL));
        // Average case time complexity..
        for (i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
        printf("The randomly generated array is: \n");
        for (i = 0; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n\n");
        printf("For average case:\n");
        count = Bubble_sort(arr, size);
        fprintf(fp, "%d\t%d\t", size, count);

        // Worst case time complexity
        printf("For Worst case: ");
        int x = size;
        for (i = 0; i < size; i++)
        {
            arr[i] = x--;
        }
        count = Bubble_sort(arr, size);
        fprintf(fp, "%d\t", count);

        // Best case time complexity
        printf("For Best case: ");

        for (i = 0; i < size; i++)
        {
            arr[i] = i + 1;
        }
        count = Bubble_sort(arr, size);

        fprintf(fp, "%d\n", count);

        size += 10;
    }
    fclose(fp);
}

int Bubble_sort(int arr[], int n)
{
    int count = 0, CompareCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        CompareCount = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                CompareCount++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (CompareCount == 0)
        {
            break;
        }
    }
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");

    return count;
}