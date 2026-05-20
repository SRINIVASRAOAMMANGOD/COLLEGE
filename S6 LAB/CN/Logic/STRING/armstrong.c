#include <stdio.h>
#include <math.h>

int main()
{
    int n, temp, rem, sum = 0;
    int length = 0;

    printf("Enter number : ");
    scanf("%d", &n);

    temp = n;

    // Step 1: Count the number of digits
    while (temp > 0)
    {
        length++;
        temp = temp / 10;
    }

    temp = n;

    // Step 2: Calculate sum of each digit raised to the power of total digits
    while (n > 0)
    {
        rem = n % 10;
        sum = sum + round(pow(rem, length));
        n = n / 10;
    }

    // Step 3: Check if sum equals original number
    if (sum == temp)
        printf("Armstrong Number\n");
    else
        printf("Not Armstrong\n");

    return 0;
}