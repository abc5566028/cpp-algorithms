// Dijkstra - single-source shortest paths, non-negative weights
// Input : n m s, then m directed edges u v w (1-indexed)
// Output: shortest distance from s to every vertex (-1 if unreachable)
// Complexity: O((n + m) log n)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;       // outdated entry, skip
        for (auto [v, w] : adj[u])
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
    }
    for (int i = 1; i <= n; i++)
        cout << (dist[i] == INF ? -1 : dist[i]) << " \n"[i == n];
}
