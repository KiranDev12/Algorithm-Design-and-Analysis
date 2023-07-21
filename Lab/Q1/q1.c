// Implement Euclid’s, consecutive integer checking and modified Euclid’s algorithms
// to find GCD of two nonnegative integers and perform comparative analysis.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count;
int modulo_gcd(int m, int n)
{
    int count = 0;

    while (n != 0)
    {
        count++;
        int rem = m % n;
        m = n;
        n = rem;
    }
    return count;
}
int subtraction_gcd(int m, int n)
{
    int count = 0;

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

int ConsInt_gcd(int m, int n)
{
    int count = 0;

    int t1, t2, ans = 1;
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
                ans = t;
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

    int ip = 1;
    FILE *fp;
    fp = fopen("q1.txt", "w");
    srand(time(NULL));
    while (ip < 11)
    {
        m = rand() % 100;
        n = rand() % 100;
        // for modulo method
        printf("%d %d\n", m, n);
        int result1 = modulo_gcd(m, n);
        // for subtraction method
        int result2 = subtraction_gcd(m, n);
        // for constant integer method
        int result3 = ConsInt_gcd(m, n);
        fprintf(fp, "%d\t%d\t%d\t%d\n", ip, result1, result2, result3);
        ip += 1;
    }
    fclose(fp);
}
