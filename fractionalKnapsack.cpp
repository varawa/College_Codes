#include <iostream>
#include <vector>
#include <algorithm> // For sorting
using namespace std;

// A structure to represent an item with weight and value
struct Item {
    int value, weight;
    
    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Sort in descending order of ratio
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items based on value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0; // Maximum value that fits into the knapsack
    int currentWeight = 0; // Current weight in the knapsack

    // Loop through the sorted items
    for (int i = 0; i < items.size(); ++i) {
        // If the item can be added fully
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            maxValue += items[i].value;
        } 
        // If the item can only be added partially
        else {
            int remain = W - currentWeight;
            maxValue += items[i].value * ((double)remain / items[i].weight);
            break; // Knapsack is full, no more items can be added
        }
    }

    return maxValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<Item> items;
    cout << "Enter value and weight of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    double maxValue = fractionalKnapsack(W, items);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
