#include <iostream>
using namespace std;

long long Fibo(long long num) {
    if (num <= 0)
        return 0;
    if (num == 1 || num == 2)
        return 1;

    long long prev1 = 1, prev2 = 1;  
    long long result = 0;

    for (long long i = 3; i <= num; ++i) {
        result = prev1 + prev2;
        prev2 = prev1;
        prev1 = result;
    }

    return result;
}

int main() {
    long long num;
    cin >> num;
    cout << Fibo(num) << endl;
    return 0;
}