import javax.swing.*;
import java.awt.event.*;

public class Inn extends JFrame implements ActionListener {
    private JButton b1, b2, b3, b4;
    private JTextField t1, t2, t3, t4;
    private int p, n, r;
    private int res;

    public Inn(){
        // Set up the frame
        setSize(600, 480);
        setLayout(null);
        
        // Initialize text fields
        t1 = new JTextField();
        t1.setBounds(250, 100, 100, 30);
        t2 = new JTextField();
        t2.setBounds(250, 140, 100, 30);
        t3 = new JTextField();
        t3.setBounds(250, 180, 100, 30);
        t4 = new JTextField();
        t4.setBounds(250, 220, 100, 30);
        t4.setEditable(false);  // Make result field non-editable

        // Initialize buttons
        b1 = new JButton("Enter Principle");
        b1.setBounds(100, 100, 120, 30);
        b2 = new JButton("Enter Year");
        b2.setBounds(100, 140, 120, 30);
        b3 = new JButton("Enter Rate");
        b3.setBounds(100, 180, 120, 30);
        b4 = new JButton("Calculate");
        b4.setBounds(100, 220, 120, 30);

        // Add components to the frame
        add(t1);
        add(t2);
        add(t3);
        add(t4);
        add(b1);
        add(b2);
        add(b3);
        add(b4);

        // Add action listeners to buttons
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
    }

    // Action for calculating the simple interest
    public void doAction() {
        try {
            // Parse text field values into integers
            p = Integer.parseInt(t1.getText());
            n = Integer.parseInt(t2.getText());
            r = Integer.parseInt(t3.getText());

            // Calculate Simple Interest
            res = (p * n * r) / 100;

            // Display result in text field t4
            t4.setText(String.valueOf(res));
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Please enter valid numbers.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Handle button actions
        if (e.getSource() == b4) {
            doAction();
        }
    }

    // Main method to run the program
    public static void main(String[] args) {
        new Inn().setVisible(true);
    }
}
