import javax.swing.*;
import java.awt.*;

public class LCS {

    private JFrame frame;
    private JPanel tablePanel;
    private JTextArea resultArea;
    private JTextField textField1;
    private JTextField textField2;

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new LCS().createAndShowGUI());
    }

    // Method to create and display the GUI
    private void createAndShowGUI() {
        frame = new JFrame("Longest Common Subsequence (LCS) Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        // Input panel at the top
        JPanel inputPanel = new JPanel(new FlowLayout());
        inputPanel.add(new JLabel("String 1:"));
        textField1 = new JTextField(10);
        inputPanel.add(textField1);
        inputPanel.add(new JLabel("String 2:"));
        textField2 = new JTextField(10);
        inputPanel.add(textField2);
        JButton computeButton = new JButton("Compute LCS");
        inputPanel.add(computeButton);

        // Result area to display the LCS result
        resultArea = new JTextArea(3, 40);
        resultArea.setEditable(false);
        resultArea.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        // Table panel to display the dynamic programming table
        tablePanel = new JPanel();
        JScrollPane tableScrollPane = new JScrollPane(tablePanel);
        tableScrollPane.setPreferredSize(new Dimension(600, 400));

        // Add components to the frame
        frame.add(inputPanel, BorderLayout.NORTH);
        frame.add(tableScrollPane, BorderLayout.CENTER);
        frame.add(resultArea, BorderLayout.SOUTH);

        // Button action to compute LCS
        computeButton.addActionListener(e -> {
            String str1 = textField1.getText();
            String str2 = textField2.getText();
            computeLCS(str1, str2);
        });

        frame.pack();
        frame.setVisible(true);
    }

    // Method to compute the LCS and update the GUI
    private void computeLCS(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();
        int[][] dp = new int[m + 1][n + 1];
        JLabel[][] tableLabels = new JLabel[m + 1][n + 1]; // Store table cells

        // Reset the table panel
        tablePanel.removeAll();
        tablePanel.setLayout(new GridLayout(m + 2, n + 2)); // Update grid layout (+1 for characters)

        // Add the first empty cell at the top-left corner
        tablePanel.add(new JLabel("")); // Empty cell at the top-left corner

        // Add the characters of the second string (B) to the first row
        for (int j = 0; j <= n; j++) {
            if (j > 0) {
                tablePanel.add(new JLabel(String.valueOf(str2.charAt(j - 1)), SwingConstants.CENTER));
            } else {
                tablePanel.add(new JLabel("")); // Empty cell
            }
        }

        // Add the characters of the first string (A) to the first column and initialize dp table
        for (int i = 0; i <= m; i++) {
            if (i > 0) {
                tablePanel.add(new JLabel(String.valueOf(str1.charAt(i - 1)), SwingConstants.CENTER));
            } else {
                tablePanel.add(new JLabel("")); // Empty cell
            }

            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0; // Initialize dp table with 0s
                JLabel label = new JLabel("0", SwingConstants.CENTER);
                label.setBorder(BorderFactory.createLineBorder(Color.BLACK));
                tablePanel.add(label);
                tableLabels[i][j] = label; // Store the label for updating later
            }
        }

        // Fill the dp table and update the labels
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }

                // Update the label with the new value
                tableLabels[i][j].setText(String.valueOf(dp[i][j]));

                // Highlight cells contributing to the LCS
                if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1]) {
                    tableLabels[i][j].setBackground(Color.GREEN);
                    tableLabels[i][j].setOpaque(true);
                }
            }
        }

        // Revalidate and repaint the table after updating
        tablePanel.revalidate();
        tablePanel.repaint();

        // Backtrack to find the LCS
        StringBuilder lcs = new StringBuilder();
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                lcs.insert(0, str1.charAt(i - 1));
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        // Show the LCS result
        resultArea.setText("LCS: " + lcs.toString());
    }
}
