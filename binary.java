
import java.util.Scanner;
public class BinarySearch {

    // Method to perform binary search
    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if the target is at mid
            if (array[mid] == target) {
                return mid;
            }

            // If target is greater, ignore left half
            if (array[mid] < target) {
                left = mid + 1;
            } else { // If target is smaller, ignore right half
                right = mid - 1;
            }
        }

        // Target is not present in the array
        return -1;
    }

    // Main method to test the binary search
    public static void main(String[] args) {
        // Example sorted array
      //  int[] sortedArray = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
          Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements you want to store: ");
        int n = sc.nextInt();
        
        // Create an array with the specified number of elements
        int[] array = new int[n];
        System.out.println("Enter the elements of the array in sorted order: ");
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        // Example target values to search for
       System.out.print("ENTER THE KEY ELEMENT:");
        int target = sc.nextInt();

        // Perform binary search
        int result = binarySearch(array, target);

        // Output the result
        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found in the array.");
        }
    }
}
