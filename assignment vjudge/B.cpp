#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int findMinDifference(vector<int>& coins) {
    int totalSum = accumulate(coins.begin(), coins.end(), 0);
    int halfSum = totalSum / 2;

    vector<bool> dp(halfSum + 1, false);
    dp[0] = true; // Base case: sum of 0 is always possible (empty subset)

    for (int coin : coins) {
        for (int j = halfSum; j >= coin; j--) {
            if (dp[j - coin]) {
                dp[j] = true;
            }
        }
    }

    int closestSum = 0;
    for (int j = halfSum; j >= 0; j--) {
        if (dp[j]) {
            closestSum = j;
            break;
        }
    }

    int otherSum = totalSum - closestSum;
    return abs(otherSum - closestSum);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        
        vector<int> coins(m);
        for (int j = 0; j < m; j++) {
            cin >> coins[j];
        }
        
        int result = findMinDifference(coins);
        cout << result << endl;
    }
    
    return 0;
}
