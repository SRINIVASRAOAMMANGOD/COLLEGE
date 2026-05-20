#include <stdio.h>

int main()
{
    int a, b, i, gcd, lcm;

    printf("Enter two numbers : ");
    scanf("%d%d", &a, &b);

    // Finding GCD using your loop logic
    for(i = 1; i <= a && i <= b; i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    // Calculating LCM using the mathematical formula
    lcm = (a * b) / gcd;

    printf("GCD = %d\n", gcd);
    printf("LCM = %d\n", lcm);

    return 0;
}

