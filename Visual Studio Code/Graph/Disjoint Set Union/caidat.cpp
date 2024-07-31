#include<bits/stdc++.h>
using namespace std;
// gop cac thanh phan lien thong lai voi nhau 
int n,m;
int parent[100005],sz[100005];
void ktao(){
    cin>>n;
    for(int i=1;i<=n;i++){
        // moi dinh dai dien cho chinh no
        parent[i]=i;
        sz[i]=i;
    }
}
// tìm đỉnh đại diện cho thành phần liên thông chứa u
int Find(int u){
    // tim phan tu u co cha la chinh no
    if(u==parent[u]){
        return u;
    }
    else return parent[u]=Find(parent[u]);
}
// ghép 2 đỉnh của 2 thành phần liên thông
bool Union(int u,int v){
    u=Find(u);
    v=Find(v);
    if(u==v){
        return false;
    }
    if(sz[u]>sz[v]){
        parent[v] =u;
        sz[u]+=sz[v];
    }
    else{
        parent[u]=v;
        sz[v]+=sz[u];
    }
    return true;
}



int main(){
    ktao();
    cout<<Union(6,7)<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
    
    

    return 0;
}