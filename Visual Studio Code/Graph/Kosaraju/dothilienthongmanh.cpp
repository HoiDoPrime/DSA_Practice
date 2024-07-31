#include<bits/stdc++.h>
// in ra 1 neu do thi lien thong manh 0 neu nguoc lai
using namespace std;
vector<int> ke[100001],t_ke[100001];
bool used[100001];
stack<int> st;
int n,m;
void nhap(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        t_ke[y].push_back(x);
    }
    memset(used,false,sizeof(used));
}
void dfs1(int u){
    used[u]=true;
    for(int v: ke[u]){
        if(!used[v]){
            dfs1(v);
        }
    }
    st.push(u);
}
void dfs2(int u){
    //cout<<u<<" ";
    used[u]=true;
    for(int v: t_ke[u]){
        if(!used[v]){
            dfs2(v);
        }
    }
}
void kosaraju(){
    for(int i=1;i<=n;i++){
        if(!used[i]){
            dfs1(i);
        }
    }
    memset(used,false,sizeof(used));
    int scc = 0;
    while(!st.empty()){
        int top =st.top();st.pop();
        if(!used[top]){
            dfs2(top);
            scc++;
        }
    }
    if(scc==1){
        cout<<1;
    }
    else cout<<0;
}

int main(){
    nhap();
    kosaraju();
    return 0;
}