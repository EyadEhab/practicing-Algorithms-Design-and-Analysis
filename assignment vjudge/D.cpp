#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(const vector<vector<int>>& items, int maxWeight) {
    vector<int> dp(maxWeight + 1, 0);

    for (const auto& item : items) {
        for (int w = maxWeight; w >= item[1]; --w) {
            dp[w] = max(dp[w], dp[w - item[1]] + item[0]);// prive item[0] weight item[1]
        }
    }

    return dp[maxWeight];
}

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int itemCount;
        cin >> itemCount;
        
        vector<vector<int>> items;
        items.reserve(itemCount);
        for (int i = 0; i < itemCount; ++i) {
            int price, weight;
            cin >> price >> weight;
            items.push_back({price, weight});
        }
        
        int peopleCount;
        cin >> peopleCount;
        
        vector<int> peopleCapacities;
        peopleCapacities.reserve(peopleCount);
        for (int i = 0; i < peopleCount; ++i) {
            int capacity;
            cin >> capacity;
            peopleCapacities.push_back(capacity);
        }
        
        sort(peopleCapacities.rbegin(), peopleCapacities.rend());
        
        int totalValue = 0;
        for (int capacity : peopleCapacities) {
            totalValue += knapsack(items, capacity);
        }
        
        cout << totalValue << endl;
    }
    
    return 0;
}