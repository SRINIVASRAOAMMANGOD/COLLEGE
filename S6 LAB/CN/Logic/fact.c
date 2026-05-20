#include<stdio.h>

int main()
{
    int n, i;

    long int fact = 1;

    printf("Enter number : ");
    scanf("%d", &n);

    // Loop from 1 to n
    for(i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    printf("Factorial = %ld", fact);

    return 0;
}
#include<stdio.h>

// Recursive function
long int factorial(int n)
{
    // Base condition
    if(n == 0 || n == 1)
    {
        return 1;
    }

    // Recursive call
    return n * factorial(n - 1);
}

int main()
{
    int n;

    printf("Enter number : ");
    scanf("%d", &n);

    printf("Factorial = %ld",
           factorial(n));

    return 0;
}