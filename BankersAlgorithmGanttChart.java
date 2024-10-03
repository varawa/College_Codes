import javax.swing.*;
import java.awt.*;
import java.util.*;

public class BankersAlgorithmGanttChart extends JPanel {
    private Map<String, Integer[]> processExecutionTimes;
    private int[][] allocation, max, need;
    private int[] available;
    private int numProcesses, numResources;
    private java.util.List<Integer> safeSequence;
    private int maxTime;

    public BankersAlgorithmGanttChart(Map<String, Integer[]> executionTimes, int[][] allocation, int[][] max, int[] available) {
        this.processExecutionTimes = executionTimes;
        this.allocation = allocation;
        this.max = max;
        this.numProcesses = allocation.length;
        this.numResources = allocation[0].length;
        this.available = available.clone();
        this.need = new int[numProcesses][numResources];
        this.safeSequence = new ArrayList<>();
        
        calculateNeed();
        calculateMaxTime();
        setPreferredSize(new Dimension(800, 600)); // Increased height to accommodate table
    }

    private void calculateNeed() {
        for (int i = 0; i < numProcesses; i++) {
            for (int j = 0; j < numResources; j++) {
                need[i][j] = max[i][j] - allocation[i][j];
                if (need[i][j] < 0) {
                    throw new IllegalArgumentException("Allocation exceeds maximum for process " + i + " and resource " + j);
                }
            }
        }
    }

    private void calculateMaxTime() {
        this.maxTime = processExecutionTimes.values().stream()
                .flatMap(Arrays::stream)
                .max(Integer::compare)
                .orElse(10);
    }

    private boolean isSafe(int processId, int[] work) {
        for (int i = 0; i < numResources; i++) {
            if (need[processId][i] > work[i]) {
                return false;
            }
        }
        return true;
    }

    public boolean runBankersAlgorithm() {
        boolean[] finished = new boolean[numProcesses];
        int[] work = available.clone();
        int completedProcesses = 0;

        while (completedProcesses < numProcesses) {
            boolean foundSafeProcess = false;
            for (int i = 0; i < numProcesses; i++) {
                if (!finished[i] && isSafe(i, work)) {
                    for (int j = 0; j < numResources; j++) {
                        work[j] += allocation[i][j];
                    }
                    safeSequence.add(i);
                    finished[i] = true;
                    completedProcesses++;
                    foundSafeProcess = true;
                }
            }
            if (!foundSafeProcess) {
                return false;
            }
        }
        return true;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2d.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);

        int startX = 100;
        int startY = 80;
        int processHeight = 40;
        int timeUnitWidth = Math.min(60, (getWidth() - 150) / (maxTime + 1));

        // Draw title
        g2d.setFont(new Font("Arial", Font.BOLD, 24));
        g2d.setColor(new Color(44, 62, 80));
        g2d.drawString("Banker's Algorithm Visualization", getWidth() / 2 - 150, 40);

        // Draw Gantt Chart
        drawGanttChart(g2d, startX, startY, processHeight, timeUnitWidth);

        // Draw Resource Table
        drawResourceTable(g2d, startX, startY + (numProcesses * (processHeight + 20)) + 60);
    }

    private void drawGanttChart(Graphics2D g2d, int startX, int startY, int processHeight, int timeUnitWidth) {
        g2d.setFont(new Font("Arial", Font.PLAIN, 14));
        int yPosition = startY;
        Color[] colors = {new Color(231, 76, 60), new Color(52, 152, 219), new Color(46, 204, 113), 
                          new Color(155, 89, 182), new Color(241, 196, 15)};
        int colorIndex = 0;

        for (Map.Entry<String, Integer[]> entry : processExecutionTimes.entrySet()) {
            String processName = entry.getKey();
            Integer[] timeRange = entry.getValue();

            int start = Math.min(timeRange[0], timeRange[1]);
            int end = Math.max(timeRange[0], timeRange[1]);
            int executionLength = end - start;

            // Draw process name
            g2d.setColor(new Color(44, 62, 80));
            g2d.drawString(processName, startX - 80, yPosition + processHeight / 2 + 5);

            // Draw process execution bar
            g2d.setColor(colors[colorIndex % colors.length]);
            g2d.fillRoundRect(startX + (start * timeUnitWidth), yPosition, executionLength * timeUnitWidth, processHeight, 15, 15);

            // Draw process time range
            g2d.setColor(Color.WHITE);
            String timeText = start + " - " + end;
            FontMetrics fm = g2d.getFontMetrics();
            int textWidth = fm.stringWidth(timeText);
            int textX = startX + (start * timeUnitWidth) + (executionLength * timeUnitWidth / 2) - (textWidth / 2);
            g2d.drawString(timeText, textX, yPosition + processHeight / 2 + 5);

            yPosition += processHeight + 20;
            colorIndex++;
        }

        // Draw time units (horizontal axis)
        g2d.setColor(new Color(44, 62, 80));
        g2d.drawLine(startX, yPosition, startX + (maxTime + 1) * timeUnitWidth, yPosition);
        for (int i = 0; i <= maxTime; i++) {
            int x = startX + i * timeUnitWidth;
            g2d.drawLine(x, yPosition, x, yPosition + 5);
            g2d.drawString(Integer.toString(i), x - 5, yPosition + 20);
        }
    }

    private void drawResourceTable(Graphics2D g2d, int startX, int startY) {
        g2d.setFont(new Font("Arial", Font.BOLD, 16));
        g2d.setColor(new Color(44, 62, 80));
        g2d.drawString("Resource Allocation Table", startX, startY);

        g2d.setFont(new Font("Arial", Font.PLAIN, 14));
        int rowHeight = 25;
        int colWidth = 120;

        String[] headers = {"Process", "Allocation", "Max", "Need", "Available"};
        for (int i = 0; i < headers.length; i++) {
            g2d.drawString(headers[i], startX + i * colWidth, startY + rowHeight);
        }

        for (int i = 0; i < numProcesses; i++) {
            g2d.drawString("P" + i, startX, startY + (i + 2) * rowHeight);
            g2d.drawString(Arrays.toString(allocation[i]), startX + colWidth, startY + (i + 2) * rowHeight);
            g2d.drawString(Arrays.toString(max[i]), startX + 2 * colWidth, startY + (i + 2) * rowHeight);
            g2d.drawString(Arrays.toString(need[i]), startX + 3 * colWidth, startY + (i + 2) * rowHeight);
            if (i == 0) {
                g2d.drawString(Arrays.toString(available), startX + 4 * colWidth, startY + (i + 2) * rowHeight);
            }
        }

        // Draw total row
        g2d.setFont(new Font("Arial", Font.BOLD, 14));
        int totalRowY = startY + (numProcesses + 2) * rowHeight;
        g2d.drawString("Total", startX, totalRowY);
        g2d.drawString(sumArray(allocation), startX + colWidth, totalRowY);
        g2d.drawString(sumArray(max), startX + 2 * colWidth, totalRowY);
        g2d.drawString(sumArray(need), startX + 3 * colWidth, totalRowY);
    }

    private String sumArray(int[][] array) {
        int[] sum = new int[array[0].length];
        for (int[] row : array) {
            for (int i = 0; i < row.length; i++) {
                sum[i] += row[i];
            }
        }
        return Arrays.toString(sum);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            try {
                runBankersAlgorithmSimulation();
            } catch (Exception e) {
                JOptionPane.showMessageDialog(null, "An error occurred: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
    }

    private static void runBankersAlgorithmSimulation() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int numProcesses = readPositiveInt(scanner);
        System.out.print("Enter the number of resources: ");
        int numResources = readPositiveInt(scanner);

        int[][] allocation = readMatrix(scanner, numProcesses, numResources, "allocation");
        int[][] max = readMatrix(scanner, numProcesses, numResources, "max");
        int[] available = readArray(scanner, numResources, "available resources");

        Map<String, Integer[]> executionTimes = new HashMap<>();
        for (int i = 0; i < numProcesses; i++) {
            System.out.println("Enter the start and end time for process P" + i + " (e.g., 0 2): ");
            int start = readNonNegativeInt(scanner);
            int end = readNonNegativeInt(scanner);
            if (start > end) {
                throw new IllegalArgumentException("Start time must be less than or equal to end time for process P" + i);
            }
            executionTimes.put("P" + i, new Integer[]{start, end});
        }

        BankersAlgorithmGanttChart chart = new BankersAlgorithmGanttChart(executionTimes, allocation, max, available);
        
        if (chart.runBankersAlgorithm()) {
            System.out.println("Safe sequence found: " + chart.safeSequence);
            
            JFrame frame = new JFrame("Banker's Algorithm Visualization");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.add(chart);
            frame.pack();
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        } else {
            System.out.println("No safe sequence found.");
        }

        scanner.close();
    }

    private static int readPositiveInt(Scanner scanner) {
        int value = scanner.nextInt();
        if (value <= 0) {
            throw new IllegalArgumentException("Value must be positive");
        }
        return value;
    }

    private static int readNonNegativeInt(Scanner scanner) {
        int value = scanner.nextInt();
        if (value < 0) {
            throw new IllegalArgumentException("Value must be non-negative");
        }
        return value;
    }

    private static int[][] readMatrix(Scanner scanner, int rows, int cols, String matrixName) {
        System.out.println("Enter the " + matrixName + " matrix:");
        int[][] matrix = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            System.out.println("Process " + i + " " + matrixName + ": ");
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = readNonNegativeInt(scanner);
            }
        }
        return matrix;
    }

    private static int[] readArray(Scanner scanner, int size, String arrayName) {
        System.out.println("Enter the " + arrayName + ":");
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = readNonNegativeInt(scanner);
        }
        return array;
    }
}