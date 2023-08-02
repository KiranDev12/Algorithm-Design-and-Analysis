#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int n, int *count)
{
    int i, j, min_index;
    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            (*count)++;
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main()
{
    int i, j, result1, result2, result3;
    j = 10;
    FILE *ptr = fopen("selection.txt", "w");
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
        selection_sort(arr, j, &count);
        result1 = count;

        // AVERAGE CASE =>
        count = 0;
        for (i = 0; i < j / 2; i++)
            arr[i] = j - i;
        for (i = j / 2; i < j; i++)
        {
            arr[i] = i;
        }
        selection_sort(arr, j, &count);
        result2 = count;

        // WORST CASE =>
        count = 0;
        for (i = 0; i < j; i++)
            arr[i] = j - i;
        selection_sort(arr, j, &count);
        result3 = count;

        fprintf(ptr, "%d\t%d\t%d\t%d\n", j, result1, result2, result3);
        j += 10;
    }
    fclose(ptr);
    return 0;
}
