#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int num;
    cin >> num;
    int arr[num];
   
    unordered_set<int> temp;
    bool understand = true;
   
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
       
        if (temp.find(arr[i]) != temp.end()) {
            understand = false;
            break;  
        }
       
        temp.insert(arr[i]);
    }
   
    if (understand) {
        cout << "Yes, I understand the algorithm.";
    } else {
        cout << "No, I'll try again.";
    }
   
    return 0;
}