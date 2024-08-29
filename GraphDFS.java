import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import java.util.concurrent.ExecutionException;

public class GraphDFS extends JFrame {
    private JPanel panel;
    private JTextArea textArea;
    private JTextArea edgesInput;
    private JButton dfsButton;
    private JButton initializeGraphButton;
    private JTextField nodesInput;
    private JLabel instructionsLabel;
    private java.util.Map<Integer, java.util.List<Integer>> graph;
    private boolean[] visited;

    public GraphDFS() {
        setTitle("DFS Graph Traversal Visualization");
        setSize(700, 700);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        panel = new JPanel() {
            public void paintComponent(Graphics g) {
                super.paintComponent(g);
                drawGraph(g);
            }
        };
        
        // Set up layout and GUI elements
        panel.setBackground(Color.WHITE);
        panel.setPreferredSize(new Dimension(500, 400));
        
        textArea = new JTextArea(5, 50);
        edgesInput = new JTextArea(5, 50); // Input for edges
        nodesInput = new JTextField(10); // Input for number of nodes
        dfsButton = new JButton("Start DFS");
        initializeGraphButton = new JButton("Initialize Graph");

        instructionsLabel = new JLabel("<html>Enter the number of nodes, and the edges in the format 'u v' (one per line):<br>"
                                       + "Example: 0 1<br>1 2<br>2 3<br>Type '-1 -1' to stop adding edges.<br><br></html>");

        // Organize the top panel for inputs
        JPanel topPanel = new JPanel();
        topPanel.setLayout(new BoxLayout(topPanel, BoxLayout.Y_AXIS));
        topPanel.add(new JLabel("Number of Nodes:"));
        topPanel.add(nodesInput);
        topPanel.add(new JLabel("Edges (format: u v, one per line):"));
        topPanel.add(new JScrollPane(edgesInput));
        topPanel.add(initializeGraphButton);
        topPanel.add(dfsButton);
        
        add(instructionsLabel, BorderLayout.NORTH);
        add(panel, BorderLayout.CENTER);
        add(new JScrollPane(textArea), BorderLayout.SOUTH);
        add(topPanel, BorderLayout.EAST);

        // Add tooltips for extra clarity
        nodesInput.setToolTipText("Enter the total number of nodes in the graph.");
        edgesInput.setToolTipText("Enter each edge as two space-separated nodes, one edge per line. Example: '0 1'.");

        // Action listener for initializing the graph
        initializeGraphButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                initializeGraphFromUserInput();
            }
        });

        // Action listener for starting DFS
        dfsButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                startDFSVisualization();
            }
        });

        graph = new java.util.HashMap<>();
    }

    private void initializeGraphFromUserInput() {
        try {
            int nodes = Integer.parseInt(nodesInput.getText().trim());
            graph.clear();

            // Initialize graph nodes
            for (int i = 0; i < nodes; i++) {
                graph.put(i, new java.util.ArrayList<>());
            }

            // Read edges from the text area
            String[] lines = edgesInput.getText().split("\\n");
            for (String line : lines) {
                String[] parts = line.trim().split("\\s+");
                int u = Integer.parseInt(parts[0]);
                int v = Integer.parseInt(parts[1]);

                if (!graph.containsKey(u)) {
                    graph.put(u, new java.util.ArrayList<>());
                }
                if (!graph.containsKey(v)) {
                    graph.put(v, new java.util.ArrayList<>());
                }
                graph.get(u).add(v);
                graph.get(v).add(u);
            }

            // Initialize visited array
            visited = new boolean[graph.size()];
            JOptionPane.showMessageDialog(this, "Graph initialized successfully!");

        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter valid input for nodes and edges.");
        }
    }

    private void startDFSVisualization() {
        if (graph.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Graph is not initialized.");
            return;
        }

        java.util.Arrays.fill(visited, false);
        textArea.setText("");

        SwingWorker<Void, Integer> worker = new SwingWorker<>() {
            protected Void doInBackground() {
                dfs(0);
                return null;
            }

            private void dfs(int node) {
                visited[node] = true;
                publish(node);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                for (int neighbor : graph.get(node)) {
                    if (!visited[neighbor]) {
                        dfs(neighbor);
                    }
                }
            }

            protected void process(List<Integer> chunks) {
                for (int node : chunks) {
                    textArea.append("Visited node: " + node + "\n");
                    panel.repaint();
                }
            }

            protected void done() {
                try {
                    get();
                } catch (InterruptedException | ExecutionException e) {
                    e.printStackTrace();
                }
            }
        };

        worker.execute();
    }

    private void drawGraph(Graphics g) {
        int radius = 20;
        int centerX = panel.getWidth() / 2;
        int centerY = panel.getHeight() / 2;
        int graphSize = graph.size();
        int angleStep = 360 / graphSize;

        java.util.Map<Integer, Point> nodePositions = new java.util.HashMap<>();
        for (int i = 0; i < graphSize; i++) {
            int angle = i * angleStep;
            int x = (int) (centerX + 200 * Math.cos(Math.toRadians(angle)));
            int y = (int) (centerY + 200 * Math.sin(Math.toRadians(angle)));
            nodePositions.put(i, new Point(x, y));

            g.setColor(visited[i] ? Color.RED : Color.PINK);
            g.fillOval(x - radius / 2, y - radius / 2, radius, radius);
            g.setColor(Color.BLACK);
            g.drawString(String.valueOf(i), x - 5, y + 5);
        }

        g.setColor(Color.BLUE);
        for (int u : graph.keySet()) {
            for (int v : graph.get(u)) {
                Point p1 = nodePositions.get(u);
                Point p2 = nodePositions.get(v);
                g.drawLine(p1.x, p1.y, p2.x, p2.y);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new GraphDFS().setVisible(true));
    }
}
