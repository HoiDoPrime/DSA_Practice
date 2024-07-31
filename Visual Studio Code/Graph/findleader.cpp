#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool used[100005];
vector<int> ke[100005];
int nhomtruong;
int bac[1005];
int m, n;
void dfs(int u){
    if(bac[u]>bac[nhomtruong] || bac[u]==bac[nhomtruong] && u<nhomtruong){
        nhomtruong=u;
    }
    used[u]=true;
    for(int v:ke[u]){
        if(!used[v]){
            dfs(v);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
        bac[x]++;bac[y]++;
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            nhomtruong=i;
            dfs(i);
            v.push_back(nhomtruong);
    }
    }
    sort(v.begin(),v.end());
    for(int x: v){
        cout<<x<<" ";
    }


    return 0;
}