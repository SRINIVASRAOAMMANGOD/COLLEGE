#include <stdio.h>
#include "sparse_operations.c"  // Include the sparse conversion functions

#define MAX 100

int arr[MAX][MAX], t[MAX][3], b[MAX][3]; // Regular matrix and sparse matrices

// Function to transpose a sparse matrix
void transpose(int a[][3], int b[][3]) {
    b[0][0] = a[0][1]; 
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    
    int k = 1; // Index for the transposed sparse matrix
    int m = a[0][1];  // Number of rows in the original matrix (columns in the sparse matrix)
    int n = a[0][2];  // Number of non-zero elements
    
    // Perform the transpose
    for (int i = 0; i < m; i++) {  // Iterate over all columns of the original matrix
        for (int j = 1; j <= n; j++) { // Iterate over non-zero elements
            if (a[j][1] == i) {  // If the column index of the element matches the current row
                b[k][0] = a[j][1]; // Set row index of transposed matrix
                b[k][1] = a[j][0]; // Set column index of transposed matrix
                b[k][2] = a[j][2]; // Set value of non-zero element
                k++;
            }
        }
    }

    // Print the transposed sparse matrix
    printf("Transpose of Sparse Matrix:\n");
    printSparseMatrix(b);
}

int main() {
    int r, c;

    // Input the matrix dimensions and elements
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    // Input the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Convert the regular matrix to a sparse matrix
    sparse(arr, t, r, c);

    // Perform transpose of the sparse matrix
    transpose(t, b);

    return 0;
}
