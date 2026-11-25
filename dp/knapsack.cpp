// 0/1 Knapsack
// Input : n W, then n lines: weight value
// Output: maximum total value with total weight <= W (each item used at most once)
// Complexity: O(n * W) time, O(W) memory
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, W;
    cin >> n >> W;
    // dp[c] = best value using capacity c with the items processed so far
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        int w; ll v; cin >> w >> v;
        // iterate capacity downwards so each item is taken at most once
        for (int c = W; c >= w; c--)
            dp[c] = max(dp[c], dp[c - w] + v);
    }
    cout << dp[W] << "\n";
}
