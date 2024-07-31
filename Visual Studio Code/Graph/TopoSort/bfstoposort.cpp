#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
// xoa gan dinh
// xoa ban bac vao
int n, m,bac[100005];
bool used[100005];
vector<int> ke[100005];
void Kahn(){
    queue<int> q;
    vector<int> topo;
    for(int i=1;i<=n;i++){
        if(bac[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        topo.push_back(u);
        //cout<<u<<" ";
        for(int v:ke[u]){
            bac[v]--;
            if(bac[v]==0){
                q.push(v);
            }

        }
    }
    if(topo.size()!=n){
        cout<<"Co chu trinh";
    }
    else{
        for(int x: topo){
            cout<<x<<" ";
        }
    }

}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        bac[y]++;  // tang bac vao
    }
    Kahn();

    return 0;
}