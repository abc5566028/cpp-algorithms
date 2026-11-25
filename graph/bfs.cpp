// BFS - shortest path in an unweighted graph
// Input : n m s, then m undirected edges u v (1-indexed)
// Output: distance from s to every vertex (-1 if unreachable)
// Complexity: O(n + m)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[s] = 0; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (dist[v] == -1) {          // first visit = shortest distance
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " \n"[i == n];
}
