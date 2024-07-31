#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, s, e;
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
void path(int s, int e)
{
    memset(used, false, sizeof(used));
    memset(parent, 0, sizeof(parent));
    dfs(s);
    if (!used[e])
    {
        cout << "Khong ton tai duong di\n";
    }
    else
    {
        // truy vet duonng di
        vector<int> res;
        // bat dau tu dinh e(end)
        while (e != s)
        {
            res.push_back(e);
            e = parent[e];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for (int x : res)
        {
            cout << x << " ";
        }
    }
}
int main()
{
    cin >> n >> m >> s >> e;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    path(s, e);
    return 0;
}
// 10 8 1 7
// 1 2
// 2 4
// 2 3
// 6 3
// 6 7
// 3 7
// 5 8
// 3 7
// 5 8
// 8 9