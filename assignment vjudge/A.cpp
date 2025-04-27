#include <iostream>
using namespace std;

void fib(long long n, long long mod, long long &x, long long &y) {
    if (n == 0) {
        x = 0 % mod;
        y = 1 % mod;
        return;
    }

    long long x1, y1; // x1 = f(n/2) , y1 = f(n/2+1)
    fib(n / 2, mod, x1, y1);

    long long w = (x1 * x1 + y1 * y1) % mod;
    long long z = (x1 * ((2 * y1 - x1) % mod + mod) % mod) % mod;

    if (n % 2 == 1) {
        x = w;
        y = (z + w) % mod;
    } else {
        x = z;
        y = w;
    }
}

void answer(long long n, int m) {
    if (m == 0) {
        cout << 0 << endl;
        return;
    }
    long long mod = 1LL << m;
    long long x, y;
    fib(n, mod, x, y);
    cout << x << endl;
}

int main() {
    long long n, m;
    while (cin >> n >> m) {
        answer(n, m);
    }
    return 0;
}