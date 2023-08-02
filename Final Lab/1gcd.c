#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count;

int modulo(int m, int n)
{
    count = 0;
    int rem;
    while (rem != 0)
    {
        count++;
        rem = m % n;
        m = n;
        n = rem;
    }
    return count;
}

int subtraction(int m, int n)
{
    count = 0;
    while (m != n)
    {
        count++;
        if (m > n)
        {
            m = m - n;
        }
        else
        {
            n = n - m;
        }
    }
    return count;
}

int constInteger(int m, int n)
{
    count = 0;
    int t1, t2;
    int t = (m > n) ? n : m;
    while (t != 1)
    {
        count++;
        t1 = m % t;
        if (t1 == 0)
        {
            t2 = n % t;
            if (t2 == 0)
            {
                break;
            }
        }
        t = t - 1;
    }
    return count;
}

void main()
{
    int m, n;
    int pair = 1;
    FILE *fp;
    fp = fopen("gcd.txt", "w");
    srand(time(NULL));
    while (pair < 11)
    {
        m = rand() % 100;
        n = rand() % 100;
        printf("%d\t%d\n", m, n);
        // for modulo method
        int result1 = modulo(m, n);
        // for subtraction method
        int result2 = subtraction(m, n);
        // for constant integer method
        int result3 = constInteger(m, n);
        fprintf(fp, "%d\t%d\t%d\t%d\n", pair, result1, result2, result3);
        pair += 1;
    }
    fclose(fp);
}
