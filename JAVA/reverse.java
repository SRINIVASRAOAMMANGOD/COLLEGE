import java.util.*;
class reverse{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter s");
        String s;
        s=sc.nextLine();
        String r="";
        for(int i=s.length()-1;i>=0;i--){
            r=r+s.charAt(i);
        }
        System.out.println(r);
    }
}