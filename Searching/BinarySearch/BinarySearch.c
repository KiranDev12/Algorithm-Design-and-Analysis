//TODO: Do binary search of an array of size n and file them into best, avg, worst

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int n, int x);

int main()
{
    int size = 10;
    while (size!=110)
    {
        int arr[size];

        int i, x, result;

        srand(time(NULL)); // initialize random seed

        // initialize array with random numbers between 0 and 99
        for (i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
        
        // Best case => 

        
        size += 10;
    }
    
        

    return 0;
}

int binary_search(int arr[], int n, int x)
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
