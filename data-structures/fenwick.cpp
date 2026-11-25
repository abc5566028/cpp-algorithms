// Fenwick Tree (Binary Indexed Tree) - point add, prefix/range sum
// Input : n q, array a[1..n], then q queries:
//         "1 i x" -> a[i] += x
//         "2 l r" -> print a[l] + ... + a[r]
// Complexity: O(log n) per operation
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n; vector<ll> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, ll x) { for (; i <= n; i += i & -i) bit[i] += x; }
    ll sum(int i) { ll s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
    ll sum(int l, int r) { return sum(r) - sum(l - 1); }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    Fenwick fw(n);
    for (int i = 1; i <= n; i++) { ll x; cin >> x; fw.add(i, x); }
    while (q--) {
        int type; cin >> type;
        if (type == 1) { int i; ll x; cin >> i >> x; fw.add(i, x); }
        else { int l, r; cin >> l >> r; cout << fw.sum(l, r) << "\n"; }
    }
}
