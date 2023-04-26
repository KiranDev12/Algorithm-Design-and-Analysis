/*
//TODO: Linear Search program using random number generator, also using time.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *ptr1;
FILE *ptr2;
FILE *ptr3;

int main()
{
    int size;
    int i, x, result;
    srand(time(0));
    int j = 10;
    ptr1 = fopen("BestCase.txt", "w");
    ptr2 = fopen("WorstCase.txt", "w");
    ptr3 = fopen("AvgCase.txt", "w");
    if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL)
    {
        printf("Error file not generated\n");
        exit(0);
    }
    while (j != 110)
    {
        int arr[j];
        for (i = 0; i < j; i++)
            arr[i] = rand() % 100;
        printf("the randomly generated array is: \n");
        for (i = 0; i < j; i++)
            printf("%d\t", arr[i]);
        printf("\n\n");

        // BEST CASE =>
        x = arr[0];
        int k, count = 0;
        for (k = 0; k < j; k++)
        {
            count++;
            if (arr[k] == x)
            {
                break;
            }
        }
        fprintf(ptr1, "%d\t%d\n", j, count);

        // WORST CASE =>
        x = -1;
        count = 0;
        for (k = 0; k < j; k++)
        {
            count++;
            if (arr[k] == x)
            {
                break;
            }
        }
        fprintf(ptr2, "%d\t%d\n", j, count);

        // AVERAGE CASE =>
        x = arr[j / 2];
        count = 0;
        for (k = 0; k < j; k++)
        {
            count++;
            if (arr[k] == x)
            {
                break;
            }
        }
        fprintf(ptr3, "%d\t%d\n", j, count);

        j = j + 10;
    }
    return 0;
}