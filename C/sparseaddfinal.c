#include <stdio.h>
void PrintSparse(int S[20][3]);
void Sparse(int A[10][10], int m, int n, int S[20][3]) {
    int i, j, k = 1;
    
    S[0][0] = m;
    S[0][1] = n;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                S[k][0] = i;
                S[k][1] = j;
                S[k][2] = A[i][j];
                k++;
            }
        }
    }

    S[0][2] = k - 1;  // The number of non-zero elements
    PrintSparse(S);
}

void PrintSparse(int S[20][3]) {
    int i;
    printf("Sparse Matrix Representation:\n");
    for (i = 0; i <= S[0][2]; i++) {
        printf("%d\t%d\t%d\n", S[i][0], S[i][1], S[i][2]);
    }
}

void AddSparse(int S[20][3], int T[20][3]) {
    int r1, c1, r2, c2, m, n, i, j, k = 1;
    int A[20][3];
    
    r1 = S[0][0];
    c1 = S[0][1];
    r2 = T[0][0];
    c2 = T[0][1];

    if (r1 != r2 || c1 != c2) {
        printf("Incompatible Matrix size\n");
        return;
    }

    A[0][0] = S[0][0];  // Rows
    A[0][1] = S[0][1];  // Columns
    m = 1;  // Index for S
    n = 1;  // Index for T

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            if (S[m][0] == i && S[m][1] == j && T[n][0] == i && T[n][1] == j) {
                // Both matrices have a non-zero value at the same position
                A[k][0] = S[m][0];
                A[k][1] = S[m][1];
                A[k][2] = S[m][2] + T[n][2];  // Add the values
                m++;
                n++;
                k++;
            } else if (S[m][0] == i && S[m][1] == j) {
                // Only S has a non-zero value
                A[k][0] = S[m][0];
                A[k][1] = S[m][1];
                A[k][2] = S[m][2];
                m++;
                k++;
            } else if (T[n][0] == i && T[n][1] == j) {
                // Only T has a non-zero value
                A[k][0] = T[n][0];
                A[k][1] = T[n][1];
                A[k][2] = T[n][2];
                n++;
                k++;
            }
        }
    }

    A[0][2] = k - 1;  // The number of non-zero elements
    printf("SUM:\n");

    for (i = 0; i <= A[0][2]; i++) {
        printf("%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2]);
    }
}


int main(){
    int i, j, A[10][10], B[10][10], m1, n1, m2, n2, S[20][3], T[20][3];

    // Input for the first matrix
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d", &m1, &n1);
    printf("Enter the matrix:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Print the first matrix
    printf("Matrix1:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    // Convert to sparse matrix representation
    Sparse(A, m1, n1, S);

    // Input for the second matrix
    printf("Enter the number of rows and columns of the second matrix: ");

    scanf("%d%d", &m2, &n2);
    printf("Enter the matrix:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Print the second matrix
    printf("Matrix2:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    // Convert to sparse matrix representation
    Sparse(B, m2, n2, T);

    // Add the two sparse matrices
    AddSparse(S, T);
    return 0;
}

