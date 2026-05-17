import java.util.Random;
 class RandonThread extends Thread{
 public void run(){
 try{
 Random r=new Random();
 for(int i=0;i<20;i++){
 int n=r.nextInt(100);
 //n will get a value between 0 and 100
 if(n%2==0)
 new Even(n).start();
 else
 new Odd(n).start();
 Thread.sleep(1000);
 }
 }catch(Exception e){
 System.out.println(e);
 }
 }
 }
 class Even extends Thread{
 private int num;
 public Even(int num){
 this.num=num;
 }
 public void run(){
 System.out.println("Square of "+num+" = "+num*num);
 }
 }
 class Odd extends Thread{
 private int num;
 public Odd(int num){
 this.num=num;
 }
 public void run(){
 System.out.println("Cube of "+num+" = "+num*num*num);
 }
 }
 class randomTest{
 public static void main(String[] args){
 RandonThread r=new RandonThread();
 r.start();
 }
 }