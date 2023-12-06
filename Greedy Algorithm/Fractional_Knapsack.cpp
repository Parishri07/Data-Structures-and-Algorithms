#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent each item
struct ItemValue {
    int profit, weight;

    ItemValue(int val, int wt) : profit(val), weight(wt) {}
};

// Function to get maximum value
double getMaxValue(vector<ItemValue>& arr, int capacity) {
    // Sorting items by profit/weight ratio
    sort(arr.begin(), arr.end(), [](const ItemValue& item1, const ItemValue& item2) {
        double cpr1 = static_cast<double>(item1.profit) / static_cast<double>(item1.weight);
        double cpr2 = static_cast<double>(item2.profit) / static_cast<double>(item2.weight);
        return cpr1 > cpr2;
    });

    double totalValue = 0.0;

    for (const ItemValue& i : arr) {
        int curWt = i.weight;
        int curVal = i.profit;

        if (capacity - curWt >= 0) {
            // This weight can be picked whole
            capacity -= curWt;
            totalValue += curVal;
        } else {
            // Item can't be picked whole
            double fraction = static_cast<double>(capacity) / static_cast<double>(curWt);
            totalValue += (curVal * fraction);
            capacity = 0;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<ItemValue> arr = {ItemValue(6, 1),
                            ItemValue(10, 2),
                            ItemValue(18, 4),
                            ItemValue(3, 1),
                            ItemValue(5, 3),
                            ItemValue(7, 7),
                            ItemValue(15, 5)};

    int capacity = 15;

    double maxValue = getMaxValue(arr, capacity);

    cout << maxValue << endl;

    return 0;
}
