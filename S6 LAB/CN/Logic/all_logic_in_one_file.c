// ALL BASIC STRING AND NUMBER LOGIC PROGRAMS
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int choice;

    printf("\n===== MENU =====\n");
    printf("1. Count Special Characters\n");
    printf("2. Prime Number Check\n");
    printf("3. Count Uppercase and Lowercase\n");
    printf("4. Uppercase to Lowercase Conversion\n");
    printf("5. Sum of Two Numbers\n");
    printf("6. Find Factorial\n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    // 1. Count Special Characters
    if(choice == 1)
    {
        char str[100];
        int i, count = 0;

        printf("Enter string : ");
        scanf("%s", str);

        for(i = 0; str[i] != '\0'; i++)
        {
            if(!(isalpha(str[i]) || isdigit(str[i])))
            {
                count++;
            }
        }

        printf("Special characters = %d", count);
    }

    // 2. Prime Number Check
    else if(choice == 2)
    {
        int n, i, flag = 0;

        printf("Enter number : ");
        scanf("%d", &n);

        for(i = 2; i < n; i++)
        {
            if(n % i == 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            printf("Prime Number");
        else
            printf("Not Prime");
    }

    // 3. Count Uppercase and Lowercase
    else if(choice == 3)
    {
        char str[100];
        int i, upper = 0, lower = 0;

        printf("Enter string : ");
        scanf("%s", str);

        for(i = 0; str[i] != '\0'; i++)
        {
            if(isupper(str[i]))
            {
                upper++;
            }
            else if(islower(str[i]))
            {
                lower++;
            }
        }

        printf("Uppercase letters = %d\n", upper);
        printf("Lowercase letters = %d\n", lower);
    }

    // 4. Uppercase to Lowercase Conversion
    else if(choice == 4)
    {
        char str[100];
        int i;

        printf("Enter string : ");
        scanf("%s", str);

        for(i = 0; str[i] != '\0'; i++)
        {
            str[i] = tolower(str[i]);
        }

        printf("Converted string = %s", str);
    }

    // 5. Sum of Two Numbers
    else if(choice == 5)
    {
        int a, b;

        printf("Enter two numbers : ");
        scanf("%d%d", &a, &b);

        printf("Sum = %d", a + b);
    }

    // 6. Factorial
    else if(choice == 6)
    {
        int n, i;
        long int fact = 1;

        printf("Enter number : ");
        scanf("%d", &n);

        for(i = 1; i <= n; i++)
        {
            fact = fact * i;
        }

        printf("Factorial = %ld", fact);
    }

    else
    {
        printf("Invalid Choice");
    }

    return 0;
}
