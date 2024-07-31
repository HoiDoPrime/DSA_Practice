#include<iostream>
#include<vector>
using namespace std;
// trường hợp n đỉnh có m-1 cạnh và không có chu trình
int n, m,ok=0,parent[1005];
bool used[1005];
vector<int> ke[1005];
void dfs(int u) {
    if(ok) return;
    used[u] = true;
    for (int x : ke[u]) {
        if (!used[x]) {
            parent[x] = u;
            dfs(x);
        }
        else if(used[x] && x!=parent[u]){
            ok=1;
            return;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    if(m==m-1 && !ok){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}