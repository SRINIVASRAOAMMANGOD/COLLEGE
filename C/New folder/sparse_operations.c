#include <stdio.h>
#define MAX 100

// Function to convert a regular matrix to sparse matrix
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
}

// Function to print the sparse matrix
void printSparseMatrix(int t[][3]) {
    printf("Sparse Matrix Representation:\n");
    for (int i = 0; i <= t[0][2]; i++) {
        printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);
    }
    printf("\n");
}
