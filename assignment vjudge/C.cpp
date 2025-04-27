#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        vector<int> prices(N);
        for (int i = 0; i < N; i++) {
            cin >> prices[i];
        }
        
        int M;
        cin >> M; 
        sort(prices.begin(), prices.end());
        int book1 = 0, book2 = 0;
        int minDiff = 1000001;
        
        int left = 0, right = N - 1;
        
        while (left < right) {
            int sum = prices[left] + prices[right];
            
            if (sum == M) {
                int diff = prices[right] - prices[left];
                if (diff < minDiff) {
                    minDiff = diff;
                    book1 = prices[left];
                    book2 = prices[right];
                }
                left++;
                right--;
            } else if (sum < M) {
                left++;
            } else {
                right--;
            }
        }

        cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << "." << endl << endl;
    }
    
    return 0;
}