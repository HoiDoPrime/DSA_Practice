/*
*    Author: rishabhxchoudhary
*    Created: Saturday, 02.03.2024 10:26 AM (GMT+5:30)
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define double long double
#define endl '\n'
 
const int MOD = 1000000007;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int n,m;
    cin>>n>>m;
    vector<int>graph[n+1],rgraph[n+1];
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    
    vector<bool> vis(n+1,false);
    vector<int>topo;
    function<void(int)> dfs = [&](int node){
        vis[node] = true;
        for(int child: graph[node])  {
            if (!vis[child]) dfs(child);
        }
        topo.push_back(node);
    };
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    reverse(topo.begin(),topo.end());
    
    function<void(int)> dfs2 = [&](int node){
        vis[node] = true;
        for(int child: rgraph[node])  {
            if (!vis[child]) dfs2(child);
        }
    };
    
    for (int i = 1; i <= n; i++) {
        vis[i]=false;
    }
    
    vector<int>scc;
    for (int i: topo) {
        if (!vis[i]){
            scc.push_back(i);
            dfs2(i);
        }
    }
    
    if (scc.size()>1){
        cout<<"NO\n";
        cout<<scc[1]<<" "<<scc[0]<<endl;
    } else {
        cout<<"YES\n";
        
    }
 
    return 0;
}