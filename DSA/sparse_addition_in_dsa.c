#include <stdio.h>

#define MAX_SIZE 1000

void printSparseMatrix(int size, int sm[3][MAX_SIZE]) {
    // Print the sparse matrix representation
    printf("SPARSE MATRIX:\n");
    printf("ROW: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sm[0][i]);
    }
    printf("\nCOLUMN: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sm[1][i]);
    }
    printf("\nVALUE: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sm[2][i]);
    }
    printf("\n");
}

void add(int r1, int c1, int r2, int c2, int first[r1][c1], int second[r2][c2]) {
    if (r1 != r2 || c1 != c2) {
        printf("Matrix addition is not possible. The dimensions of the matrices must be the same.\n");
        return;
    }

    int add[r1][c1];
    int size = 0;

    // Add matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            add[i][j] = first[i][j] + second[i][j];
        }
    }

    // Calculate the size of the sparse matrix
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (add[i][j] != 0) {
                size++;
            }
        }
    }

    // Allocate space for sparse matrix representation
    int addsp[3][MAX_SIZE];
    int h = 0;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (add[i][j] != 0) {
                addsp[0][h] = i; // Row index
                addsp[1][h] = j; // Column index
                addsp[2][h] = add[i][j]; // Non-zero value
                h++;
            }
        }
    }

    // Print the sparse matrix representation
    printf("Sparse matrix representation of the sum:\n");
    printSparseMatrix(size, addsp);
}

void convertToSparse(int r, int c, int arr[r][c]) {
    int size = 0;
    int sparseMatrix[3][MAX_SIZE]; // Fixed-size array for simplicity

    // Count non-zero elements
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                if (size >= MAX_SIZE) {
                    printf("Error: Number of non-zero elements exceeds the maximum allowed size.\n");
                    return;
                }
                sparseMatrix[0][size] = i; // Row index
                sparseMatrix[1][size] = j; // Column index
                sparseMatrix[2][size] = arr[i][j]; // Non-zero value
                size++;
            }
        }
    }

    printSparseMatrix(size, sparseMatrix);
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &r1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &c1);

    int firstMatrix[r1][c1];

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printf("Enter the number of rows for the second matrix: ");
    scanf("%d", &r2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &c2);

    if (r1 != r2 || c1 != c2) {
        printf("Matrix addition is not possible. The dimensions of the matrices must be the same.\n");
        return 1;
    }

    int secondMatrix[r2][c2];

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Convert and display the sparse matrix representation of the first matrix
    printf("Sparse matrix representation of the first matrix:\n");
    convertToSparse(r1, c1, firstMatrix);

    // Convert and display the sparse matrix representation of the second matrix
    printf("Sparse matrix representation of the second matrix:\n");
    convertToSparse(r2, c2, secondMatrix);

    // Add the matrices and display the sparse matrix representation of the sum
    add(r1, c1, r2, c2, firstMatrix, secondMatrix);

    return 0;
}
