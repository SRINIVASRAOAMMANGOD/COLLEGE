import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class TrafficLight extends JFrame implements ActionListener {
    private Color stop, start, go;
    private JRadioButton r1, r2, r3;

    public TrafficLight() {
        setSize(600, 480);
        setBounds(0, 0, 600, 480);
        setLayout(null);

        // Initialize the radio buttons
        r1 = new JRadioButton("Stop");
        r2 = new JRadioButton("Start");
        r3 = new JRadioButton("Go");

        // Group the radio buttons together so only one can be selected
        ButtonGroup group = new ButtonGroup();
        group.add(r1);
        group.add(r2);
        group.add(r3);

        // Set positions of radio buttons
        r1.setBounds(100, 350, 100, 30);
        r2.setBounds(220, 350, 100, 30);
        r3.setBounds(340, 350, 100, 30);

        // Add radio buttons to the JFrame
        add(r1);
        add(r2);
        add(r3);

        // Initially, no color is set for the lights, so set them to background color
        stop = getBackground();
        start = getBackground();
        go = getBackground();

        // Add listeners for each radio button
        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);

        // Set the background color of the JFrame
        setBackground(Color.BLACK);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Change the colors based on the selected radio button
        if (e.getSource() == r1) {
            stop = Color.RED;
            start = getBackground();
            go = getBackground();
        } else if (e.getSource() == r2) {
            start = Color.YELLOW;
            stop = getBackground();
            go = getBackground();
        } else if (e.getSource() == r3) {
            go = Color.GREEN;
            start = getBackground();
            stop = getBackground();
        }
        // Repaint the frame to update the traffic light colors
        repaint();
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);

        // Draw the three circles for the traffic light, but only if any button is pressed
        g.setColor(stop);
        g.fillOval(50, 50, 50, 50);  // Red light
        g.setColor(start);
        g.fillOval(50, 110, 50, 50); // Yellow light
        g.setColor(go);
        g.fillOval(50, 170, 50, 50);  // Green light
    }

    public static void main(String[] args) {
        new TrafficLight().setVisible(true);
    }
}
