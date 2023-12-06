#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int>& weights, vector<int>& profits, int capacity) {
    int n = weights.size();
    vector<vector<int>> T(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (weights[i - 1] <= j) {
                T[i][j] = max(T[i - 1][j], T[i - 1][j - weights[i - 1]] + profits[i - 1]);
            } else {
                T[i][j] = T[i - 1][j];
            }
        }
    }

    return T[n][capacity];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> profits(n);

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the profits of items: ";
    for (int i = 0; i < n; ++i) {
        cin >> profits[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int result = knapsack(weights, profits, capacity);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}
