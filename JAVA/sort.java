import java.util.Scanner;

public class ArraySorter {
    public static void main(String[] args) {
        // Define an array of integers
        //int[] array = {64, 25, 12, 22, 11};
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements you want to store: ");
        int n = sc.nextInt();
        
        // Create an array with the specified number of elements
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        // Print the array before sorting
        System.out.println("Array before sorting:");
        printArray(array);

        // Sort the array in ascending order using Selection Sort
        selectionSort(array);

        // Print the array after sorting
        System.out.println("Array after sorting:");
        printArray(array);
    }

    // Method to perform Selection Sort
    public static void selectionSort(int[] array) {
        int n = array.length;
        // Traverse through all array elements
        for (int i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted portion of array
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap the found minimum element with the first element
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }

    // Method to print the array
    public static void printArray(int[] array) {
        for (int value : array) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}
