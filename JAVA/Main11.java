// Method to reverse the bits of a given integer
public class Main11{
public static int reverseBits(int n) {
    int reversed = 0; // To store the reversed bits
    int totalBits = 32; // Total bits in an integer
    for (int i = 0; i < totalBits; i++) {
        // Shift reversed to the left to make space for the next bit
        reversed <<= 1;
        // Get the last bit of n and add it to reversed
        if ((n & 1) == 1) {
            reversed |= 1;
        }
        // Shift n to the right to process the next bit
        n >>= 1;
    }
    return reversed;
}

public static void main(String[] args) {
    int number = 43261596; // Example number
    System.out.println("Original number: " + number);
    int reversedNumber = reverseBits(number);
    System.out.println("Reversed bits: " + reversedNumber);
}
}