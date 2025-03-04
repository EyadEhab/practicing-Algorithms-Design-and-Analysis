#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    int arr[num];
    vector<int> v;
    bool understand = true;
        for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
        for (int i = 0; i < num; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < v.size(); j++) {
            if (arr[i] == v[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (isDuplicate) {
            understand = false;
            break;  
        } else {
            v.push_back(arr[i]);
        }
    }
        if (understand) {
        cout << "Yes, I understand the algorithm.";
    } else {
        cout << "No, I'll try again.";
    }
   
    return 0;
}