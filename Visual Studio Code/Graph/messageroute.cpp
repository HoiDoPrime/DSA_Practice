#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
// tim duong di ngan nhat giua dinh 1 va dinh n
bool used[100005];
vector<int> ke[100005];
int parent[100005];

void dfs(int u)
{
    used[u] = true;
    for (int v : ke[u])
    {
        if (!used[v])
        {
            parent[v] = u;
            dfs(v);
        }
    }
}
void path(int n)
{
    dfs(1);
    if (!used[n])
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> res;
        while (n != 1)
        {
            res.push_back(n);
            n = parent[n];
        }
        res.push_back(1);
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        for (int x : res)
        {
            cout << x << " ";
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    path(n);
    return 0;
}