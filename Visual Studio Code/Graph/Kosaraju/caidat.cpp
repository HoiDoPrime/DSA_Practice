#include<bits/stdc++.h>

using namespace std;
int n,m;
vector<int> ke[100001],t_ke[100001];
bool used[100001];
stack<int> st;
void nhap(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        t_ke[y].push_back(x);    //dao nguoc
    }
    memset(used,false,sizeof(used));
}
void dfs1(int u){
    used[u]=true;
    for(int x:ke[u]){
        if(!used[x]){
            dfs1(x);
        }
    }
    st.push(u);
}
void dfs2(int u){
    cout<<u<<" ";
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
        int top =st.top() ;st.pop();
        if(!used[top]){
            ++scc;
            dfs2(top);
            cout<<endl;
        }
    }
    if(scc==1){
        cout<<"Do thi lien thong manh\n";
    }
    else
    cout<<"So thanh phan lien thong manh la: "<<scc<<endl;

}
int main(){
    nhap();
    kosaraju();

    return 0;
}