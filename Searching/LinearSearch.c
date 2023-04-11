/*
//TODO: Linear Search program using random number generator, also using time.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int arr[], int n, int x);

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    int i, x, result;

    srand(time(NULL)); // initialize random seed

    // initialize array with random numbers between 0 and 99
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
    // get a random number to search for
    printf("Enter a number to search for: ");
    scanf("%d", &x);

    result = linear_search(arr, size, x);
    if (result == -1)
    {
        printf("Element %d not found in the array\n", x);
    }
    else
    {
        printf("Element %d found at index %d\n", x, result);
    }

    return 0;
}

int linear_search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1; // element not found
}
