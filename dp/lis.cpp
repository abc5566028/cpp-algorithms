// Longest (strictly) Increasing Subsequence
// Input : n, then n integers
// Output: length of the LIS
// Complexity: O(n log n)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    // tail[k] = smallest possible last element of an increasing subsequence of length k+1
    vector<long long> tail;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        auto it = lower_bound(tail.begin(), tail.end(), x);   // use upper_bound for non-decreasing
        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    cout << tail.size() << "\n";
}
