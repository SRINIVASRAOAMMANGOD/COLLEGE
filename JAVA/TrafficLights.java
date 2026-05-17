import javax.swing.*;  
import java.awt.*;  
import java.awt.event.*;  
class TrafficLight extends JPanel implements ActionListener {  
    private JRadioButton r1;  
    private JRadioButton r2;  
    private JRadioButton r3;  
    private Color stop_c;  
    private Color go_c;  
    private Color ready_c;  
    public TrafficLight() {  
        setBounds(0, 0, 600, 480);  
        r1 = new JRadioButton("Stop");  
        r2 = new JRadioButton("Go");  
        r3 = new JRadioButton("Ready");  
        ButtonGroup group = new ButtonGroup(); // javax.swing package  
        r1.setSelected(false);  
        group.add(r1); // Add radio button to group  
        group.add(r2);  
        group.add(r3); // Only one radio button selected at a time  
        add(r1);  
        add(r2);  
        add(r3); // Added to JPanel  
         
        // Initialize colors to background color 
        stop_c = getBackground();  
        go_c = getBackground();  
        ready_c = getBackground();  
        r1.addActionListener(this); // This class implements ActionListener  
        r2.addActionListener(this);  
        r3.addActionListener(this);  
    }  
    public void actionPerformed(ActionEvent e) {  
        if (r1.isSelected()) {  
            stop_c = Color.red;  
            go_c = getBackground();  
            ready_c = getBackground();  
        } else if (r2.isSelected()) {  
            stop_c = getBackground();  
            go_c = Color.green;  
            ready_c = getBackground();  
        } else if (r3.isSelected()) {  
            stop_c = getBackground();  
            go_c = getBackground();  
            ready_c = Color.orange;  
        }  
        repaint();  
    }  
    public void paintComponent(Graphics g) { // Called by repaint()  
        super.paintComponent(g); // Do this before going for custom painting  
        // Draw the traffic light circles 
        g.drawOval(50, 50, 50, 50);  
        g.drawOval(50, 110, 50, 50);  
        g.drawOval(50, 170, 50, 50);  
         
        // Fill the ovals based on the current color states 
        g.setColor(stop_c);  
        g.fillOval(50, 50, 50, 50);  
        g.setColor(ready_c);  
        g.fillOval(50, 110, 50, 50);  
        g.setColor(go_c);  
        g.fillOval(50, 170, 50, 50); // At a time one color  
    }  
}  
class TestTraffic {  
    public static void main(String args[]) {  
        JFrame f1 = new JFrame();  
        f1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close the application 
        f1.setVisible(true);  
        f1.setSize(600, 480);  
        f1.setLayout(null);  
        TrafficLight t = new TrafficLight();  
        f1.add(t);  
    }  
} 