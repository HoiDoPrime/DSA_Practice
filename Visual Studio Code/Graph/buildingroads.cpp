#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool used[100005];
vector<int> ke[100005];
// thêm vào ít nhất bao nhiêu cạnh để đồ thị liên thông
void dfs(int u)
{
    used[u] = true;
    for (int x : ke[u])
    {
        if (!used[x])
        {
            dfs(x);
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
    int count = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            count++;
            v.push_back(i);
            dfs(i);
        }
    }
    cout << count - 1 << endl;
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i - 1] << " " << v[i] << endl;
    }

    return 0;
}
/*Example
Input:
4 2
1 2
3 4
Output:
1
2 3*/