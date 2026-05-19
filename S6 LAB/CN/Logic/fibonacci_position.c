#include<stdio.h>

int main()
{
    int pos, a = 0, b = 1, c, i;

    printf("Enter position : ");
    scanf("%d", &pos);

    for(i = 2; i <= pos; i++)
    {
        c = a + b;

        a = b;
        b = c;
    }

    printf("Fibonacci number = %d", b);

    return 0;
}
