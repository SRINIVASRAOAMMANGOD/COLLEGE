import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TrafficLightSimulator extends JFrame {
    private JPanel redLight, yellowLight, greenLight;

    public TrafficLightSimulator() {
        setTitle("Traffic Light Simulator");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create light panels and set initial color to gray
        redLight = createLightPanel();
        yellowLight = createLightPanel();
        greenLight = createLightPanel();

        // Create a panel to hold the lights
        JPanel lightPanel = new JPanel();
        lightPanel.setLayout(new GridLayout(3, 1)); // 3 rows, 1 column
        lightPanel.add(redLight);
        lightPanel.add(yellowLight);
        lightPanel.add(greenLight);

        // Create radio buttons for light selection
        JRadioButton redButton = new JRadioButton("Red");
        JRadioButton yellowButton = new JRadioButton("Yellow");
        JRadioButton greenButton = new JRadioButton("Green");

        // Group the radio buttons so only one can be selected at a time
        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(redButton);
        buttonGroup.add(yellowButton);
        buttonGroup.add(greenButton);

        // Add action listeners using anonymous inner classes
        redButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setLightColor(Color.RED);
            }
        });

        yellowButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setLightColor(Color.YELLOW);
            }
        });

        greenButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setLightColor(Color.GREEN);
            }
        });

        // Create a panel for the radio buttons
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(redButton);
        buttonPanel.add(yellowButton);
        buttonPanel.add(greenButton);

        // Add panels to the frame
        add(lightPanel, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    // Create a light panel and set its initial color to gray
    private JPanel createLightPanel() {
        JPanel light = new JPanel();
        light.setBackground(Color.GRAY); // No light on
        light.setPreferredSize(new Dimension(200, 100));
        light.setOpaque(true);
        light.setBorder(BorderFactory.createLineBorder(Color.WHITE)); // Add border for visibility
        return light;
    }

    // Set the selected light color and reset others to gray
    private void setLightColor(Color color) {
        // Reset all lights to gray
        redLight.setBackground(Color.GRAY);
        yellowLight.setBackground(Color.GRAY);
        greenLight.setBackground(Color.GRAY);

        // Set the selected light to its color
        if (color == Color.RED) {
            redLight.setBackground(Color.RED);
        } else if (color == Color.YELLOW) {
            yellowLight.setBackground(Color.YELLOW);
        } else if (color == Color.GREEN) {
            greenLight.setBackground(Color.GREEN);
        }
    }

    public static void main(String[] args) {
        // Run the simulator in the Swing Event Dispatch Thread
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                TrafficLightSimulator simulator = new TrafficLightSimulator();
                simulator.setVisible(true); // Show the window
            }
        });
    }
}
