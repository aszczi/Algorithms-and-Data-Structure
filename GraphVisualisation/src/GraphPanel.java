import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.List;

class GraphPanel extends JPanel {
    private List<Node> nodes;
    private List<Edge> edges;
    private static final int NODE_RADIUS = 20;

    public GraphPanel() {
        nodes = new ArrayList<>();
        edges = new ArrayList<>();
        setBackground(Color.WHITE);
    }

    public void loadGraph(BufferedReader reader) throws Exception {
        nodes.clear();
        edges.clear();


        int nodeCount = Integer.parseInt(reader.readLine());
        for (int i = 0; i < nodeCount; i++) {
            nodes.add(new Node(i));
        }

        String line;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split("\\s+");
            if (parts.length >= 2) {
                int from = Integer.parseInt(parts[0]);
                int to = Integer.parseInt(parts[1]);
                edges.add(new Edge(from, to));
            }
        }

        arrangeNodes();
        repaint();
    }

    private void arrangeNodes() {
        if (nodes.isEmpty()) return;

        // Circle Layout
        double centerX = 400;
        double centerY = 400;
        double radius = Math.min(350, 350 * nodes.size() / 10.0);
        double angleStep = 2 * Math.PI / nodes.size();

        for (int i = 0; i < nodes.size(); i++) {
            double angle = i * angleStep;
            nodes.get(i).x = centerX + radius * Math.cos(angle);
            nodes.get(i).y = centerY + radius * Math.sin(angle);
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        // Drawing edges
        g2.setColor(Color.BLACK);
        for (Edge e : edges) {
            Node from = nodes.get(e.from);
            Node to = nodes.get(e.to);

            //Calculating points on the circumference of the circles
            double dx = to.x - from.x;
            double dy = to.y - from.y;
            double length = Math.sqrt(dx*dx + dy*dy);
            dx /= length;
            dy /= length;

            double startX = from.x + dx * NODE_RADIUS;
            double startY = from.y + dy * NODE_RADIUS;
            double endX = to.x - dx * NODE_RADIUS;
            double endY = to.y - dy * NODE_RADIUS;

            g2.draw(new Line2D.Double(startX, startY, endX, endY));
        }

        //Drawing edges
        for (Node n : nodes) {

            Ellipse2D circle = new Ellipse2D.Double(n.x - NODE_RADIUS, n.y - NODE_RADIUS,
                    2 * NODE_RADIUS, 2 * NODE_RADIUS);
            g2.setColor(new Color(100, 150, 255));
            g2.fill(circle);
            g2.setColor(Color.BLACK);
            g2.draw(circle);

            //Edge label 
            String label = String.valueOf(n.id);
            FontMetrics fm = g2.getFontMetrics();
            int labelWidth = fm.stringWidth(label);
            int labelHeight = fm.getAscent();
            g2.drawString(label, (int)(n.x - labelWidth/2), (int)(n.y + labelHeight/4));
        }
    }

    @Override
    public Dimension getPreferredSize() {
        return new Dimension(800, 800);
    }
}