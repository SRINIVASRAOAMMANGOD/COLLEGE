#include <stdio.h>
#define MAX 100

int arr1[MAX][MAX], t[MAX][3],b[MAX][3];// Arrays for matrices and sparse matrices

// Convert matrix to sparse matrix
void sparse(int arr[][MAX], int t[][3], int r, int c) {
    t[0][0] = r; 
    t[0][1] = c;
    int k = 1; // To start filling from the second row (index 1)
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                t[k][0] = i;       // Row index of non-zero element
                t[k][1] = j;       // Column index of non-zero element
                t[k][2] = arr[i][j];  // Value of the non-zero element
                k++;
            }
        }
    }

    t[0][2] = k - 1;  // Store the count of non-zero elements at t[0][2]

    // Print the sparse matrix
    printf("Sparse Matrix Representation:\n");
    for (int i = 0; i <= t[0][2]; i++) {
        printf("%d %d %d\t", t[i][0], t[i][1], t[i][2]);
    }
    printf("\n");
}

// Transpose the sparse matrix
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
    for (int i = 0; i <= b[0][2]; i++) {
        printf("%d %d %d\t", b[i][0], b[i][1], b[i][2]);
    }
    printf("\n");
}

// Add two sparse matrices


// Print the matrix
void printmat(int a[][MAX], int r, int c) {
    // Print the entered matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);
    
    printf("Enter the matrix elements for Matrix 1:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Entered Matrix 1:\n");
    printmat(arr1, r, c);


    
    // Convert the matrices to sparse format
    sparse(arr1, t, r, c);
    transpose(t,b);

    return 0;
}
