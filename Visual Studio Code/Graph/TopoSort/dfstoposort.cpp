#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//theo thu tu duyet xong 
//<=> dinh u duyet xong => stack
stack<int> st;
int n, m;
bool used[100005];
vector<int> ke[100005];
void dfs(int u){
    used[u]=true;
    for(int x: ke[u]){
        if(!used[x]){
            dfs(x);
        }
    }
    st.push(u);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            dfs(i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();

    }
}