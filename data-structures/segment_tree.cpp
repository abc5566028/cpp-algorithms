// Segment Tree - point update, range sum query
// Input : n q, array a[1..n], then q queries:
//         "1 i x" -> set a[i] = x
//         "2 l r" -> print a[l] + ... + a[r]
// Complexity: O(n) build, O(log n) per query
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> t;

void update(int node, int l, int r, int pos, ll val) {
    if (l == r) { t[node] = val; return; }
    int mid = (l + r) / 2;
    if (pos <= mid) update(2 * node, l, mid, pos, val);
    else            update(2 * node + 1, mid + 1, r, pos, val);
    t[node] = t[2 * node] + t[2 * node + 1];
}

ll query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;                 // no overlap
    if (ql <= l && r <= qr) return t[node];         // full overlap
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q;
    cin >> n >> q;
    t.assign(4 * n, 0);
    for (int i = 1; i <= n; i++) { ll x; cin >> x; update(1, 1, n, i, x); }
    while (q--) {
        int type; cin >> type;
        if (type == 1) { int i; ll x; cin >> i >> x; update(1, 1, n, i, x); }
        else { int l, r; cin >> l >> r; cout << query(1, 1, n, l, r) << "\n"; }
    }
}
