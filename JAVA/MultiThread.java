class PrintLetters extends Thread {
    public void run() {
        for (char letter = 'a'; letter <= 'j'; letter++) {
            System.out.print(letter + " ");
            try {
                Thread.sleep(1); 
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class PrintNumbers extends Thread {
    public void run() {
        for (int number = 1; number <= 10; number++) {
            System.out.print(number + " ");
            try {
                Thread.sleep(1); 
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class MultiThread extends Thread{
    public static void main(String[] args) {
        // Create instances of the threads
        PrintLetters letterThread = new PrintLetters();
        PrintNumbers numberThread = new PrintNumbers();

        // Start both threads
        letterThread.start();
        numberThread.start();
    }
}