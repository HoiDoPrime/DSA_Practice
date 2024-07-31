#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int x, y;
};

int n, m,dem,current=1;
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
    current=max({current,sz[v],sz[u]});
    return true;
}
int main()
{
    cin>>n>>m;
    ktao();
    dem=n;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        if(Union(x,y)){
        dem--;
        }
        cout<<dem<<" "<<current<<endl;
    }

    return 0;
}
