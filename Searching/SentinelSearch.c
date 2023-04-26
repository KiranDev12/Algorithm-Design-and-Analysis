// TODO: Sentinal search is same as that of linear search with slight variation to improve the average time

// Now considering the worst case in which the search element does not exist in the list of size N then the Simple Linear Search will take a total of 2N + 1 comparisons(N comparisons against every element in the search list and N + 1 comparisons to test against the end of the loop condition).

// Last element of the array => search key
// while search key is not found => increment i
// if i is less than size || equal to last element => found
// else => not found

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sentinelsearch(int a[max], int n, int key)
{
    int i, last;

    last = a[n - 1];
    a[n - 1] = key;

    i = 0;

    while (a[i] != key)
        i++;

    a[n - 1] = last;

    if (a[i] == key)
        printf("Search found at index %d", i + 1);
    else
        printf("Not found");
}
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

    printf("Enter Key To Search:");
    int key;
    scanf("%d", &key);

    sentinelsearch(arr, size, key);
}
