#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// pair<value, weight>

bool compare(pair<int, int> a, pair<int, int> b) {

    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;

    return r1 > r2;
}

double fractionalKnapsack(vector<pair<int, int>> items, int capacity) {

    // Sort by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;

    cout << "Selected Items:\n";

    for (auto item : items) {

        int value = item.first;
        int weight = item.second;

        double take = min(capacity, weight);   // Weight taken
        
        totalValue += ((double)value / weight) * take;

        cout << "Value = " << value
            << ", Weight = " << weight;

        if (take == weight)
            cout << " (Fully Taken)";
        else
            cout << ", Fraction Taken = " << take / weight;

        cout << endl;

        capacity -= take;

        if (capacity <= 0)
            break;
    }

    return totalValue;
}

int main() {

    vector<pair<int, int>> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int capacity = 50;

    double ans = fractionalKnapsack(items, capacity);

    cout << "\nMaximum value = " << ans << endl;

    return 0;
}