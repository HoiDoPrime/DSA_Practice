#include<bits/stdc++.h>
using namespace std;
int n,m,st;

vector<pair<int,int>> ke[1005]; // first: chi phi, second: dinh ke
void bellmanford(int st){
    for(int i=1;i<=n;i++){
        d[i]=1e9;
    }
    d[st]=0;
    for(int i=0;i<n;i++){
        for(int u=1;u<=n;u++){
            for(auto it: ke[u]){
                int v=it.second,len=it.first;
                d[v]=min(d[v],d[u]+len);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
}
int main(){
    cin>>n>>m>>st;
    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        ke[x].push_back({z,y});
        ke[y].push_back({z,x});
    }
    bellmanford(st);


    return 0;
}