#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, x1, y1; // number of rows and columns
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char a[1005][1005];
bool used[1005][1005];
vector<char> path;

bool dfs(int i, int j) {
    if (a[i][j] == 'B') {
        return true;
    }
    used[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];

        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !used[i1][j1] && a[i1][j1] != '#') {
            if (k == 0) path.push_back('U');
            if (k == 1) path.push_back('L');
            if (k == 2) path.push_back('R');
            if (k == 3) path.push_back('D');

            if (dfs(i1, j1)) {
                return true;
            }
            path.pop_back(); // backtrack
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                x1 = i, y1 = j;
            }
        }
    }
    memset(used, false, sizeof(used));
    if (dfs(x1, y1)) {
        cout << "YES\n";
        cout << path.size() << "\n";
        for (char c : path) {
            cout << c;
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
