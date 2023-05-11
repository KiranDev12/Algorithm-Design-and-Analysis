#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binaryDigits(int n)
{
    int count = 0;
    if (n == 0)
    {
        return 1;
    }
    while (n != 0)
    {
        count++;
        n = n / 2;
    }
    return count;
}

int main()
{
    int num = 1;
    int count;
    FILE *fp = fopen("Count.txt", "w");
    if (fp == NULL)
    {
        printf("File is not created\n");
        exit(0);
    }
    while (num != 2048)
    {
        count = binaryDigits(num);
        fprintf(fp, "%d\t%d\n", num, count);
        num = num * 2;
    }
    fclose(fp);
    return 0;
}