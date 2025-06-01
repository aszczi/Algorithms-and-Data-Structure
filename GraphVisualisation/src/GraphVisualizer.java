import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.FileReader;

public class GraphVisualizer extends JFrame {
    private GraphPanel graphPanel;

    public GraphVisualizer() {
        setTitle("Graph Visualizer");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(850, 850);
        setLayout(new BorderLayout());

        graphPanel = new GraphPanel();
        add(new JScrollPane(graphPanel), BorderLayout.CENTER);

        try {
            BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
            graphPanel.loadGraph(reader);
            reader.close();
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Error loading file: " + ex.getMessage(),
                    "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            GraphVisualizer visualizer = new GraphVisualizer();
            visualizer.setVisible(true);
        });
    }
}
