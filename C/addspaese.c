#include<stdio.h>
#define MAX 100
int arr1[MAX][MAX],arr2[MAX][MAX], t[MAX][3],b[MAX][3],cr[MAX][3];
void sparse(int arr[][MAX], int s[][3], int r, int c) {
    s[0][0] = r; 
    s[0][1] = c;
    int k = 1; // To start filling from the second row (index 1)
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                s[k][0] = i;       // Row index of non-zero element
                s[k][1] = j;       // Column index of non-zero element
                s[k][2] = arr[i][j];  // Value of the non-zero element
                k++;
            }
        }
    }

    s[0][2] = k - 1;  // Store the count of non-zero elements at t[0][2]

    // Print the sparse matrix
    printf("Sparse Matrix Representation:\n");
    for (int i = 0; i <= s[0][2]; i++) {
        printf("%d %d %d\t", s[i][0], s[i][1], s[i][2]);
    }
    printf("\n");
}
void add(int a[][3], int b[][3], int c[][3]) {
    int r1 = a[0][0], r2 = b[0][0];
    int c1 = a[0][1], c2 = b[0][1];

    if (r1 != r2 || c1 != c2) {
        printf("Matrices are not of the same order\n");
        return; // Early exit if matrices are not the same size
    } else {
        c[0][0] = r1; // Number of rows
        c[0][1] = c1; // Number of columns
        int m = 1, n = 1, k = 1;

        // Iterate until we reach the end of either sparse matrix
        for (int i = 0; i <= a[0][2] || i <= b[0][2];) {
            if (m <= a[0][2] && n <= b[0][2]) {
                if (a[m][0] == b[n][0] && a[m][1] == b[n][1]) {
                    // Both matrices have a value at this position
                    c[k][0] = a[m][0];
                    c[k][1] = a[m][1];
                    c[k][2] = a[m][2] + b[n][2]; // Add the values
                    m++;
                    n++;
                    k++;
                } else if (a[m][0] < b[n][0] || (a[m][0] == b[n][0] && a[m][1] < b[n][1])) {
                    // Only matrix a has a value at this position
                    c[k][0] = a[m][0];
                    c[k][1] = a[m][1];
                    c[k][2] = a[m][2];
                    m++;
                    k++;
                } else {
                    // Only matrix b has a value at this position
                    c[k][0] = b[n][0];
                    c[k][1] = b[n][1];
                    c[k][2] = b[n][2];
                    n++;
                    k++;
                }
            } else if (m <= a[0][2]) {
                // Only matrix a has remaining values
                c[k][0] = a[m][0];
                c[k][1] = a[m][1];
                c[k][2] = a[m][2];
                m++;
                k++;
            } else if (n <= b[0][2]) {
                // Only matrix b has remaining values
                c[k][0] = b[n][0];
                c[k][1] = b[n][1];
                c[k][2] = b[n][2];
                n++;
                k++;
            }
        }

        c[0][2] = k - 1; // Update the count of non-zero elements

        // Print the result sparse matrix
        printf("Sum of Sparse Matrices:\n");
        for (int i = 0; i <= c[0][2]; i++) {
            printf("%d %d %d\t", c[i][0], c[i][1], c[i][2]);
        }
        printf("\n");
    }
}

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

    printf("Enter the matrix elements for Matrix 2:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("Entered Matrix 2:\n");
    printmat(arr2, r, c);

    // Convert the matrices to sparse format
    sparse(arr1, t, r, c);
    sparse(arr2, b, r, c);

    // Add the sparse matrices
    add(t, b, cr);

    return 0;
}
