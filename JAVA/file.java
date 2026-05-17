import java.io.FileWriter;
import java.util.Scanner;
public class file {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n;
        System.out.println("ENTER NUMBER:");
        n=sc.nextInt();
        try( FileWriter fileWriter= new FileWriter("output.txt")) {
           
            for(int i=0;i<10;i++){
                fileWriter.write(i +" * "+n+" = "+i*n +"\n");
              

            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
