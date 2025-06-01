import javax.swing.*;
import java.awt.*;
import javax.imageio.ImageIO;
import java.io.IOException;

public class Maze extends JFrame {
    public static final int CELL_SIZE = 25;
    private int cols = 20, rows = 15;
    private MazePanel mazePanel;
    private JButton startBtn;
    private JTextField colsField, rowsField;

    public Maze() {
        setTitle("Maze generator");
        try {
            setIconImage(ImageIO.read(getClass().getResource("Icon.jpg")));
        } catch (IOException | IllegalArgumentException e) {
            System.out.println("Icon not found!");
        }

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        JPanel topPanel = new JPanel();
        topPanel.add(new JLabel("Width:"));
        colsField = new JTextField(String.valueOf(cols), 3);
        topPanel.add(colsField);
        topPanel.add(new JLabel("Height:"));
        rowsField = new JTextField(String.valueOf(rows), 3);
        topPanel.add(rowsField);

        startBtn = new JButton("Generate");
        topPanel.add(startBtn);

        mazePanel = new MazePanel(cols, rows, this);
        setLayout(new BorderLayout());
        add(topPanel, BorderLayout.NORTH);
        add(mazePanel, BorderLayout.CENTER);

        startBtn.addActionListener(e -> startGeneration());

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void startGeneration() {
        try {
            cols = Integer.parseInt(colsField.getText());
            rows = Integer.parseInt(rowsField.getText());
            mazePanel.setMazeSize(cols, rows);
            startBtn.setEnabled(false);
            new Thread(() -> mazePanel.generateMazeAnimated()).start();
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Enter valid integer.");
        }
    }

    public void enableButton() {
        startBtn.setEnabled(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Maze::new);
    }
}
