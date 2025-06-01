import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        String filename = "input.txt";
        int n = 0;
        int[] whereIsKey = null;

        //reading from the file
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line = br.readLine();
            n = Integer.parseInt(line.trim());
            whereIsKey = new int[n + 1]; //we ignore index 0

            for (int i = 1; i <= n; i++) {
                line = br.readLine();
                whereIsKey[i] = Integer.parseInt(line.trim());
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        // state[i] = 0  unvisited
        // state[i] = 1  visiting
        // state[i] = 2  processed
        int[] state = new int[n + 1];
        int cycles = 0;

        for (int i = 1; i <= n; i++) {
            if (state[i] == 0) {
                int u = i;
                // we search unvisited state
                while (state[u] == 0) {
                    state[u] = 1;           //visited
                    u = whereIsKey[u];
                }

                //if we have visited we have a new cycle
                if (state[u] == 1) {
                    cycles++;
                }
                // Now we backtrack through the current chain and mark it as processed,
                // until we clear all nodes that were in state == 1 in this iteration.
                int v = i;
                while (state[v] == 1) {
                    state[v] = 2;
                    v = whereIsKey[v];
                }
            }
        }

        System.out.println(cycles);
    }
}
