#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 70; // Knapsack capacity
    vector<int> wt = {10, 20, 30, 40}; // Item weights
    vector<int> val = {50, 60, 80, 130}; // Item values
    int n = wt.size(); // Number of items

    int maxVal = knapsack(W, wt, val, n);
    cout << "Maximum value: " << maxVal << endl;

    return 0;
}
