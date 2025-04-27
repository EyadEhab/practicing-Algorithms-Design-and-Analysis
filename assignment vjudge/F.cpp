#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFormTriangle(const vector<int>& sides) {
    int n = sides.size();
    
    vector<int> sortedSides = sides;
    sort(sortedSides.begin(), sortedSides.end());

    for (int i = 0; i < n - 2; i++) {
        long long a = sortedSides[i];
        long long b = sortedSides[i + 1];
        long long c = sortedSides[i + 2];
        
        if (a + b > c) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i];
    }
    
    if (canFormTriangle(segments)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
