#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D table to store the maximum values for subproblems
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table dp[][] in bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right cell will have the maximum value
    return dp[n][W];
}

int main() {
    int n, W;
    
    // Input number of items and maximum weight capacity
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight capacity: ";
    cin >> W;

    vector<int> weights(n), values(n);

    // Input the weights and values of the items
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) cin >> weights[i];

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) cin >> values[i];

    // Solve the 0/1 Knapsack problem
    int maxValue = knapsack(W, weights, values, n);

    // Output the result
    cout << "Maximum value in Knapsack: " << maxValue << endl;

    return 0;
}
