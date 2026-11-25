// Sieve of Eratosthenes
// Input : n
// Output: number of primes <= n, then the primes themselves
// Complexity: O(n log log n)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    for (long long i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (long long j = i * i; j <= n; j += i)   // start at i*i: smaller multiples already marked
                isPrime[j] = false;
    vector<int> primes;
    for (int i = 2; i <= n; i++) if (isPrime[i]) primes.push_back(i);
    cout << primes.size() << "\n";
    for (size_t i = 0; i < primes.size(); i++) cout << primes[i] << " \n"[i + 1 == primes.size()];
}
