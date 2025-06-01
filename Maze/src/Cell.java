public class Cell {
    int x, y;
    boolean[] walls = {true, true, true, true}; // top, right, bottom, left
    boolean visited = false;
    public Cell(int x, int y) { this.x = x; this.y = y; }
    public void removeWall(int dir) { walls[dir] = false; }
    public static int opposite(int dir) { return (dir + 2) % 4; }

}
