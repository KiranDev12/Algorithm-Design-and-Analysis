/*
//TODO: Consecutive Integer Checking method
    t <- min{m,n}
    until t not equal to 1
        t1 <- m mod t
        if t1 is equal to zero
            t2 <- n mod t
            if t2 is equal to zero
                return t
        t <- t - 1
    gcd <- t
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, t1, t2, answer = 1;
    int count = 0;
    printf("Enter two numbers, to find GCD\n");
    scanf("%d%d", &m, &n);
    int t = (m > n) ? n : m;
    while (t >= 1)
    {
        count++;
        t1 = m % t;
        if (t1 == 0)
        {
            t2 = n % t;
            if (t2 == 0)
            {
                answer = t;
                break;
            }
        }
        t = t - 1;
    }
    printf("GCD of the given numbers is %d and count is %d", answer, count);
    return 0;
}
