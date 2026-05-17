import java.io.*;
import java.util.Scanner;
public class fileboth {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n;
        System.out.println("ENTER NUMBER:");
        n=sc.nextInt();
        try( BufferedReader fileReader=new BufferedReader(new FileReader("output.txt"));
            BufferedWriter fileWriter= new BufferedWriter(new FileWriter("input.txt"))) {
                String line;
                while((line=fileReader.readLine())!=null){
                    fileWriter.write(line+"\n");
                }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
