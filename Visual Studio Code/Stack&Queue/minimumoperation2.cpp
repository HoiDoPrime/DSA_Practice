#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem of transforming s into e using -1 and max(u,v)  u*v=N
int solve(int s) {

    queue<pair<int, int>> q; 
    q.push({s, 0}); 
    set<int> se; 
    se.insert(s);
    while (!q.empty()) {
        pair<int, int> x = q.front(); q.pop(); 

        if (x.first == 1) {
            return x.second; 
        }

        // Perform -1 operation
        if (x.first > 1 && se.count(x.first - 1) == 0) {
            q.push({x.first - 1, x.second + 1});
            se.insert(x.first - 1);
        }

        // Perform *2 operation
        int n=x.first;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                int u=i,v=n/i;
                int temp=max(u,v);
                if(se.count(temp)==0){
                    q.push({temp,x.second+1});
                    se.insert(temp);
                }
            }
        }
    }

    return -1; // If no solution is found
}

int main() {
    int t; cin >> t;
    while (t--) {
        int x;cin>>x;
        cout << solve(x) << endl; 
    }
    return 0;
}
