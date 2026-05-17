import java.util.Scanner;

public class DiagonalSum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input the size of the matrix
        System.out.print("Enter the size of the matrix (n x n): ");
        int n = scanner.nextInt();
        
        int[][] matrix = new int[n][n];
        
        // Input matrix elements
        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        int diagonalSum = 0;

        // Loop to sum the diagonal elements
        for (int i = 0; i < n; i++) {
            diagonalSum += matrix[i][i]; // Main diagonal (top-left to bottom-right)
            
            
        }

        // Output the result
        System.out.println("Sum of diagonal elements: " + diagonalSum);

        scanner.close();
    }
}
