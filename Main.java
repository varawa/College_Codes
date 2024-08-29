import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Main extends JFrame{
    private static final int NODE_SIZE = 40;
    private int nodeCounter = 0;
    private final ArrayList<Node> nodes = new ArrayList<>();
    private final ArrayList<Edge> edges = new ArrayList<>();
    private Node selectedNode = null;
    private boolean isTraversalRunning = false;

    public Main(){
        setTitle("Graph DFS traversal");
        setSize(800, 700); 
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        GraphPanel graphPanel = new GraphPanel();
        add(graphPanel, BorderLayout.CENTER);

        JPanel controlPanel = new JPanel();
        JButton addNodeBtn = new JButton("Add Node");
        JButton addEdgeBtn = new JButton("Connect Nodes");
        JButton startDfsBtn = new JButton("Start DFS");
        
        controlPanel.add(addNodeBtn);
        controlPanel.add(addEdgeBtn);
        controlPanel.add(startDfsBtn);
        add(controlPanel, BorderLayout.NORTH);

        addNodeBtn.addActionListener(e -> graphPanel.addNode());
        addEdgeBtn.addActionListener(e -> graphPanel.addEdge());
        startDfsBtn.addActionListener(e -> {
            if (!nodes.isEmpty() && !isTraversalRunning) {
                isTraversalRunning = true;
                new Thread(this::startDFS).start();
            }
        });
    }

    private void startDFS() {
        resetNodes();
        
            dfs(nodes.get(0));

        isTraversalRunning = false;
    }


    private void dfs(Node node) {
        node.setVisited(true);
        
        repaint();
        try{
            Thread.sleep(1000);

        }catch(InterruptedException e){
            e.printStackTrace();
        }

        for (Edge edge : edges) {
            Node neighbor = null;
            if (edge.getFromNode() == node && !edge.getToNode().isVisited()) {
                neighbor = edge.getToNode();
            } else if (edge.getToNode() == node && !edge.getFromNode().isVisited()) {
                neighbor = edge.getFromNode();
            }
            if (neighbor != null) {
                dfs(neighbor);
            }
        }
    }

    private void resetNodes() {
        for (Node node : nodes) {
            node.setVisited(false);
        }
        repaint();
    }

    class GraphPanel extends JPanel {
        public GraphPanel() {
            addMouseListener(new MouseAdapter() {
                @Override
                public void mousePressed(MouseEvent e) {
                    if (!isTraversalRunning) {
                        selectOrAddNode(e.getX(), e.getY());
                    }
                }
            });
        }

        public void addNode() {
            JOptionPane.showMessageDialog(null, "Click anywhere to create a new node.");
        }

        public void addEdge() {
            if (selectedNode != null) {
                JOptionPane.showMessageDialog(null, "Now, select node to create a connection.");
            } else {
                JOptionPane.showMessageDialog(null, "First, select node to link.");
            }
        }

        private void selectOrAddNode(int x, int y) {
            for (Node node : nodes) {
                if (node.contains(x, y)) {
                    if (selectedNode == null) {
                        selectedNode = node;
                        node.setSelected(true);
                    } else {
                        if (selectedNode != node) {
                            edges.add(new Edge(selectedNode, node));
                        }
                        selectedNode.setSelected(false);
                        selectedNode = null;
                    }
                    repaint();
                    return;
                }
            }
            
            nodes.add(new Node(x, y, "Node" + nodeCounter++));
            
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            for (Edge edge : edges) {
                Node fromNode = edge.getFromNode();
                Node toNode = edge.getToNode();
                g.setColor(Color.BLACK);
                g.drawLine(fromNode.getX(), fromNode.getY(), toNode.getX(), toNode.getY());
            }

            for (Node node : nodes) {
                if (node.isVisited()) {
                    g.setColor(Color.BLUE);
                } else if (node.isSelected()) {
                    g.setColor(Color.GREEN);
                } else {
                    g.setColor(Color.YELLOW);
                }
                g.fillOval(node.getX() - NODE_SIZE / 2, node.getY() - NODE_SIZE / 2, NODE_SIZE, NODE_SIZE);
                g.setColor(Color.BLACK);
                g.drawString(node.getLabel(), node.getX() - 10, node.getY() - NODE_SIZE / 2 - 5);
            }
        }
    }

    static class Node {
        private int x, y;
        private final String label;
        private boolean visited;
        private boolean selected;

        public Node(int x, int y, String label) {
            this.x = x;
            this.y = y;
            this.label = label;
            this.visited = false;
            this.selected = false;
        }

        public int getX() { return x; }
        public void setX(int x) { this.x = x; }
        public int getY() { return y; }
        public void setY(int y) { this.y = y; }
        public String getLabel() { return label; }
        public boolean isVisited() { return visited; }
        public void setVisited(boolean visited) { this.visited = visited; }
        public boolean isSelected() { return selected; }
        public void setSelected(boolean selected) { this.selected = selected; }
        public boolean contains(int x, int y) {
            return Math.sqrt(Math.pow(x - this.x, 2) + Math.pow(y - this.y, 2)) <= NODE_SIZE / 2.0;
        }
    }

    static class Edge {
        private final Node fromNode, toNode;

        public Edge(Node fromNode, Node toNode) {
            this.fromNode = fromNode;
            this.toNode = toNode;
        }

        public Node getFromNode() { return fromNode; }
        public Node getToNode() { return toNode; }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new Main().setVisible(true));
    }
}
