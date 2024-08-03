import java.util.Scanner;

public class ArrayInputAndDuplicateCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number of elements
        System.out.print("Enter the number of elements you want to store: ");
        int n = sc.nextInt();
        
        // Create an array with the specified number of elements
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        
        // Print array elements
        System.out.println("Array elements are: ");
        for (int i = 0; i < n; i++) {
            System.out.println(array[i]);
        }
        
//int [] arr = new int [] {1, 2, 3, 4, 2, 7, 8, 8, 3};   
          
        System.out.println("Duplicate elements in given array: ");  
        //Searches for duplicate element  
        for(int i = 0; i < array.length; i++) {  
            for(int j = i + 1; j < array.length; j++) {  
                if(array[i] == array[j])  
                    System.out.println(array[j]);  
            }  
        }  
    }  
    }

