#include<stdio.h>

// RECURSIVE FUNCTION
// Time Complexity: O(2^n) - Exponential
// Space Complexity: O(n) - Due to call stack
int fibonacciRecursive(int n)
{
    if(n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// NON-RECURSIVE (ITERATIVE) FUNCTION
// Time Complexity: O(n) - Linear
// Space Complexity: O(1) - Constant
int fibonacciNonRecursive(int n)
{
    if(n <= 1)
        return n;
    
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// ITERATIVE FUNCTION TO PRINT FIBONACCI SERIES
void printFibonacciSeries(int limit)
{
    int a = 0, b = 1, c, i;

    printf("Fibonacci Series up to %d terms:\n", limit);
    printf("%d %d ", a, b);

    for(i = 2; i < limit; i++)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

int main()
{
    int n, choice;

    printf("Fibonacci Program\n");
    printf("==================\n");
    printf("1. Print Fibonacci Series (Iterative)\n");
    printf("2. Get nth Fibonacci Number (Recursive)\n");
    printf("3. Get nth Fibonacci Number (Non-Recursive)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter limit: ");
            scanf("%d", &n);
            printFibonacciSeries(n);
            break;

        case 2:
            printf("Enter position (n): ");
            scanf("%d", &n);
            printf("Fibonacci(%d) = %d (Recursive)\n", n, fibonacciRecursive(n));
            break;

        case 3:
            printf("Enter position (n): ");
            scanf("%d", &n);
            printf("Fibonacci(%d) = %d (Non-Recursive)\n", n, fibonacciNonRecursive(n));
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
