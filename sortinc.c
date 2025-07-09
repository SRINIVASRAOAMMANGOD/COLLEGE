#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------------------------
// Integer comparison functions
// ----------------------------

// Ascending order for integers
int compare_int_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Descending order for integers
int compare_int_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// ----------------------------
// String comparison functions
// ----------------------------

// Ascending order for strings (A to Z)
int compare_str_asc(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Descending order for strings (Z to A)
int compare_str_desc(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

int main() {
    // Integer array for sorting
    int nums[] = {5, 2, 9, 1, 7};
    int n_nums = sizeof(nums) / sizeof(nums[0]);

    // Sort integers in ascending order
    qsort(nums, n_nums, sizeof(int), compare_int_asc);
    printf("Integers Ascending: ");
    for (int i = 0; i < n_nums; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Sort integers in descending order
    qsort(nums, n_nums, sizeof(int), compare_int_desc);
    printf("Integers Descending: ");
    for (int i = 0; i < n_nums; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // String array for sorting
    const char *words[] = {"banana", "apple", "cherry", "date"};
    int n_words = sizeof(words) / sizeof(words[0]);

    // Sort strings in ascending order (A-Z)
    qsort(words, n_words, sizeof(char *), compare_str_asc);
    printf("Strings Ascending (A-Z): ");
    for (int i = 0; i < n_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Sort strings in descending order (Z-A)
    qsort(words, n_words, sizeof(char *), compare_str_desc);
    printf("Strings Descending (Z-A): ");
    for (int i = 0; i < n_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}
