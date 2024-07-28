#include <stdio.h>

int main() {
    // Declare matrices and variables
    int a[2][2], b[2][2];    // Matrices to store input
    int k = 0, g = 0, h = 0; // Counters for indexing sparse matrices
    int sizea = 0, sizeb = 0, sizesum = 0; // Number of non-zero elements in matrices

    // Input elements for the first matrix
    printf("ENTER ELEMENTS IN FIRST MATRIX:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("ENTER ELEMENTS IN SECOND MATRIX:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Print the first matrix
    printf("MATRIX A:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Print the second matrix
    printf("MATRIX B:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // Convert matrix A to its sparse matrix representation
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[i][j] != 0) {
                sizea++; // Count non-zero elements
            }
        }
    }

    // Allocate space for sparse matrix representation of A
    int c[3][sizea];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[i][j] != 0) {
                c[0][k] = i; // Row index
                c[1][k] = j; // Column index
                c[2][k] = a[i][j]; // Non-zero value
                k++;
            }
        }
    }

    // Print the sparse matrix representation of A
    printf("SPARSE MATRIX A:\n");
    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                printf("ROW: ");
                break;
            case 1:
                printf("COLUMN: ");
                break;
            case 2:
                printf("VALUE: ");
                break;
        }
        for (int j = 0; j < sizea; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Convert matrix B to its sparse matrix representation
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (b[i][j] != 0) {
                sizeb++; // Count non-zero elements
            }
        }
    }

    // Allocate space for sparse matrix representation of B
    int d[3][sizeb];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (b[i][j] != 0) {
                d[0][g] = i; // Row index
                d[1][g] = j; // Column index
                d[2][g] = b[i][j]; // Non-zero value
                g++;
            }
        }
    }

    // Print the sparse matrix representation of B
    printf("SPARSE MATRIX B:\n");
    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                printf("ROW: ");
                break;
            case 1:
                printf("COLUMN: ");
                break;
            case 2:
                printf("VALUE: ");
                break;
        }
        for (int j = 0; j < sizeb; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    // Add matrices A and B
    int add[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            add[i][j] = a[i][j] + b[i][j];
        }
    }

    // Convert the added matrix to its sparse matrix representation
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (add[i][j] != 0) {
                sizesum++; // Count non-zero elements
            }
        }
    }

    // Allocate space for sparse matrix representation of the sum
    int addsp[3][sizesum];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (add[i][j] != 0) {
                addsp[0][h] = i; // Row index
                addsp[1][h] = j; // Column index
                addsp[2][h] = add[i][j]; // Non-zero value
                h++;
            }
        }
    }

    // Print the sparse matrix representation of the sum
    printf("SPARSE MATRIX SUM:\n");
    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                printf("ROW: ");
                break;
            case 1:
                printf("COLUMN: ");
                break;
            case 2:
                printf("VALUE: ");
                break;
        }
        for (int j = 0; j < sizesum; j++) {
            printf("%d ", addsp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
