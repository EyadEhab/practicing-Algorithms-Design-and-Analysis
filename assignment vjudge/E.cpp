#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void calculateNicestRoute(vector<int>& routeSegments, int totalStops, int routeIndex) {
    int maxNiceness = routeSegments[0];
    int currentNiceness = routeSegments[0];
    int bestStartStop = 1, bestEndStop = 2;
    int currentStartStop = 1;
    int maxLength = 1;

    for(int segmentIndex = 1; segmentIndex < totalStops-1; segmentIndex++) {
        if (routeSegments[segmentIndex] > currentNiceness + routeSegments[segmentIndex]) {
            currentNiceness = routeSegments[segmentIndex];
            currentStartStop = segmentIndex + 1;
        } else {
            currentNiceness = currentNiceness + routeSegments[segmentIndex];
        }
        
        int currentLength = (segmentIndex + 2) - currentStartStop;
        
        if (currentNiceness > maxNiceness || 
            (currentNiceness == maxNiceness && currentLength > maxLength) ||
            (currentNiceness == maxNiceness && currentLength == maxLength && currentStartStop < bestStartStop)) {
            maxNiceness = currentNiceness;
            bestStartStop = currentStartStop;
            bestEndStop = segmentIndex + 2;
            maxLength = currentLength;
        }
    }
    
    if (maxNiceness <= 0) {
        cout << "Route " << routeIndex + 1 << " has no nice parts" << endl;
    } else {
        cout << "The nicest part of route " << routeIndex + 1 << " is between stops " << bestStartStop << " and " << bestEndStop << endl;
    }
}

int main() {
    int routeCount;
    cin >> routeCount;
    
    for (int routeIndex = 0; routeIndex < routeCount; routeIndex++) {
        int stopCount;
        cin >> stopCount;
        
        vector<int> routeSegments(stopCount-1);
        
        for (int segmentIndex = 0; segmentIndex < stopCount-1; segmentIndex++) {
            cin >> routeSegments[segmentIndex];
        }
        
        calculateNicestRoute(routeSegments, stopCount, routeIndex);
    }
    
    return 0;
}
