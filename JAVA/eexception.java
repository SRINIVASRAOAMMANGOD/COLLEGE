import java.util.Scanner;

class cu extends Exception {
    public cu() {
        // Custom exception constructor
        super("e entered"); // Providing a custom message to the exception
    }
}

public class eexception{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s;

        // Prompt user for input
        System.out.println("Enter a string:");
        s = sc.nextLine();
        
        boolean foundE = false; // Flag to track if 'e' is found

        // Iterate through the string
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            try {
                // Check if the character is 'e'
                if (c == 'e') {
                    throw new cu(); // Throw custom exception when 'e' is encountered
                }
            } catch (cu e) {
                // Catch the exception and print the message
                System.err.println(e.getMessage()); // Will print the message from super("e entered")
                foundE = true; // Mark that 'e' was found
                break; // Exit loop after the exception is thrown
            }
        }

        // Print "no e" if no 'e' was found
        if (!foundE) {
            System.out.println("No 'e' found.");
        }
    }
}
