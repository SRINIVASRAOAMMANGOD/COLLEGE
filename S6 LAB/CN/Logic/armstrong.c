#include <stdio.h>
#include <math.h> // Required for the pow() function

int main()
{
    int n, temp, rem, sum = 0;
    int length = 0; // Stores the number of digits

    printf("Enter number : ");
    scanf("%d", &n);

    temp = n;

    // Step 1: Find the length (number of digits) of the number
    while (temp > 0)
    {
        length++;
        temp = temp / 10;
    }

    temp = n; // Reset temp back to the original number

    // Step 2: Calculate the sum of digits raised to the power of length
    while (n > 0)
    {
        rem = n % 10;

        // round() prevents floating-point precision issues with pow()
        sum = sum + round(pow(rem, length));

        n = n / 10;
    }

    // Step 3: Check if it matches the original number
    if (sum == temp)
        printf("Armstrong Number\n");
    else
        printf("Not Armstrong\n");

    return 0;
}
alternamte /*
int power = 1; // Start at 1

for (i = 1; i <= length; i++) 
{
    power = power * rem; // Keep multiplying by the original remainder
}

sum = sum + power; // Add the final result to your sum

*/
