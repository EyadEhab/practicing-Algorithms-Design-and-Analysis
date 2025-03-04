#include <iostream>
#include <unordered_set>
using namespace std;

long long Fibo(long long num){
    if(num <= 0)
        return 0;
    if(num == 1 || num == 2)
        return 1;
    return Fibo(num - 1) + Fibo(num - 2);
}

int main() {
    long long num;
    cin >> num;
    cout << Fibo(num);
    return 0;
}