#include <stdio.h>

#define MAX_SIZE 1000

void printMatrix(int r, int c, int arr[r][c]) {
    printf("Original Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printTransposedMatrix(int r, int c, int arr[c][r]) {
    printf("Transposed Matrix:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printSparseMatrix(int size, int sm[3][MAX_SIZE]) {
    printf("SPARSE MATRIX:\nROW: ");
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

void convertToSparse(int r, int c, int arr[r][c], int sparseMatrix[3][MAX_SIZE], int *size) {
    *size = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                if (*size >= MAX_SIZE) {
                    printf("Error: Number of non-zero elements exceeds the maximum allowed size.\n");
                    return;
                }
                sparseMatrix[0][*size] = i;
                sparseMatrix[1][*size] = j;
                sparseMatrix[2][*size] = arr[i][j];
                (*size)++;
            }
        }
    }
}

void transposeSparse(int size, int sm[3][MAX_SIZE], int transposed[3][MAX_SIZE]) {
    for (int i = 0; i < size; i++) {
        transposed[0][i] = sm[1][i];
        transposed[1][i] = sm[0][i];
        transposed[2][i] = sm[2][i];
    }
}

void transposeMatrix(int r, int c, int arr[r][c], int transposed[c][r]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transposed[j][i] = arr[i][j];
        }
    }
}

int main() {
    int r1, c1;

    printf("Enter the number of rows for the matrix: ");
    scanf("%d", &r1);
    printf("Enter the number of columns for the matrix: ");
    scanf("%d", &c1);

    if (r1 <= 0 || c1 <= 0) {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    int firstMatrix[r1][c1];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    printMatrix(r1, c1, firstMatrix);

    int transposedMatrix[c1][r1];
    transposeMatrix(r1, c1, firstMatrix, transposedMatrix);
    printTransposedMatrix(c1, r1, transposedMatrix);

    int sparseMatrix[3][MAX_SIZE];
    int size1;

    printf("Sparse matrix representation of the matrix:\n");
    convertToSparse(r1, c1, firstMatrix, sparseMatrix, &size1);
    printSparseMatrix(size1, sparseMatrix);

    int transposed[3][MAX_SIZE];
    transposeSparse(size1, sparseMatrix, transposed);

    printf("Transpose of the sparse matrix:\n");
    printSparseMatrix(size1, transposed);

    return 0;
}
