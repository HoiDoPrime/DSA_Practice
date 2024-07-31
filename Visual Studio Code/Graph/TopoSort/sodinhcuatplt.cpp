
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
stack<int> st;
bool used[100005];
char a[10005][10005];
int n,m;
// 1 la di duoc 0 la vat can
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int bfs(int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    a[i][j]='#';
    int dem=0;
    while(!q.empty()){
        auto it = q.front();q.pop();
        int i =it.first,j=it.second;
        dem++;
        for(int k=0;k<4;k++){
            int i1=i+dx[k],j1=j+dy[k];
            if(i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]=='.'){
                q.push({i1,j1});
                a[i1][j1]=0;
            }
        }
    }
    return dem;
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='.'){
                cout<<bfs(i,j)<<" ";
            }
        }
    }
    


    return 0;
}