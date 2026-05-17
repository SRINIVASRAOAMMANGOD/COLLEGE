import java.io.*;

public class FileReadWriteExample {
    public static void main(String[] args) {
        String inputFilePath = "input.txt"; 
        String outputFilePath = "output.txt"; 

        try (
            BufferedReader bufferedReader = new BufferedReader(new FileReader(inputFilePath));
            BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(outputFilePath))
        ) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                bufferedWriter.write(line);
                bufferedWriter.newLine(); // Write a new line after each line read
            }
            System.out.println("File read and written successfully.");
        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found: " + e.getMessage());
        } catch (IOException e) {
            System.out.println("I/O error: " + e.getMessage());
        } catch (SecurityException e) {
            System.out.println("Security error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        }
    }
}
