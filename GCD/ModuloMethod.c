/*
//TODO: Modulo method by Euclid
Until n isn't zero,
    calculate reminder of m and n
    Set m as n
    and n as reminder
gcd will be m
*/

#include<stdio.h>

int main(){
    int m, n;
    int count = 0;
    printf("Enter two numbers, to find GCD\n");
    scanf("%d%d", &m, &n);
    while (n != 0)
    {
        count++;
        int rem = m % n;
        m = n;
        n = rem;
    }
    printf("GCD of the given numbers is %d and count is %d", m, count);
}