import java.util.Scanner;

public class LinearSearchExample {
    public static void main(String[] args) {
        // Define an array of integers
        //int[] array = {3, 5, 7, 9, 11, 13, 15};
         Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements you want to store: ");
        int n = sc.nextInt();
        
        // Create an array with the specified number of elements
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        // Define the target value to search for
         System.out.print("ENTER THE KEY ELEMENT:");
        int target = sc.nextInt();
        
        
        // Perform linear search
        int result = linearSearch(array, target);
        
        // Print the result
        if (result == -1) {
            System.out.println("KEY " + target + " not found in the array.");
        } else {
            System.out.println("KEY " + target + " found at index " + result + ".");
        }
    }

    // Method to perform Linear Search
    public static int linearSearch(int[] array, int target) {
        // Traverse through all array elements
        for (int i = 0; i < array.length; i++) {
            if (array[i] == target) {
                return i; // Return the index of the target value
            }
        }
        return -1; // Return -1 if target is not found
    }
}
