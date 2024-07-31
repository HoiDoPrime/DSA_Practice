#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; // Sử dụng giá trị lớn làm vô cực

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    // Khởi tạo khoảng cách từ mỗi thành phố đến chính nó là 0
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // Đọc thông tin các con đường và cập nhật khoảng cách
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (long long)c);
        dist[b][a] = min(dist[b][a], (long long)c);
    }

    // Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Xử lý các truy vấn
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }

    return 0;
}
