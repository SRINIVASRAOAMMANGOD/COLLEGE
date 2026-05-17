import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class QuickSortExample {
    
    // Method to perform quicksort
    public static void quickSort(String[] names, int low, int high) {
        if (low < high) {
            int pi = partition(names, low, high);
            quickSort(names, low, pi - 1);
            quickSort(names, pi + 1, high);
        }
    }

    // Method to partition the array
    private static int partition(String[] names, int low, int high) {
        String pivot = names[high];
        int i = (low - 1);
        
        for (int j = low; j < high; j++) {
            if (names[j].compareTo(pivot) <= 0) {
                i++;
                String temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
        
        String temp = names[i + 1];
        names[i + 1] = names[high];
        names[high] = temp;
        
        return i + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = 0;

        // Input validation for number of names
        while (true) {
            try {
                System.out.print("Enter the number of names: ");
                n = scanner.nextInt();
                scanner.nextLine(); // Consume the newline
                if (n > 0) {
                    break; // valid input
                } else {
                    System.out.println("Please enter a positive integer.");
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter an integer.");
                scanner.next(); // Clear the invalid input
            }
        }

        String[] names = new String[n];

        System.out.println("Enter the names:");
        for (int i = 0; i < n; i++) {
            names[i] = scanner.nextLine();
        }
        
        System.out.println("Original array: " + Arrays.toString(names));
        
        quickSort(names, 0, names.length - 1);
        
        System.out.println("Sorted array: " + Arrays.toString(names));
        
        scanner.close();
    }
}
