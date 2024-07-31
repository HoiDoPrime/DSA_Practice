#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX; // Định nghĩa giá trị vô cùng lớn

int n, m;
vector<pair<int, long long>> ke[100001];

void nhap() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        long long w; // Sử dụng long long cho trọng số
        cin >> x >> y >> w;
        ke[x].push_back({y, w});
        // ke[y].push_back({x, w}); // Nếu đồ thị có hướng thì không cần dòng này
    }
}

void dijkstra(int s) {
    vector<long long> d(n + 1, INF); // Sử dụng long long cho độ dài đường đi
    d[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
    Q.push({0, s});
    
    while (!Q.empty()) {
        // Chọn ra đỉnh u có đường đi ngắn nhất => relaxation
        pair<long long, int> top = Q.top(); 
        Q.pop();
        int u = top.second;
        long long kc = top.first;
        
        if (kc > d[u]) continue; // Nếu khoảng cách không còn nhỏ hơn thì bỏ qua
        
        // Relax
        for (auto it : ke[u]) {
            int v = it.first;
            long long w = it.second; // Sử dụng long long cho trọng số
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            cout << "INF "; // Nếu không thể đến đỉnh i, in ra INF
        } else {
            cout << d[i] << " ";
        }
    }
}

int main() {
    nhap();
    dijkstra(1);
    return 0;
}
