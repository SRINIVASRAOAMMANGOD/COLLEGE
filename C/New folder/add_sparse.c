#include <stdio.h>
#include "sparse_operations.c"  // Include the sparse conversion functions

#define MAX 100

int arr1[MAX][MAX], arr2[MAX][MAX], t[MAX][3], b[MAX][3], c[MAX][3]; // Matrices and their sparse forms

// Function to add two sparse matrices
void add(int a[][3], int b[][3], int c[][3]) {
    int r1 = a[0][0], r2 = b[0][0];
    int c1 = a[0][1], c2 = b[0][1];

    if (r1 != r2 || c1 != c2) {
        printf("Matrices are not of the same order\n");
    } else {
        c[0][0] = r1; // Number of rows
        c[0][1] = c1; // Number of columns
        int m = 1, n = 1, k = 1;

        // Iterate over all possible positions
        while (m <= a[0][2] && n <= b[0][2]) {
            if (a[m][0] == b[n][0] && a[m][1] == b[n][1]) {
                c[k][0] = a[m][0];
                c[k][1] = a[m][1];
                c[k][2] = a[m][2] + b[n][2]; // Add the values of the corresponding elements
                m++;
                n++;
                k++;
            } else if (a[m][0] < b[n][0] || (a[m][0] == b[n][0] && a[m][1] < b[n][1])) {
                c[k][0] = a[m][0];
                c[k][1] = a[m][1];
                c[k][2] = a[m][2];
                m++;
                k++;
            } else {
                c[k][0] = b[n][0];
                c[k][1] = b[n][1];
                c[k][2] = b[n][2];
                n++;
                k++;
            }
        }

        // If elements are left in matrix a
        while (m <= a[0][2]) {
            c[k][0] = a[m][0];
            c[k][1] = a[m][1];
            c[k][2] = a[m][2];
            m++;
            k++;
        }

        // If elements are left in matrix b
        while (n <= b[0][2]) {
            c[k][0] = b[n][0];
            c[k][1] = b[n][1];
            c[k][2] = b[n][2];
            n++;
            k++;
        }

        c[0][2] = k - 1; // Update the count of non-zero elements

        // Print the result sparse matrix
        printf("Sum of Sparse Matrices:\n");
        for (int i = 0; i <= c[0][2]; i++) {
            printf("%d %d %d\n", c[i][0], c[i][1], c[i][2]);
        }
    }
}

int main() {
    int r, c;

    // Input the matrix dimensions and elements
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    // Input the first matrix
    printf("Enter the matrix elements for Matrix 1:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    // Input the second matrix
    printf("Enter the matrix elements for Matrix 2:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Convert the matrices to sparse format
    sparse(arr1, t, r, c);
    sparse(arr2, b, r, c);

    // Perform addition of the sparse matrices
    add(t, b, c);

    return 0;
}
