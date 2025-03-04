#include <iostream>
using namespace std;
//                             O(n log(n))
bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low; 
    
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[low], arr[i]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if (isSorted(arr, n)) {
    } else {
        quickSort(arr, 0, n - 1);
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

   return 0;
}