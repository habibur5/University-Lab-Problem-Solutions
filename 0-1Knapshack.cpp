#include <bits/stdc++.h>
using namespace std;

// pair<weight, value>

int knapsack(int W, vector<pair<int, int>>& items, int n) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP Table
    for (int i = 1; i <= n; i++) {

        int weight = items[i - 1].first;
        int value = items[i - 1].second;

        for (int w = 0; w <= W; w++) {

            // If item can be taken
            if (weight <= w) {

                dp[i][w] = max(
                    value + dp[i - 1][w - weight],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print Selected Items
    cout << "\nSelected Items:\n";

    int w = W;

    for (int i = n; i > 0; i--) {

        // Item selected
        if (dp[i][w] != dp[i - 1][w]) {

            cout << "Item " << i
                 << " -> Weight = " << items[i - 1].first
                 << ", Value = " << items[i - 1].second
                 << endl;

            w = w - items[i - 1].first;
        }
    }

    return dp[n][W];
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<pair<int, int>> items(n);

    cout << "Enter weight and value:\n";

    for (int i = 0; i < n; i++) {

        cin >> items[i].first >> items[i].second;
    }

    cout << "Enter capacity: ";
    cin >> W;

    int result = knapsack(W, items, n);

    cout << "\nMaximum value = " << result << endl;

    return 0;
}