#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int StringMatch(char text[], char pattern[],int M,int N)
{
    int count = 0;
    for (int i = 0; i <= N - M; i++)
    {
        int j = 0;
        while (j < M && (pattern[j] == text[i + j]))
        {
            j++;
            count++;
        }
        if (j == M)
        {
            return count;
        }
        count++;
    }
    return count;
}
int main()
{
    int j = 10, x, result1=0, result2=0, result3=0,N=100;
    char T[N];
    srand(time(NULL));
    FILE *ptr = fopen("string.txt", "w");
    if (ptr == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }

    for (int i = 0; i < N; i++)
    {
        T[i] = 'a';
    }
    while (j <= N)
    {
        char* P=malloc(sizeof(char)*j);
        for (int i = 0; i < j; i++)
        {
            P[i] = 'a';
        }
        // best case
        result1 = StringMatch(T, P,j,N);

        // worst case
        P[j - 1] = 'b';
        result3 = StringMatch(T, P,j,N);

        // avg case
        x = rand() % j;
        P[x] = 'b';
        result2 = StringMatch(T, P,j,N);

        fprintf(ptr, "%d\t%d\t%d\t%d\n", j, result1, result2, result3);
        j += 10;
        free(P);
    }
    fclose(ptr);
    return 0;
}
