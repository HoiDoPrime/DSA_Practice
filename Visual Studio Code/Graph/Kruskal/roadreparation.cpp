#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int x, y, w;
};

int n, m;
int parent[100005], sz[100005];
vector<edge> dscanh;

void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        // Each node is its own parent initially
        parent[i] = i;
        sz[i] = 1; // Size should be initialized to 1
    }
}

// Find the representative of the set containing u
int Find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    else
    {
        return parent[u] = Find(parent[u]);
    }
}

// Union by size: attach the smaller tree under the larger tree
bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
    {
        return false;
    }
    if (sz[u] > sz[v])
    {
        parent[v] = u;
        sz[u] += sz[v];
    }
    else
    {
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        dscanh.push_back({x, y, w});
    }
}

void Kruskal()
{
    // Step 1: Sort edges by weight
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b) -> bool
         { return a.w < b.w; });

    // Step 2: Iterate and construct MST
    long long d = 0;
    vector<edge> MST;
    for (int i = 0; i < m; i++)
    {
        if (MST.size() == n - 1)
            break;
        edge e = dscanh[i];
        if (Union(e.x, e.y))
        {
            MST.push_back(e);
            d += e.w;
        }
    }
    if (MST.size() < n - 1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << d << endl;
    }
}

int main()
{
    nhap();
    ktao();
    Kruskal();
    return 0;
}
