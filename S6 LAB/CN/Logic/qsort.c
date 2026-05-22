KO#include<stdio.h>
#include<stdlib.h>

// Compare function for integers
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int arr[100], n, i;

    printf("Enter size : ");
    scanf("%d", &n);

    printf("Enter elements : ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Built-in sorting
    qsort(arr,
          n,
          sizeof(int),
          compare);

    printf("Sorted array : ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Compare function for strings
int compare(const void *a, const void *b)
{
    return strcmp((char*)a,
                  (char*)b);
}

int main()
{
    char arr[][20] =
    {
        "Orange",
        "Apple",
        "Banana",
        "Mango"
    };

    int n, i;

    n = sizeof(arr) / sizeof(arr[0]);

    // Built-in sorting
    qsort(arr,
          n,
          sizeof(arr[0]),
          compare);

    printf("Sorted strings :\n");

    for(i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}