/*
//TODO: Subtraction method by Euclid
Until m and n are not equal,
    if m is greater than n, m <- m - n
    else n <- n - m
gcd is m
*/

#include <stdio.h>

int main()
{
    int m, n;
    int count = 0;
    printf("Enter two numbers, to find GCD\n");
    scanf("%d%d", &m, &n);
    while (m!=n)
    {
        count++;
        if (m>n)
        {
            m = m - n;
        }
        else{
            n = n - m;
        }
    }
    printf("GCD of the given numbers is %d and count is %d", m, count);
}