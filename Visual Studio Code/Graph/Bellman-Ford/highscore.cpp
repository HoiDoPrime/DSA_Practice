#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n, m;
vector<pair<int, long long>> adj[2505]; // adjacency list with cost and destination
vector<long long> dist;

void bellmanFord(int start) {
    dist.assign(n + 1, -INF);
    dist[start] = 0;

    // Relax edges up to n-1 times
    for (int i = 1; i <= n; ++i) {
        for (int u = 1; u <= n; ++u) {
            if (dist[u] != -INF) {
                for (auto &edge : adj[u]) {
                    int v = edge.first;
                    long long weight = edge.second;
                    if (dist[u] + weight > dist[v]) {
                        dist[v] = dist[u] + weight;
                        // Check if relaxation is possible in the nth iteration
                        if (i == n) {
                            // Run an extra iteration to detect negative-weight cycles
                            for (auto &e : adj[u]) {
                                int v = e.first;
                                long long weight = e.second;
                                if (dist[u] + weight > dist[v]) {
                                    // If we can still relax an edge, it means there's a negative-weight cycle
                                    // that can reach the destination.
                                    dist[v] = INF;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // After all relaxations, if dist[n] is INF, it means there is a reachable negative-weight cycle
    // affecting the path to n.
    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
    }

    bellmanFord(1); // Compute longest path from node 1
    return 0;
}
