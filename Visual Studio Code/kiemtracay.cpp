#include<iostream>
#include<vector>
using namespace std;

int n, m, count = 0;
bool used[1005];
vector<int> ke[1005];

void dfs(int u) {
    count++;
    used[u] = true;
    for (int x : ke[u]) {
        if (!used[x]) {
            dfs(x);
        }
    }
}

int Check() {
    fill(used, used + n + 1, false);
    count = 0;
    dfs(1);
    if (n == count) {
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    
    if (m == n - 1 && Check()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
