import java.util.Scanner;

public class MatrixMultiplication {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for the first matrix
        System.out.println("Enter the number of rows  for the first matrix:");
        int r1 = scanner.nextInt();
        System.out.println("Enter the number of columns or the first matrix:");
        int c1 = scanner.nextInt();
        
        int[][] firstMatrix = new int[r1][c1];
        System.out.println("Enter the elements of the first matrix");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                firstMatrix[i][j] = scanner.nextInt();
            }
        }

        // Input for the second matrix
        System.out.println("Enter the number of rows  for the second matrix:");
        int r2 = scanner.nextInt();
        
        System.out.println("Enter the number of columns for the second matrix:");
        int c2 = scanner.nextInt();

        if (c1 != r2) {
            System.out.println("Matrix multiplication is not possible. The number of columns of the first matrix must equal the number of rows of the second matrix.");
            return;
        }

        int[][] secondMatrix = new int[r2][c2];
        System.out.println("Enter the elements of the second matrix:");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                secondMatrix[i][j] = scanner.nextInt();
            }
        }

        // Matrix multiplication
        int[][] product = new int[r1][c2];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    product[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                }
            }
        }

        // Displaying the result
        System.out.println("Multiplication of two matrices is: ");
        for (int[] row : product) {
            for (int column : row) {
                System.out.print(column + "    ");
            }
            System.out.println();
        }
    }
}
