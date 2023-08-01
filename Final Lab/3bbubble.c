#include <stdio.h>
#include <stdlib.h>
FILE *ptr;
void bubble_sort(int arr[], int n, int *count)
{
    int i, j, s = 0;
    for (i = 0; i < n - 1; i++)
    {
        s = 1;
        for (j = 0; j < n - i - 1; j++)
        {
            (*count)++;
            if (arr[j] > arr[j + 1])
            {
                s = 0;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (s)
        {
            return;
        }
    }
}

int main()
{
    int size;
    int i, x, k, result1, result2, result3;
    int j = 10;
    ptr = fopen("Plot.txt", "w");
    if (ptr == NULL)
    {
        printf("Error file not generated\n");
        exit(0);
    }
    while (j != 110)
    {
        int arr[j];

        // BEST CASE =>
        int count = 0;
        for (i = 0; i < j; i++)
            arr[i] = i;
        bubble_sort(arr, j, &count);
        result1 = count;

        // AVERAGE CASE =>
        count = 0;
        for (i = 0; i < j / 2; i++)
            arr[i] = j - i;
        for (i = j / 2; i < j; i++)
        {
            arr[i] = i;
        }
        bubble_sort(arr, j, &count);
        result2 = count;

        // WORST CASE =>
        count = 0;
        for (i = 0; i < j; i++)
            arr[i] = j - i;
        bubble_sort(arr, j, &count);
        result3 = count;

        fprintf(ptr, "%d\t%d\t%d\t%d\n", j, result1, result2, result3);
        j = j + 10;
    }
    return 0;
}
