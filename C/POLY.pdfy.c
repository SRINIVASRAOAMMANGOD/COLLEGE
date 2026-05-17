#include <stdio.h>
#define max 100

int main() {
    int poly1[max + 1], poly2[max + 1], poly3[max + 1], i, d1, d2, d3;

    printf("enter degree 1: ");
    scanf("%d", &d1);
    printf("enter degree 2: ");
    scanf("%d", &d2);
    
    d3 = d1 > d2 ? d1 : d2;

    printf("enter pol 1:\n");
    for (i = 0; i <= d1; i++) { // Changed to <= to include the d1 degree
        printf("enter coefficient for x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    printf("enter pol 2:\n");
    for (i = 0; i <= d2; i++) { // Changed to <= to include the d2 degree
        printf("enter coefficient for x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    for (i = 0; i <= d3; i++) {
        poly3[i] = 0; // Initialize to 0
        poly3[i]=poly3[i]+(poly1[i]+poly2[i]);
    }

    printf("Resultant polynomial: ");
for (i = 0; i <= d3; i++) {
    if (poly3[i] != 0) { // Only print non-zero coefficients
        if (i == 0) {
            printf("%d", poly3[i]); // Print the constant term without a plus sign
        } else {
            printf(" + %d x^%d", poly3[i], i); // Print the other terms with a plus sign
        }
    }
}
printf("\n"); // New line after printing the polynomial

    return 0;
}