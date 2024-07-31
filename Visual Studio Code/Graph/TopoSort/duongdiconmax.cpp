#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
stack<int> st;
bool used[100005];
vector<int> ke[100005];
int a[10005][10005];
// duong di cua con ma
int dx[]={-2,-2,-1,-1, 1, 1, 2, 2};
int dy[]={-1, 1,-2, 2,-2, 2,-1, 1};
int bfs(){
    queue<pair<pair<int,int>,int>> q; //((s1,s2),so buoc)
    q.push({{s1,s2},0});
    a[s1][s2]=0;
    while(!q.empty()){
        auto it=q.front();q.pop();
        int i=it.first.first, j =it.first.second, d=it.second;
        if(i==t1 && j==t2){
            return d;
        }
        for(int k=0;k<8;k++){
            int i1=i+dx[k],j1=j+dy[k];
            if(i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]){
                q.push({{i1,j1},d+1});
                a[i1][j1]=0;
            }
        }

    }
    return -1; // -1 neu khong co duong di
}
int n,s1,s2,t1,t2;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<bfs()<<endl;



    return 0;
}