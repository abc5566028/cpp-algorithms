// Fast modular exponentiation (binary exponentiation)
// Input : a b m
// Output: a^b mod m
// Complexity: O(log b)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll m) {
    ll res = 1 % m;
    a %= m; if (a < 0) a += m;
    while (b > 0) {
        if (b & 1) res = (__int128)res * a % m;   // __int128 avoids overflow when m is up to 1e18
        a = (__int128)a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ll a, b, m;
    cin >> a >> b >> m;
    cout << power(a, b, m) << "\n";
}
