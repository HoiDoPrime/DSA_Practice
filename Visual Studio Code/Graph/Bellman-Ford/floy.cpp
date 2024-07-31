#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10005][10005];

int main(){
    int q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) a[i][j]=0;
            else a[i][j] =1e18;
        }
    }
    for(int i=0;i<m;i++){
        long long x,y,z;cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while(q--){
        long  long x,y;cin>>x>>y;
        if(a[x][y]==1e18){
            cout<<-1<<endl;
        }
        else
        cout<<a[x][y]<<endl;
    }
    
    


    return 0;

}