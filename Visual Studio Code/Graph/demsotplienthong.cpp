#include <iostream>
#include <vector>
using namespace std;
bool used[100005];
vector<int> ke[100005];
int m, n;
void dfs(int u)
{
    cout << u << " ";
    used[u] = true;
    for (int x : ke[u])
    {
        if (!used[x])
        {
            dfs(x);
        }
    }
}
void demtplt()
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            count++;
            cout << "Cac dinh thuoc thanh phan lien thong thu " << count << " la: ";
            dfs(i);
            cout << endl;
        }
    }
    if (count == 1)
    {
        cout << "Do thi lien thong\n";
    }
    else
    {
        cout << "Do thi khong lien thong\n";
    }
    cout << "So thanh phan lien thong cua do thi la: " << count << endl;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    demtplt();

    return 0;
}