#include <stdio.h>
#include <stdlib.h>

int towerOfHanoi(int n, char from, char to, char aux, int *op_count)
{
    if (n == 1)
    {
        (*op_count)++;
        return 1;
    }
    (*op_count)++;
    towerOfHanoi(n - 1, from, aux, to, op_count);
    printf("Disk moved from %c to %c\n", from, to);
    towerOfHanoi(n - 1, aux, to, from, op_count);
    return *op_count;
}

int main()
{
    FILE *f = fopen("count.txt", "w");
    int n;
    for (n = 1; n <= 10; n++)
    {
        int op_count = 0;
        int count = towerOfHanoi(n, 'A', 'C', 'B', &op_count);
        // f=fopen("count.txt", "a");
        fprintf(f, "%d\t%d\n", n, count);
        printf("\n\n");
    }
    fclose(f);
    return 0;
}