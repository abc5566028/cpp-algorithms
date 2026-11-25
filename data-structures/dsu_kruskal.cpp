// DSU (union by size + path compression) and Kruskal's MST
// Input : n m, then m undirected edges u v w (1-indexed)
// Output: total weight of the minimum spanning tree, or -1 if the graph is disconnected
// Complexity: O(m log m)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n + 1), sz(n + 1, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<ll, 3>> e(m);              // {w, u, v}
    for (auto &x : e) cin >> x[1] >> x[2] >> x[0];
    sort(e.begin(), e.end());               // greedy: lightest edges first
    DSU d(n);
    ll total = 0; int used = 0;
    for (auto [w, u, v] : e)
        if (d.unite(u, v)) { total += w; used++; }
    cout << (used == n - 1 ? total : -1) << "\n";
}
