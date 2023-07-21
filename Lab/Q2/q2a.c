// Implement the following searching algorithms and perform their analysis for worst
// case, best-case and average inputs.
// a) Sequential Search
// b) Binary Search (Recursive)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE * ptr;

int main()
{
    int size;
    int i, x, result;
    srand(time(0));
    int j = 10;
    ptr = fopen("q2a.txt", "w");
    if (ptr==NULL)
    {
        printf("Error file not generated\n");
        exit(0);
    }
    while (j != 110)
    {
        int arr[j];
        for (i = 0; i < j; i++)
            arr[i] = rand() % 100;
        printf("The randomly generated array is: \n");
        for (i = 0; i < j; i++)
            printf("%d\t", arr[i]);
        printf("\n\n");

        // BEST CASE =>
        x = arr[0];
        int k, count1 = 0, count2, count3;
        for (k = 0; k < j; k++)
        {
            count1++;
            if (arr[k] == x)
            {
                break;
            }
        }

        // WORST CASE =>
        x = -1;
        count2 = 0;
        for (k = 0; k < j; k++)
        {
            count2++;
            if (arr[k] == x)
            {
                break;
            }
        }

        // AVERAGE CASE =>
        x = arr[j / 2];
        count3 = 0;
        for (k = 0; k < j; k++)
        {
            count3++;
            if (arr[k] == x)
            {
                break;
            }
        }
        fprintf(ptr, "%d\t%d\t%d\t%d\n", j, count1, count3, count2);

        j = j + 10;
    }
    return 0;
}