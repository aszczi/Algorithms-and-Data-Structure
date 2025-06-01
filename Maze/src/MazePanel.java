import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.util.List;

public class MazePanel extends JPanel {
    private int cols, rows;
    private Cell[][] grid;
    private Stack<Cell> stack = new Stack<>();
    private Cell currentCell = null;
    private Maze parent;

    public MazePanel(int cols, int rows, Maze parent) {
        this.parent = parent;
        setMazeSize(cols, rows);
        setBackground(Color.WHITE);
    }

    public void setMazeSize(int c, int r) {
        this.cols = c;
        this.rows = r;
        grid = new Cell[rows][cols];
        for (int y = 0; y < rows; y++)
            for (int x = 0; x < cols; x++)
                grid[y][x] = new Cell(x, y);
        setPreferredSize(new Dimension(cols * Maze.CELL_SIZE + 2, rows * Maze.CELL_SIZE + 2));
        revalidate();
        repaint();
        if (parent != null) parent.pack(); // <-- KLUCZOWA LINIA!
    }

    public void generateMazeAnimated() {
        for (Cell[] row : grid)
            for (Cell cell : row)
                cell.visited = false;
        stack.clear();

        List<Cell> edges = Arrays.asList(
                grid[0][new Random().nextInt(cols)],
                grid[rows-1][new Random().nextInt(cols)],
                grid[new Random().nextInt(rows)][0],
                grid[new Random().nextInt(rows)][cols-1]
        );
        Cell start = edges.get(new Random().nextInt(edges.size()));
        currentCell = start;
        stack.push(start);
        start.visited = true;
        repaint();

        while (!stack.isEmpty()) {
            Cell cell = stack.peek();
            currentCell = cell;
            List<CellDir> unvisited = getUnvisitedNeighbors(cell);
            if (!unvisited.isEmpty()) {
                CellDir picked = unvisited.get(new Random().nextInt(unvisited.size()));
                cell.removeWall(picked.dir);
                picked.cell.removeWall(Cell.opposite(picked.dir));
                picked.cell.visited = true;
                stack.push(picked.cell);
            } else {
                stack.pop();
            }
            repaint();
            try {
                Thread.sleep(30);
            } catch (InterruptedException ignored) {}
        }
        currentCell = null;
        repaint();
        SwingUtilities.invokeLater(() -> parent.enableButton());
    }

    private List<CellDir> getUnvisitedNeighbors(Cell cell) {
        List<CellDir> nbs = new ArrayList<>();
        int x = cell.x, y = cell.y;
        if (y > 0 && !grid[y-1][x].visited) nbs.add(new CellDir(grid[y-1][x], 0));
        if (x < cols-1 && !grid[y][x+1].visited) nbs.add(new CellDir(grid[y][x+1], 1));
        if (y < rows-1 && !grid[y+1][x].visited) nbs.add(new CellDir(grid[y+1][x], 2));
        if (x > 0 && !grid[y][x-1].visited) nbs.add(new CellDir(grid[y][x-1], 3));
        return nbs;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                Cell cell = grid[y][x];
                int xx = x * Maze.CELL_SIZE;
                int yy = y * Maze.CELL_SIZE;

                // entry/finish color
                if ((y == 0 && x == 0) || (y == rows-1 && x == cols-1)) {
                    g.setColor((y == 0 && x == 0) ? Color.GREEN : Color.RED);
                    g.fillRect(xx+2, yy+2, Maze.CELL_SIZE-3, Maze.CELL_SIZE-3);
                }

                // Current cell
                if (cell == currentCell) {
                    g.setColor(Color.BLUE);
                    g.fillRect(xx+3, yy+3, Maze.CELL_SIZE-6, Maze.CELL_SIZE-6);
                }

                g.setColor(Color.BLACK);

                if (cell.walls[0])      // Top
                    g.drawLine(xx, yy, xx + Maze.CELL_SIZE, yy);

                if (cell.walls[1])      // Right
                    g.drawLine(xx + Maze.CELL_SIZE, yy, xx + Maze.CELL_SIZE, yy + Maze.CELL_SIZE);

                if (cell.walls[2])      // Bottom
                    g.drawLine(xx, yy + Maze.CELL_SIZE, xx + Maze.CELL_SIZE, yy + Maze.CELL_SIZE);

                if (cell.walls[3])      // Left
                    g.drawLine(xx, yy, xx, yy + Maze.CELL_SIZE);
            }
        }
    }

    class CellDir {
        Cell cell; int dir;
        CellDir(Cell cell, int dir) { this.cell = cell; this.dir = dir; }
    }
}
